CC = g++
CFLAGS = -O2
LFLAGS = -static -s
PROG = bin/harmonic
OBJS = obj/rational.o obj/main.o
HDRS = src/rational.hpp
DIRS = obj bin

$(PROG): $(OBJS)
	$(CC) -o $@ $^

obj/%.o: src/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : clean
clean:
	$(RM) $(PROG) $(OBJS)

$(shell mkdir -p $(DIRS))
