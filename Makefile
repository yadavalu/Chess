CXX := g++
CXXFLAGS := -std=c++17 -g
LDFLAGS := -lGL -lGLU -lglfw

OBJS := main.o board.o


chess: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) chess
