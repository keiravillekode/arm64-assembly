FUNC_PROTO = """\
#include "vendor/unity.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
} date_t;

extern bool shared_birthday(size_t birthdates_count, const date_t *birthdates);

// estimated probability of shared birthday
extern double estimate(int group_size);
"""

# Tolerances allowing the probability to be estimated by simulating at least
# 600 groups, rather than calculated exactly. Shared with the x86-64 track.
DELTA = {"0.0": 0.1, "11.694818": 8.2765, "50.729723": 12.88, "99.915958": 0.83}


def array_literal(numbers):
    return str(numbers).replace("[", "{").replace("]", "}")


def gen_func_body(prop, inp, expected):
    if prop == "shared_birthday":
        str_list = []
        if expected:
            macro = "TEST_ASSERT_TRUE"
        else:
            macro = "TEST_ASSERT_FALSE"
        birthdates = [
            [int(part) for part in birthdate.split("-")]
            for birthdate in inp["birthdates"]
        ]
        str_list.append(f"const date_t birthdates[] = {array_literal(birthdates)};")
        str_list.append(f"{macro}({prop}(ARRAY_SIZE(birthdates), birthdates));\n")
        return "\n".join(str_list)

    group_size = inp["groupSize"]
    delta = DELTA[str(expected)]
    return f"TEST_ASSERT_FLOAT_WITHIN({delta}, {expected}, estimate({group_size}));\n"
