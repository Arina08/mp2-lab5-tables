#include <gtest.h>
#include "utils.h"

TEST(UTILS, check_incorrect_values_multiplicative)
{
	ASSERT_ANY_THROW(isMultiplicative(1000, 1000));
	ASSERT_ANY_THROW(isMultiplicative(8220, 99));
	ASSERT_ANY_THROW(isMultiplicative(-45, 900));
	ASSERT_ANY_THROW(isMultiplicative(33, 1212));
	ASSERT_ANY_THROW(isMultiplicative(-1, -1));
	ASSERT_ANY_THROW(isMultiplicative(34, -234));
}

TEST(UTILS, can_get_multiplicative)
{
	EXPECT_EQ(isMultiplicative(256, 123), true);
	EXPECT_EQ(isMultiplicative(256, 124), false);
	EXPECT_EQ(isMultiplicative(751, 243), true);
	EXPECT_EQ(isMultiplicative(751, 263), false);
	EXPECT_EQ(isMultiplicative(628, 241), true);
	EXPECT_EQ(isMultiplicative(628, 941), false);
	EXPECT_EQ(isMultiplicative(123, 256), true);
	EXPECT_EQ(isMultiplicative(124, 256), false);
	EXPECT_EQ(isMultiplicative(243, 751), true);
	EXPECT_EQ(isMultiplicative(263, 751), false);
	EXPECT_EQ(isMultiplicative(241, 628), true);
	EXPECT_EQ(isMultiplicative(941, 628), false);
}

TEST(UTILS, check_split_and_remove_null_coeffs)
{
	EXPECT_EQ(splitAndRemoveNullCoeffs("w", ' ')[0], 0);
	
	auto v1 = splitAndRemoveNullCoeffs("12;;13;14;;", ';');
	EXPECT_EQ(v1.size(), 4);
	EXPECT_EQ(v1[0], 12);
	EXPECT_EQ(v1[1], 0);
	EXPECT_EQ(v1[2], 13);
	EXPECT_EQ(v1[3], 14);

	auto v2 = splitAndRemoveNullCoeffs("34.5;23;67;-12.5", ';');
	EXPECT_EQ(v2[0], 34.5);
	EXPECT_EQ(v2[1], 23);
	EXPECT_EQ(v2[2], 67);
	EXPECT_EQ(v2[3], -12.5);
}