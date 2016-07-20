#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

enum suit_t {hearts, spades, clubs, diamonds};

enum value_t {two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

struct card_t {
  suit_t csuit;
  value_t cvalue;
};

void printcard(card_t incard);
    
#endif
