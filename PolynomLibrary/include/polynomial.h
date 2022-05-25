#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "list.h"
#include "monomial.h"
#include <string>

// Класс "многочлен"
class Polynomial
{
	// Список одночленов
	List<Monomial>* monomials;

	// Упорядочивание многочлена
	void arrange();
	// Приведение подобных слагаемых
	void combineLikeTerms();

public:
	// Конструктор по умолчанию
	Polynomial();
	// Конструктор (параметр - список мономов)
	Polynomial(const List<Monomial>& monomials);
	// Конструктор (параметр - строка)
	Polynomial(std::string s);
	
	// Получение списка мономов
	List<Monomial>* getMonomials() const;
	// Добавление одночлена
	void addMonomial(const Monomial& m);
	
	// Перегрузка арифметических операторов
	friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator-(const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator*(const Polynomial& p, double c);
	friend Polynomial operator*(double c, const Polynomial& p);
	// Перегрузка оператора потокового вывода
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

	// Текстовое представление многочлена
	std::string to_string();
};

#endif /* POLYNOMIAL_H */