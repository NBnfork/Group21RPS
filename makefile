OBJS = main.o RPSGame.o utilities.o validInt.o validChar.o tool.o rock.o paper.o scissors.o
CC = g++
CFLAGS = -std=c++11 -c -Wall -g
LFLAGS = -std=c++11 -Wall -o

game.o: $(OBJS)
	$(CC) $(LFLAGS) game $(OBJS)

RPSGame.o: RPSGame.cpp
	$(CC) $(CFLAGS) RPSGame.cpp

utilities.o: utilities.cpp
	$(CC) $(CFLAGS) utilities.cpp

validInt.o: validInt.cpp
	$(CC) $(CFLAGS) validInt.cpp

validChar.o: validChar.cpp
	$(CC) $(CFLAGS) validChar.cpp

tool.o: tool.cpp
	$(CC) $(CFLAGS) tool.cpp

rock.o: rock.cpp
	$(CC) $(CFLAGS) rock.cpp

paper.o: paper.cpp
	$(CC) $(CFLAGS) paper.cpp

scissors.o: scissors.cpp
	$(CC) $(CFLAGS) scissors.cpp

clean: 
	rm *.o

