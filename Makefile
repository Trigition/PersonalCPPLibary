CC = g++
CFLAGS = -g
CPPSRC = $(wildcard src/*.cpp)
OBJ = $(CPPSRC:.cpp=.o)
DEP = $(OBJ:.o=.d) # One dependency file for each source

TestingKit: $(OBJ)
	$(CC) -o $@ $^

$.d: $.cpp
	@$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -fv $(OBJ) all

.PHONY: cleandep
cleandep:
	rm -fv $(DEP)
