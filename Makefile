CXX := g++
CXXFLAGS := -std=c++17 -g -IUI -IAI -I.
LDFLAGS := -lsfml-window -lsfml-graphics -lsfml-system

OBJS := main.o UI/board.o UI/pieces.o UI/places.o


chess: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) chess
