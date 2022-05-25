/*
	Вспомогательные функции
*/


#include "../include/utils.h"
#include <sstream>

// Проверка, могут ли быть числа a и b умножены без переполнения
bool isMultiplicative(int a, int b)
{
	if (a < 0 || a > 999) // Проверка значения числа a
		throw std::exception("Значение переменной a должно быть от 0 до 999");

	if (b < 0 || b > 999) // Проверка значения числа b
		throw std::exception("Значение переменной b должно быть от 0 до 999");

	if (a > 9 && a < 99) // Приведение к одинаковому количеству разрядов
		b = b % 100;
	else if (a < 9)
		b = b % 10;

	while (a > 0) // Пока проверены не все разряды
	{
		if (a % 10 + b % 10 > 9) // Если переполнение, выход из функции
			return false; 
		a = a / 10; // Переход к следующему разряду числа a
		b = b / 10; // Переход к следующему разряду числа b
	}

	return true;
}

// Извлечение из строки s ненулевых значений (разделитель - символ delim)
std::vector<double> splitAndRemoveNullCoeffs(const std::string &s, char delim) 
{
	std::stringstream ss(s); // Поток строк
	std::string item; // Значение считываемого элемента
	std::vector<double> elems; // Результирующий вектор
	
	int i = 1;
	while (std::getline(ss, item, delim)) // Пока строка не кончилась
	{
		double a = atof(item.c_str()); // Конвертация строки в вещественное число
		if (a || i % 2 == 0) // Если не 0 (то есть либо не число, либо ноль - но нулевые мономы не нужны)
		{
			elems.push_back(a); // Добавление в вектор
			i++;
		}
		else
		{
			if (!std::getline(ss, item, delim))
				break;
		}
	}
	
	// Если вектор содержит не более одного значения, то запись нулевых значений
	if (elems.size() < 2)
	{
		elems.clear();
		elems.push_back(0);
		elems.push_back(0);
	}

	return elems;
}