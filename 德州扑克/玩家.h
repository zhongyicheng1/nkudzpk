#pragma once
#include"����.h"
#include"card.h"
#include"pch.h"
#include"����.h"
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
    string playerName;  // �������
    string password;
    std::vector<card>hand;  // �������
    int chips;               // ��ҵ�ǰ����
    int currentBet = 0;      // ��ǰ�ִε���ע��
    bool isFolded = false;   // �Ƿ�����
    bool isAllIn = false;    // �Ƿ�ȫ��
};
