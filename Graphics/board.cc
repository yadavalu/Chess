#include <SFML/Graphics.hpp>

#include <iostream>
#include <cmath>

#include "board.hh"

Board::Board()
{
    for (int i = 0; i < 64; i++) {
        this->squares[i] = new sf::RectangleShape(sf::Vector2f(60, 60));
        this->squares[i]->setPosition((i % 8) * 60, (std::floor(i/8)) * 60);
        if (i % 2 == ((int) i/8) % 2) this->squares[i]->setFillColor(sf::Color(250, 205, 170));
        else this->squares[i]->setFillColor(sf::Color(170, 128, 96));
    }
}

Board::~Board() 
{
}

void Board::SetColours()
{
    for (int i = 0; i < 64; i++) {
        if (i % 2 == ((int) i/8) % 2) this->squares[i]->setFillColor(sf::Color(250, 205, 170));
        else this->squares[i]->setFillColor(sf::Color(170, 128, 96));
    }
}

void Board::UpdateColours(sf::Vector2i pos)
{
    for (int i = 0; i < 64; i++) {
        if (this->squares[i]->getPosition() == sf::Vector2f(pos)) {
            this->squares[i]->setFillColor(sf::Color(50, 50, 50));
            break;
        }
    }
}

void Board::UpdateColours(sf::Vector2i pos1, sf::Vector2i pos2)
{
    for (int i = 0; i < 64; i++) {
        if (this->squares[i]->getPosition() == sf::Vector2f(pos1)) {
            this->squares[i]->setFillColor(sf::Color(0, 175, 0));
            //std::cout << "pos1 index: " << i << std::endl;
        }

        if (this->squares[i]->getPosition() == sf::Vector2f(pos2)) {
            this->squares[i]->setFillColor(sf::Color(0, 150, 0));
            //std::cout << "pos2 index: " << i << std::endl;
        }
    }
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (int i = 0; i < 64; i++) target.draw(*this->squares[i], state);
}
