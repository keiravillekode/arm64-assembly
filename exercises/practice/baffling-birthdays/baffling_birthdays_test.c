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

void setUp(void) {
}

void tearDown(void) {
}

void test_one_birthdate(void) {
    const date_t birthdates[] = {{2000, 1, 1}};
    TEST_ASSERT_FALSE(shared_birthday(ARRAY_SIZE(birthdates), birthdates));
}

void test_two_birthdates_with_same_year_month_and_day(void) {
    TEST_IGNORE();
    const date_t birthdates[] = {{2000, 1, 1}, {2000, 1, 1}};
    TEST_ASSERT_TRUE(shared_birthday(ARRAY_SIZE(birthdates), birthdates));
}

void test_two_birthdates_with_same_year_and_month_but_different_day(void) {
    TEST_IGNORE();
    const date_t birthdates[] = {{2012, 5, 9}, {2012, 5, 17}};
    TEST_ASSERT_FALSE(shared_birthday(ARRAY_SIZE(birthdates), birthdates));
}

void test_two_birthdates_with_same_month_and_day_but_different_year(void) {
    TEST_IGNORE();
    const date_t birthdates[] = {{1999, 10, 23}, {1988, 10, 23}};
    TEST_ASSERT_TRUE(shared_birthday(ARRAY_SIZE(birthdates), birthdates));
}

void test_two_birthdates_with_same_year_but_different_month_and_day(void) {
    TEST_IGNORE();
    const date_t birthdates[] = {{2007, 12, 19}, {2007, 4, 27}};
    TEST_ASSERT_FALSE(shared_birthday(ARRAY_SIZE(birthdates), birthdates));
}

void test_two_birthdates_with_different_year_month_and_day(void) {
    TEST_IGNORE();
    const date_t birthdates[] = {{1997, 8, 4}, {1963, 11, 23}};
    TEST_ASSERT_FALSE(shared_birthday(ARRAY_SIZE(birthdates), birthdates));
}

void test_multiple_birthdates_without_shared_birthday(void) {
    TEST_IGNORE();
    const date_t birthdates[] = {{1966, 7, 29}, {1977, 2, 12}, {2001, 12, 25}, {1980, 11, 10}};
    TEST_ASSERT_FALSE(shared_birthday(ARRAY_SIZE(birthdates), birthdates));
}

void test_multiple_birthdates_with_one_shared_birthday(void) {
    TEST_IGNORE();
    const date_t birthdates[] = {{1966, 7, 29}, {1977, 2, 12}, {2001, 7, 29}, {1980, 11, 10}};
    TEST_ASSERT_TRUE(shared_birthday(ARRAY_SIZE(birthdates), birthdates));
}

void test_multiple_birthdates_with_more_than_one_shared_birthday(void) {
    TEST_IGNORE();
    const date_t birthdates[] = {{1966, 7, 29}, {1977, 2, 12}, {2001, 12, 25}, {1980, 7, 29}, {2019, 2, 12}};
    TEST_ASSERT_TRUE(shared_birthday(ARRAY_SIZE(birthdates), birthdates));
}

void test_for_one_person(void) {
    TEST_IGNORE();
    TEST_ASSERT_FLOAT_WITHIN(0.1, 0.0, estimate(1));
}

void test_among_ten_people(void) {
    TEST_IGNORE();
    TEST_ASSERT_FLOAT_WITHIN(8.2765, 11.694818, estimate(10));
}

void test_among_twentythree_people(void) {
    TEST_IGNORE();
    TEST_ASSERT_FLOAT_WITHIN(12.88, 50.729723, estimate(23));
}

void test_among_seventy_people(void) {
    TEST_IGNORE();
    TEST_ASSERT_FLOAT_WITHIN(0.83, 99.915958, estimate(70));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_one_birthdate);
    RUN_TEST(test_two_birthdates_with_same_year_month_and_day);
    RUN_TEST(test_two_birthdates_with_same_year_and_month_but_different_day);
    RUN_TEST(test_two_birthdates_with_same_month_and_day_but_different_year);
    RUN_TEST(test_two_birthdates_with_same_year_but_different_month_and_day);
    RUN_TEST(test_two_birthdates_with_different_year_month_and_day);
    RUN_TEST(test_multiple_birthdates_without_shared_birthday);
    RUN_TEST(test_multiple_birthdates_with_one_shared_birthday);
    RUN_TEST(test_multiple_birthdates_with_more_than_one_shared_birthday);
    RUN_TEST(test_for_one_person);
    RUN_TEST(test_among_ten_people);
    RUN_TEST(test_among_twentythree_people);
    RUN_TEST(test_among_seventy_people);
    return UNITY_END();
}
