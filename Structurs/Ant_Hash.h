#pragma once
#define _STD ::std::
#define END ::std::endl

#include <iostream>
#include "Ant_List.h"

template <typename K, typename V>
class Ant_Hash
{
private:
	size_t count;
	size_t capacity_t;
	size_t hash_func(_STD string key);
	size_t hash_func(int key);
	std::unique_ptr<Ant_List<V>[]> table;

public:
	Ant_Hash();

	void reserve(int);
	void add(K, V);
	size_t size();
	size_t capacity();

	Ant_List<V>& operator[](K key) {
		return table[hash_func(key)];
	};
};

template<typename K, typename V>
inline Ant_Hash<K, V>::Ant_Hash()
	:count(0),
	capacity_t(1)

{
	table.reset(new Ant_List<V>[capacity_t]);
}

template<typename K, typename V>
inline size_t Ant_Hash<K, V>::hash_func(_STD string key)
{
	return key[0] % capacity_t;
}

template<typename K, typename V>
inline size_t Ant_Hash<K, V>::hash_func(int key)
{
	return key % capacity_t;
}

template<typename K, typename V>
inline void Ant_Hash<K, V>::reserve(int countItems)
{
	capacity_t = countItems;
	table.reset(new Ant_List<V>[capacity_t]);
}

template<typename K, typename V>
inline void Ant_Hash<K, V>::add(K key, V value)
{
	table[hash_func(key)].push_front(value);
	++count;
}

template<typename K, typename V>
inline size_t Ant_Hash<K, V>::size()
{
	size_t t_count =0;
	for (Ant_List<V> *q = table.get(); q != table.get() + capacity_t; q++)
	{
		t_count+=q->size();
	}
	return t_count;
}

template<typename K, typename V>
inline size_t Ant_Hash<K, V>::capacity()
{
	return this->capacity_t;
}



