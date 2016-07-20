#include <iostream>
#include "card.h"
#include "deck.h"
#include "Blackjack.h"

using namespace std;

int main() {
  Player p1;
  Dealer d1;
  Deck maindeck;
  bool again = true;
  int pot;
  while (again) {
    d1.initialize(maindeck);
    p1.initialize(maindeck);
    pot = 2* p1.bet();
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
    if (p1.calculateScore() > 21) {
      cout << "Bust! You lose.\n";
    }
    else {
      d1.dealerturn(maindeck);
      cout << "Dealer's final score: " << d1.calculateScore() << " || Your Score: " << p1.calculateScore() << endl;
      if (d1.calculateScore() > 21) {
	cout << "Dealer bust! You win!\n";
	p1.winner(pot);
      }
      else if (p1.calculateScore() > d1.calculateScore()) {
	cout << "You win!\n";
	p1.winner(pot);
      }
      else {
	cout << "You lose.\n";
      }
    }
    cout << "Play again? (1 for yes, 0 for no)\n";
    cin >> again;
  }
}
