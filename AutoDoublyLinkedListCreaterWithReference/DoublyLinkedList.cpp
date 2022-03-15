#include "DoublyLinkedList.hpp"

#include <iomanip>
#include <iostream>
template<typename Type>
DoublyLinkedList<Type>::DoublyLinkedList()
{
	first = nullptr;
	numberOfNode = 0;
}
template<typename Type>
DoublyLinkedList<Type>::~DoublyLinkedList()
{
	Node<Type>* temp = first;

	for (int i = 0; i < numberOfNode; i++)
	{
		Node<Type>* deleted = temp;

		temp = temp->next;
		delete deleted;
	}

}

template<typename Type>
	void DoublyLinkedList<Type>::Remove(int queue) {
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
	void DoublyLinkedList<Type>::Add(int queue, const Type& data) {
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
	
	template<typename Type>
	void DoublyLinkedList<Type>::Append(const Type& data)
	{
		Node<Type>* novel = new Node<Type>(data);

		if (first == nullptr) {
			first = novel;
			first->previous = first;
			first->next = first;
		}
		else {
			Node<Type>*temp = GetNode(numberOfNode-1);
			temp->next = novel;
			novel->previous = temp;
			novel->next = first;
			first->previous = novel;

		}
		numberOfNode++;
	}
	
