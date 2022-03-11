#ifndef Node_hpp
#define Node_hpp
#include<iostream>
using namespace std;

template<typename Type>
class Node
{
public:
    Node(const Type& data) // If you noticed, we gain performance with this notation.
    {
        this->data = data;
        next = previous = 0;
    }

    Type data;
    Node* next;
    Node* previous;

};
#endif