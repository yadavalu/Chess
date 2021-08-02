#ifndef __PIECES_CHESS_HH__
#define __PIECES_CHESS_HH__

#include <SFML/Graphics.hpp>

#include <vector>
#include <array>
#include <utility>

#include "piece.hh"

class Pieces: public sf::Drawable
{
public:
    Pieces();
    void SetLocation();
    void PairLocation();

    int GetPiece(int, sf::Vector2i);
    int Move(int, int, sf::Vector2i);

    std::array<SPiece, 16> GetPiecesArray(int) const;

    std::vector<int> PossibleMoves(SPiece);
    std::vector<int> PossibleTake(SPiece);

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    std::array<SPiece, 16> pieces_white, pieces_black;
    int removed_white, removed_black;
};

#endif
