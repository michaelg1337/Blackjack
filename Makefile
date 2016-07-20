SOURCES = BJGame.cpp Blackjack.cpp deck.cpp card.cpp

game: $(SOURCES)
	g++ -o game $(SOURCES)
