#include "card.h"
#include <iostream>

using namespace std;


void printcard(card_t incard) {
  switch (incard.csuit) {
  case hearts:
    cout << "H";
    break;
  case spades:
    cout << "S";
    break;
  case diamonds:
    cout << "D";
    break;
  case clubs:
    cout << "C";
    break;
  }
  switch (incard.cvalue) {
  case two:
    cout << "2";
    break;
  case three:
    cout << "3";
    break;
  case four:
    cout << "4";
    break;
  case five:
    cout << "5";
    break;
  case six:
    cout << "6";
    break;
  case seven:
    cout << "7";
    break;
  case eight:
    cout << "8";
    break;
  case nine:
    cout << "9";
    break;
  case ten:
    cout << "T";
    break;
  case jack:
    cout << "J";
    break;
  case queen:
    cout << "Q";
    break;
  case king:
    cout << "K";
    break;
  case ace:
    cout << "A";
    break;
  }
  cout << endl;
  return;
}
