#pragma once
#define _STD ::std::

#include <iostream>

template <typename V>
class Ant_List
{
private:
	struct Node {
	private:
		V Data;
		Node* Next;

	public:
		void setNext(Node* newItem);
		void setData(V newData);

		auto getNext();
		V getData();
	};
	Node* first;
	Node* last;
	size_t count;
public:
	
	class Iterator
	{
	private:
		Node* head;
	public:
		Iterator(Node* head) {
			this->head = head;
		}
		Iterator getNext() {
			Iterator it = *this;
			it = head->getNext();
			return it;
		}
		Node* _head()
		{
			return head;
		}
		Iterator operator++() {
			Iterator itr = *this; head = head->getNext();
			return itr;
		}
		Iterator operator++(int) {
			Iterator itr = *this; head = head->getNext();
			return itr;
		}
		V operator*() {
			return head->getData();
		}
		bool operator ==(Iterator const rhs) const {
			return head == rhs.head;
		}
		bool operator !=(Iterator const rhs) const {
			return !(*this == rhs);
		}
		Iterator operator=(V newItem) {
			Iterator itr = *this; head->setData(newItem);
			return itr;
		}
	};
	//default construct
	Ant_List();
	~Ant_List();

	//insert item like beginer :O(1)
	void push_front(V&&);
	void push_front(V&);

	//insert item at end :O(n)
	void push_back(V&&);
	void push_back(V&);

	//:O(n)
	void clear();

	//:O(1)
	size_t size();

	//first item :O(1)
	V front();
	//last item :O(n)
	V back();

	Iterator begin() { return Iterator(first); };
	Iterator end() { return Iterator(last); };

	//:~O(n)
	Iterator find(V&& searchItem) {
		Iterator it = begin();
		for (size_t i = 0; i < count; i++, it++)
		{
			if (*it == _STD move(searchItem)) break;
		}
		return it;
	};
	//:~O(n)
	Iterator find(V& searchItem) {
		Iterator it = begin();
		for (size_t i = 0; i < count; i++, it++)
		{
			if (*it == searchItem) break;
		}
		return it;
	};
	//:~O(1)
	Iterator emplace(Iterator It, V&& newData) {
		if (It != NULL)
		{
			Iterator it = It;
			it = _STD move(newData);
			return it;
		}
		else return NULL;
	}
	//:~O(1)
	Iterator emplace(Iterator It, V& newData) {
		if (It != NULL)
		{
			Iterator it = It;
			it = newData;
			return it;
		}
		else return NULL;
	}
	//~O(n)
	Iterator erase(Iterator first, Iterator last) {
		if (first != NULL)
		{
			Iterator it = begin();
			if (it != first) {
				while (it.getNext() != first) {
					it++;
				}
				it._head()->setNext(last._head()->getNext());
			}
			else {
			this->first = last._head()->getNext();
			}
			while (first != last)
			{
				--count;
				auto tmp = first;
				first++;
				delete tmp._head();
			}
			delete last._head();
			--count;
			return it;
		}
		return NULL;
	}
	void operator =(V value)
	{
		this->push_front(value);
	}
};

template<typename V>
inline Ant_List<V>::Ant_List()
	:last(NULL),
	count(0)
{
	first = new Node();	
}

template<typename V>
inline Ant_List<V>::~Ant_List()
{
	Node* tmp = first;
	Node* deleteitem;
	for (size_t i = 0; i < count; i++)
	{
		deleteitem = tmp;
		tmp = tmp->getNext();
		deleteitem = new Node();
	}
	count = 0;
}

template<typename V>
inline void Ant_List<V>::push_front(V&& newData)
{
	Node* tmp = new Node();
	tmp->setData(_STD move(newData));

	if (count == 0)
	{
		tmp->setNext(last);
		first = tmp;
	}
	else {
		tmp->setNext(first);
		first = tmp;
	}
	++count;
}

template<typename V>
inline void Ant_List<V>::push_front(V& newData)
{
	Node* tmp = new Node();
	tmp->setData(newData);

	if (count == 0)
	{
		tmp->setNext(last);
		first = tmp;
	}
	else {
		tmp->setNext(first);
		first = tmp;
	}
	++count;
}

template<typename V>
inline void Ant_List<V>::push_back(V&& newData)
{
	if (count > 0)
	{
		Node* tmp = first;
		Node* insertItem = new Node();//new item for insert
		insertItem->setData(_STD move(newData));
		insertItem->setNext(last);

		for (size_t i = 0; i < count - 1; i++)
		{
			tmp = tmp->getNext();
		}
		tmp->setNext(insertItem);
		++count;
	}
	else push_front(_STD move(newData));
}

template<typename V>
inline void Ant_List<V>::push_back(V& newData)
{
	if (count > 0)
	{
		Node* tmp = first;
		Node* insertItem = new Node();//new item for insert
		insertItem->setData(newData);
		insertItem->setNext(last);
		for (size_t i = 0; i < count - 1; i++)
		{
			tmp = tmp->getNext();
		}
		tmp->setNext(insertItem);
		++count;
	}
	else push_front(newData);
}

template<typename V>
inline void Ant_List<V>::clear()
{
	if (count > 0)
	{
		Node* tmp = first;
		Node* deleteitem;

		for (size_t i = 0; i < count - 1; i++)
		{
			deleteitem = tmp;
			tmp = tmp->getNext();
			delete deleteitem;
		}
		last = new Node();
		first = last;
		count = 0;
	}
}

template<typename V>
inline size_t Ant_List<V>::size()
{
	return count;
}

template<typename V>
inline V Ant_List<V>::front()
{
#ifdef _DEBUG
	_STL_VERIFY(count > 0, "List empty, front() exception");//throw
#endif // _DEBUG
	return first->getData();
}

template<typename V>
inline V Ant_List<V>::back()
{
#ifdef _DEBUG
	_STL_VERIFY(count > 0, "List empty, back() exception");//throw
#endif // _DEBUG

	Iterator it = begin();
	if (count > 0) {
		for (size_t i = 0; i < count - 1; i++, it++);
	}
	return *it;
}

template<typename V>
inline void Ant_List<V>::Node::setNext(Node* newItem)
{
	Next = newItem;
}

template<typename V>
inline void Ant_List<V>::Node::setData(V newData)
{
	Data = newData;
}

template<typename V>
inline auto Ant_List<V>::Node::getNext()
{
	return Next;
}

template<typename V>
inline V Ant_List<V>::Node::getData()
{
	return this->Data;
}
