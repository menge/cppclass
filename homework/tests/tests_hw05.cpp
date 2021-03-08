#include <cmath>

#include "hw05.h"
#include "gtest/gtest.h"

int* populate_dst_canary(int *dst, size_t size)
{
    const int MAGIC_PAINT = 0xdeadbeef;
    dst[0] = MAGIC_PAINT;
    dst[size-1] = MAGIC_PAINT;
    return dst+1;
}

void validate_dst_canary(int *dst, size_t size)
{
    const int MAGIC_PAINT = 0xdeadbeef;
    EXPECT_EQ(dst[0], MAGIC_PAINT);
    EXPECT_EQ(dst[size-1], MAGIC_PAINT);
}

void validate_dst_from_expected(const int *dst, const int *src, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(dst[i], src[i]);
    }
}

TEST(HW05, FIND_FIRST_ZERO_BASIC) {
    // Basic operational tests
    {
        int src[] = {0, 1, 2, 3, 4, 5};
        const int *result = find_first_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src);
    }
    {
        int src[] = {5, 4, 3, 2, 1, 0};
        const int *result = find_first_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src + 5);
    }
    {
        int src[] = {5, 4, 3, 2, 1, 5};
        const int *result = find_first_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, nullptr);
    }
    {
        int src[] = {0};
        const int *result = find_first_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src);
    }
    {
        int src[] = {};
        const int *result = find_first_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, nullptr);
    }
}
TEST(HW05, FIND_FIRST_ZERO_MULTI_MATCH) {
    // Basic operational tests
    {
        int src[] = {0, 1, 2, 3, 4, 0};
        const int *result = find_first_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src);
    }
    {
        int src[] = {5, 0, 3, 2, 1, 0};
        const int *result = find_first_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src + 1);
    }
    {
        int src[] = {0, 0, 0, 0, 0, 0};
        const int *result = find_first_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src);
    }
}
TEST(HW05, FIND_FIRST_ZERO_WITH_PADDED_ARRAYS) {
    // tests where there are prepended/appended markers, and ensure that they are not considered
    {
        int src[] = {0, 0, 1, 2, 3, 4, 5, 0};
        const int *result = find_first_zero(src + 1, (sizeof(src) / sizeof(src[0])) - 2);
        EXPECT_EQ(result, src + 1);
    }
    {
        int src[] = {0, 5, 4, 3, 2, 1, 0, 0};
        const int *result = find_first_zero(src + 1, (sizeof(src) / sizeof(src[0])) - 2);
        EXPECT_EQ(result, src + 5 + 1);
    }
    {
        int src[] = {0, 5, 4, 3, 2, 1, 5, 0};
        const int *result = find_first_zero(src + 1, (sizeof(src) / sizeof(src[0])) - 2);
        EXPECT_EQ(result, nullptr);
    }
    {
        int src[] = {0, 0, 0};
        const int *result = find_first_zero(src + 1, (sizeof(src) / sizeof(src[0])) - 2);
        EXPECT_EQ(result, src + 1);
    }
    {
        int src[] = {0, 0};
        const int *result = find_first_zero(src + 1, (sizeof(src) / sizeof(src[0])) - 2);
        EXPECT_EQ(result, nullptr);
    }
}
TEST(HW05, FIND_FIRST_ZERO_WITH_INVALID_INPUT) {
    // invalid inputs
    {
        int *src = nullptr;
        const int *result = find_first_zero(src, 100);
        EXPECT_EQ(result, nullptr);
    }
}

