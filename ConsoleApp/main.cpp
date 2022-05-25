#include "polynomial.h"
#include "hashtable.h"
#include "orderedtable.h"
#include "unorderedtable.h"
#include <iostream>
#include <string>

int main()
{
	setlocale(LC_CTYPE, "Russian");

	std::cout << "Пример:\n";
	std::cout << "для полинома 4 * x ^ 4 * y ^ 2 * z ввести нужно 4;421\n";
	std::cout << "для полинома x*y*z + y*z ^ 5 ввести нужно 1;111;1;15\n";
	std::cout << "То есть для каждого монома первое число - коэффициент при одночлене, \nзатем точка с запятой, после число от 0 до 999 - показатели\n";
	std::cout << "105 = x ^ 1 y ^ 0 z ^ 5\n";
	std::cout << "256 = x ^ 2 y ^ 5 z ^ 6\n";
	std::cout << "8 = z ^ 8\n";
	std::cout << "60 = y ^ 6\n";
	std::cout << "200 = x ^ 2\n";
	std::cout << "Вводить полином нужно без пробелов\nВ случае, если полином введен неправильно-он приравнивается к 0 или выводится сообщение об ошибке\n";

	HashTable<std::string, Polynomial, KeyHash> *ht 
		= new HashTable<std::string, Polynomial, KeyHash>();
	OrderedTable *ot = new OrderedTable();
	UnorderedTable *ut = new UnorderedTable();

	while (true)
	{
		try
		{
			std::cout << "Введите многочлен p, get для извлечения или exit для выхода: ";
			std::string s1;
			std::cin >> s1;

			Polynomial p;

			if (s1 == "exit")
				break;
			else if (s1 == "get")
			{
				std::string key;
				std::cout << "Введите ключ: ";
				std::cin >> key;
				if (!ht->get(key, p))
					continue;
				ot->get(key);
				ut->get(key);
			}
			else 
				p = Polynomial(s1);
			std::cout << "Многочлен p: " << p << std::endl;
			while (true)
			{
				bool b = true;
				try
				{
					std::string s;
					std::cout << "Введите номер операции: 0 - выход, 1 - сложение, 2 - вычитание, "
						<< "3 - умножение, 4 - умножение на константу, 5 - сохранение: ";

					std::cin >> s;

					int op = atoi(s.c_str());

					if (op < 0 || op > 4)
						throw std::exception();
					else if (op == 0)
						break;
					else
					{
						if (op < 4)
						{
							while (true)
							{
								try
								{
									std::cout << "Введите многочлен q или exit для выхода: ";
									std::string s2;
									std::cin >> s2;
									if (s2 == "exit")
										break;

									Polynomial q = Polynomial(s2), r;
									std::cout << "Многочлен q: " << q << std::endl;
									std::cout << "Результат операции ";
									if (op == 1)
									{
										std::cout << "p + q: ";
										r = p + q;
									}
									else if (op == 2)
									{
										std::cout << "p - q: ";
										r = p - q;
									}
									else
									{
										std::cout << "p * q: ";
										r = p * q;
									}
									std::cout << r << std::endl;
									b = false;

									int save;
									std::cout << "Сохранить в таблицу результат - 0 - нет, 1 - да: ";
									std::cin >> save;

									if (save == 1)
									{
										std::string key;
										std::cout << "Введите ключ: ";
										std::cin >> key;

										TableElement *te = new TableElement(key, r);

										if (!ht->existsKey(key))
											ht->add(te->key(), te->value());
										else
											std::cout << "Такой ключ в хеш-таблице уже существует!" << std::endl;

										if (!ot->existsKey(*te))
											ot->add(*te);
										else
											std::cout << "Такой ключ в упорядоченной таблице уже существует!" << std::endl;
										
										if (!ut->existsKey(key))
											ut->add(*te);
										else
											std::cout << "Такой ключ в неупорядоченной таблице уже существует!" << std::endl;
									}

									break;
								}
								catch (std::overflow_error& e)
								{
									std::cout << e.what() << std::endl;
								}
								catch (std::exception&)
								{
									std::cout << "Неверный формат ввода! Повторите ввод." << std::endl;
								}
							}
							if (!b)
								break;
						}
						else if (op == 4)
						{
							while (true)
							{
								try
								{
									std::string s;
									std::cout << "Введите константу с: ";
									std::cin >> s;

									double c = atof(s.c_str());

									Polynomial r = p * c;
									std::cout << "Результат операции p * c: " << r << std::endl;
									b = false;

								    int save;
									std::cout << "Сохранить в таблицу результат - 0 - нет, 1 - да: ";
									std::cin >> save;

									if (save == 1)
									{
										std::string key;
										std::cout << "Введите ключ: ";
										std::cin >> key;

										TableElement *te = new TableElement(key, r);
										ht->add(te->key(), te->value());
										ot->add(*te);
										ut->add(*te);
									}

									break;
								}
								catch (std::exception&)
								{
									std::cout << "Неверный формат ввода! Повторите ввод." << std::endl;
								}
							}
							if (!b)
								break;
						}
						else
						{
							std::string key;
							std::cout << "Введите ключ: ";
							std::cin >> key;

							TableElement *te = new TableElement(key, p);
							if (!ht->existsKey(key))
								ht->add(te->key(), te->value());
							else
								std::cout << "Такой ключ в хеш-таблице уже существует!" << std::endl;

							if (!ot->existsKey(*te))
								ot->add(*te);
							else
								std::cout << "Такой ключ в упорядоченной таблице уже существует!" << std::endl;

							if (!ut->existsKey(key))
								ut->add(*te);
							else
								std::cout << "Такой ключ в неупорядоченной таблице уже существует!" << std::endl;
						}
						break;
					}
				}
				catch (std::exception&)
				{
					std::cout << "Введите число от 0 до 3!" << std::endl;
					std::cin.clear();
				}
			}
		}
		catch (std::exception&)
		{
			std::cout << "Неверный формат ввода! Повторите ввод." << std::endl;
		}
	}
}