#include "../include/monomial.h"
#include <sstream>
#include <string>

// Конструктор по умолчанию
Monomial::Monomial()
{

}

// Конструктор с параметрами
Monomial::Monomial(double coeff, int pow)
{
	this->coeff = coeff;
	this->pow = pow;
}

// Получение коэффициента
double Monomial::getCoeff() const
{
	return this->coeff;
}

// Получение степени
int Monomial::getPow() const
{
	return this->pow;
}

// Изменение коэффициента
void Monomial::setCoeff(double coeff)
{
	this->coeff = coeff;
}

// Изменение степени
void Monomial::setPow(int pow)
{
	this->pow = pow;
}

// Перегрузка оператора <
bool operator<(const Monomial& m1, const Monomial& m2)
{
	return m1.pow < m2.pow;
}

// Перегрузка оператора >
bool operator>(const Monomial& m1, const Monomial& m2)
{
	return m1.pow > m2.pow;
}

// Перегрузка оператора ==
bool operator==(const Monomial& m1, const Monomial& m2)
{
	return m1.pow == m2.pow;
}

// Перегрузка оператора потокового вывода
std::ostream& operator<<(std::ostream& os, const Monomial& m)
{
	// Вывод коэффициента (если все степени нулевые, выводится только коэффициент)
	os << m.getCoeff();

	if (m.getPow() != 0)
	{
		os << " * ";

		// Получение степеней x, y, z
		int pow = m.getPow();
		int x = pow / 100;
		int y = (pow / 10) % 10;
		int z = pow % 10;

		// Вывод степеней x, y, z (опциально ставятся знаки умножения)
		if (x == 1)
			os << "x";
		else if (x > 1)
			os << "x^" << x;

		if (x > 0 && (y > 0 || z > 0))
			os << "*";

		if (y == 1)
			os << "y";
		else if (y > 1)
			os << "y^" << y;

		if (y > 0 && z > 0)
			os << "*";

		if (z == 1)
			os << "z";
		else if (z > 1)
			os << "z^" << z;
	}

	return os;
}