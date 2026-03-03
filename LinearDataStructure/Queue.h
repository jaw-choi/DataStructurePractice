#pragma once

#include <iostream>


class Queue
{
public:
    Queue() : capacity(100), front(0), rear(0), size_(0)
    {

    }
    ~Queue();

    void Push(const char& ch)
    {
        rear = (rear + 1) % (capacity+1);
        inputQueue[rear] = ch;
        size_++;
    }

    void Pop()
    {
        if (IsEmpty()) return;
        front = (front + 1) % (capacity + 1);
        inputQueue[front] = 0;
        size_--;
    }

    void Deque()
    {
        if (IsEmpty()) return;
        inputQueue[rear] = 0;
        rear = (rear - 1) % (capacity + 1);
        size_--;
    }

    const char Front() const
    {
        if (IsEmpty())
        {
            __debugbreak();
        }
        return inputQueue[(front + 1) % (capacity + 1)];
    }

    bool IsEmpty() const
    {
        return rear == front;
    }

    void Print()
    {
        std::cout << "현재 Queue에 있는 char는 ";
        for (int i = 0; i < size_; i++)
        {
            std::cout << inputQueue[(front + i + 1 + 100) % (capacity)] <<", ";
        }
        std::cout << std::endl;
    }
public:
    char inputQueue[100];
    int capacity = 100;
    int front = 0;
    int rear = 0;
    int size_;
};

