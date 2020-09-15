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

	template <typename T>
	static void Merge(T& arr);

private:

	template <typename T>
	static void swap(T& arr, size_t first, size_t second);
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
				swap(arr, i, i + 1);
				swaped = true;
			}
		}
	} while (swaped);
}

template<typename T>
inline void Sorts::Cocktail(T& arr)
{
	size_t left = 0, right = arr.size() - 1;
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
		right--;
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

template<typename T>
inline void Sorts::Merge(T& arr)
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
						arr[curentItems] = left[leftIndex];
						curentItems++;
						countItems--;
						leftIndex++;
					}
					else {
						arr[curentItems] = right[rightIndex];
						curentItems++;
						rightIndex++;
						countItems--;
					}
				}
				else {
					for (size_t i = leftIndex; i < left.size(); i++, curentItems++, leftIndex++, countItems--)
					{
						arr[curentItems] = left[i];
					}
					break;
				}
			}
			else {
				for (size_t i = rightIndex; i < right.size(); i++, curentItems++, rightIndex++, countItems--)
				{
					arr[curentItems] = right[i];
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

template<typename T>
inline void Sorts::swap(T& arr, size_t first, size_t second)
{
	arr[first] += arr[second];
	arr[second] = arr[first] - arr[second];
	arr[first] -= arr[second];
}
