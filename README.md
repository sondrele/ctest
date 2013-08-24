ctest
=====

Small unit test framework for C, inspired by this post of Eric Radman: http://eradman.com/posts/tdd-in-c.html

Featuring colorful and descriptive error messages! :)

Usage
-----
ctest uses macros in order to define **test suites**, **test cases** and **assertions**.

Define a test case:

    void my_testcase() {
        int a = 1,
            b = 1;
        ASSERT_EQUAL_INT(a, b);
    }

The testcase belongs to a test suite, the test case macro's 
argument is a function reference to a function containing assetions:

    void my_testsuite() {
      TEST_CASE(my_testcase);
      TEST_CASE(my_other_testcase);
    }

Run the testsuite by passing a function reference to the test suite runner macro:

    RUN_TEST_SUITE(my_testsuite);

Assert macros
-------------
A list of the currently available assertions
* ASSERT_TRUE(test)
* ASSERT_FALSE(test)
* ASSERT_EQUAL_INT(actual, expected)
* ASSERT_NOT_EQUAL_INT(actual, expected)
* ASSERT_EQUAL_DOUBLE(actual, expected, delta)
* ASSERT_EQUAL_FLOAT(actual, expected, delta)
* ASSERT_EQUAL_STRING(actual, expected)
* ASSERT_NOT_EQUAL_STRING(actual, expected)
* ASSERT_CONTAINS_STRING(string, find)

