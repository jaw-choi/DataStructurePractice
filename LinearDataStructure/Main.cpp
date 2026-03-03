#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"

/*
입력 받아서 q에 계속 넣음
과 동시에 Undo에도 쌓음
undo하면 st.undo.top()을 print하고, redo에 쌓음
redo하면 st.redo.top()을 print하고, undo에 쌓음
입력 받으면 redo는 초기화 와 동시에 Undo에 쌓음
show 하면 undo redo 보여줌
*/
int main(void)
{
    std::string input;
    Queue q;
    Stack st;
    while (true)
    {
        std::cin >> input;
        if (input == "A" || input == "B" || input == "C" || input == "D" || input == "E" ||
            input == "a" || input == "b" || input == "c" || input == "d" || input == "e")
        {
            q.Push(input[0]);
            st.RedoPop();
            st.undo.push_back(input[0]);
        }
        else if (input == "undo" || input == "UNDO")
        {
            q.Deque();
            st.Undo(st.Top(st.undo));
            st.UndoPop();
            //q.Pop();
        }
        else if (input == "redo" || input == "REDO")
        {
            if (st.IsEmpty(st.redo))
            {
                std::cout << "redo is empty." << std::endl;
                continue;
            }
            st.Redo(st.Top(st.redo));
            q.Push(st.Top(st.redo));
            st.RedoPop();
        }
        else if (input == "show")
        {
            st.Show();
        }
        else
            continue;
        

        q.Print();
    }

    return 0;
}
