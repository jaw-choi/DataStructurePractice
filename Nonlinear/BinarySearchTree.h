#pragma once
#include <string>
#include <set>


class BinarySearchTree
{
    struct Node
    {
        std::string playerName;
        int score;
        Node* parent;
        Node* left;
        Node* right;
    };
public:
    BinarySearchTree(std::string name, int score);
    ~BinarySearchTree();

    void Clear(Node* node);
    void Insert(std::string name, int score);
    bool LoadFromCSV(const std::string& path);
    Node* Find(std::string name);
    void Delete(std::string name);
    Node* Minimum(Node* node);
    void ChangeNode(Node*& a, Node*& b);
    void putInfo(std::set<std::pair<int, std::string>, std::greater<std::pair<int, std::string>>>& s,
        Node* node);
    void Top(int k);
private:
    Node* root;

    static const int Capacity = 100;
};

