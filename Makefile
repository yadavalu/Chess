CXX := g++
CXXFLAGS := -std=c++17 -g
LDFLAGS := -lsfml-window -lsfml-graphics -lsfml-system

OBJS := main.o board.o pieces.o


chess: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) chess