TEST(HW05, FIND_LAST_ZERO_BASIC) {
    // Basic operational tests
    {
        int src[] = {0, 1, 2, 3, 4, 5};
        const int *result = find_last_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src);
    }
    {
        int src[] = {5, 4, 3, 2, 1, 0};
        const int *result = find_last_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src + 5);
    }
    {
        int src[] = {5, 4, 3, 2, 1, 5};
        const int *result = find_last_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, nullptr);
    }
    {
        int src[] = {0};
        const int *result = find_last_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src);
    }
    {
        int src[] = {};
        const int *result = find_last_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, nullptr);
    }
}
TEST(HW05, FIND_LAST_ZERO_MULTI_MATCH) {
    // Basic operational tests
    {
        int src[] = {0, 1, 2, 3, 4, 0};
        const int *result = find_last_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src+5);
    }
    {
        int src[] = {5, 0, 3, 2, 1, 0};
        const int *result = find_last_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src + 5);
    }
    {
        int src[] = {0, 0, 0, 0, 0, 0};
        const int *result = find_last_zero(src, sizeof(src) / sizeof(src[0]));
        EXPECT_EQ(result, src+5);
    }
}
TEST(HW05, FIND_LAST_ZERO_WITH_PADDED_ARRAYS) {
    // tests where there are prepended/appended markers, and ensure that they are not considered
    {
        int src[] = {0, 0, 1, 2, 3, 4, 5, 0};
        const int *result = find_last_zero(src + 1, (sizeof(src) / sizeof(src[0])) - 2);
        EXPECT_EQ(result, src + 1);
    }
    {
        int src[] = {0, 5, 4, 3, 2, 1, 0, 0};
        const int *result = find_last_zero(src + 1, (sizeof(src) / sizeof(src[0])) - 2);
        EXPECT_EQ(result, src + 5 + 1);
    }
    {
        int src[] = {0, 5, 4, 3, 2, 1, 5, 0};
        const int *result = find_last_zero(src + 1, (sizeof(src) / sizeof(src[0])) - 2);
        EXPECT_EQ(result, nullptr);
    }
    {
        int src[] = {0, 0, 0};
        const int *result = find_last_zero(src + 1, (sizeof(src) / sizeof(src[0])) - 2);
        EXPECT_EQ(result, src + 1);
    }
    {
        int src[] = {0, 0};
        const int *result = find_last_zero(src + 1, (sizeof(src) / sizeof(src[0])) - 2);
        EXPECT_EQ(result, nullptr);
    }
}
TEST(HW05, FIND_LAST_ZERO_WITH_INVALID_INPUT) {
    // invalid inputs
    {
        int *src = nullptr;
        const int *result = find_last_zero(src, 100);
        EXPECT_EQ(result, nullptr);
    }
}

TEST(HW05, FIND_NUM_KEYS_BASIC) {
    {
        int src[] = {0, 1, 2, 3, 4, 5, 6};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 0);
        EXPECT_EQ(retval, 1);
    }
    {
        int src[] = {0, 1, 2, 3, 4, 5, 6};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 1);
        EXPECT_EQ(retval, 1);
    }
    {
        int src[] = {0, 1, 2, 3, 4, 5, 6};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 2);
        EXPECT_EQ(retval, 1);
    }
    {
        int src[] = {0, 1, 2, 3, 4, 5, 6};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 3);
        EXPECT_EQ(retval, 1);
    }
    {
        int src[] = {0, 1, 2, 3, 4, 5, 6};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 4);
        EXPECT_EQ(retval, 1);
    }
    {
        int src[] = {0, 1, 2, 3, 4, 5, 6};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 5);
        EXPECT_EQ(retval, 1);
    }
    {
        int src[] = {0, 1, 2, 3, 4, 5, 6};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 6);
        EXPECT_EQ(retval, 1);
    }
    {
        int src[] = {0, 1, 2, 3, 4, 5, 6};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 7);
        EXPECT_EQ(retval, 0);
    }
    {
        int src[] = {0, 1, 2, 3, 4, 5, 6};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), -1);
        EXPECT_EQ(retval, 0);
    }
}
TEST(HW05, FIND_NUM_KEYS_REPEATS) {
    {
        int src[] = {0, 1, 2, 3, 3, 2, 3};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 0);
        EXPECT_EQ(retval, 1);
    }
    {
        int src[] = {0, 1, 2, 3, 3, 2, 3};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 1);
        EXPECT_EQ(retval, 1);
    }
    {
        int src[] = {0, 1, 2, 3, 3, 2, 3};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 2);
        EXPECT_EQ(retval, 2);
    }
    {
        int src[] = {0, 1, 2, 3, 3, 2, 3};
        auto retval = find_num_keys(src, (sizeof(src) / sizeof(src[0])), 3);
        EXPECT_EQ(retval, 3);
    }
}
TEST(HW05, FIND_NUM_KEYS_WITHIN_ARRAY_ONLY) {
    // valid range is omitting first and last element
    {
        int src[] = {0, 1, 2, 3, 3, 2, 3};
        auto retval = find_num_keys(src + 1, (sizeof(src) / sizeof(src[0])) - 2, 0);
        EXPECT_EQ(retval, 0);
    }
    {
        int src[] = {0, 1, 2, 3, 3, 2, 3};
        auto retval = find_num_keys(src + 1, (sizeof(src) / sizeof(src[0])) - 2, 1);
        EXPECT_EQ(retval, 1);
    }
    {
        int src[] = {0, 1, 2, 3, 3, 2, 3};
        auto retval = find_num_keys(src + 1, (sizeof(src) / sizeof(src[0])) - 2, 2);
        EXPECT_EQ(retval, 2);
    }
    {
        int src[] = {0, 1, 2, 3, 3, 2, 3};
        auto retval = find_num_keys(src + 1, (sizeof(src) / sizeof(src[0])) - 2, 3);
        EXPECT_EQ(retval, 2);
    }
}
TEST(HW05, FIND_NUM_KEYS_INVALID_ARRAY) {
    // invalid input
    {
        int *src = nullptr;
        auto retval = find_num_keys(src, 100, 0);
        EXPECT_EQ(retval, 0);
    }
}

