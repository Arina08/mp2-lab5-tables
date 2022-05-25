#ifndef UNORDERED_TABLE_H
#define UNORDERED_TABLE_H

#include <iostream>
#include <vector>
#include "../include/tableelement.h"

// Класс "неупорядоченная таблица"
class UnorderedTable
{
	std::vector<TableElement*> table; // Массив
public:
	// Конструктор таблицы
	UnorderedTable()
	{
		table = std::vector<TableElement*>();
	}

	bool existsKey(const std::string& key)
	{
		for (auto te : table)
			if (te->key() == key)
				return true;
		return false;
	}

	// Добавление данных
	void add(const std::string& key, const Polynomial& p)
	{
		table.push_back(new TableElement(key, p));
		std::cout << "Неупорядоченная таблица - операций добавления: 1." << std::endl;
	}

	// Добавление данных
	void add(const TableElement& te)
	{
		add(te.key(), te.value());
	}

	// Получение данных
	Polynomial get(const std::string& key)
	{
		for (size_t i = 0; i < table.size(); i++)
		{
			if (table.at(i)->key() == key)
			{
				std::cout << "Неупорядоченная таблица - операций поиска: "
					<< i + 1 << "." << std::endl;
				return table.at(i)->value();
			}
		}
		return NULL;
	}
};

#endif /* UNORDERED_TABLE_H */