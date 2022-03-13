#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp
#include "Node.hpp"
#include <iostream>
#include <iomanip>

template<typename Type>
class DoublyLinkedList {
public:
	DoublyLinkedList();

	~DoublyLinkedList();
	void Append(const Type& data);
	void Remove(int queue);
	
	void Remove();
	template<typename Type>
	friend std::ostream& operator <<(std::ostream& os, const DoublyLinkedList<Type>& list) {
		
		os << std::setw(15) << "The adress of node" << std::setw(15) << "data" << std::setw(15) << "previous" << std::setw(15) << "next" << std::endl;

		Node<Type>* temp = list.first;
		for (int i = 0; i < list.numberOfNode; i++) {
			os << std::setw(15) << temp << std::setw(15) << temp->data << std::setw(15) << temp->previous << std::setw(15) << temp->next << std::endl;

			temp = temp->next;
		}
		os << "--------------------------------------" << std::endl;
		return os;
	}
	
	void Add(int queue, const Type& data);
private:
	Node<Type>* GetNode(int queue);
	Node<Type>* first ;
	int numberOfNode;
};

#endif