TEST(HW05, MEAN_OF_ARRAY_BASIC) {
    {
        double src[] = {1.0, 2.0, 3.0};
        double retval;
        auto success = mean_of_array(src, (sizeof(src) / sizeof(src[0])), retval);
        EXPECT_EQ(success, true);
        EXPECT_EQ(retval, 2.0);
    }
    {
        double src[] = {1.0, 2.0, 3.0, 4.0, 5.0};
        double retval;
        auto success = mean_of_array(src, (sizeof(src) / sizeof(src[0])), retval);
        EXPECT_EQ(success, true);
        EXPECT_EQ(retval, 3.0);
    }
    {
        double src[] = {5.0, 4.0, 3.0, 2.0, 1.0};
        double retval;
        auto success = mean_of_array(src, (sizeof(src) / sizeof(src[0])), retval);
        EXPECT_EQ(success, true);
        EXPECT_EQ(retval, 3.0);
    }
    {
        double src[] = {10.0};
        double retval;
        auto success = mean_of_array(src, (sizeof(src) / sizeof(src[0])), retval);
        EXPECT_EQ(success, true);
        EXPECT_EQ(retval, 10.0);
    }
    {
        double src[] = {};
        double retval;
        auto success = mean_of_array(src, (sizeof(src) / sizeof(src[0])), retval);
        EXPECT_EQ(success, false);
    }
}
TEST(HW05, MEAN_OF_ARRAY_SUBSET) {
    {
        double src[] = {-100.0, 1.0, 2.0, 3.0, -100.0};
        double retval;
        auto success = mean_of_array(src+1, (sizeof(src) / sizeof(src[0])) - 2, retval);
        EXPECT_EQ(success, true);
        EXPECT_EQ(retval, 2.0);
    }
    {
        double src[] = {-100.0, -100.0};
        double retval;
        auto success = mean_of_array(src+1, (sizeof(src) / sizeof(src[0])) - 2, retval);
        EXPECT_EQ(success, false);
    }
}
TEST(HW05, MEAN_OF_ARRAY_INVALID_INPUT) {
    {
        double *src = nullptr;
        double retval;
        auto success = mean_of_array(src, 100, retval);
        EXPECT_EQ(success, false);
    }
}

TEST(HW05, COPY_ARRAY_BASIC) {
    {
        int src[] = {0, 1, 2, 3, 4, 5};
        int dst[sizeof(src) / sizeof(src[0]) + 2];
        int *fake_dst_start = populate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));

        auto retval = copy_array(fake_dst_start, src, sizeof(src) / sizeof(src[0]));
        validate_dst_from_expected(fake_dst_start, src, sizeof(src)/sizeof(src[0]));
        validate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));
        EXPECT_EQ(retval, sizeof(src)/sizeof(src[0]));
    }
    {
        int src[] = {100};
        int dst[sizeof(src) / sizeof(src[0]) + 2];
        int *fake_dst_start = populate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));

        auto retval = copy_array(fake_dst_start, src, sizeof(src) / sizeof(src[0]));
        validate_dst_from_expected(fake_dst_start, src, sizeof(src)/sizeof(src[0]));
        validate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));
        EXPECT_EQ(retval, sizeof(src)/sizeof(src[0]));
    }
    {
        int src[] = {};
        int dst[sizeof(src) / sizeof(src[0]) + 2];
        int *fake_dst_start = populate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));

        auto retval = copy_array(fake_dst_start, src, sizeof(src) / sizeof(src[0]));
        validate_dst_from_expected(fake_dst_start, src, sizeof(src)/sizeof(src[0]));
        validate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));
        EXPECT_EQ(retval, sizeof(src)/sizeof(src[0]));
    }
}
TEST(HW05, COPY_ARRAY_INVALID) {
    {
        int* src = nullptr;
        int dst[100];

        auto retval = copy_array(dst, src, 1000);
        EXPECT_EQ(retval, 0);
    }
    {
        int src[100];
        int* dst = nullptr;

        auto retval = copy_array(dst, src, 1000);
        EXPECT_EQ(retval, 0);
    }
    {
        int* src = nullptr;
        int* dst = nullptr;

        auto retval = copy_array(dst, src, 1000);
        EXPECT_EQ(retval, 0);
    }
}

