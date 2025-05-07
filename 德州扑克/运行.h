#pragma once

#include<iostream>
#include "pch.h"
#include <algorithm>
#include <unordered_set>
using namespace std;
#include"Íæ¼Ò.h";
#include"ÅÆÀà.h"
#include<vector>
#include"card.h"
bool compairhandtype(std::vector<card>& a, std::vector<card>& b);
#include<map>
enum GameResult {
    win,   
    lose,
    ti   
};
bool IsStraight(std::vector<card>& a);
bool IsStraightFlush(std::vector<card>& a);
bool IsFourOfAKind(std::vector<card>& a);
bool IsFullHouse(std::vector<card>& a);
bool IsFlush(std::vector<card>& a);
bool IsThreeOfAKind(std::vector<card>& a);
bool IsTwoPairs(std::vector<card>& a);
bool IsOnePair(std::vector<card>& a);
int evaluate1(std::vector<card>& a, std::vector<card>& b);