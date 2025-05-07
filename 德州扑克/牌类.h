#pragma once
#include"card.h"
#include <algorithm>  // std::shuffle
#include <random>     // 随机数生成器
#include <vector>
class Cpoker {
public:
	Cpoker();
	void printcards(const std::vector<card>& cards);
	std::vector<card>cards;
	void Fisher_Yates( std::vector<card>& cards);
	void deliverCards(int numCards, std::vector<card>& destination);
};