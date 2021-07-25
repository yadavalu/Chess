#ifndef __BOARD_CHESS_HH__
#define __BOARD_CHESS_HH__

#include <SFML/Graphics.hpp>

class Board : public sf::Drawable
{
public:
    Board();
    ~Board();

    void SetColours();
    void UpdateColours(sf::Vector2i pos);
    void UpdateColours(sf::Vector2i pos1, sf::Vector2i pos2);

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    sf::RectangleShape *squares[64];
};

#endif 
