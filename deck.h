#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Deck {
 private:
  vector<card_t> vdeck;
 public:
  Deck();
  void shuffle();
  card_t draw();
};

#endif
