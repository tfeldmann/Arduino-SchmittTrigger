#include <SchmittTrigger.h>
#include <unity.h>

void test_integers()
{
    SchmittTrigger<int> s(8, 10);
    s.input(-20);
    TEST_ASSERT_EQUAL(s.output(), false);
    s.input(12);
    TEST_ASSERT_EQUAL(s.output(), true);
    s.input(9);
    TEST_ASSERT_EQUAL(s.output(), true);
    s.input(4);
    TEST_ASSERT_EQUAL(s.output(), false);
}

void test_floats()
{
    SchmittTrigger<float> s;
    s.set_thresholds(0.3, 0.6);
    s.input(0);
    TEST_ASSERT_EQUAL(s.output(), false);
    s.input(1.0);
    TEST_ASSERT_EQUAL(s.output(), true);
    s.input(0.5);
    TEST_ASSERT_EQUAL(s.output(), true);
    s.input(0.2);
    TEST_ASSERT_EQUAL(s.output(), false);
    s.input(0.5);
    TEST_ASSERT_EQUAL(s.output(), false);
}

void test_trigger_init_with_values()
{
    SchmittTrigger<int> s(-10, 10);
    s.input(-20);
    TEST_ASSERT_EQUAL(s.output(), false);
    s.input(20);
    TEST_ASSERT_EQUAL(s.output(), true);
    TEST_ASSERT_EQUAL(s.output(), true);
}

void test_trigger_init_without_values()
{
    SchmittTrigger<long> s;
    s.set_thresholds(10, 100);
    s.input(0);
    TEST_ASSERT_EQUAL(s.output(), false);
    s.input(11);
    TEST_ASSERT_EQUAL(s.output(), false);
    s.input(15);
    TEST_ASSERT_EQUAL(s.output(), false);
    s.input(101);
    TEST_ASSERT_EQUAL(s.output(), true);
    s.input(100);
    TEST_ASSERT_EQUAL(s.output(), true);
    s.input(15);
    TEST_ASSERT_EQUAL(s.output(), true);
    s.input(-10);
    TEST_ASSERT_EQUAL(s.output(), false);
    s.input(10);
    TEST_ASSERT_EQUAL(s.output(), false);
    s.input(50);
    TEST_ASSERT_EQUAL(s.output(), false);
}

void test_float()
{
    SchmittTrigger<float> s;
    s.set_thresholds(0.1, 0.2);
    TEST_ASSERT_EQUAL(s.output(), false);
    s.input(0.21);
    TEST_ASSERT_EQUAL(s.output(), true);
    s.input(0.14);
    TEST_ASSERT_EQUAL(s.output(), true);
    s.input(0.092);
    TEST_ASSERT_EQUAL(s.output(), false);
    s.input(0.099);
    TEST_ASSERT_EQUAL(s.output(), false);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_integers);
    RUN_TEST(test_floats);
    RUN_TEST(test_trigger_init_with_values);
    RUN_TEST(test_trigger_init_without_values);
    RUN_TEST(test_float);
    return UNITY_END();
}
