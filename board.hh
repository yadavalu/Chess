#ifndef __BOARD_CHESS_HH__
#define __BOARD_CHESS_HH__

#include <SFML/Graphics.hpp>

class Board : public sf::Drawable
{
public:
    Board();
    ~Board();

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

    sf::CircleShape *squares[64];
};

#endif 
