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

    void Move(int, int, sf::Vector2f);
    void Remove(int, int);

    std::vector<sf::Sprite> GetWhiteSprites();
    std::vector<std::string> GetWhiteLocations();
    std::vector<sf::Sprite> GetBlackSprites();
    std::vector<std::string> GetBlackLocations();

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    std::vector<sf::Texture> white_textures, black_textures;
    std::vector<sf::Sprite> white_sprites, black_sprites;

    std::vector<std::string> white_locations, black_locations;

    int removed_white, removed_black;
};

#endif
