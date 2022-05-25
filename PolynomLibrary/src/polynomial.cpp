#include "../include/polynomial.h"
#include "../include/utils.h"
#include <cmath>
#include <sstream>

#define EPS 1E-15

// Упорядочивание многочлена
void Polynomial::arrange()
{
	monomials->sort();
}

// Приведение подобных слагаемых
void Polynomial::combineLikeTerms()
{
	arrange(); // Упорядочивание
	Node<Monomial> *a = monomials->getHead(); // Получение головы
	if (a != nullptr) // Если она не пуста
		while (a->next != nullptr) // Пока не пуст следующий
		{
			Node<Monomial> *b = a->next;
			if (abs(a->data.getPow() - b->data.getPow()) < EPS) // Если степени соседей равны
			{
				// Коэффициент 1го - сумма коэффициентов
				a->data.setCoeff(a->data.getCoeff() + b->data.getCoeff());
				// Удаление 2го (с проверкой, не является ли концом)
				if (b == this->getMonomials()->getTail())
				{
					b = b->prev;
					b->next = nullptr;
				}
				else
				{
					b->prev->next = b->next;
					b->next->prev = b->prev;
				}
			}
			a = b;
		}

	a = monomials->getHead();
	// Удаление возникших нулей (если есть только ноль, то не удаляется)
	while (a != nullptr)
	{
		if (abs(a->data.getCoeff()) < EPS)
		{
			// Если голова
			if (a == this->getMonomials()->getHead())
			{
				if (a->next == nullptr)
					break;
				a = a->next;
				a->prev = nullptr;
			}
			// Если хвост
			else if (a == this->getMonomials()->getTail())
			{
				a = a->prev;
				a->next = nullptr;
			}
			// Иначе
			else
			{
				a->prev->next = a->next;
				a->next->prev = a->prev;
			}
		}
		a = a->next;
	}
}

// Конструктор по умолчанию
Polynomial::Polynomial()
{
	monomials = new List<Monomial>();
}

// Конструктор (параметр - список мономов)
Polynomial::Polynomial(const List<Monomial>& monomials)
{
	this->monomials = new List<Monomial>(monomials);
}

// Конструктор (параметр - строка)
Polynomial::Polynomial(std::string s)
{
	monomials = new List<Monomial>();
	auto v = splitAndRemoveNullCoeffs(s, ';');
	if (v.size() % 2 == 1)
	{
		throw std::exception();
	}
	else
		for (size_t i = 0; i < v.size(); i += 2)
		{
			double j = 0;
			double f = modf(v[i + 1], &j);
			if (j < 0 || j > 999)
				throw std::exception();
			this->addMonomial(Monomial(v[i], (int)j));
		}
	combineLikeTerms();
}

// Получение списка мономов
List<Monomial>* Polynomial::getMonomials() const
{
	return monomials;
}

// Добавление одночлена
void Polynomial::addMonomial(const Monomial& m)
{
	monomials->push_back(m);
}

// Перегрузка оператора +
Polynomial operator+(const Polynomial& p1, const Polynomial& p2)
{
	// Получение первых элементов многочленов
	Node<Monomial> *a = p1.getMonomials()->getHead(),
		*b = p2.getMonomials()->getHead();
	Polynomial c;

	// Пока оба не закончились
	while (a != nullptr && b != nullptr)
	{
		if (a->data > b->data) // Если степень 1го монома больше
		{
			c.addMonomial(a->data); // Запись 1го монома
			a = a->next; // Движение по 1му многочлену
		}
		else if (a->data < b->data) // Если степень 2го монома больше
		{
			c.addMonomial(b->data); // Запись 2го монома
			b = b->next; // Движение по 2му многочлену
		}
		else // Если равны
		{
			double cCoeff = a->data.getCoeff() + b->data.getCoeff();
			if (abs(cCoeff) > EPS) // Если новый коэффициент не ноль
				c.addMonomial(Monomial(cCoeff, a->data.getPow())); // Добавляем моном
			a = a->next; // Движение по обоим многочленам
			b = b->next;
		}
	}

	while (a != nullptr) // Добавление непрочитанных мономов из 1го многочлена
	{
		c.addMonomial(a->data);
		a = a->next;
	}

	while (b != nullptr) // Добавление непрочитанных мономов из 2го многочлена
	{
		c.addMonomial(b->data);
		b = b->next;
	}

	c.combineLikeTerms(); // Приведение подобных
	return c;
}

// Перегрузка оператора -
Polynomial operator-(const Polynomial& p1, const Polynomial& p2)
{
	Polynomial p3 = p2 * -1.0,
		p4 = p1 + p3;
	p4.combineLikeTerms(); // Приведение подобных
	return p4;
}

// Перегрузка оператора *
Polynomial operator*(const Polynomial& p1, const Polynomial& p2)
{
	Node<Monomial> *a = p1.getMonomials()->getHead();
	Polynomial c;

	while (a != nullptr) // Пока не прочитан 1й многочлен
	{
		Node<Monomial> *b = p2.getMonomials()->getHead(); 
		while (b != nullptr) // Пока не прочитан 1й многочлен
		{
			// Если переполнение, то исключение
			if (!isMultiplicative(a->data.getPow(), b->data.getPow()))
				throw std::overflow_error("Произошло переполнение!");
			// Перемножение коэффицентов и суммирование показателей
			c.addMonomial(Monomial(a->data.getCoeff() * b->data.getCoeff(),
				a->data.getPow() + b->data.getPow()));
			b = b->next;
		}
		a = a->next;
	}

	c.combineLikeTerms();
	return c;
}

// Перегрузка оператора *
Polynomial operator*(const Polynomial& p, double c)
{
	Node<Monomial> *a = p.getMonomials()->getHead();
	Polynomial b;
	if (c != 0)
	{
		while (a != nullptr) // Пока не прочитан многочлен
		{
			b.addMonomial(Monomial(a->data.getCoeff() * c,
				a->data.getPow())); // Умножение коэффициента
			a = a->next;
		}
		b.combineLikeTerms(); // Приведение подобных
		return b;
	}
	else
		return Polynomial();
}

// Перегрузка оператора *
Polynomial operator*(double c, const Polynomial& p)
{
	return p * c;
}

// Перегрузка оператора потокового вывода
std::ostream& operator<<(std::ostream& os, const Polynomial& p)
{
	Node<Monomial>* i = p.getMonomials()->getHead();
	if (i != nullptr) // Пока текущий элемент не конец списка
		while (i->next != nullptr) // Пока следующий элемент не конец списка
		{
			os << i->data << " + "; // Записываем моном, разделяем +
			i = i->next;
		}
	else 
		os << 0; // Случай пустого многочлена
	if (i != nullptr) // Записываем моном хвоста
		os << i->data;
	return os;
}

// Текстовое представление многочлена
std::string Polynomial::to_string()
{
	// Запись в строковый поток
	std::string result;
	std::stringstream stream(result);
	stream << *this;
	// Получение строки из потока
	return stream.str();
}