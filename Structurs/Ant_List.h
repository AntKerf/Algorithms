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
	};
	//default construct
	Ant_List();
	~Ant_List();

	void push_front(V&&);
	void push_front(V&);

	void push_back(V&&);
	void push_back(V&);

	void clear();

	size_t size();

	Iterator begin() { return Iterator(first); };
	Iterator end() { return Iterator(last); };

};


template<typename V>
inline Ant_List<V>::Ant_List()
	:last(NULL),
	first(NULL),
	count(0)
{
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
		delete deleteitem;
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
	count++;
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
	count++;
}

template<typename V>
inline void Ant_List<V>::push_back(V&& newData)
{
	Node* tmp = first; 
	Node* insertItem=new Node();//new item for insert
	insertItem->setData(_STD move(newData));
	insertItem->setNext(last);

	for (size_t i = 0; i < count-1; i++)
	{
		tmp = tmp->getNext();
	}
	tmp->setNext(insertItem);
	count++;
}

template<typename V>
inline void Ant_List<V>::push_back(V& newData)
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
	count++;
}

template<typename V>
inline void Ant_List<V>::clear()
{
	Node* tmp = first;
	Node* deleteitem;

	for (size_t i = 0; i < count-1; i++)
	{
		deleteitem = tmp;
		tmp = tmp->getNext();
		delete deleteitem;
	}

	last = new Node();
	first = last;
	count = 0;
}

template<typename V>
inline size_t Ant_List<V>::size()
{
	return count;
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
	return Data;
}
