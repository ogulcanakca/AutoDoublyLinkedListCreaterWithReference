#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp
#include "Node.hpp"


template<typename Type>
class DoublyLinkedList {
public:
	DoublyLinkedList();

	~DoublyLinkedList();

	void Append(Type data);
	void Remove(int queue);
	void Remove();
	friend ostream& operator <<(ostream& os, const DoublyLinkedList& list);
	Node<Type>* GetNode(int queue);
	void Add(int queue, Type data);
private:
	Node<Type>* first;
	int numberOfNode;
};

#endif