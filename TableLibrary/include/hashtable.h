#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashnode.h"
#include <sstream>

// Константа размера хэш-таблицы
const size_t SIZE = 100;

// Хэш-функция
struct KeyHash
{
	unsigned long operator()(const std::string& key) const
	{
		int sum = 0;
		for (char c : key)
			sum += (int)c;
		return sum % SIZE;
	}
};

// Класс хэш-таблицы
template <typename K, typename V, typename F>
class HashTable
{
	HashNode<K, V> **table; // Таблица
	F function; // Хэш-функция

public:
	// Конструктор хэш-таблицы
	HashTable()
	{
		table = new HashNode<K, V>*[SIZE]();
	}

	bool existsKey(const K &key)
	{
		if (table[function(key)])
			return true;
		else
			return false;
	}

	// Поиск по ключу key и запись в value
	bool get(const K &key, V &value)
	{
		// Вычисление хэш-значения
		unsigned long hashValue = function(key);
		HashNode<K, V> *entry = table[hashValue];

		int count = 0;
		while (entry)
		{
			count++;
			if (entry->key() == key) // Если найдена запись
			{
				value = entry->value();
				std::cout << "Хэш-таблица - операций поиска: " << count << std::endl;
				return true;
			}
			entry = entry->next();
		}

		std::cout << "Полином с таким ключом не найден\n";
		return false;
	}

	void add(const K &key, const V &value)
	{
		// Вычисление хэш-значения
		unsigned long hashValue = function(key);
		HashNode<K, V> *prev = NULL;
		HashNode<K, V> *entry = table[hashValue];

		// Вычисление количества операций
		int count = 1;
		while (entry && entry->key() != key)
		{
			prev = entry;
			entry = entry->next();
			count++;
		}

		// Изменение таблицы (перезапись или создание узла)
		if (!entry)
		{
			entry = new HashNode<K, V>(key, value);
			if (prev == NULL)
				table[hashValue] = entry;
			else
				prev->setNext(entry);
		}
		else
			entry->setValue(value);

		std::cout << "Хэш-таблица - операций добавления: "
			<< count << std::endl;
	}
};

#endif /* HASHTABLE_H */