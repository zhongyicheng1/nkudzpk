#pragma once
// Card.h
#ifndef CARD_H
#define CARD_H

struct card {
    int suit;  // 花色
    int rank;  // 点数
};
inline bool operator==(const card& a, const card& b) {
    return a.suit == b.suit && a.rank == b.rank;
}

#endif
