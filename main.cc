#include <SFML/Graphics.hpp>

#include <iostream>

#include "board.hh"
#include "pieces.hh"

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
    
    Board board;
    Pieces pieces;

    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        
        window.clear();
        window.draw(board);
        window.draw(pieces);
        window.display();
    }

    return 0;
}
