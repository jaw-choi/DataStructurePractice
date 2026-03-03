#include <iostream>
#include "BinarySearchTree.h"
#include "HashTable.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>




int main(void)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    BinarySearchTree bst("Jae", 100);
    HashTable ht;
    //BinarySearchTree bst;
    std::cout << "--------------------------------------------------------------------------\n";
    std::cout << " Binary Search Tree Practice \n\n";
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
    std::cout << "--------------------------------------------------------------------------\n";
    std::cout << " Hash Table Practice \n\n";
    if (!ht.LoadFromCSV("../players.csv"))
    {
        std::cout << "CSV load failed\n";
    }

    ht.Add("Jae", 99);
    ht.Add("Jaq", 92);
    ht.Add("Jaw", 39);
    ht.Find("JJJ");
    ht.Find("Jae");
    ht.Remove("JJJ");
    ht.Remove("Jae");
    ht.ShowList();


    return 0;
}