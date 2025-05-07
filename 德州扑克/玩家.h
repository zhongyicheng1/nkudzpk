#pragma once
#include"牌类.h"
#include"card.h"
#include"pch.h"
#include"牌类.h"
using namespace std;
#include<string>
#include <vector>
class player {
public:
    player(string  playerName1, string  password1);
    player();

    void goin();
    void bet(int comments);
    void AllIn();
    void backbet();
    void raise(int a);
    void call(int a);
    void check();
    void fold();
    void DealHand(std::vector<card>& hand);
    string playerName;  // 玩家名称
    string password;
    std::vector<card>hand;  // 玩家手牌
    int chips;               // 玩家当前筹码
    int currentBet = 0;      // 当前轮次的下注额
    bool isFolded = false;   // 是否弃牌
    bool isAllIn = false;    // 是否全下
};
