#pragma once

#include <vector>
#include <iostream>

class Stack
{
public:
    void Undo(char c)
    {
        Print(c);
        redo.push_back(c);
    }

    void RedoPop()
    {
        if (IsEmpty(redo)) return;
        redo.pop_back();
    }

    void UndoPop()
    {
        if (IsEmpty(undo)) return;
        undo.pop_back();
    }


    void Redo(char c)
    {
        Print(c);
        undo.push_back(c);
    }
    
    char Top(const std::vector<char>& v)
    {
        if (IsEmpty(v)) return '\0';
        return v.back();
    }

    void Show()
    {
        std::cout << "Undo: ";
        for (int i = undo.size() - 1; i >= 0; i--)
        {
            std::cout << undo[i] << ", ";
        }
        std::cout << std::endl;
        std::cout << "Redo: ";
        for (int i = redo.size() - 1; i >= 0; i--)
        {
            std::cout << redo[i] << ", ";
        }
        std::cout << std::endl;

    }
    void Print(char c)
    {
        std::cout << c << "실행." << std::endl;
    }

    bool IsEmpty(const std::vector<char>& v)
    {
        return v.size() == 0;
    }

    
public:
    std::vector<char> undo;
    std::vector<char> redo;
};

