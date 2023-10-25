#include "linked_list.cpp"
#include <cassert>
#include <iostream>

void test_empty_list_has_zero_length()
{

    LinkedList my_list = LinkedList();
    assert(my_list.length() == 0);
}

void test_append()
{

    LinkedList my_list = LinkedList();
    my_list.append(1);
    my_list.append(2);
    my_list.append(3);
    my_list.append(4);
    my_list.append(5);
    my_list.append(6);

    assert(my_list[0] == 1);
    assert(my_list[1] == 2);
    assert(my_list[5] == 6);
}

void test_push_front()
{
    LinkedList my_list = LinkedList();
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(4);

    assert(my_list[0] == 4);
    assert(my_list[2] == 1);
}

void test_operator()
{

    LinkedList my_list = LinkedList();
    my_list.append(1);
    my_list.append(2);

    try
    {
        my_list[10];
        assert(false);
    }
    catch (const std::out_of_range &e)
    {
        assert(true);
    }
}

void test_insert()
{

    LinkedList my_list = LinkedList();

    my_list.insert(1, 0);
    assert(my_list[0] == 1);

    my_list.insert(2, 1);
    assert(my_list[1] == 2);

    my_list.append(3);
    my_list.append(4);
    my_list.append(5);

    my_list.insert(7, 3);
    assert(my_list[3] == 7);
    assert(my_list[4] == 4);
    assert(my_list.length() == 6);

    try
    {
        my_list.insert(1, 20);
        assert(false);
    }
    catch (const std::out_of_range &e)
    {
        assert(true);
    }
}

void test_vector_constructor()
{

    std::vector<int> vec{1, 2, 3, 4, 5};
    LinkedList my_list = LinkedList(vec);

    assert(my_list[0] == 1);
    assert(my_list[4] == 5);
    assert(my_list.length() == 5);
}

void test_remove()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    LinkedList my_list = LinkedList(vec);

    my_list.remove(2);
    assert(my_list[2] == 4);
    assert(my_list.length() == 4);
    my_list.remove(0);
    assert(my_list[0] == 2);
    assert(my_list.length() == 3);
    my_list.push_front(0);
    my_list.remove(3);
    assert(my_list[2] == 4);

    try
    {
        my_list.remove(10);
        assert(false);
    }
    catch (const std::out_of_range &e)
    {
        assert(true);
    }
}

void test_pop_at_index()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    LinkedList my_list = LinkedList(vec);

    int tmp;
    tmp = my_list.pop(2);
    assert(tmp == 3);
    assert(my_list[2] == 4);
    assert(my_list.length() == 4);
    tmp = my_list.pop(0);
    assert(tmp == 1);
    assert(my_list[0] == 2);
    assert(my_list.length() == 3);
    my_list.push_front(0);
    tmp = my_list.pop(3);
    assert(my_list[2] == 4);
    assert(tmp = 5);

    try
    {
        my_list.pop(10);
        assert(false);
    }
    catch (const std::out_of_range &e)
    {
        assert(true);
    }
}

void test_pop()
{

    std::vector<int> vec{1, 2, 3, 4, 5};
    LinkedList my_list = LinkedList(vec);

    int tmp;
    tmp = my_list.pop();
    assert(my_list.length() == 4);
    assert(tmp == 5);
}

void test_min()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    LinkedList my_list = LinkedList(vec);

    assert(my_list.min() == 1);
}

void test_max()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    LinkedList my_list = LinkedList(vec);

    assert(my_list.max() == 5);
}

int main()
{
    std::cout << "Testing..." << std::endl;
    test_empty_list_has_zero_length();
    std::cout << "1st test passed..." << std::endl;
    test_append();
    std::cout << "2nd test passed..." << std::endl;
    test_push_front();
    std::cout << "3rd test passed..." << std::endl;
    test_insert();
    std::cout << "4th test passed..." << std::endl;
    test_vector_constructor();
    std::cout << "5th test passed..." << std::endl;
    test_remove();
    std::cout << "6th test passed..." << std::endl;
    test_pop_at_index();
    std::cout << "7th test passed..." << std::endl;
    test_pop();
    std::cout << "8th test passed..." << std::endl;
    test_min();
    std::cout << "9th test passed..." << std::endl;
    test_max();
    std::cout << "10th test passed..." << std::endl;

    std::cout << "\n" << std::endl;
    std::cout << "All tests passed!" << std::endl;
    return 0;
}