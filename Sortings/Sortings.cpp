// Sortings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Sorts.h"
#include <vector>

int main()
{
	//Пузырьковая сортировка
	std::vector<int> vec = { 0,5,1,56,2,123,3 };
	Sorts::buble(vec);
	for (auto el : vec) std::cout << el << " ";

	system("PAUSE");
}