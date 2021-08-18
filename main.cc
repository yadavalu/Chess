#include <SFML/Graphics.hpp>

#include <iostream>
#include <cmath>

#include "board.hh"
#include "pieces.hh"
#include "places.hh"

#include "enumerate.hh"



int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(680, 480), "Chess");
    
    Board board;
    Pieces pieces;

    int moving_index;
    bool moving = false;

    unsigned int turn = WHITE;
    int white_points_int = 0, black_points_int = 0;

    sf::CircleShape white_turn_circle(5), black_turn_circle(5);
    white_turn_circle.setFillColor(sf::Color::White);
    white_turn_circle.setPosition(500, 420);
    black_turn_circle.setFillColor(sf::Color::Black);
    black_turn_circle.setPosition(500, 25);

    sf::Vector2i location, approx_pos;

    sf::Font font;
    font.loadFromFile("font/FiraCode-Light.ttf");

    sf::Text white_points, black_points;
    white_points.setFont(font);
    black_points.setFont(font);
    white_points.setString(sf::String(std::to_string(white_points_int)));
    black_points.setString(sf::String(std::to_string(black_points_int)));
    white_points.setPosition(825, 50);
    black_points.setPosition(825, 675);     

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2i pos;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
                pos = sf::Mouse::getPosition(window);
                std::string move = GetNotes(pos);
                location = GetLocations(move);
                std::cout << pos.x << ", " << pos.y << ": " << move << std::endl;
                
                if (!moving) {
                    approx_pos = location;
                    moving_index = pieces.GetPiece(turn, location);
                    if (moving_index == -1) break;
                    board.UpdateColours(location);

                    moving = true;
                } else {
                    int status = pieces.Move(turn, moving_index, location);
                    if (status == -1) {
                        moving = false;
                        board.SetColours();
                    } else if (status == -2) {
                        moving = false;
                        board.SetColours();
                    } else if (status == 0) {
                        board.UpdateColours(approx_pos, location);
                        turn++;
                        turn %= 2;
                        moving = false;
                    }
                }
            }

			if (event.type == sf::Event::Resized) {
                window.setSize(sf::Vector2u(680, 480));
            }
        }
        
        window.clear(sf::Color(50, 50, 50));
        window.draw(board);
        window.draw(pieces);
        turn ? window.draw(black_turn_circle): window.draw(white_turn_circle);
        window.display();
    }

    return 0;
}
