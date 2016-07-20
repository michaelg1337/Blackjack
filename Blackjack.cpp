#include <iostream>
#include "card.h"
#include "deck.h"
#include "Blackjack.h"
#include <vector>

using namespace std;

void Dealer::initialize(Deck &indeck) {
  dhand.clear();
  dhand.push_back(indeck.draw());
}

void Dealer::dealerturn(Deck &indeck) {
  while (calculateScore() < 17) {
    cout << "Dealer draws\n";
    dhand.push_back(indeck.draw());
    printHand();
  }
}

void Dealer::printHand() {
  cout << "Dealer's hand:\n";
  for (int i=0; i < dhand.size(); i++) {
    printcard(dhand[i]);
  }
  return;
}

int Dealer::calculateScore() {
  int score = 0;
  int aces = 0;
  for (int i=0; i < dhand.size(); i++) {
    if (dhand[i].cvalue < jack) {
      score += dhand[i].cvalue;
    }
    else if (dhand[i].cvalue == ace) {
      aces++;
    }
    else {
      score += 10;
    }
  }
  if (aces == 0)
    return score;
  else {
    while (aces != 0) {
      if (score + aces * 11 < 21) {
	score += aces * 11;
	return score;
      }
      else {
	score++;
	aces--;
      }
    }
  }
  return score;
}

void Dealer::printScore() {
  cout << "Dealer's score: " << calculateScore() << endl;
}

Player::Player() {
  money = 100;
}

void Player::initialize(Deck &indeck) {
  phand.clear();
  phand.push_back(indeck.draw());
  phand.push_back(indeck.draw());
  turn = true;
}

void Player::printHand() {
  cout << "Player's hand:\n";
  for (int i=0; i < phand.size(); i++) {
    printcard(phand[i]);
  }
  return;
}

int Player::calculateScore() {
  int score = 0;
  int aces = 0;
  for (int i=0; i < phand.size(); i++) {
    if (phand[i].cvalue < jack) {
      score += phand[i].cvalue;
    }
    else if (phand[i].cvalue == ace) {
      aces++;
    }
    else {
      score += 10;
    }
  }
  if (aces == 0)
    return score;
  else {
    while (aces != 0) {
      if (score + aces * 11 < 21) {
	score += aces * 11;
	return score;
      }
      else {
	score++;
	aces--;
      }
    }
  }
  return score;
}

void Player::playerturn(Deck &indeck) {
  cout << "Please make a choice (1=hit, 2=stand, 3=double down, 4=split)\n";
  int choice=0;
  while (choice < 1 or choice > 4)
    cin >> choice;
  switch (choice) {
  case 1:
    hit(indeck);
    break;
  case 2:
    stand(indeck);
    break;
  case 3:
    doubledown(indeck);
    break;
  case 4:
    split(indeck);
    break;
  }
}
  
void Player::hit(Deck &indeck) {
  phand.push_back(indeck.draw());
  if (calculateScore() > 21)
    turn = false;
}

void Player::stand(Deck &indeck) {
  turn = false;
}

void Player::doubledown(Deck &indeck) {
}

void Player::split(Deck &indeck){
}

void Player::printScore() {
  cout << "Player's score: " << calculateScore() << endl;
}

int Player::bet() {
  cout << "You have $" << money << ". How much would you like to bet?\n";
  int betamount;
  cin >> betamount;
  money -= betamount;
  return betamount;
}

void Player::winner(int moneywon) {
  money += moneywon;
}
