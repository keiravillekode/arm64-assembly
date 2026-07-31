# Instructions append

## Implementation

This track does not ask you to generate random birthdates, so there is no
`random_birthdates` function to implement.
The tests pass the birthdates to `shared_birthday` as an array of

```c
typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
} date_t;
```

together with the number of elements in that array.

`estimate` returns the probability as a percentage between `0.0` and `100.0`.
You may either calculate it exactly, or estimate it by simulation.

If you simulate, you will need to write your own pseudo random number
generator, and simulate at least 600 groups.
Any seed will do, including a hard coded one: the tests never require two runs
to produce different results.
The tolerances are 0.1 for a group of one person, 8.2765 for ten people, 12.88
for twenty-three people, and 0.83 for seventy people.
