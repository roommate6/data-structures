#pragma once

#include <iostream>

template <class SimpleList>
class SimpleListIterator
{
public:
    using NodeType = typename SimpleList::Node;
    using NodePointer = NodeType *;
    using ValueType = typename NodeType::ValueType;
    using ReferenceType = ValueType &;

private:
    NodePointer _pointer;

public:
    SimpleListIterator(NodePointer pointer) : _pointer(pointer)
    {
        // empty
    }

public:
    SimpleListIterator &operator++()
    {
        _pointer = _pointer->nextNode;
        return *this;
    }

    SimpleListIterator operator++(int)
    {
        SimpleListIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    ReferenceType operator*()
    {
        return _pointer->object;
    }

    bool operator==(const SimpleListIterator &object)
    {
        return _pointer == object._pointer;
    }

    bool operator!=(const SimpleListIterator &object)
    {
        return !(*this == object);
    }
};

template <class T>
class SimpleListNode
{
public:
    using ValueType = T;

public:
    T object;
    SimpleListNode *nextNode;

public:
    SimpleListNode()
    {
        // empty
    }

    SimpleListNode(T object)
    {
        this->object = object;
        this->nextNode = nullptr;
    }

    SimpleListNode(T object, SimpleListNode *nextNode)
    {
        this->object = object;
        this->nextNode = nextNode;
    }
};

template <class T>
class SimpleList
{
public:
    using Node = SimpleListNode<T>;
    using Iterator = SimpleListIterator<SimpleList<T>>;

private:
    Node *_firstNode;
    Node *_lastNode;
    size_t _size;

public:
    SimpleList()
    {
        _firstNode = nullptr;
        _lastNode = nullptr;
        _size = 0;
    }

public:
    size_t Size()
    {
        return _size;
    }

    bool Empty()
    {
        return _size == 0;
    }

    Iterator begin()
    {
        return Iterator(_firstNode);
    }

    Iterator end()
    {
        return Iterator(_lastNode->nextNode);
    }

public:
    void PushBack(T object)
    {
        Node *previousLastNode = _lastNode;
        _lastNode = new Node(object);
        ++_size;

        if (previousLastNode != nullptr)
        {
            previousLastNode->nextNode = _lastNode;
            return;
        }

        _firstNode = _lastNode;
    }

    void PushFront(T object)
    {
        Node *previousFirstNode = _firstNode;
        _firstNode = new Node(object);
        ++_size;

        if (previousFirstNode != nullptr)
        {
            _firstNode->nextNode = previousFirstNode;
            return;
        }

        _lastNode = _firstNode;
    }
};