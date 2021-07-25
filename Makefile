CXX := g++
CXXFLAGS := -std=c++17 -g -IGraphics -IAI -I.
LDFLAGS := -lsfml-window -lsfml-graphics -lsfml-system

OBJS := main.o Graphics/board.o Graphics/pieces.o Graphics/places.o


chess: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) chess
