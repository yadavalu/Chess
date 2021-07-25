#include <SFML/Graphics.hpp>

#include <iostream>

#include "board.hh"
#include "pieces.hh"
#include "places.hh"

#include "enumerate.hh"


int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(680, 480), "Chess");
    
    Board board;
    Pieces pieces;
    pieces.PairLocation();
    pieces.SetLocation();

    int moving_index;
    bool moving = false;

    unsigned int turn = WHITE;
    int white_points_int = 0, black_points_int = 0;

    sf::CircleShape white_turn_circle(5), black_turn_circle(5);
    white_turn_circle.setFillColor(sf::Color::White);
    white_turn_circle.setPosition(500, 420);
    black_turn_circle.setFillColor(sf::Color::Black);
    black_turn_circle.setPosition(500, 25);

    sf::Vector2i approx_pos_1, approx_pos_2;

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
                
                
                std::vector<std::string> locations = 
                        (turn == WHITE ? pieces.GetWhiteLocations():pieces.GetBlackLocations());

                for (unsigned int i = 0; i < locations.size(); i++) {
                    if (!moving) {
                        if (locations[i] == move) {
                            moving_index = i;
                            moving = true;
                            approx_pos_1 = GetLocations(move);
                            board.UpdateColours(approx_pos_1);
                            std::cout << "approx_pos_1: " << approx_pos_1.x << ", " << approx_pos_1.y << std::endl;
                            break;
                        }
                    } else {
                        std::vector<std::string> o_locations = 
                                (turn == BLACK ? pieces.GetWhiteLocations(): pieces.GetBlackLocations());
                        std::vector<std::string> oo_locations = 
                                (turn == WHITE ? pieces.GetWhiteLocations(): pieces.GetBlackLocations());

                        for (int i = 0; i < o_locations.size(); i++) {
                            if (o_locations[i] == move) {
                                pieces.Remove(i, !turn);
                                break;
                            }

                            if (oo_locations[i] == move) {
                                moving = false;
                                break;
                            }
                        }

                        board.SetColours();
                        if (moving) {
                            approx_pos_2 = GetLocations(move);
                            std::cout << "approx_pos_2: " << approx_pos_2.x << ", " << approx_pos_2.y << std::endl;
                        
                            pieces.Move(turn, moving_index, sf::Vector2f(approx_pos_2));
                            board.UpdateColours(approx_pos_1, approx_pos_2);
                            moving = false;
                            turn++;
                            turn = turn % 2;
                        }
                    }
                }
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
