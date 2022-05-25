#ifndef TABLE_ELEMENT_H
#define TABLE_ELEMENT_H

#include <string>
#include "polynomial.h"

// Класс "элемент таблицы"
class TableElement
{
	std::string _key; // Ключ
	Polynomial _value; // Значение

public:
	// Конструктор по умолчанию
	TableElement(){}

	// Конструктор с параметрами
	TableElement(const std::string& key, const Polynomial& value)
	{
		_key = key;
		_value = value;
	}

	// Получение ключа
	std::string key() const
	{
		return _key;
	}

	// Получение данных
	Polynomial value() const
	{
		return _value;
	}

	// Перегрузка оператора<
	friend bool operator<(const TableElement& te1, const TableElement& te2)
	{
		return te1.key() < te2.key();
	}

	// Перегрузка оператора==
	friend bool operator==(const TableElement& te1, const TableElement& te2)
	{
		return te1.key() == te2.key();
	}

	// Перегрузка оператора>
	friend bool operator>(const TableElement& te1, const TableElement& te2)
	{
		return te1.key() > te2.key();
	}
};

#endif /* TABLE_ELEMENT_H */
