#include "priority_queue.h"

template<typename T>
Node <T>::Node ()
{
    _data = new std::pair <int, T>;
    _parent = nullptr;
    _right = nullptr;
    _left = nullptr;
}
template<typename T>
void Node<T>::SetParent (Node *N)
{
    _parent = N;
}
template<typename T>
void Node<T>::SetRight (Node *N)
{
    _right = N;
}
template<typename T>
void Node<T>::SetLeft (Node *N)
{
    _left = N;
}
template<typename T>
void Node<T>::SetData (std::pair<int, T> &data)
{
    _data = data;
}
template<typename T>
Node<T>* Node<T>::GetParent ()
{
    return _parent;
}
template<typename T>
Node<T>* Node<T>::GetRight ()
{
    return _right;
}
template<typename T>
Node<T>* Node<T>::GetLeft ()
{
    return _left;
}
template<typename T>
std::pair <int, T>& Node<T>::GetData ()
{
    return _data;
}

template<typename T>
My_Priority_Queue<T>::My_Priority_Queue ()
{
    _size = 0;
    Root = nullptr;
}

template<typename T>
int My_Priority_Queue<T>::GetSize ()
{
    return _size;
}

template<typename T>
bool My_Priority_Queue<T>::IsEmpty()
{
    return !(bool)_size;
}

template<typename T>
void My_Priority_Queue<T>::Push (int priority, T data)
{
    Node<T> N;
    N.SetData(std::make_pair(priority, data));
    if (IsEmpty())
    {
        Root = N;
        N.SetParent(nullptr);
        N.SetRight(nullptr);
        N.SetLeft(nullptr);
    }
    else
    {
        Node<T>* buf = nullptr;
        Node<T>* tmp = Root;
        while (tmp)
        {
            if (priority <= tmp->GetData().first)
            {
                buf = tmp;
                tmp = tmp->GetLeft();
            }
            else
            {
                buf = tmp;
                tmp = tmp->GetRight();
            }
        }
        if (priority <= buf->GetData().first)
        {
            buf->GetRight() = N;
        }
        else
        {
            buf->GetLeft() = N;
        }
    }
}

template<typename T>
T& My_Priority_Queue<T>::Top ()
{
    Node<T>* N = &FindMin();
    if (N)
    {
        return N->GetData().second;
    }
    return nullptr;
}

template<typename T>
void My_Priority_Queue<T>::Pop ()
{
    Node<T>* N = FindMin();
    if (N)
    {
        DeleteNode(N);
    }
}

template<typename T>
Node<T>* My_Priority_Queue<T>::FindMin ()
{
    Node<T>* tmp = Root;
    Node<T>* buf = nullptr;
    while (tmp)
    {   buf = tmp;
        tmp = tmp->GetLeft();
    }
    return buf;
}

template<typename T>
void My_Priority_Queue<T>::DeleteNode (Node<T> *N)
{
    if (N->GetRight())
    {
        N->GetRight()->GetParent() = N->GetParent();
        N->GetParent()->GetLeft() = N->GetRight();
    }
    else
    {
        N->GetParent() = nullptr;
    }
}





