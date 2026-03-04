#pragma once

#include <vector>
#include <iostream>


class Stack
{
public:
    static constexpr int Capacity = 100;
public:
    Stack() : undoTop(-1), redoTop(-1) {}

    void Push(char c)
    {
        undo[++undoTop] = c;
    }

    void Undo()
    {
        if (undoTop == -1)
            return;
        char ch = undo[undoTop--];
        Print(ch);
        redo[++redoTop] = ch;
    }

    void Redo()
    {
        if (redoTop == -1)
            return;

        char ch = redo[redoTop--];
        Print(ch);
        undo[++undoTop] = ch;
    }

    bool IsUndoEmpty()
    {
        return undoTop == -1;
    }

    bool IsRedoEmpty()
    {
        return redoTop == -1;
    }

    char RedoTop()
    {
        return redo[redoTop];
    }


    void Show()
    {
        if (undoTop != -1)
        {

            std::cout << "Undo: ";
            for (int i = 0; i < undoTop+1; i++)
            {
                std::cout << undo[i] << ", ";
            }
            std::cout << std::endl;
        }
        else
        {

            std::cout << "Undo is empty \n";
        }
        if (redoTop != -1)
        {

            std::cout << "Redo: ";
            for (int i = 0; i < redoTop+1; i++)
            {
                std::cout << redo[i] << ", ";
            }
            std::cout << std::endl;
        }
        else
        {

            std::cout << "Redo is empty \n";
        }

    }
    void Print(char c)
    {
        std::cout << c << "실행." << std::endl;
    }


public:
    int undoTop = -1;
    int redoTop = -1;
    char undo[Capacity];
    char redo[Capacity];
};

