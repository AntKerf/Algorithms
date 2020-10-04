// Ant_List.h - односвязный список
// Ниже представлен небольшой пример для работы с моим кастомным списком

#define _STD ::std::
#define END ::std::endl

#include <iostream>
#include "Ant_List.h"
#include "Ant_Hash.h"
int main()
{
	Ant_Hash<int, int> hl;
	hl.reserve(10);
	hl.add(0, 10);
	hl.add(5, 40);
	_STD cout << hl.size()<< END;

	Ant_List<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_back(3);
	//l = {2, 1, 3}

	if (l.emplace(l.find(1), 5) != NULL) _STD cout << "Success emplace" << END;//меняем 1 на 5
	else _STD cout << "Failure emplace" << END;

	_STD cout << "Items: "<< END;

	for (auto el : l) // вывод всем элементов списка через итераторы begin() и end()
	{
		_STD cout << "\t" << el << END;
	}

	_STD cout <<"Ant_List size: "<< l.size() << END;

	_STD cout << "Front: " << l.front() << END;
	_STD cout << "Back: " << l.back() << END;

	l.clear();
	_STD cout << "Ant_List size after clear: " << l.size() << END;

	//генерируем исключение вызвав .front() на пустой список (Abort() только при дебаге)
	_STD cout << "\nAttention!!! throw!!!" << END;
	_STD cout << l.front() << END;
}
