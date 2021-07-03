#ifndef __PIECES_CHESS_HH__
#define __PIECES_CHESS_HH__

#include <SFML/Graphics.hpp>

#include <vector>

class Pieces : public sf::Drawable
{
public:
    Pieces();

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    std::vector<sf::Texture> white_textures;
    std::vector<sf::Sprite> white_sprites;

    std::vector<sf::Texture> black_textures;
    std::vector<sf::Sprite> black_sprites;
};

#endif