TEST(HW05, REVERSE_ARRAY_BASIC) {
    {
        int src[] = {0, 1, 2, 3, 4, 5};
        int expected_output[] = {5, 4, 3, 2, 1, 0};
        int dst[sizeof(src) / sizeof(src[0]) + 2];
        int *fake_dst_start = populate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));

        reverse_array(fake_dst_start, src, sizeof(src) / sizeof(src[0]));
        validate_dst_from_expected(fake_dst_start, expected_output, sizeof(expected_output)/sizeof(expected_output[0]));
        validate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));
    }
    {
        int src[] = {10, 8, 6, 4, 2, 0};
        int expected_output[] = {0, 2, 4, 6, 8, 10};
        int dst[sizeof(src) / sizeof(src[0]) + 2];
        int *fake_dst_start = populate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));

        reverse_array(fake_dst_start, src, sizeof(src) / sizeof(src[0]));
        validate_dst_from_expected(fake_dst_start, expected_output, sizeof(expected_output)/sizeof(expected_output[0]));
        validate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));
    }
    {
        int src[] = {3};
        int expected_output[] = {3};
        int dst[sizeof(src) / sizeof(src[0]) + 2];
        int *fake_dst_start = populate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));

        reverse_array(fake_dst_start, src, sizeof(src) / sizeof(src[0]));
        validate_dst_from_expected(fake_dst_start, expected_output, sizeof(expected_output)/sizeof(expected_output[0]));
        validate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));
    }
    {
        int src[] = {};
        int expected_output[] = {};
        int dst[sizeof(src) / sizeof(src[0]) + 2];
        int *fake_dst_start = populate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));

        reverse_array(fake_dst_start, src, sizeof(src) / sizeof(src[0]));
        validate_dst_from_expected(fake_dst_start, expected_output, sizeof(expected_output)/sizeof(expected_output[0]));
        validate_dst_canary(dst, sizeof(dst)/sizeof(dst[0]));
    }
}
TEST(HW05, REVERSE_ARRAY_INVALID) {
    {
        int* src = nullptr;
        int dst[100];

        reverse_array(dst, src, 1000);
    }
    {
        int src[100];
        int* dst = nullptr;

        reverse_array(dst, src, 1000);
    }
    {
        int* src = nullptr;
        int* dst = nullptr;

        reverse_array(dst, src, 1000);
    }
}

TEST(HW05, REVERSE_IN_PLACE_BASIC) {
    {
        int src[] = {-100, 0, 1, 2, 3, 4, 5, -100};
        int expected_output[] = {5, 4, 3, 2, 1, 0};
        int *fake_src_start = populate_dst_canary(src, sizeof(src)/sizeof(src[0]));

        reverse_in_place(fake_src_start, sizeof(src) / sizeof(src[0]) - 2);
        validate_dst_from_expected(fake_src_start, expected_output, sizeof(expected_output)/sizeof(expected_output[0]));
        validate_dst_canary(src, sizeof(src)/sizeof(src[0]));
    }
    {
        int src[] = {-100, 100, 11, 12, 13, 14, 15, -100};
        int expected_output[] = {15, 14, 13, 12, 11, 100};
        int *fake_src_start = populate_dst_canary(src, sizeof(src)/sizeof(src[0]));

        reverse_in_place(fake_src_start, sizeof(src) / sizeof(src[0]) - 2);
        validate_dst_from_expected(fake_src_start, expected_output, sizeof(expected_output)/sizeof(expected_output[0]));
        validate_dst_canary(src, sizeof(src)/sizeof(src[0]));
    }
}
TEST(HW05, REVERSE_IN_PLACE_INVALID) {
    {
        int* src = nullptr;
        reverse_in_place(src, 100);
    }
}
