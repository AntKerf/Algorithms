#pragma once
#include <iostream>
#include <ctime>

class Sorts
{
public:

	template <typename T>
	static void Buble(T& arr);

	template <typename T>
	static void Cocktail(T& arr);

	template <typename T>
	static void Insertion(T& arr);

	template <typename T>
	static void Merge(T& arr);

	template <typename T>
	static void Quick(T& arr);

private:

	template <typename T>
	static void swap(T& arr, size_t first, size_t second);
};

template<typename T>
inline void Sorts::Buble(T& arr)
{
	try
	{
		bool swaped;
		do
		{
			swaped = false;
			for (size_t i = 0; i < arr.size() - 1; i++)
			{

				if (arr[i] > arr[i + 1])
				{
					swap(arr, i, i + 1);
					swaped = true;
				}
			}
		} while (swaped);
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error buble sort: " << e.what() << std::endl;
	}
}

template<typename T>
inline void Sorts::Cocktail(T& arr)
{
	try
	{
		if (arr.size() < 2)
		{
			throw std::exception("Very small array size for sorting");
		}
		size_t left = 0, right = 0;
		right = arr.size() - 1;
		bool swaped;
		do
		{
			swaped = false;
			for (size_t i = left; i < right; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					swap(arr, i, i + 1);
					swaped = true;
				}
			}
			right-=1;
			for (size_t i = right; i > left; i--)
			{
				if (arr[i] < arr[i - 1])
				{
					swap(arr, i, i - 1);
					swaped = true;
				}
			}
			left++;
		} while (swaped);
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error cocktail sort: " << e.what() << std::endl;
	}
}

template<typename T>
inline void Sorts::Insertion(T& arr)
{
	try
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
							arr[t] = std::move(arr[t - 1]);
						}
						arr[j] = std::move(tmpValue);//вставка
						swaped = true;
					}
				}
			}
		} while (swaped);
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error insertion sort: " << e.what() << std::endl;
	}
}

template<typename T>
inline void Sorts::Merge(T& arr)
{
	try
	{
		if (arr.size() > 2)
		{
			size_t leftSize = arr.size() / 2;
			size_t rightSize = arr.size() - leftSize;
			T left(leftSize);
			T right(rightSize);
			for (size_t i = 0; i < leftSize; i++)
			{
				left[i] = arr[i];
			}
			for (size_t i = 0; i < rightSize; i++)
			{
				right[i] = arr[i + leftSize];
			}
			Merge(left);
			Merge(right);

			size_t countItems = left.size() + right.size();
			size_t leftIndex = 0, rightIndex = 0;
			size_t curentItems = 0;
			while (countItems > 0)
			{
				if (leftIndex < left.size())
				{
					if (rightIndex < right.size())
					{
						if (left[leftIndex] <= right[rightIndex])
						{
							arr[curentItems] = std::move(left[leftIndex]);
							curentItems++;
							countItems--;
							leftIndex++;
						}
						else {
							arr[curentItems] = std::move(right[rightIndex]);
							curentItems++;
							rightIndex++;
							countItems--;
						}
					}
					else {
						for (size_t i = leftIndex; i < left.size(); i++, curentItems++, leftIndex++, countItems--)
						{
							arr[curentItems] = std::move(left[i]);
						}
						break;
					}
				}
				else {
					for (size_t i = rightIndex; i < right.size(); i++, curentItems++, rightIndex++, countItems--)
					{
						arr[curentItems] = std::move(right[i]);
					}
					break;
				}
			}
		}
		else {
			Buble(arr);
			return;
		}
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error megre sort: " << e.what() << std::endl;
	}
}

template<typename T>
inline void Sorts::Quick(T& arr)
{
	try 
	{
		if (arr.size() > 1)
		{
			size_t targetIndex = rand() % (arr.size());
			auto targetValue = arr[targetIndex];
			for (size_t i = 0; i < arr.size(); i++)
			{
				if (arr[i] < targetValue && i > targetIndex)
				{
					auto tmp = arr[i];
					for (size_t j = i; j > targetIndex; j--)//сдвиг значений массива
					{
						arr[j] = arr[j - 1];
					}
					targetIndex++;
					arr[targetIndex - 1] = tmp;
				}
				else if (arr[i] > targetValue && i < targetIndex)
				{
					auto tmp = arr[i];
					for (size_t j = i; j < targetIndex; j++)
					{
						arr[j] = arr[j + 1];
					}
					targetIndex--;
					i--;
					arr[targetIndex + 1] = tmp;
				}
			}
			//разбивка массива на 2 части(< и >)
			T left(targetIndex);
			T right((arr.size() - targetIndex));
			for (size_t i = 0; i < arr.size(); i++)
			{
				if (i < targetIndex) {
					left[i] = std::move(arr[i]);
				}
				else {
					right[i - targetIndex] = std::move(arr[i]);
				}
			}
			//сортировка частей
			Quick(left);
			Quick(right);
			//сборка исходного массива(сперва левая часть потом правая)
			for (size_t i = 0; i < left.size(); i++)
			{
				arr[i] = std::move(left[i]);
			}
			for (size_t i = 0; i < right.size(); i++)
			{
				arr[i + left.size()] = std::move(right[i]);
			}
		}
		return;
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error quick sort: " << e.what() << std::endl;
	}
}


template<typename T>
inline void Sorts::swap(T& arr, size_t first, size_t second)
{
	try
	{
		auto tmp = std::move(arr[second]);
		arr[second] = std::move(arr[first]);
		arr[first] = std::move(tmp);
		
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error swap func: " << e.what() << std::endl;
	}
}
