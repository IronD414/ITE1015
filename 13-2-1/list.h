#include <iostream>

template <class T>
class Node
{
public:
    T data;
    Node<T>* next = NULL;
};

template <class T>
class List 
{
private:
    Node<T> *head;
public:
    List() : head(NULL) {};
    ~List()
    {
        auto temp = this->head;
        while (temp != NULL)
        {
            this->head = temp->next;
            delete temp;
            temp = this->head;
        }
    }
    List(T* arr, int n_nodes): head(NULL)
    {
        this->head = new Node<T>;
        auto cur = this->head;
        for (int i = 0; i < n_nodes; ++i)
        {
            cur->data = arr[i];
            if (i != n_nodes-1) cur->next = new Node<T>;
            cur = cur->next;
        }
    }
    void insert_at(int idx, const T& data)
    {
        if (this->head == NULL && idx == 0)
        {
            this->head = new Node<T>;
            this->head->data = data;            
        }else
        {
            auto left = this->head;
            for (int i = 0; i < idx - 1; ++i)
            {
                left = left->next;
            }
            auto right = left->next;
            left->next = new Node<T>;
            left->next->data = data;
            left->next->next = right;
        }
    }
    void remove_at(int idx)
    {
        if (idx == 0 && this->head->next != NULL)
        {
            auto temp = this->head->next;
            delete this->head;
            this->head = NULL;
            this->head = temp;
        }else if (idx == 0)
        {
            delete this->head;
            this->head = NULL;
        }else
        {
            auto cur = this->head;
            for (int i = 0; i < idx - 1; ++i)
            {
                cur = cur->next;
            }
            auto target = cur->next;
            cur->next = target->next;
            delete target;
            target = NULL;
        }
    }
    void pop_back()
    {
        if (this->head->next == NULL)
        {
            delete this->head;
            this->head = NULL;
        }else
        {
            auto cur = this->head;
            while (cur->next->next != NULL)
            {
                cur = cur->next;
            }
            delete cur->next;
            cur->next = NULL;
        }
    }
    void push_back(const T& val)
    {
        if (this->head == NULL)
        {
            this->head = new Node<T>;
            this->head->data = val;            
        }else
        {
            auto cur = this->head;
            while (cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = new Node<T>;
            cur->next->data = val;
        }
    }
    void pop_front()
    {
        auto temp = this->head->next;
        delete this->head;
        this->head = NULL;
        this->head = temp;
    }
    void push_front(const T& val)
    {
        auto temp = this->head;
        this->head = new Node<T>;
        this->head->data = val;
        this->head->next = temp;
    }
    template <class U>
    friend std::ostream& operator<<(std::ostream& out, List<U>& rhs);//print out nodes
};
template <class U>
std::ostream& operator<<(std::ostream& out, List<U>& rhs)
{
    if (rhs.head == NULL) return out;
    else
    {
        auto cur = rhs.head;
        while (cur->next != NULL)
        {
            out << cur->data << ",";
            cur = cur->next;
        }
        out << cur->data;
        return out;
    }
}