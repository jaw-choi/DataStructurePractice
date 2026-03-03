#include "CardInfo.h"
#include <conio.h>

int getArrowKey()
{
    int ch = _getch();

    if (ch == 224) {
        return _getch();
    }
    return ch;
}

void printCard(const Card& c)
{
    system("cls");  // 화면 지우기 (Windows)
    std::cout << "ID: " << c.id << "\n";
    std::cout << "Name: " << c.name << "\n";
    std::cout << "Type: " << c.type << "\n";
    std::cout << "Cost: " << c.cost << "\n";
    std::cout << "Rarity: " << c.rarity << "\n";
    std::cout << "\n← → 로 이동, ESC 종료\n";
}

int main(void)
{
    const char* path = "../cardInfo.csv";
    CardInfo card(path);
    int index = 0;
    int _size = card.cards.size();
    printCard(card.cards[0]);

    while (true)
    {
        int key = _getch();

        if (key == 27) break; // ESC 종료

        if (key == 224)
        {
            key = _getch();

            if (key == 77) // →
            {
                if (index < _size)
                    index++;
                if (index == _size)
                    index = 0;
            }
            else if (key == 75) // ←
            {
                if (index >= 0)
                    index--;
                if (index == -1)
                    index = _size-1;
            }

            printCard(card.cards[index]);
        }
    }
    return 0;
}