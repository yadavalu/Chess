#include "pieces.hh"
#include "piece.hh"
#include "enumerate.hh"

#include <string>

Pieces::Pieces()
{
    // Black
    const char *letters = "ABCDEFGH";
    
    for (int i = 0; i < 8; i++) pieces_black[i].Constructor(BLACK, PAWN, sf::Vector2i(60 * i, 60));
    pieces_black[8].Constructor(BLACK, ROOK, "A8");
    pieces_black[9].Constructor(BLACK, KNIGHT, "B8"); 
    pieces_black[10].Constructor(BLACK, BISHOP, "C8");
    pieces_black[11].Constructor(BLACK, QUEEN, "D8");
    pieces_black[12].Constructor(BLACK, KING, "E8");
    pieces_black[13].Constructor(BLACK, BISHOP, "F8");
    pieces_black[14].Constructor(BLACK, KNIGHT, "G8");
    pieces_black[15].Constructor(BLACK, ROOK, "H8");

    // White
    for (int i = 0; i < 8; i++) pieces_white[i].Constructor(WHITE, PAWN, sf::Vector2i(60 * i, 360));
    pieces_white[8].Constructor(WHITE, ROOK, "A1");
    pieces_white[9].Constructor(WHITE, KNIGHT, "B1");
    pieces_white[10].Constructor(WHITE, BISHOP, "C1");
    pieces_white[11].Constructor(WHITE, QUEEN, "D1");
    pieces_white[12].Constructor(WHITE, KING, "E1");
    pieces_white[13].Constructor(WHITE, BISHOP, "F1");
    pieces_white[14].Constructor(WHITE, KNIGHT, "G1");
    pieces_white[15].Constructor(WHITE, ROOK, "H1");
    
    removed_white = 0;
    removed_black = 0;
}

int Pieces::GetPiece(int colour, sf::Vector2i _position)
{
    if (colour == BLACK) {
        for (int i = 0; i < 16; i++) {
            if (pieces_black[i].GetSprite().getPosition() == sf::Vector2f(_position)) {
                return i;
            }
        }
    } else {
        for (int i = 0; i < 16; i++) {
            if (pieces_white[i].GetSprite().getPosition() == sf::Vector2f(_position)) {
                return i;
            }
        }
    }
}

int Pieces::Move(int colour, int index, sf::Vector2i newpos)
{
    if (colour == BLACK) {
        for (int i = 0; i < 16; i++) {
            if (pieces_black[i].GetSprite().getPosition() == sf::Vector2f(newpos)) return -1;
            else if (pieces_white[i].GetSprite().getPosition() == sf::Vector2f(newpos)) {
                pieces_white[i].Remove(removed_white);
                break;
            }
        }
        pieces_black[index].Move(newpos);
    } else {
        for (int i = 0; i < 16; i++) {
            if (pieces_white[i].GetSprite().getPosition() == sf::Vector2f(newpos)) return -1;
            else if (pieces_black[i].GetSprite().getPosition() == sf::Vector2f(newpos)) {
                pieces_black[i].Remove(removed_black);
                break;
            }
        }
        pieces_white[index].Move(newpos);
    }
}

void Pieces::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (int i = 0; i < 16; i++) {
        target.draw(pieces_white[i].GetSprite(), state);
        target.draw(pieces_black[i].GetSprite(), state);
    }
}

