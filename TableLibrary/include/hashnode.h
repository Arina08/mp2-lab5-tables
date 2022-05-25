#ifndef HASHNODE_H
#define HASHNODE_H

// Класс узла хэш-таблицы
template <typename K, typename V>
class HashNode
{
	K _key; // Ключ
	V _value; // Данные
	HashNode *_next; // Следующий узел

public:
	// Конструктор
	HashNode(const K &key, const V &value)
	{
		_key = key;
		_value = value;
		_next = NULL;
	}

	// Получение ключа
	K key() const 
	{
		return _key;
	}

	// Получение данных
	V value() const
	{
		return _value;
	}

	// Получение следующего узла
	HashNode* next() const
	{
		return _next;
	}

	// Изменение ключа
	void setKey(const K &key)
	{
		_key = key;
	}

	// Изменение данных
	void setValue(const V &value)
	{
		_value = value;
	}

	// Изменение следующего узла
	void setNext(HashNode *next)
	{
		_next = next;
	}

};

#endif /* HASHNODE_H */