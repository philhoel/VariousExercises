#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

class LinkedList
{

    struct Node
    {

        int val;
        Node *next;
        Node *prev;

        Node(int v, Node *n, Node *p)
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
    LinkedList()
    {

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    LinkedList(std::vector<int> vec)
    {

        head = nullptr;
        tail = nullptr;
        size = 0;

        for (int i = 0; i < vec.size(); i++)
        {
            append(vec[i]);
        }
    }

    ~LinkedList()
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

    int &operator[](int index)
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

    void append(int val)
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

    void push_front(int val)
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

    void insert(int val, int index)
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

    int pop(int index)
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

    int pop()
    {
        return pop(size - 1);
    }

    int min()
    {

        if (head == nullptr)
        {
            throw std::out_of_range("List is empty");
        }

        int m = head->val;
        Node *current = head;

        while (current->next != nullptr)
        {
            if (m > current->val)
            {
                m = current->val;
            }
            current = current->next;
        }

        if (m > current->val)
        {
            m = current->val;
        }

        return m;
    }

    int max()
    {

        if (head == nullptr)
        {
            throw std::out_of_range("List is empty");
        }

        int m = head->val;
        Node *current = head;

        while (current->next != nullptr)
        {
            if (m < current->val)
            {
                m = current->val;
            }
            current = current->next;
        }

        if (m < current->val)
        {
            m = current->val;
        }

        return m;
    }
};
