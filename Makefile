# Parts of this file were taken for the makefile lecture in Module 1.
# Parts were also used from the example written by TA Harlan James. 

#target: dependencies
#	rule to build

PROJ = game

ASSIGN = Group21_Group_Project

SRCS = main.cpp paper.cpp rock.cpp RPSGame.cpp scissors.cpp tool.cpp utilities.cpp validChar.cpp validInt.cpp


#HEADERS =  inputValidation.hpp useMenu.hpp getMenuChoice.hpp

OBJS = ${SRCS:.cpp=.o}

CXX = g++

CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

VALGRINDOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

${PROJ}: ${OBJS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o ${PROJ}
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${SRCS} 


.PHONY: clean zip debug

debug: ${PROJ}
	valgrind ${VALGRINDOPT} ./${PROJ}
	 
clean: 
	@echo "RM                *o"
	@echo "RM 		${PROJ}"
	@rm -f *.o ${PROJ}

zip:
	zip ${ASSIGN}_Buchen_Noah *.cpp *.hpp *.pdf makefile


