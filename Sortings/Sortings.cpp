// Sortings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Sorts.h"
#include <vector>
#include <ctime>

int main()
{
	srand(time(0));
	std::vector<int> vec = { 9,8,7,6,5,4,3,2,1 };

	//Пузырьковая сортировка
	Sorts::Buble(vec);

	//Шейкерная сортировка
	Sorts::Cocktail(vec);

	//Сортировка вставками
	Sorts::Insertion(vec);

	//Сортировка слиянием
	Sorts::Merge(vec);

	//Быстрая сортировка
	Sorts::Quick(vec);

	for (auto el : vec) std::cout << el << " ";

	system("PAUSE");
}