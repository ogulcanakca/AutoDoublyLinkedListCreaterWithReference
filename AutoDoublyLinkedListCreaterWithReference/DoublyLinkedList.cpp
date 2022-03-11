#include "DoublyLinkedList.hpp"

#include <iomanip>
#include <iostream>
template<typename Type>
DoublyLinkedList<Type>::DoublyLinkedList()
{
	first = 0;
	numberOfNode = 0;
}
template<typename Type>
DoublyLinkedList<Type>::~DoublyLinkedList() {

	}
template<typename Type>
void DoublyLinkedList<Type>::Append(Type data)
{
		Node<Type>* novel = new Node<Type>(data);

		if (first == 0) {
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
}template<typename Type>
	void DoublyLinkedList<Type>::Remove(int queue) {
		Node<Type>* temp = GetNode(queue);
		if (temp) {
			Node<Type>* previousNode = temp->previous;
			Node<Type>* nextNode = temp->next;

			previousNode->next = nextNode;
			nextNode->previous = previousNode;
			if (first->previous == first) {
				first = 0;
			}
			if (temp == first) {
				first = nextNode;
			}


			delete temp;


			numberOfNode--;
		}
	}
template<typename Type>
	void DoublyLinkedList<Type>::Remove() 
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
	template<typename Type>
	ostream& operator <<(ostream& os, const DoublyLinkedList<Type>& list){
		os << setw(15) << "The adress of node" << setw(15) << "data" << setw(15) << "previous" << setw(15) << "next" << endl;

		Node<Type>* temp = list.first;
		for (int i = 0; i < list.numberOfNode; i++) {
			os << setw(15) << temp << setw(15) << temp->data << setw(15) << temp->previous << setw(15) << temp->next << endl;

			temp = temp->next;
		}
		os << "--------------------------------------" << endl;
		return os;
	}

	template<typename Type>
	Node<Type>* DoublyLinkedList<Type>:: GetNode(int queue)  {
		
		if (queue < 0 || queue >= numberOfNode) {
			return 0;

		}
		
		Node<Type>* temp = first;
		for (int i = 0; i < queue; i++) {
			temp = temp->next;

		}
		return temp;
	}
	template<typename Type>
	void DoublyLinkedList<Type>::Add(int queue, Type data) {
		Node<Type>* temp = GetNode(queue);

		if (temp) {

			Node<Type>* previousNode = temp->previous;
			Node<Type>* novelNode = new Node<Type>(data);
			if (temp == first) {
				first = novelNode;

			}
			previousNode->next = novelNode;
			novelNode->previous = previousNode;
			novelNode->next = temp;
			temp->previous = novelNode;
			numberOfNode++;
		}
	}

	
