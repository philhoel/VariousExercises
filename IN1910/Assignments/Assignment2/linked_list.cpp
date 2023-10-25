#include <cmath>
#include <iostream>
#include <stdexcept>

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

  public:
    LinkedList()
    {

        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};
