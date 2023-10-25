#include "general_linked_list.cpp"
#include <cassert>
#include <iostream>

void test_constructor()
{

    GeneralLinkedList<double> my_list = GeneralLinkedList<double>();
    assert(my_list.length() == 0);
}

void test_append()
{

    GeneralLinkedList<double> my_list = GeneralLinkedList<double>();
    my_list.append(3.5);
    my_list.append(3.6);

    assert(my_list[0] == 3.5);
    assert(my_list[1] == 3.6);
}

int main()
{
    return 0;
}