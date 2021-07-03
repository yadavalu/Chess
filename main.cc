#include <SFML/Graphics.hpp>

#include <iostream>

#include "board.hh"

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
    
    Board board;

    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        
        window.clear();
        window.draw(board);
        window.display();
    }

    return 0;
}
