#include "BinarySearchTree.h"
#include <string>
#include <iostream>
#include <set>
#include <functional>
#include <fstream>
#include <sstream>

BinarySearchTree::BinarySearchTree(std::string name, int score)
{
    
    root = new Node(name, score);
}

BinarySearchTree::~BinarySearchTree()
{
    Clear(root);
    root = nullptr;
}

void BinarySearchTree::Clear(Node* node)
{
    if (!node)
        return;
    Clear(node->left);
    Clear(node->right);
    delete node;
}

void BinarySearchTree::Insert(std::string name, int score)
{
    if (!root) {
        root = new Node(std::move(name), score);
        return;
    }

    Node* parent = nullptr;
    Node* curr = root;
    while (curr)
    {
        parent = curr;
        if (curr->playerName < name)
            curr = curr->right;        
        else        
            curr = curr->left;
        
    }
    curr = new Node(name, score);
    curr->parent = parent;

    if (curr->playerName < parent->playerName)
        parent->left = curr;
    else
        parent->right = curr;

}
bool BinarySearchTree::LoadFromCSV(const std::string& path)
{
    std::ifstream fin(path);
    if (!fin.is_open()) return false;

    std::string line;

    // 1) 첫 줄 헤더 처리 (playerName,score)
    if (!std::getline(fin, line)) return false;

    // 2) 데이터 줄 읽기
    while (std::getline(fin, line))
    {
        if (line.empty()) continue;

        // Windows CRLF 처리: 마지막에 '\r' 붙는 경우 제거
        if (!line.empty() && line.back() == '\r') line.pop_back();

        std::stringstream ss(line);
        std::string name, scoreStr;

        // CSV: name,score
        if (!std::getline(ss, name, ',')) continue;
        if (!std::getline(ss, scoreStr)) continue;

        // 공백이 섞인 경우 대비(선택)
        // name 앞뒤 공백 제거가 필요하면 Trim 함수 추가해서 적용해도 됨.

        int score = 0;
        try {
            score = std::stoi(scoreStr);
        }
        catch (...) {
            continue; // 숫자 변환 실패 줄은 스킵
        }

        Insert(name, score);
    }

    return true;
}
BinarySearchTree::Node* BinarySearchTree::Find(std::string name)
{
    std::cout << "Call Find()\n";
    Node* curr = root;
    while (curr)
    {
        if (curr->playerName == name)
        {
            std::cout << "There is \"" << name << "\"" << " with "<< curr->score<< std::endl;
            return curr;
        }
        if (curr->playerName < name)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    std::cout << "There is no \"" << name <<"\""<< std::endl;
    return nullptr;
}

void BinarySearchTree::Delete(std::string name)
{
    std::cout << "Call Delete()\n";

    Node* z = Find(name);
    if (!z)
    {
        std::cout << "There is no \"" << name << "\"" << std::endl;
        return;
    }
    if (z->left && z->right)
    {
        z = Minimum(z->right);
    }

    Node* child = z->left ? z->left : z->right;

    if (child)
        child->parent = z->parent;

    if (!z->parent) {
        root = child; // z가 root였던 경우
    }
    else if (z == z->parent->left) {
        z->parent->left = child;
    }
    else {
        z->parent->right = child;
    }
    std::cout << "Delete " << name << std::endl;
    delete z;
}

BinarySearchTree::Node* BinarySearchTree::Minimum(Node* node)
{
    if (!node->left && !node->right)
        return node;
    while (node && node->left)
    {
        node = node->left;
    }
    return node;
}

void BinarySearchTree::ChangeNode(Node*& a, Node*& b)
{
    Node* tmp = a;
    a = b;
    b = tmp;
}

void BinarySearchTree::putInfo(std::set<std::pair<int, std::string>, std::greater<std::pair<int, std::string>>>& s, Node* node)
{
    if (!node)
        return;
    s.insert(std::make_pair(node->score, node->playerName));
    if (node->left)
        putInfo(s, node->left);
    if (node->right)
        putInfo(s, node->right);
}


void BinarySearchTree::Top(int k)
{
    std::cout << "Call Top()\n";

    std::set<std::pair<int,std::string>,std::greater<std::pair<int,std::string>>> topSet;
    putInfo(topSet, root);
    std::cout << "탑 " << k << "의 이름과 점수입니다." << std::endl;
    for (const auto& s : topSet)
    {
        std::cout << s.second << "의 점수는 " << s.first <<" 점 입니다." << std::endl;
        k--;
        if (k == 0)
            return;
    }
}
