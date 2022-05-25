#ifndef LIST_H
#define LIST_H

/*
	Класс "двусвязный список"
*/

#include "node.h"

template<typename T>
class List
{
	Node<T> *head, *tail; // Начальный и конечный элементы

public:
	// Конструктор класса
	List()
	{
		head = tail = nullptr;
	}

	// Получение начального элемента
	Node<T>* getHead()
	{
		return head;
	}

	// Получение конечного элемента
	Node<T>* getTail()
	{
		return tail;
	}

	// Добавление элемента item в список
	void push_back(const T& item)
	{
		Node<T> *tmp = new Node<T>;
		tmp->next = nullptr;
		tmp->data = item;

		if (head != nullptr)
		{
			tmp->prev = tail;
			tail->next = tmp;
			tail = tmp;
		}
		else
		{
			tmp->prev = nullptr;
			head = tail = tmp;
		}
	}

	void clear()
	{
		head = tail = nullptr;
	}

	// Сортировка списка
	void sort()
	{
		Node<T> *i = head;
		if (i != nullptr)
			while (i->next != nullptr)
			{
				Node<T> *j = i->next;
				while (j != nullptr)
				{
					if (i->data < j->data)
					{
						T tmp = i->data;
						i->data = j->data;
						j->data = tmp;
					}
					j = j->next;
				}
				i = i->next;
			}
	}
};

#endif /* LIST_H */