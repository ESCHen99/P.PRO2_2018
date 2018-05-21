OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.x: program.o warehouse.o Sala.o inventory.o
	g++ -o program.x *.o 

warehouse.o: warehouse.cc Warehouse.hh Sala.hh Inventory.hh
	g++ -c warehouse.cc $(OPCIONS) 

Sala.o: Sala.cc Sala.hh Inventory.hh
	g++ -c Sala.cc $(OPCIONS) 

inventory.o: inventory.cc Inventory.hh
	g++ -c inventory.cc $(OPCIONS) 

program.o: program.cc Warehouse.hh Inventory.hh
	g++ -c program.cc $(OPCIONS) 

clean:
	rm *.o
	rm *.x
