#include "pieces.hh"
#include "piece.hh"
#include "places.hh"
#include "enumerate.hh"

#include <string>
#include <cmath>
#include <iostream>

Pieces::Pieces()
{
    // Black    
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

    return -1;
}


// TODO

/*
 * Returns 0 if move is valid
 * Returns -1 if piece wasn't clicked
 * Returns -2 if move is invalid
 */
int Pieces::Move(int colour, int index, sf::Vector2i newpos)
{
    if (colour == BLACK) {
        bool moved = false;
        for (int& i: PossibleMoves(pieces_black[index])) {
            if (i == GetIntLocation(newpos)) {
                pieces_black[index].Move(newpos);
                moved = true;
                break;
            }
        }
        if (!moved) return -2;

        for (int i = 0; i < 16; i++) {
            if (pieces_black[i].GetSprite().getPosition() == sf::Vector2f(newpos)) return -1;
            else if (pieces_white[i].GetSprite().getPosition() == sf::Vector2f(newpos)) {
                pieces_white[i].Remove(removed_white);
                removed_white++;
                break;
            }
        }
    } else {
        bool moved = false;
        for (int& i: PossibleMoves(pieces_white[index])) {
            if (i == GetIntLocation(newpos)) {
                pieces_white[index].Move(newpos);
                moved = true;
                break;
            }
        }
        if (!moved) return -2;

        for (int i = 0; i < 16; i++) {
            if (pieces_white[i].GetSprite().getPosition() == sf::Vector2f(newpos)) return -1;
            else if (pieces_black[i].GetSprite().getPosition() == sf::Vector2f(newpos)) {
                pieces_black[i].Remove(removed_black);
                removed_black++;
                break;
            }
        }
    }

    return 0;
}

void Pieces::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (int i = 0; i < 16; i++) {
        target.draw(pieces_white[i].GetSprite(), state);
        target.draw(pieces_black[i].GetSprite(), state);
    }
}

std::vector<int> Pieces::PossibleMoves(SPiece piece)
{
    std::vector<int> ret;
    int location = piece.GetPosition();
    
    switch (piece.GetType()) {
    case PAWN:
        if (piece.GetColour() == BLACK) {
            // Single move
            ret.push_back(location + 1);
            
            // Double move
            if (std::floor(location % 8) == 1) ret.push_back(location + 2);
        } else {
            // Single move
            ret.push_back(location - 1);
            
            // Double move
            if (std::floor(location % 8) == 1) ret.push_back(location - 2);
        }

        piece.GetValidMoves().clear();
        for (int& i: ret) {
            std::cout << i << std::endl;
        }

        // FIXME
        piece.SetValidMoves(ret);
        break;

    // TODO
    case ROOK: break;
    case KNIGHT: break;
    case BISHOP: break;
    case KING: break;
    case QUEEN: break;
    }

    return ret;
}

std::vector<int> Pieces::PossibleTake(SPiece piece)
{
    // TODO
}

std::array<SPiece, 16> Pieces::GetPiecesArray(int colour) const
{
    return colour == BLACK ? pieces_black: pieces_white;
}

