#include "valid.hh"
#include "enumerate.hh"


Validate::Validate()
{

}

int Validate::GetPieceIndex(int index, int colour)
{
    if (colour == WHITE) {
        if (index <= 7) return PAWN;
        else if (index == 8 || index == 15) return ROOK;
        else if (index == 9 || index == 14) return KNIGHT;
        else if (index == 10 || index == 13) return BISHOP;
        else if (index == 12) return KING;
        else if (index == 11) return QUEEN;
    } else {
        if (index >= 8) return PAWN;
        else if (index == 0 || index == 7) return ROOK;
        else if (index == 1 || index == 6) return KNIGHT;
        else if (index == 2 || index == 5) return BISHOP;
        else if (index == 3) return KING;
        else if (index == 4) return QUEEN;
    }
}

std::vector<std::string> Validate::GetValidity(int colour, int piece, std::string position) 
{
    std::vector<std::string> pos;
    switch (piece) {
    case PAWN: pos = Pawn(colour, position); break;
    case ROOK: pos = Rook(colour, position); break;
    case KNIGHT: pos = Knight(colour, position); break;
    case BISHOP: pos = Bishop(colour, position); break;
    case KING: pos = King(colour, position); break;
    case QUEEN: pos = Queen(colour, position); break;
    }
}

// TODO: Implement the following methods
std::vector<std::string> Validate::Pawn(int colour, std::string position)
{
    // TODO
}

std::vector<std::string> Validate::Rook(int colour, std::string position)
{
    // TODO
}

std::vector<std::string> Validate::Knight(int colour, std::string position)
{
    // TODO
}

std::vector<std::string> Validate::Bishop(int colour, std::string position)
{
    // TODO
}

std::vector<std::string> Validate::King(int colour, std::string position)
{
    // TODO
}

std::vector<std::string> Validate::Queen(int colour, std::string position)
{
    // TODO
}

