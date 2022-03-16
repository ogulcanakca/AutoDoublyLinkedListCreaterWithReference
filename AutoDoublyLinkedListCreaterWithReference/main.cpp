#include "DoublyLinkedList.cpp"
#include "DoublyLinkedList.hpp"


template<typename T>
void f(const std::initializer_list<T>& args/*, const int& count*/) {
	DoublyLinkedList<T> list;
	for (auto&& arg : args) {
		list.Append(arg);
	}
	std::cout << list;
}
int main()
{
	f({'a','b','c','d'});
	/*for (int i = 0; i < 5; i++) {
		std::cout << list;
		list.Remove(0);
		
	}*/
	/*std::cout << list;
	list.Append(6);

	list.Add(0, 5);
	std::cout << list;*/
}