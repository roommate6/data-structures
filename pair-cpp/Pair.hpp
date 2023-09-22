#pragma once

template <class T1, class T2>
class Pair
{
private:
    T1 _first;
    T2 _second;

public:
    Pair() : _first(), _second()
    {
        // empty
    }

    Pair(T1 first, T2 second) : _first(first), _second(second)
    {
        // empty
    }

public:
    T1 GetFirst()
    {
        return _first;
    }

    void SetFrist(T1 first)
    {
        _first = first;
    }

    T2 GetSecond()
    {
        return _second;
    }

    void SetSecond(T2 second)
    {
        _second = second;
    }
};