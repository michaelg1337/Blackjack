#include <iostream>
#include "card.h"
#include "deck.h"
#include "Blackjack.h"

using namespace std;

int main() {
  Player p1;
  Dealer d1;
  Deck maindeck;
  d1.initialize(maindeck);
  p1.initialize(maindeck);
  p1.printHand();
  p1.printScore();
  d1.printHand();
  d1.printScore();
  while (p1.turn == true) {
    p1.playerturn(maindeck);
    p1.printHand();
    p1.printScore();
    d1.printHand();
    d1.printScore();
  }
}
