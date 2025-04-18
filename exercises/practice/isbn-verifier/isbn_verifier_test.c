#include "vendor/unity.h"

extern int is_valid(const char *isbn);

void setUp(void) {
}

void tearDown(void) {
}

void test_valid_isbn(void) {
    TEST_ASSERT_TRUE(is_valid("3-598-21508-8"));
}

void test_invalid_isbn_check_digit(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("3-598-21508-9"));
}

void test_valid_isbn_with_a_check_digit_of_10(void) {
    TEST_IGNORE();
    TEST_ASSERT_TRUE(is_valid("3-598-21507-X"));
}

void test_check_digit_is_a_character_other_than_x(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("3-598-21507-A"));
}

void test_invalid_check_digit_in_isbn_is_not_treated_as_zero(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("4-598-21507-B"));
}

void test_invalid_character_in_isbn_is_not_treated_as_zero(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("3-598-P1581-X"));
}

void test_x_is_only_valid_as_a_check_digit(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("3-598-2X507-9"));
}

void test_valid_isbn_without_separating_dashes(void) {
    TEST_IGNORE();
    TEST_ASSERT_TRUE(is_valid("3598215088"));
}

void test_isbn_without_separating_dashes_and_x_as_check_digit(void) {
    TEST_IGNORE();
    TEST_ASSERT_TRUE(is_valid("359821507X"));
}

void test_isbn_without_check_digit_and_dashes(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("359821507"));
}

void test_too_long_isbn_and_no_dashes(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("3598215078X"));
}

void test_too_short_isbn(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("00"));
}

void test_isbn_without_check_digit(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("3-598-21507"));
}

void test_check_digit_of_x_should_not_be_used_for_0(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("3-598-21515-X"));
}

void test_empty_isbn(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid(""));
}

void test_input_is_9_characters(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("134456729"));
}

void test_invalid_characters_are_not_ignored_after_checking_length(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("3132P34035"));
}

void test_invalid_characters_are_not_ignored_before_checking_length(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("3598P215088"));
}

void test_input_is_too_long_but_contains_a_valid_isbn(void) {
    TEST_IGNORE();
    TEST_ASSERT_FALSE(is_valid("98245726788"));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_valid_isbn);
    RUN_TEST(test_invalid_isbn_check_digit);
    RUN_TEST(test_valid_isbn_with_a_check_digit_of_10);
    RUN_TEST(test_check_digit_is_a_character_other_than_x);
    RUN_TEST(test_invalid_check_digit_in_isbn_is_not_treated_as_zero);
    RUN_TEST(test_invalid_character_in_isbn_is_not_treated_as_zero);
    RUN_TEST(test_x_is_only_valid_as_a_check_digit);
    RUN_TEST(test_valid_isbn_without_separating_dashes);
    RUN_TEST(test_isbn_without_separating_dashes_and_x_as_check_digit);
    RUN_TEST(test_isbn_without_check_digit_and_dashes);
    RUN_TEST(test_too_long_isbn_and_no_dashes);
    RUN_TEST(test_too_short_isbn);
    RUN_TEST(test_isbn_without_check_digit);
    RUN_TEST(test_check_digit_of_x_should_not_be_used_for_0);
    RUN_TEST(test_empty_isbn);
    RUN_TEST(test_input_is_9_characters);
    RUN_TEST(test_invalid_characters_are_not_ignored_after_checking_length);
    RUN_TEST(test_invalid_characters_are_not_ignored_before_checking_length);
    RUN_TEST(test_input_is_too_long_but_contains_a_valid_isbn);
    return UNITY_END();
}
