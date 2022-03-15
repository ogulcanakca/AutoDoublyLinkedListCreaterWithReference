#include "DoublyLinkedList.cpp"
#include "DoublyLinkedList.hpp"

template<typename T>
void f(const T& param,const int& count) {
	DoublyLinkedList<T> list;

	for (int i = 0; i < count; i++) {

		list.Append(param);

	}
	std::cout << list;
}

int main()
{
	f(false,3);
	
	/*for (int i = 0; i < 5; i++) {
		std::cout << list;
		list.Remove(0);
		
	}*/
	/*std::cout << list;
	list.Append(6);

	list.Add(0, 5);
	std::cout << list;*/
}