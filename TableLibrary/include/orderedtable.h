#ifndef ORDERED_TABLE_H
#define ORDERED_TABLE_H

#include "../include/tableelement.h"
#include "../include/tree.h"
#include <iostream>

// Класс "упорядоченная таблица"
class OrderedTable
{
	Tree *table; // Бинарное дерево поиска

public:
	// Конструктор таблицы
	OrderedTable() 
	{
		table = new Tree();
	}

	bool existsKey(const TableElement& te)
	{
		return table->existsKey(te);
	}

	// Добавление данных
	void add(const std::string& key, const Polynomial& p)
	{
		int count = table->add(TableElement(key, p));
		std::cout << "Упорядоченная таблица - операций добавления: "
			<< count << std::endl;
	}

	// Добавление данных
	void add(const TableElement& te)
	{
		add(te.key(), te.value());
	}

	// Поиск полинома
	Polynomial get(const std::string& key)
	{
		auto result = table->find(TableElement(key, Polynomial()));
		std::cout << "Упорядоченная таблица - операций поиска: "
			<< result.second << "." << std::endl;
		return result.first->data.value();
	}
};

#endif /* ORDERED_TABLE_H */