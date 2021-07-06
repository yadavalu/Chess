#include <SFML/Graphics.hpp>

#include <cmath>

#include "board.hh"

Board::Board()
{
    for (int i = 0; i < 64; i++) {
        this->squares[i] = new sf::CircleShape(75, 4);
        this->squares[i]->setPosition((i % 8) * 100 + 50, (std::floor(i/8)) * 100 - 50);
        this->squares[i]->setRotation(45);
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
    // Doesn't work
    for (int i = 0; i < 64; i++) {
        if (this->squares[i]->getPosition() == sf::Vector2f(pos)) {
            this->squares[i]->setFillColor(sf::Color::Blue);
            break;
        }
    }
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (int i = 0; i < 64; i++) target.draw(*this->squares[i], state);
}
