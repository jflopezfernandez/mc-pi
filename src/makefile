# Monte Carlo Simulation to approximate the value of PI

# Author: Jose Lopez
# Date: 22-June-2017
# License: The Unlicense


# ----- ----- Compiler Info ----- ----- 

CPP := g++
CPPFLAGS := -Wall -Wextra -Wpedantic -Werror


# ----- ----- Program Info ----- ----- 

PROGRAM := test

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))


# ----- ----- Program Compilation ----- ----- 

$(PROGRAM): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(PROGRAM) $(OBJS)

$(OBJS): $(SRCS)
	$(CPP) -c $(CPPFLAGS) $(SRCS)

clean:
	rm -rf $(wildcard *.o)
	rm -rf $(wildcard *.exe)