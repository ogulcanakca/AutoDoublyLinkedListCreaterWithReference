#ifndef Node_hpp
#define Node_hpp



template<typename Type>
class Node
{
public:
    Node(const Type& data) // If you noticed, we gain performance with this notation.
    {
        this->data = data;
        next = previous = nullptr;
    }

    Type data;
    Node* next;
    Node* previous;

};
#endif