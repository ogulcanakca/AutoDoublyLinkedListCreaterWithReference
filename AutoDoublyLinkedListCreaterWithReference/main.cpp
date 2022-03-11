#include<iostream>

#include "DoublyLinkedList.cpp"
using namespace std;

int main()
{
	DoublyLinkedList<int> list;

	for (int i = 0; i < 5; i++) {
		list.Append((i + 1) * 11);
	}
	cout << list;
	for (int i = 0; i < 5; i++) {
		list.Remove(0);
		cout << list;
	}
	list.Append(77);
	cout << list;

	list.Add(0, 88);
	cout << list;
}