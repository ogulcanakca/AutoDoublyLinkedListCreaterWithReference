#include "DoublyLinkedList.cpp"
#include "DoublyLinkedList.hpp"

int main()
{
	DoublyLinkedList<int> list;
	for (int i = 0; i < 5; i++) {
		list.Append((i + 1) * 11);
	}
	std::cout << list;
	for (int i = 0; i < 5; i++) {
		std::cout << list;
		list.Remove(0);
		
	}
	std::cout << list;
	list.Append(6);

	list.Add(5, 5);
	std::cout << list;
}