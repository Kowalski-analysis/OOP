#ifndef LAB4_OOP_PRIORITY_QUEUE_H
#define LAB4_OOP_PRIORITY_QUEUE_H
#include <iostream>

template <typename T>
class Node
{
private:
    std::pair <int, T> _data;
    Node* _parent;
    Node* _right;
    Node* _left;
public:
    Node ();
    void SetParent (Node* N);
    void SetRight (Node* N);
    void SetLeft (Node* N);
    void SetData (std::pair <int, T>& data);
    Node* GetParent ();
    Node* GetRight ();
    Node* GetLeft ();
    std::pair <int, T>& GetData ();
};

template <typename T>
class My_Priority_Queue
{
private:
    int _size;
    Node<T>* Root;
    Node<T>* FindMin ();
    void DeleteNode (Node<T>* N);
public:
    My_Priority_Queue();
    int GetSize ();
    bool IsEmpty ();
    void Push (int priority, T data);
    T& Top ();
    void Pop ();
};

#endif //LAB4_OOP_PRIORITY_QUEUE_H
