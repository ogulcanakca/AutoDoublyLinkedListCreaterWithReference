#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp
#include "Node.hpp"

#include <iomanip>
#include <iostream>
template<typename Type>
class DoublyLinkedList {
public:
	DoublyLinkedList()
	{
		first = nullptr;
		numberOfNode = 0;
	}
	~DoublyLinkedList()
	{
		Node<Type>* temp = first;

		for (int i = 0; i < numberOfNode; i++)
		{
			Node<Type>* deleted = temp;

			temp = temp->next;
			delete deleted;
		}

	}

	void Remove(int queue) {
		Node<Type>* temp = GetNode(queue);
		if (temp) {
			Node<Type>* previousNode = temp->previous;
			Node<Type>* nextNode = temp->next;

			previousNode->next = nextNode;
			nextNode->previous = previousNode;
			if (first->previous == first) {
				first = nullptr;
			}
			if (temp == first) {
				first = nextNode;
			}


			delete temp;


			numberOfNode--;
		}
	}
	void Remove()
	{ // the last of the list
		if (first == 0) {
			return;

		}
		if (first->next == first) {
			delete first;
			first = 0;
		}
		else
		{
			Node<Type>* temp = GetNode(numberOfNode - 2);

			delete temp->next;

			temp->next = first;
			first->previous = temp;

		}
		numberOfNode--;
	}


	
	void Add(int queue, const Type& data) {
		Node<Type>* temp = GetNode(queue);

		if (temp) {
			Node<Type>* novelNode = new Node<Type>(data);
			Node<Type>* previousNode = temp->previous;

			if (temp == first) {
				first = novelNode;
			}
			else
			{
				previousNode->next = novelNode;
				novelNode->previous = previousNode;
				novelNode->next = temp;
				temp->previous = novelNode;
				numberOfNode++;
			}
		}

	}

	/*template<typename Type>
void DoublyLinkedList<Type>::Append(const Type& data)
{
	Node<Type>* novel = new Node<Type>(data);

	if (first == nullptr) {
		first = novel;
		first->previous = first;
		first->next = first;
	}
	else {
		Node<Type>* temp = first;
		while (temp->next != first) {
			temp = temp->next;
		}
		temp->previous = novel;
		novel->previous = temp;
		novel->next = first;
		first->previous = novel;

	}
	numberOfNode++;
}*/

	void Append(const Type& data)
	{
		Node<Type>* novel = new Node<Type>(data);

		if (first == nullptr) {
			first = novel;
			first->previous = first;
			first->next = first;
		}
		else {
			Node<Type>* temp = GetNode(numberOfNode - 1);
			temp->next = novel;
			novel->previous = temp;
			novel->next = first;
			first->previous = novel;

		}
		numberOfNode++;
	}
	
	void MultiAppend(const std::initializer_list<Type>& args, DoublyLinkedList<Type>& list) {
		
		for (auto&& arg : args) {
			list.Append(arg);
		}
		std::cout << list;

	}
	
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
	
	
private:
	Node<Type>* GetNode(int queue) {

		if (queue < 0 || queue >= numberOfNode) {
			return 0;

		}

		Node<Type>* temp = first;
		for (int i = 0; i < queue; i++) {
			temp = temp->next;

		}
		return temp;
	}
	Node<Type>* first ;
	int numberOfNode;
};

#endif