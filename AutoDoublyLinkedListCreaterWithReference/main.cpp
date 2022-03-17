#include "DoublyLinkedList.cpp"

int main()
{
	DoublyLinkedList<char> list;
	list.Append('2');
	list.MultiAppend({ 'a','1','c','d'}, list);
	/*for (int i = 0; i < 5; i++) {
		std::cout << list;
		list.Remove(0);
	}
	DoublyLinkedList<int> list_2;
	list_2.Append(1);
	std::cout << list_2;*/
	/*list.Add(3, 'a');
	std::cout << list;*/

	return 0;
}