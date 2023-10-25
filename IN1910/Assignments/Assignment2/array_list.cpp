#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

class ArrayList
{
  private:
    int *data;
    int capacity;
    int size;
    int growth_factor = 2;

    void resize()
    {

        capacity *= growth_factor;
        int *new_data = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }

        delete data;
        data = new_data;
    }

    void shrink_to_fit()
    {
        int tmp_cap = 0;
        for (int i = 0; i < (int)size / 2; i++)
        {
            tmp_cap = pow(2, i);
            if (tmp_cap > size)
            {
                capacity = tmp_cap;
                break;
            }
        }

        int *tmp = new int[capacity];
        for (int j = 0; j < size; j++)
        {
            tmp[j] = data[j];
        }

        delete data;
        data = tmp;
    }

  public:
    ArrayList()
    {
        capacity = 10;
        size = 0;
        data = new int[capacity];
    }

    ArrayList(std::vector<int> vec)
    {
        capacity = 2 * vec.size();
        size = 0;
        data = new int[capacity];

        for (int i = 0; i < vec.size(); i++)
        {
            append(vec[i]);
        }
    }

    ~ArrayList()
    {

        delete data;
    }

    int length()
    {
        return size;
    }

    int get_capacity()
    {
        return capacity;
    }

    int &operator[](int index)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index was too high");
        }

        return data[index];
    }

    void append(int val)
    {

        if (size >= capacity)
        {
            resize();
        }

        data[size] = val;
        size++;
    }

    void insert(int val, int index)
    {

        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index was too high");
        }

        if (size >= capacity)
        {
            resize();
        }

        int *tmp = new int[capacity];
        tmp[index] = val;

        for (int i = 0; i < index; i++)
        {
            tmp[i] = data[i];
        }

        for (int j = index; j < size; j++)
        {
            tmp[j + 1] = data[j];
        }
        delete data;
        data = tmp;
        size++;
    }

    void remove(int index)
    {

        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index was too high");
        }

        int *tmp = new int[capacity];
        for (int i = 0; i < index; i++)
        {
            tmp[i] = data[i];
        }
        for (int j = index + 1; j < size; j++)
        {
            tmp[j - 1] = data[j];
        }

        delete data;
        data = tmp;
        size--;

        if (size < capacity * 0.25)
        {
            shrink_to_fit();
        }
    }

    int pop(int index)
    {

        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index was too high");
        }

        int r = data[index];
        int *tmp = new int[capacity];
        for (int i = 0; i < index; i++)
        {
            tmp[i] = data[i];
        }
        for (int j = index + 1; j < size; j++)
        {
            tmp[j - 1] = data[j];
        }

        delete data;
        data = tmp;
        size--;

        if (size < capacity * 0.25)
        {
            shrink_to_fit();
        }

        return r;
    }

    int pop()
    {
        return pop(size - 1);
    }

    int argmin()
    {

        int min = 0;
        for (int i = 1; i < size; i++)
        {
            if (data[i] < data[min])
            {
                min = i;
            }
        }

        return min;
    }

    int argmax()
    {
        int max = 0;
        for (int i = 1; i < size; i++)
        {
            if (data[i] > data[max])
            {
                max = i;
            }
        }

        return max;
    }

    int min()
    {

        int m = data[0];
        for (int i = 1; i < size; i++)
        {
            if (data[i] < m)
            {
                m = data[i];
            }
        }

        return m;
    }

    int max()
    {

        int m = data[0];
        for (int i = 1; i < size; i++)
        {
            if (data[i] > m)
            {
                m = data[i];
            }
        }

        return m;
    }

    int count(int x)
    {

        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == x)
            {
                count++;
            }
        }

        return count;
    }
};