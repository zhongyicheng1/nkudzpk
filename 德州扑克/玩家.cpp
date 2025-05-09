#include "pch.h"
#include "Íæ¼Ò.h"
Cpoker poker1;
player::player(string playerName1, string password1)
{
	playerName = playerName1;
	password = password1;
	chips = 1500;
}
player::player()
{
	chips = 2500;
}



void player::AllIn()
{
	currentBet = chips;
	chips = 0;
	isAllIn = true;
	cout << " showhand " << currentBet<<"money" << endl;

}

void player::backbet()
{
	chips = chips - 100;
	currentBet = 100;
}

void player::raise(int a)
{
	if (a == 0) {
		chips -= 200;
		currentBet = 200;
	}
	else {
		chips = chips - 2 * a;
		currentBet = 2 * a;
	}
}

void player::call(int a)
{
	if (a == 0) {
		chips -= 100;
		currentBet = 100;
	}
	else {
		chips = chips - a;
		currentBet = a;
	}
}

void player::check()
{
	currentBet = 0;
}

void player::fold()
{
		isFolded = true;
		

}

void player::DealHand(std::vector<card>& hand)
{
	poker1.deliverCards(2, hand);
}


