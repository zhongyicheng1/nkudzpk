#pragma once
// Card.h
#ifndef CARD_H
#define CARD_H

struct card {
    int suit;  // ��ɫ
    int rank;  // ����
};
inline bool operator==(const card& a, const card& b) {
    return a.suit == b.suit && a.rank == b.rank;
}

#endif
