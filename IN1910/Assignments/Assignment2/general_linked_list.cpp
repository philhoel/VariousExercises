#include <cmath>
#include <iostream>
#include <stdexcept>

template <typename T> struct Node
{

    T val;
    Node *next;
    Node *prev;

    Node(T v, Node *n, Node *p)
    {
        val = v;
        next = n;
        prev = p;
    }
};

template <typename T> class GeneralLinkedList
{

    struct Node
    {

        T val;
        Node *next;
        Node *prev;

        Node(T v, Node *n, Node *p)
        {
            val = v;
            next = n;
            prev = p;
        }
    };

  private:
    Node *head;
    Node *tail;
    int size;

    Node *loop(int index)
    {

        Node *current;
        if (index > size / 2)
        {
            current = tail;
            int i = size - 1;
            while (i > index)
            {
                current = current->prev;
                i--;
            }

            return current;
        }
        else
        {
            current = head;
            int i = 0;
            while (i < index)
            {
                current = current->next;
                i++;
            }

            return current;
        }
    }

  public:
    GeneralLinkedList()
    {

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~GeneralLinkedList()
    {

        Node *current;
        Node *next_node;

        current = head;

        while (current != nullptr)
        {
            next_node = current->next;
            delete current;
            current = next_node;
        }
    }

    T &operator[](int index)
    {
        if (index >= size)
        {
            throw std::out_of_range("List index out of range");
        }

        if (index == 0)
        {
            return head->val;
        }

        if (index == (size - 1))
        {
            return tail->val;
        }

        Node *current;
        current = loop(index);

        return current->val;
    }

    int length()
    {
        return size;
    }

    void append(T val)
    {
        if (head == nullptr)
        {
            head = new Node(val, nullptr, nullptr);
            tail = head;
            size++;
            return;
        }

        if (size == 1)
        {
            tail = new Node(val, nullptr, head);
            head->next = tail;
            size++;
            return;
        }

        Node *current;
        current = tail;
        Node *tmp = new Node(val, nullptr, tail);
        current->next = tmp;
        tail = tmp;
        size++;
    }

    void push_front(T val)
    {

        if (head == nullptr)
        {
            head = new Node(val, nullptr, nullptr);
            tail = head;
            size++;
            return;
        }

        Node *current;
        current = head;
        Node *tmp = new Node(val, current, nullptr);
        head = tmp;

        if (size == 1)
        {
            tail = current;
        }

        size++;
    }

    void insert(T val, int index)
    {

        if (index > size || index < 0)
        {
            throw std::out_of_range("List index out of range");
        }

        if (head == nullptr && index == 0)
        {
            head = new Node(val, nullptr, nullptr);
            tail = head;
            size++;
            return;
        }

        if (index == size)
        {
            append(val);
            return;
        }

        if (index == 0)
        {
            push_front(val);
            return;
        }

        Node *current;
        current = loop(index);
        Node *tmp = current->prev;
        Node *new_node = new Node(val, current, tmp);
        tmp->next = new_node;
        current->prev = new_node;
        size++;
    }

    void remove(int index)
    {

        if (index >= size || index < 0 || head == nullptr)
        {
            throw std::out_of_range("List index out of range");
        }

        if (index == 0)
        {
            Node *current = head;
            head = current->next;
            delete current;
            head->prev = nullptr;
            size--;
            return;
        }

        if (index == size - 1)
        {
            Node *current = tail;
            tail = current->prev;
            delete current;
            tail->next = nullptr;
            size--;
            return;
        }

        Node *current;
        current = loop(index);
        Node *tmp = current->prev;
        Node *forward = current->next;
        tmp->next = forward;
        forward->prev = tmp;
        delete current;
        size--;
    }

    T pop(int index)
    {

        if (index >= size || index < 0 || head == nullptr)
        {
            throw std::out_of_range("List index out of range");
        }

        if (index == 0)
        {
            Node *current = head;
            int r = current->val;
            head = current->next;
            delete current;
            head->prev = nullptr;
            size--;
            return r;
        }

        if (index == size - 1)
        {
            Node *current = tail;
            int r = current->val;
            tail = current->prev;
            delete current;
            tail->next = nullptr;
            size--;
            return r;
        }

        Node *current;
        current = loop(index);
        int r = current->val;
        Node *tmp = current->prev;
        Node *forward = current->next;
        tmp->next = forward;
        forward->prev = tmp;
        delete current;
        size--;

        return r;
    }

    T pop()
    {
        return pop(size - 1);
    }
};