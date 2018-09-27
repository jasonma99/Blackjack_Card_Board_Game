
run:		compile
		./dice
		./cards
		
compile:	dice.cpp cards.cpp
	g++ dice.cpp -o dice
	g++ cards.cpp -o cards
	
clean:
	rm -f dice
	rm -f cards