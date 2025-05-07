#include "pch.h"
#include "牌类.h"
using namespace std;
Cpoker::Cpoker()
{
    cards.clear();//清空牌组;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 2; rank <= 14; rank++) {
            cards.push_back({ suit, rank });
        }
    }
}

void Cpoker::printcards(const std::vector<card>& cards)
{
        for ( auto& card : cards) {
           cout << "(" << card.suit  << ", " << card.rank << ") ";
        }
       cout << endl;
}

void Cpoker::Fisher_Yates( std::vector<card>& cards)
{
    random_device rd;
    mt19937 g(rd());
    for (int i = cards.size() - 1; i > 0; i--) {
        uniform_int_distribution<int> dis(0, i);
        int j = dis(g);
        swap(cards[i], cards[j]);
    }
}
void Cpoker::deliverCards(int numCards, std::vector<card>& destination) {


    for (int i = 0; i < numCards; i++) {
        destination.push_back(cards.back());  // 从牌组顶部抽取牌
        cards.pop_back();  // 移除抽取的牌
    }
}

