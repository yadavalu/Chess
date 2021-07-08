#include "valid.hh"
#include "piece.hh"

#include <string>
#include <sstream>

Valid::Valid(std::vector<std::string> white, std::vector<std::string> black)
    : white_locations(white)
    , black_locations(black)
{
}

std::vector<std::string> Valid::CheckValidity(int colour, int piece, int index)
{
    std::vector<std::string> locations;
    if (colour == Colour::WHITE) locations = this->white_locations;
    else locations = this->black_locations;

    std::vector<std::string> o_locations;
    if (colour == Colour::WHITE) o_locations = this->black_locations;
    else o_locations = this->white_locations;

    std::string location = locations[index];

    std::vector<std::string> valid;

    // static_cast<char>(o_locations[i][0] + 1)

    std::stringstream ss;

    switch (piece) {
    case PAWN:
        bool straight = false;

        for (int i = 0; i < o_locations.size(); i++) {
            if (colour == Colour::WHITE) {
                if (o_locations[i] != "null") {
                    if (static_cast<char>(o_locations[i][0] + 1) == location[0]) {
                        ss.clear();
                        if (o_locations[i][1] == location[1] + 1) {
                            ss << static_cast<char>(o_locations[i][0] + 1) << location[1];
                            valid.push_back(ss.str());
                        } else if (o_locations[i][1] == location[1] - 1) {
                            std::stringstream ss;
                            ss << static_cast<char>(o_locations[i][0] - 1) << location[1];
                            valid.push_back(ss.str());
                        }
                    }
                } else {
                    if (o_locations[i][0] == location[0]) {
                        ss.clear();

                        if (std::stoi(ss.str()) == std::stoi(locations[1]) + 1) {
                            ss << locations[0];
                            ss << std::stoi(locations[1]) + 1;
                            valid.push_back(locations[0] + ss.str());

                            straight = !straight;
                        }
                    }
                }
            }
        }
        
        ss.clear();
        ss << locations[0];
        
        if (!straight) {
            ss << std::stoi(locations[1]) + 1;
            valid.push_back(locations[0] + ss.str());
        }
        
        break;
    }

    return valid;
}

