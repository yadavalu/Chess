#ifndef __VALID_CHESS_HH__
#define __VALID_CHESS_HH__

#include <vector>

#include <SFML/Graphics.hpp>

class Valid
{
public:
    Valid(std::vector<std::string>, std::vector<std::string>);  // args: white, black

    std::vector<std::string> CheckValidity(int, int, int);

private:
    std::vector<std::string> white_locations, black_locations;
};

#endif
