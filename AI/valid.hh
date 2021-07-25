#ifndef __VALID_CHESS_HH__
#define __VALID_CHESS_HH__

#include <string>
#include <vector>

class Validate
{
public:
    Validate();

    int GetPieceIndex(int, int);

    std::vector<std::string> GetValidity(int, int, std::string);

private:
    std::vector<std::string> Pawn(int, std::string);
    std::vector<std::string> Rook(int, std::string);
    std::vector<std::string> Knight(int, std::string);
    std::vector<std::string> Bishop(int, std::string);
    std::vector<std::string> King(int, std::string);
    std::vector<std::string> Queen(int, std::string);
};

#endif
