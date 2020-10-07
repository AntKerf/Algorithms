#pragma once
#define _STD ::std::
#define END ::std::endl

#include <iostream>
#include "Ant_List.h"

template <typename K, typename V>
class Ant_Hash
{
private:
	//_STD unique_ptr<K[]> keys; //unique_ptr don`t work in natvis???
	K* keys;

	size_t count;
	size_t count_bucket;
	size_t capacity_t;
	size_t hash_func(_STD string key);
	size_t hash_func(int key);

	//_STD unique_ptr<Ant_List<V>[]> table;
	Ant_List<V>* table;
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
	capacity_t(1),
	count_bucket(0)
{
	//table = _STD make_unique<Ant_List<V>[]>(capacity_t);
	table = new Ant_List<V>[capacity_t]();

	//keys = _STD make_unique<K[]>(capacity_t);
	keys = new K[capacity_t]();
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
	//table = _STD make_unique<Ant_List<V>[]>(capacity_t);
	table = new Ant_List<V>[capacity_t]();

	//keys = _STD make_unique<K[]>(capacity_t);
	keys = new K[capacity_t]();
}

template<typename K, typename V>
inline void Ant_Hash<K, V>::add(K key, V value)
{
	size_t hash = hash_func(key);
	if (table[hash].size() == 0) {
		++count_bucket;
		keys[hash] = key;
	}
	table[hash].push_front(value);
	++count;
}

template<typename K, typename V>
inline size_t Ant_Hash<K, V>::size()
{
	return count;
}

template<typename K, typename V>
inline size_t Ant_Hash<K, V>::capacity()
{
	return this->capacity_t;
}



