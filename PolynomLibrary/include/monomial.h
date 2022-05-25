#ifndef MONOMIAL_H
#define MONOMIAL_H

#include <string>

// Класс "одночлен"
class Monomial
{
	double coeff; // Коэффициент
	int pow; // Показатели x, y, z

public:
	// Конструктор по умолчанию
	Monomial();
	// Конструктор с параметрами
	Monomial(double coeff, int pow);
	
	// Получение коэффициента
	double getCoeff() const;
	// Получение степени
	int getPow() const;
	// Изменение коэффициента
	void setCoeff(double coeff);
	// Изменение степени
	void setPow(int pow);

	// Перегрузка операторов сравнения <, >, =
	friend bool operator<(const Monomial& m1, const Monomial& m2);
	friend bool operator>(const Monomial& m1, const Monomial& m2);
	friend bool operator==(const Monomial& m1, const Monomial& m2);
	// Перегрузка оператора потокового вывода
	friend std::ostream& operator<<(std::ostream& os, const Monomial& m);
};

#endif /* MONOMIAL_H */