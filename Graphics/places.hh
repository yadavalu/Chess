#ifndef __PLACES_CHESS_HH__
#define __PLACES_CHESS_HH__

#define PA 0
#define PB 60
#define PC 120
#define PD 180
#define PE 240
#define PF 300
#define PG 360
#define PH 420

#define N1 420
#define N2 360
#define N3 300
#define N4 240
#define N5 180
#define N6 120
#define N7 60
#define N8 0

#include <SFML/Graphics.hpp>

sf::Vector2i GetLocations(std::string);
std::string GetNotes(sf::Vector2i);
int GetIntLocation(std::string);
int GetIntLocation(sf::Vector2i);

#endif
