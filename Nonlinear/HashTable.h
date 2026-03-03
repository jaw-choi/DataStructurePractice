#pragma once
#include <string>
#include <vector>

/*
*- HashTable 직접 구현 (배열 + 충돌 처리)
- 문자열 키 처리 (아이템 이름)
- 동작
    - find [name] → 검색 후 정보 출력.
        - add [name] [type] [value] → 아이템 추가.
    - remove [name] → 이름으로 검색 후 삭제.
    - list → 아이템 목록 출력.
- 권장
    - 아이템 데이터를 직접 추가하는 형태로 구현하기 보다는 AI
    (Gemini 등)를 활용해서 텍스트 기반 데이터(csv 권장)를 생성한 후에
    텍스트 데이터를 파싱해서 동작하도록 구현
*/
class HashTable
{
public:
    HashTable();
    ~HashTable();
public:
    bool LoadFromCSV(const std::string& path);
    bool Find(std::string key);
    void Add(std::string name, int value);
    void Remove(std::string name);
    void ShowList();
private:
    static const int bucketCount = 13;
    std::vector<std::pair<std::string, int>> table[bucketCount];
};

