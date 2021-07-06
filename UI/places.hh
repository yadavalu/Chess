#ifndef __PLACES_CHESS_HH__
#define __PLACES_CHESS_HH__

#define PA 0
#define PB 100
#define PC 200
#define PD 300
#define PE 400
#define PF 500
#define PG 600
#define PH 700

#define N1 700
#define N2 600
#define N3 500
#define N4 400
#define N5 300
#define N6 200
#define N7 100
#define N8 0

#include <SFML/Graphics.hpp>

sf::Vector2i GetLocations(std::string locations);
std::string GetNotes(sf::Vector2i locations);

#endif
