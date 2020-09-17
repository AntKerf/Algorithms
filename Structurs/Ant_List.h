#pragma once
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

	void add(V);
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
inline void Ant_List<V>::add(V newData)
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
