#include <gtest.h>
#include "../include/hashtable.h"

TEST(KEYHASH, check_function)
{
	KeyHash k;
	auto key = k("123");
	ASSERT_EQ(key, 50);
	key = k(";d");
	ASSERT_EQ(key, 59);
	key = k("abcde");
	ASSERT_EQ(key, 95);
}