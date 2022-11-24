#ifndef __MY_CONTAINER_H__
#define __MY_CONTAINER_H__
#include <iostream>
#include <string>
template <class T>
class MyContainer
{
public:
    MyContainer(int size)
    {
        this->n_elements = size;
        this->obj_arr = new T[size];
    }
    ~MyContainer()
    {
        delete[] this->obj_arr;
    }
    void clear()
    {
        for (int i = 0; i < this->n_elements; ++i)
        {
            this->obj_arr[i] = NULL;
        }
    }
    int size()
    {
        return this->n_elements;
    }
    template <class U>
    friend std::istream& operator>> (std::istream &in, MyContainer<U> &b);
    template <class U>
    friend std::ostream& operator<< (std::ostream &out, MyContainer<U> &b);
protected:
    T * obj_arr = NULL;
    int n_elements;
};

template<class T>
std::istream& operator>> (std::istream &in, MyContainer<T> &b)
{
    for (int i = 0; i < b.size(); ++i)
    {
        std::cin >> b.obj_arr[i];
    }
    return in;
}
template<class T>
std::ostream& operator<< (std::ostream &out, MyContainer<T> &b)
{
    for (int i = 0; i < b.size(); ++i)
    {
        std::cout << b.obj_arr[i] << " ";
    }
    return out;
}
#endif // __MY_CONTAINER_H__