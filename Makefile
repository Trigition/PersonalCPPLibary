CC = g++
CFLAGS = -g -Wall
CPPSRC = $(wildcard src/*.cpp)
OBJ = $(CPPSRC:.cpp=.o)
DEP = $(OBJ:.o=.d) # One dependency file for each source

TestingKit: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$.d: $.cpp
	@$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -fv $(OBJ) all
	rm -rvf *.dSYM

.PHONY: cleandep
cleandep:
	rm -fv $(DEP)
