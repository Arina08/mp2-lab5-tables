#include <gtest.h>
#include "polynomial.h"

TEST(POLYNOMIAL, check_combine_like_terms)
{
	Polynomial p1("5;111;-8;111");
	EXPECT_EQ(p1.to_string(), "-3 * x*y*z");
	Polynomial p2("7.5;151;-6;110;8;110;-2.35;151");
	EXPECT_EQ(p2.to_string(), "5.15 * x*y^5*z + 2 * x*y");
	Polynomial p3("8;123;6;4;7;30");
	EXPECT_EQ(p3.to_string(), "8 * x*y^2*z^3 + 7 * y^3 + 6 * z^4");
	Polynomial p4("18;235;6;4;7;30;305;4");
	EXPECT_EQ(p4.to_string(), "18 * x^2*y^3*z^5 + 7 * y^3 + 311 * z^4");
}

TEST(POLYNOMIAL, check_operator_plus)
{
	Polynomial p1("1;111"), p2("4;111"),
		p3 = p1 + p2;
	EXPECT_EQ(p3.to_string(), "5 * x*y*z");

	p1 = Polynomial("7,25;300;6;783");
	p2 = Polynomial("-7,25;300;6;501");
	p3 = p1 + p2;
	EXPECT_EQ(p3.to_string(), "6 * x^7*y^8*z^3 + 6 * x^5*z");

	p1 = Polynomial("2;999");
	p2 = Polynomial("-2;999");
	p3 = p1 + p2;
	EXPECT_EQ(p3.to_string(), "0");

	p1 = Polynomial("2;999");
	p2 = Polynomial("-2;999;8;23");
	p3 = p1 + p2;
	EXPECT_EQ(p3.to_string(), "8 * y^2*z^3");
}

TEST(POLYNOMIAL, check_operator_minus)
{
	Polynomial p1("1;111"), p2("4;111"),
		p3 = p1 - p2;
	EXPECT_EQ(p3.to_string(), "-3 * x*y*z");

	p1 = Polynomial("7,25;300;6;783");
	p2 = Polynomial("7,25;300;6;501");
	p3 = p1 - p2;
	EXPECT_EQ(p3.to_string(), "6 * x^7*y^8*z^3 + -6 * x^5*z");

	p1 = Polynomial("2;999");
	p2 = Polynomial("-2;999");
	p3 = p1 - p2;
	EXPECT_EQ(p3.to_string(), "4 * x^9*y^9*z^9");

	p1 = Polynomial("2;999");
	p2 = Polynomial("2;999;8;23");
	p3 = p1 - p2;
	EXPECT_EQ(p3.to_string(), "-8 * y^2*z^3");
}

TEST(POLYNOMIAL, check_operator_mult_const)
{
	Polynomial p1("1;111"), p2 = p1 * 5;
	EXPECT_EQ(p2.to_string(), "5 * x*y*z");

	p1 = Polynomial("2;456");
	p2 = p1 * -3.45;
	EXPECT_EQ(p2.to_string(), "-6.9 * x^4*y^5*z^6");

	p1 = Polynomial("-45;50");
	p2 = p1 * -3;
	EXPECT_EQ(p2.to_string(), "135 * y^5");
}

TEST(POLYNOMIAL, check_operator_mult)
{
	Polynomial p1("1;111"), p2("4;111"),
		p3 = p1 * p2;
	EXPECT_EQ(p3.to_string(), "4 * x^2*y^2*z^2");

	p1 = Polynomial("7,25;300;6;783");
	p2 = Polynomial("7,25;300;6;501");
	ASSERT_ANY_THROW(p1 * p2);

	p1 = Polynomial("2;140;1;111");
	p2 = Polynomial("2;30;-1;1");
	p3 = p1 * p2;
	EXPECT_EQ(p3.to_string(), "4 * x*y^7 + -1 * x*y*z^2");

	p1 = Polynomial("1;200;1;20;1;2");
	p2 = Polynomial("1;200;1;20;1;2");
	p3 = p1 * p2;
	EXPECT_EQ(p3.to_string(), "1 * x^4 + 2 * x^2*y^2 + 2 * x^2*z^2 + 1 * y^4 + 2 * y^2*z^2 + 1 * z^4");
}