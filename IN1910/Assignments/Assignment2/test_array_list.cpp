#include "array_list.cpp"
#include <cassert>
#include <iostream>
#include <vector>

void test_empty_array_has_length_zero()
{
    ArrayList my_array = ArrayList();
    assert(my_array.length() == 0);
}

void test_array_with_two_elements_appended_has_length_two()
{

    ArrayList my_array = ArrayList();

    my_array.append(1);
    my_array.append(2);

    assert(my_array.length() == 2);
}

void test_indexing_operator()
{

    ArrayList my_array = ArrayList();

    my_array.append(1);
    my_array.append(5);
    my_array.append(6);

    assert(my_array[0] == 1);
    assert(my_array[1] == 5);
    assert(my_array[2] == 6);
}

void test_vector_constructor()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    ArrayList my_array = ArrayList(vec);

    assert(my_array.length() == 5);
    assert(my_array[0] == 1);
    assert(my_array[4] == 5);
}

void test_insert()
{

    ArrayList my_array = ArrayList();
    try
    {
        my_array.insert(10, 10);

        assert(false);
    }
    catch (const std::out_of_range &e)
    {

        assert(true);
    }

    my_array.insert(1, 0);
    assert(my_array.length() == 1);
    assert(my_array[0] == 1);

    my_array.append(1);
    my_array.append(4);
    my_array.append(5);

    my_array.insert(3, 2);
    assert(my_array[2] == 3);
    assert(my_array[3] == 4);
}

void test_remove()
{

    ArrayList my_array = ArrayList();

    for (int i = 0; i < 5; i++)
    {
        my_array.append(i);
    }

    my_array.remove(0);
    assert(my_array[0] == 1);
    assert(my_array.length() == 4);

    my_array.remove(2);
    assert(my_array[2] == 4);
    assert(my_array.length() == 3);

    try
    {
        my_array.remove(10);
        assert(false);
    }
    catch (const std::out_of_range &e)
    {
        assert(true);
    }
}

void test_pop_at_index()
{

    ArrayList my_array = ArrayList();

    for (int i = 0; i < 5; i++)
    {
        my_array.append(i);
    }

    int tmp;
    tmp = my_array.pop(0);
    assert(my_array[0] == 1);
    assert(my_array.length() == 4);
    assert(tmp == 0);

    tmp = my_array.pop(2);
    assert(my_array[2] == 4);
    assert(my_array.length() == 3);
    assert(tmp == 3);

    try
    {
        my_array.remove(10);
        assert(false);
    }
    catch (const std::out_of_range &e)
    {
        assert(true);
    }
}

void test_pop()
{

    ArrayList my_array = ArrayList();

    for (int i = 0; i < 5; i++)
    {
        my_array.append(i);
    }

    int tmp;
    tmp = my_array.pop();
    assert(my_array.length() == 4);
    assert(my_array[my_array.length() - 1] == 3);
    assert(tmp == 4);
}

void test_shrink_to_fit()
{
}

int main()
{
    std::cout << "Testing..." << std::endl;
    test_array_with_two_elements_appended_has_length_two();
    std::cout << "1st test passed..." << std::endl;
    test_empty_array_has_length_zero();
    std::cout << "2nd test passed..." << std::endl;
    test_indexing_operator();
    std::cout << "3rd test passed..." << std::endl;
    test_vector_constructor();
    std::cout << "4th test passed..." << std::endl;
    test_insert();
    std::cout << "5th test passed..." << std::endl;
    test_remove();
    std::cout << "6th test passed..." << std::endl;
    test_pop_at_index();
    std::cout << "7th test passed..." << std::endl;
    test_pop();
    std::cout << "8th test passed..." << std::endl;
    std::cout << "..." << std::endl;
    std::cout << "All tests passed" << std::endl;

    return 0;
}