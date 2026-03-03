#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

bool HashTable::LoadFromCSV(const std::string& path)
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

        Add(name, score);
    }

    return true;
}
// 해시 함수(Hash Function). hash는 숫자임.
// 키를 어떠한 과정을 통해서 숫자로 변환 해주는 함수.
// 여기 붙이는 static은 전역이 아니라 이 파일에서만 사용할 수 있는 함수라는 의미.(private)
static int GenerateHash(const std::string& keyString)
{
    // 출력할 해시 변수 선언.
    int hash = 0;

    // 문자열을 문자 배열로 활용해 해시 생성.
    const int length = static_cast<int>(keyString.length());

    for (int i = 0; i < length; ++i)
    {
        // 해시 생성 로직
        // hash += keyString[i] * (i + 1);

        // Java방식, Hornor's Method: hash = hash * 31 + keyString[i];
        hash = hash * 31 + keyString[i];    //
    }

    // 배열의 인덱스로 사용할것임.
    // 오버플로우 방지 위해 절댓값으로 반환
    return std::abs(hash);
}


bool HashTable::Find(std::string key)
{
    int num = GenerateHash(key) % bucketCount;
    int n = table[num].size();
    for (int i = 0; i < n; i++)
    {
        if (table[num][i].first == key)
        {
            std::cout << "Find " << key << ", and its value is " << table[num][i].second << "\n";
            return true;
        }
    }
    std::cout << "There is no " << key << "\n";
    return false;
}

void HashTable::Add(std::string name, int value)
{
    table[GenerateHash(name) % bucketCount].emplace_back(std::make_pair(name, value));
    std::cout << "Add < " << name << ", " << value << " >" << "\n";
}

void HashTable::Remove(std::string name)
{
    if (!Find(name))
        return;
    //Delete
    int num = GenerateHash(name) % bucketCount;
    int n = table[num].size();
    for (int i = 0; i < n; i++)
    {
        if (table[num][i].first == name)
        {
            // Swap pop
            std::swap(table[num][i], table[num].back());
            table[num].pop_back();
        }
    }
    std::cout << "Delete " << name << "\n";
}

void HashTable::ShowList()
{
    for (int i = 0; i < bucketCount; i++)
    {
        if (table[i].size() == 0)
            continue;
        std::cout << "Bucket " << i << ": \n";
        for (int j = 0; j < table[i].size(); j++)
        {
            std::cout << "key: " << table[i][j].first << ", value: " << table[i][j].second << "\n";
        }
        std::cout << "\n";
    }
}
