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
void My_Priority_Queue<T>::Push (int priority, T& data)
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
        Node<T>* buf = Root;
        while (buf)
        {
            if (priority <= buf->GetData().first)
            {
                buf = buf->GetLeft();
            }
            else
            {
                buf = buf->GetRight();
            }
        }

    }
}

template<typename T>
T& My_Priority_Queue<T>::Top ()
{
    return ;
}

template<typename T>
void My_Priority_Queue<T>::Pop ()
{

}





