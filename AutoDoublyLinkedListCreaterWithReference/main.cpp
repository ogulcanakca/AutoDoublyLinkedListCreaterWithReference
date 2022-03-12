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
		list.Remove(0);
		std::cout << list;
	}
	list.Append(77);
	std::cout << list;

	list.Add(0, 88);
	std::cout << list;
}