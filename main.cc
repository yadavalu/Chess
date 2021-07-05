#include <SFML/Graphics.hpp>

#include <iostream>

#include "board.hh"
#include "pieces.hh"
#include "places.hh"

#define WHITE 0
#define BLACK 1

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
    
    Board board;
    Pieces pieces;
    pieces.SetLocation();

    sf::Sprite sp_moving;
    bool moving;

    unsigned int turn = WHITE;

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2i pos;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
                // TODO: Pieces don't move
                pos = sf::Mouse::getPosition(window);
                std::string move = GetNotes(pos);
                std::cout << pos.x << ", " << pos.y << ": " << move << std::endl;
                
                std::vector<std::string> locations = 
                        (turn == WHITE ? pieces.GetWhiteLocations():pieces.GetBlackLocations());

                for (unsigned int i = 0; i < locations.size(); i++) {
                    if (!moving) if (locations[i] == move) sp_moving = pieces.GetWhiteSprites()[i];
                    else {
                        sp_moving.setPosition(sf::Vector2f(GetLocations(move)));
                        moving = false;
                        turn = BLACK;
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
