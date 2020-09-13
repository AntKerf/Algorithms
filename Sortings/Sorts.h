#pragma once

class Sorts
{
public:

	template <typename T>
	static void Buble(T& arr);

	template <typename T>
	static void Insertion(T& arr);

};

template<typename T>
inline void Sorts::Buble(T& arr)
{
	size_t cswap = 1;
	while (cswap > 0)
	{
		cswap = 0;
		for (size_t i = 0; i < arr.size() - 1; i++)
		{

			if (arr[i] > arr[i + 1])
			{
				arr[i] += arr[i + 1];
				arr[i + 1] = arr[i] - arr[i + 1];
				arr[i] -= arr[i + 1];
				cswap++;
			}
		}
	}
}

template<typename T>
inline void Sorts::Insertion(T& arr)
{
	for (size_t i = 1; i < arr.size(); i++)
	{
		if (arr[i - 1] > arr[i])
		{
			size_t j = i;
			while (arr[i] < arr[j - 1] && j>0) j--;
			if (j != i)
			{
				auto tmpValue = arr[i];
				for (size_t t = i; t >= j; t--)
				{
					arr[t] = arr[t - 1];
				}
				arr[j] = tmpValue;
			}
		}
	}
}
