#include "ctest.h"

void true_integer_assertions() {
    int a = 0,
        b = 0,
        c = 1;
    ASSERT_EQUAL_INT(a, b);
    ASSERT_NOT_EQUAL_INT(a, c);
    ASSERT_TRUE(1+1);
    ASSERT_FALSE(1-1);
}

void false_integers_assertions() {
    int a = 0,
        b = 1,
        c = 0;
    ASSERT_EQUAL_INT(a, b);
    ASSERT_NOT_EQUAL_INT(a, c);
    ASSERT_TRUE((1-1));
    ASSERT_FALSE((1+1));
}

void true_float_assertions() {
    double a = 1.12,
        b = 1.12,
        c = 1.13;
    ASSERT_EQUAL_DOUBLE(a, b, 0);
    ASSERT_EQUAL_DOUBLE(a, c, 0.01);

    float d = 2.12,
        e = 2.12,
        f = 2.1201;
    ASSERT_EQUAL_FLOAT(d, e, 0);
    ASSERT_EQUAL_FLOAT(d, f, 0.001);
}

void false_float_assertions() {
    double a = 1.1,
        b = 1.12,
        c = 1.13;
    ASSERT_EQUAL_DOUBLE(a, b, 0);
    ASSERT_EQUAL_DOUBLE(a, c, 0.001);

    float d = 2.1,
        e = 2.12,
        f = 2.1201;
    ASSERT_EQUAL_FLOAT(d, e, 0);
    ASSERT_EQUAL_FLOAT(d, f, 0.00001);
}

void true_string_assertions() {
    char *a = "A comet appears!",
        *b = "A comet appears!",
        *c = "appears!";

    ASSERT_EQUAL_STRING(a, b);
    ASSERT_NOT_EQUAL_STRING(a, c);
    ASSERT_CONTAINS_STRING(a, c);
}

void false_string_assertions() {
    char *a = "A comet appears!",
        *b = "A comet appears!",
        *c = "appears!";

    ASSERT_EQUAL_STRING(a, c);
    ASSERT_NOT_EQUAL_STRING(a, b);
    ASSERT_CONTAINS_STRING(c, a);
}

void false_pointer_assertions() {
    int *a = NULL,
        *b = (int *) malloc(sizeof(int)),
        *c = (int *) malloc(sizeof(int));
    ASSERT_SAME(a, b);
    ASSERT_SAME(a, c);
    ASSERT_SAME(b, c);
}

void true_pointer_assertions() {
    int *a = NULL,
        *b = (int *) malloc(sizeof(int)),
        *c = b;
    ASSERT_SAME(a, 0);
    ASSERT_SAME(b, c);
    ASSERT_SAME(b, b);
}

void all_assertions_false() {
    TEST_CASE(false_integers_assertions);
    TEST_CASE(false_float_assertions);
    TEST_CASE(false_string_assertions);
    TEST_CASE(false_pointer_assertions);
}

void all_assertions_true() {
    TEST_CASE(true_integer_assertions);
    TEST_CASE(true_float_assertions);
    TEST_CASE(true_string_assertions);
    TEST_CASE(true_pointer_assertions);
}

int main() {
    int a = RUN_TEST_SUITE(all_assertions_false);
    int b = RUN_TEST_SUITE(all_assertions_true);
}
