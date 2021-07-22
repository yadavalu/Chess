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
    int white_points_int = 0, black_points_int = 0;

    sf::CircleShape white_turn_circle(10), black_turn_circle(10);
    white_turn_circle.setFillColor(sf::Color::White);
    white_turn_circle.setPosition(825, 700);
    black_turn_circle.setFillColor(sf::Color::Black);
    black_turn_circle.setPosition(825, 25);

    sf::RectangleShape selected(sf::Vector2f(100, 100));
    selected.setFillColor(sf::Color(0, 0, 0, 100));

    /*
     * TODO

    sf::Font font;
    font.loadFromFile("font/FiraCode-Light.ttf");

    sf::Text white_points, black_points;
    white_points.setFont(font);
    black_points.setFont(font);
    white_points.setString('0');//sf::String((char) white_points_int));
    black_points.setString('0');//sf::String((char) black_points_int));
    white_points.setPosition(825, 50);
    black_points.setPosition(825, 675);
     */

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
                            selected.setPosition(sf::Vector2f(GetLocations(move)));
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
        
        window.clear(sf::Color(50, 50, 50));
        window.draw(board);
        if (moving) window.draw(selected);
        window.draw(pieces);
        turn ? window.draw(black_turn_circle):window.draw(white_turn_circle);
        window.display();
    }

    return 0;
}
