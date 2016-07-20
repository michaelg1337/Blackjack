#include <vector>
#include <cstdlib>
#include <ctime>
#include "deck.h"
#include "card.h"

using namespace std;

Deck::Deck() {
  srand(time(NULL));
  for (int i=0; i < 4; i++) {
    for (int j=2; j < 15; j++) {
      card_t newcard;
      newcard.csuit = static_cast<suit_t>(i);
      newcard.cvalue = static_cast<value_t>(j);
      vdeck.push_back(newcard);
    }
  }
}

void Deck::shuffle() {
  vdeck.clear();
  for (int i=0; i < 4; i++) {
    for (int j=2; j < 15; j++) {
      card_t newcard;
      newcard.csuit = static_cast<suit_t>(i);
      newcard.cvalue = static_cast<value_t>(j);
      vdeck.push_back(newcard);
    }
  }
}

card_t Deck::draw() {
  if (vdeck.size() == 0)
    shuffle();
  int picker = rand()%vdeck.size();
  card_t output = vdeck[picker];
  vdeck.erase(vdeck.begin()+picker);
  return output;
}
