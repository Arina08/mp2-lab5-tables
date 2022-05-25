#include <gtest.h>
#include "list.h"
#include "monomial.h"

TEST(LIST, can_get_head)
{
	List<int> *l1 = new List<int>();
	l1->push_back(200);
	EXPECT_EQ(l1->getHead()->data, 200);
	l1->push_back(100);
	EXPECT_EQ(l1->getHead()->data, 200);
	l1->push_back(400);
	EXPECT_EQ(l1->getHead()->data, 200);
	l1->push_back(800);
	EXPECT_EQ(l1->getHead()->data, 200);

	List<double> *l2 = new List<double>();
	l2->push_back(256.2);
	EXPECT_EQ(l2->getHead()->data, 256.2);
	l2->push_back(-234.59);
	EXPECT_EQ(l2->getHead()->data, 256.2);
	l2->push_back(10000.233);
	EXPECT_EQ(l2->getHead()->data, 256.2);
}

TEST(LIST, can_get_tail)
{
	List<int> *l1 = new List<int>();
	l1->push_back(200);
	EXPECT_EQ(l1->getTail()->data, 200);
	l1->push_back(100);
	EXPECT_EQ(l1->getTail()->data, 100);
	l1->push_back(400);
	EXPECT_EQ(l1->getTail()->data, 400);
	l1->push_back(800);
	EXPECT_EQ(l1->getTail()->data, 800);

	List<double> *l2 = new List<double>();
	l2->push_back(256.2);
	EXPECT_EQ(l2->getTail()->data, 256.2);
	l2->push_back(-234.59);
	EXPECT_EQ(l2->getTail()->data, -234.59);
	l2->push_back(10000.233);
	EXPECT_EQ(l2->getTail()->data, 10000.233);
}

TEST(LIST, check_sort_int)
{
	List<int> *l = new List<int>();
	
	l->push_back(200);
	l->push_back(100);
	l->push_back(400);
	l->push_back(800);
	l->sort();

	EXPECT_EQ(l->getHead()->data, 800);
	EXPECT_EQ(l->getHead()->next->data, 400);
	EXPECT_EQ(l->getTail()->prev->data, 200);
	EXPECT_EQ(l->getTail()->data, 100);
}

TEST(LIST, check_sort_monom)
{
	List<Monomial> *l = new List<Monomial>();

	l->push_back(Monomial(2, 200));
	l->push_back(Monomial(-12, 562));
	l->push_back(Monomial(21, 834));
	l->push_back(Monomial(102, 500));
	l->sort();

	EXPECT_EQ(l->getHead()->data, Monomial(21, 834));
	EXPECT_EQ(l->getHead()->next->data, Monomial(-12, 562));
	EXPECT_EQ(l->getTail()->prev->data, Monomial(102, 500));
	EXPECT_EQ(l->getTail()->data, Monomial(2, 200));
}