#pragma once

class Sorts
{
public:

	template <typename T>
	static void buble(T& arr)
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


};



