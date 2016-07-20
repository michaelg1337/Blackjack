#ifndef BJ_H
#define BJ_H

#include <iostream>
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;

class Dealer {
 private:
  vector<card_t> dhand;
 public:
  void initialize(Deck &indeck);
  void dealerturn(Deck &indeck);
  void printHand();
  int calculateScore();
  void printScore();
};

class Player {
 private:
  vector<card_t> phand;
  int money;
 public:
  Player();
  bool turn;
  void initialize(Deck &indeck);
  void printHand();
  int calculateScore();
  void playerturn(Deck &indeck);
  void hit(Deck &indeck);
  void stand(Deck &indeck);
  void doubledown(Deck &indeck);
  void split(Deck &indeck);
  void printScore();
  int bet();
  void winner(int moneywon);
};

#endif
