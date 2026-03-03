#include <iostream>
#include "BinarySearchTree.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>




int main(void)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    BinarySearchTree bst("Jae", 100);
    //BinarySearchTree bst;
    if (!bst.LoadFromCSV("../players.csv"))
    {
        std::cout << "CSV load failed\n";
    }

    bst.Find("a");
    std::cout << "\n";

    bst.Find("Tina");
    std::cout << "\n";

    bst.Delete("Aron");
    std::cout << "\n";
    bst.Delete("g");

    bst.Top(100);
    std::cout << "\n";

    bst.Delete("Jae");
    std::cout << "\n";


    return 0;
}