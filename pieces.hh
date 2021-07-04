#ifndef __PIECES_CHESS_HH__
#define __PIECES_CHESS_HH__

#include <SFML/Graphics.hpp>

#include <vector>
#include <utility>

class Pieces : public sf::Drawable
{
public:
    Pieces();
    void SetLocation();
    void PairLocation();

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    std::vector<sf::Texture> white_textures, black_textures;
    std::vector<sf::Sprite> white_sprites, black_sprites;

    std::vector<std::pair<std::pair<int, int>, char *>> locations;
    std::vector<std::pair<sf::Sprite, char *>> black, white;
};

#endif
