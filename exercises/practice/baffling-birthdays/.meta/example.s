.text
.globl shared_birthday
.globl estimate

/* extern bool shared_birthday(size_t birthdates_count, const date_t *birthdates); */
shared_birthday:
        stp     xzr, xzr, [sp, #-64]!   /* 32 halfwords on stack */
        stp     xzr, xzr, [sp, #16]
        stp     xzr, xzr, [sp, #32]
        stp     xzr, xzr, [sp, #48]

        add     x2, x1, x0, lsl #2      /* end of birthdates */
        mov     x0, xzr
        mov     w3, #1

.birthdate:
        cmp     x1, x2
        beq     .return

        ldrb    w12, [x1, #2]           /* month 1..12 */
        ldrb    w13, [x1, #3]           /* day 1..31 */
        add     x1, x1, #4

        lsl     w13, w13, #1
        lsl     w12, w3, w12            /* 1 << month */

        ldrh    w11, [sp, x13]
        orr     w14, w11, w12
        strh    w14, [sp, x13]
        cmp     w11, w14
        bne     .birthdate

        mov     x0, #1

.return:
        add     sp, sp, #64
        ret

/* extern double estimate(int group_size); */
estimate:
        mov     w9, #1
        mov     w10, #100
        mov     w11, #365
        scvtf   d0, w9                  /* probability of no shared birthday */
        scvtf   d1, w9
        scvtf   d2, w11                 /* descending numerator */
        scvtf   d3, w11                 /* constant denominator */
        scvtf   d4, w10

        cbz     w0, .complement

.multiply:
        fmul    d0, d0, d2              /* multiply by 365, 364, 363, ... */
        fdiv    d0, d0, d3              /* divide by 365 */
        fsub    d2, d2, d1
        add     w0, w0, #-1             /* number of remaining birthdates */
        cbnz    w0, .multiply

.complement:
        fsub    d0, d1, d0              /* probability of shared birthday */
        fmul    d0, d0, d4              /* convert to percentage */
        ret
