#include <SFML/Graphics.hpp>

#include <iostream>

#include "board.hh"
#include "pieces.hh"
#include "places.hh"

#define WHITE 0
#define BLACK 1

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Chess");
    
    Board board;
    Pieces pieces;
    pieces.PairLocation();
    pieces.SetLocation();

    int moving_index;
    bool moving = false;

    unsigned int turn = WHITE;

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2i pos;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
                pos = sf::Mouse::getPosition(window);
                std::string move = GetNotes(pos);
                std::cout << pos.x << ", " << pos.y << ": " << move << std::endl;
                
                // Causes SIGSEGV
                board.UpdateColours(pos);
                
                std::vector<std::string> locations = 
                        (turn == WHITE ? pieces.GetWhiteLocations():pieces.GetBlackLocations());

                for (unsigned int i = 0; i < locations.size(); i++) {
                    if (!moving) {
                        if (locations[i] == move) {
                            moving_index = i;
                            moving = true;
                            break;
                        }
                    } else {
                        std::vector<std::string> o_locations = 
                                (turn == BLACK ? pieces.GetWhiteLocations():pieces.GetBlackLocations());
                        for (int i = 0; i < o_locations.size(); i++) {
                            if (o_locations[i] == move) {
                                pieces.Remove(i, !turn);
                                break;
                            }
                        }
                        pieces.Move(turn, moving_index, sf::Vector2f(GetLocations(move)));
                        board.SetColours();
                        moving = false;
                        turn++;
                        turn = turn % 2;
                    }
                }
            }
        }
        
        window.clear();
        window.draw(board);
        window.draw(pieces);
        window.display();
    }

    return 0;
}
