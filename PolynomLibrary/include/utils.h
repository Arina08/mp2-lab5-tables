#ifndef UTILS_H
#define UTILS_H

/*
	Вспомогательные функции
*/

#include <string>
#include <vector>

// Проверка, могут ли быть числа a и b умножены без переполнения
bool isMultiplicative(int a, int b);

// Извлечение из строки s ненулевых значений коэффициентов (разделитель - символ delim)
std::vector<double> splitAndRemoveNullCoeffs(const std::string &s, char delim);

#endif /* UTILS_H */