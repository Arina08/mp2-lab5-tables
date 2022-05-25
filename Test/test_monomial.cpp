#include <gtest.h>
#include "monomial.h"

TEST(MONOMIAL, can_get_coeff)
{
	Monomial m = Monomial(1, 2);
	EXPECT_EQ(m.getCoeff(), 1);
	m = Monomial(-2.34, 142);
	EXPECT_EQ(m.getCoeff(), -2.34);
	m = Monomial(4.52, 420);
	EXPECT_EQ(m.getCoeff(), 4.52);
}

TEST(MONOMIAL, can_get_pow)
{
	Monomial m = Monomial(1, 2);
	EXPECT_EQ(m.getPow(), 2);
	m = Monomial(-2.34, 142);
	EXPECT_EQ(m.getPow(), 142);
	m = Monomial(4.52, 420);
	EXPECT_EQ(m.getPow(), 420);
}

TEST(MONOMIAL, check_operator_gt)
{
	Monomial m1 = Monomial(1, 102),
		m2 = Monomial(-1, 202);
	EXPECT_EQ(m1 < m2, true);

	m1 = Monomial(14, 567);
	m2 = Monomial(23, 234);
	EXPECT_EQ(m1 < m2, false);

	m1 = Monomial(14, 450);
	m2 = Monomial(23, 450);
	EXPECT_EQ(m1 < m2, false);
}

TEST(MONOMIAL, check_operator_lt)
{
	Monomial m1 = Monomial(1, 102),
		m2 = Monomial(-1, 202);
	EXPECT_EQ(m1 > m2, false);

	m1 = Monomial(14, 567);
	m2 = Monomial(23, 234);
	EXPECT_EQ(m1 > m2, true);

	m1 = Monomial(14, 450);
	m2 = Monomial(23, 450);
	EXPECT_EQ(m1 > m2, false);
}

TEST(MONOMIAL, check_operator_eq)
{
	Monomial m1 = Monomial(1, 102),
		m2 = Monomial(-1, 202);
	EXPECT_EQ(m1 == m2, false);

	m1 = Monomial(14, 567);
	m2 = Monomial(23, 234);
	EXPECT_EQ(m1 == m2, false);

	m1 = Monomial(14, 450);
	m2 = Monomial(23, 450);
	EXPECT_EQ(m1 == m2, true);
}