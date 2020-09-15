#pragma once
#include <iostream>

class Sorts
{
public:

	template <typename T>
	static void Buble(T& arr);

	template <typename T>
	static void Cocktail(T& arr);

	template <typename T>
	static void Insertion(T& arr);


};

template<typename T>
inline void Sorts::Buble(T& arr)
{
	bool swaped;
	do
	{
		swaped = false;
		for (size_t i = 0; i < arr.size() - 1; i++)
		{

			if (arr[i] > arr[i + 1])
			{
				arr[i] += arr[i + 1];
				arr[i + 1] = arr[i] - arr[i + 1];
				arr[i] -= arr[i + 1];
				swaped = true;
			}
		}
	} while (swaped);
}

template<typename T>
inline void Sorts::Cocktail(T& arr)
{
	size_t left = 0, right = arr.size()-1;
	bool swaped;
	do
	{
		swaped = false;
		for (size_t i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				arr[i] += arr[i + 1];
				arr[i + 1] = arr[i] - arr[i + 1];
				arr[i] -= arr[i + 1];
				swaped = true;
			}
		}
		right--;
		for (size_t i = right; i > left; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				arr[i] += arr[i - 1];
				arr[i - 1] = arr[i] - arr[i - 1];
				arr[i] -= arr[i - 1];
				swaped = true;
			}
		}
		left++;
	} while (swaped);
}

template<typename T>
inline void Sorts::Insertion(T& arr)
{
	bool swaped;
	do {
		swaped = false;
		for (size_t i = 1; i < arr.size(); i++)
		{
			if (arr[i - 1] > arr[i])
			{
				size_t j = i;
				while (arr[i] < arr[j - 1] && j>0) j--;//поиск места вставки
				if (j != i)
				{
					auto tmpValue = arr[i];
					for (size_t t = i; t >= j; t--)//сдвиг элементов
					{
						arr[t] = arr[t - 1];
					}
					arr[j] = tmpValue;//вставка
					swaped = true;
				}
			}
		}
	} while (swaped);
}
