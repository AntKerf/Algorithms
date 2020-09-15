// Sortings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Sorts.h"
#include <vector>

int main()
{
	std::vector<int> vec = { 0,5,1,56,2,123,3 };

	//Пузырьковая сортировка
//	Sorts::Buble(vec);

	//Шейкерная сортировка
//	Sorts::Cocktail(vec);

	//Сортировка вставками
	Sorts::Insertion(vec);

	for (auto el : vec) std::cout << el << " ";

	system("PAUSE");
}