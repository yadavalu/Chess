#ifndef __SINGLE_PIECE_CHESS_HH__
#define __SINGLE_PIECE_CHESS_HH__

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

class SPiece
{
public:
    SPiece();
    ~SPiece();

    void Constructor(int, int, std::string);
    void Constructor(int, int, sf::Vector2i);

    void Remove(int);
    void Move(sf::Vector2i);

    sf::Sprite GetSprite() const;
    int GetColour() const;
    int GetType() const;
    int GetPosition() const;

private:
    int colour, type, position_int;
    std::string position;
    sf::Vector2i position_vector;
    std::vector<int> valid_moves;

    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
