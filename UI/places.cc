#include "places.hh"

#include <cmath>

sf::Vector2i GetLocations(std::string locations)
{
    int x, y;
    if (locations.find('A') != std::string::npos) x = PA;
    else if (locations.find('B') != std::string::npos) x = PB;
    else if (locations.find('C') != std::string::npos) x = PC;
    else if (locations.find('D') != std::string::npos) x = PD;
    else if (locations.find('E') != std::string::npos) x = PE;
    else if (locations.find('F') != std::string::npos) x = PF;
    else if (locations.find('G') != std::string::npos) x = PG;
    else if (locations.find('H') != std::string::npos) x = PH;
    
    if (locations.find('1') != std::string::npos) y = N1;
    else if (locations.find('2') != std::string::npos) y = N2;
    else if (locations.find('3') != std::string::npos) y = N3;
    else if (locations.find('4') != std::string::npos) y = N4;
    else if (locations.find('5') != std::string::npos) y = N5;
    else if (locations.find('6') != std::string::npos) y = N6;
    else if (locations.find('7') != std::string::npos) y = N7;
    else if (locations.find('8') != std::string::npos) y = N8;
        
    return sf::Vector2i(x, y);
}

std::string GetNotes(sf::Vector2i locations)
{
    std::string ret;

    if (std::floor(locations.x/60)*60 == PA) ret += 'A';
    else if (std::floor(locations.x/60)*60 == PB) ret += 'B';
    else if (std::floor(locations.x/60)*60 == PC) ret += 'C';
    else if (std::floor(locations.x/60)*60 == PD) ret += 'D';
    else if (std::floor(locations.x/60)*60 == PE) ret += 'E';
    else if (std::floor(locations.x/60)*60 == PF) ret += 'F';
    else if (std::floor(locations.x/60)*60 == PG) ret += 'G';
    else if (std::floor(locations.x/60)*60 == PH) ret += 'H';

    if (std::floor(locations.y/60)*60 == N1) ret += '1';
    else if (std::floor(locations.y/60)*60 == N2) ret += '2';
    else if (std::floor(locations.y/60)*60 == N3) ret += '3';
    else if (std::floor(locations.y/60)*60 == N4) ret += '4';
    else if (std::floor(locations.y/60)*60 == N5) ret += '5';
    else if (std::floor(locations.y/60)*60 == N6) ret += '6';
    else if (std::floor(locations.y/60)*60 == N7) ret += '7';
    else if (std::floor(locations.y/60)*60 == N8) ret += '8';

    return ret;
}
