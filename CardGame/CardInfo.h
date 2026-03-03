#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>



struct Card {
    int id;
    std::string name;
    std::string type;   // "Spell" / "Unit"
    int cost;
    int rarity;
};

class CardInfo
{
public:
    CardInfo(const char* path) {
        std::ifstream fin(path);
        if (!fin.is_open()) {
            std::cout << "file open failed: " << path << "\n";
            return;
        }

        std::string line;

        // 1) 헤더 스킵
        if (!std::getline(fin, line)) return;

        // 2) 데이터 파싱
        while (std::getline(fin, line)) {
            if (line.empty()) continue;

            auto cols = split_csv(line);
            if (cols.size() != 5) continue;

            Card c;
            try {
                c.id = std::stoi(cols[0]);
                c.name = cols[1];
                c.type = cols[2];
                c.cost = std::stoi(cols[3]);
                c.rarity = std::stoi(cols[4]);
            }
            catch (...) {
                continue; // 숫자 변환 실패 등
            }

            cards.push_back(std::move(c));
        }
    }

private:

    static std::vector<std::string> split_csv(const std::string& line) {
        std::vector<std::string> out;
        std::string field;
        std::istringstream iss(line);

        while (std::getline(iss, field, ',')) {
            // 윈도우 CRLF(\r) 제거
            if (!field.empty() && field.back() == '\r') field.pop_back();
            out.push_back(field);
        }
        return out;
    }

public:
    std::vector<Card> cards;
};

