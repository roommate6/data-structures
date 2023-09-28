#pragma once

#include <stdexcept>

template <class T>
class Vector
{
private:
    T *_root;
    unsigned int _size;
    unsigned int _capacity;

public:
    Vector()
    {
        _root = new T[0];
        _size = 0;
        _capacity = 0;
    }

public:
    unsigned int GetSize()
    {
        return _size;
    }

    unsigned int GetCapacity()
    {
        return _capacity;
    }

    bool Empty()
    {
        return _size == 0;
    }

    T GetElementAt(unsigned int position)
    {
        if (position < 0 || position >= _size)
        {
            throw std::domain_error("position should be in [0, size)");
        }
        return _root[position];
    }

public:
    void PushBack(T object)
    {
        if (_size == _capacity)
        {
            Reallocate();
        }
        _root[_size] = object;
        ++_size;
    }

    void PopBack()
    {
        if (_size == 0)
        {
            return;
        }
        --_size;
    }

    void Clear()
    {
        _size = 0;
    }

private:
    void Reallocate()
    {
        _capacity = _size * 2 + 1;
        T *newRoot = new T[_capacity];

        for (unsigned int i = 0; i < _size; ++i)
        {
            newRoot[i] = _root[i];
        }

        delete[] _root;
        _root = newRoot;
    }
};