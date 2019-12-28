#Makefile for Writing Make Files Example
# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -Werror -g

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o ticTacToe.o
	$(CXX) $(CXXFLAGS) -o main main.o ticTacToe.o

# The main.o target can be written more simply

main.o: main.cpp ticTacToe.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

ticTacToe.o: ticTacToe.hpp

clean:
	rm main *.o
