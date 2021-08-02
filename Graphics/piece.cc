#include "piece.hh"
#include "places.hh"
#include "enumerate.hh"

SPiece::SPiece()
{
    
}

SPiece::~SPiece()
{

}

void SPiece::Constructor(int colour, int type, sf::Vector2i position)
{
    this->colour = colour;
    this->type = type;
    this->position_vector = position;
    this->position_int = GetIntLocation(position);
    this->valid_moves = {};

    std::string child_dir;
    if (colour == BLACK) child_dir = "texture/black/";
    else child_dir = "texture/white/";

    switch (type) {
    case PAWN: texture.loadFromFile(child_dir + "pawn.png"); break;
    case ROOK: texture.loadFromFile(child_dir + "rook.png"); break;
    case KNIGHT: texture.loadFromFile(child_dir + "knight.png"); break;
    case BISHOP: texture.loadFromFile(child_dir + "bishop.png"); break;
    case KING: texture.loadFromFile(child_dir + "king.png"); break;
    case QUEEN: texture.loadFromFile(child_dir + "queen.png"); break;
    }

    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(position_vector));
}

void SPiece::Constructor(int colour, int type, std::string _position)
{
    this->colour = colour;
    this->type = type;
    this->position = _position;
    this->position_vector = GetLocations(position);
    this->position_int = GetIntLocation(position);

    std::string child_dir;
    if (colour == BLACK) child_dir = "texture/black/";
    else child_dir = "texture/white/";

    switch (type) {
    case PAWN: texture.loadFromFile(child_dir + "pawn.png"); break;
    case ROOK: texture.loadFromFile(child_dir + "rook.png"); break;
    case KNIGHT: texture.loadFromFile(child_dir + "knight.png"); break;
    case BISHOP: texture.loadFromFile(child_dir + "bishop.png"); break;
    case KING: texture.loadFromFile(child_dir + "king.png"); break;
    case QUEEN: texture.loadFromFile(child_dir + "queen.png"); break;
    }

    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(position_vector));
}

void SPiece::Move(sf::Vector2i _position)
{
    sprite.setPosition(sf::Vector2f(_position));
    this->position_vector = _position;
    this->position_int = GetIntLocation(position_vector);
    this->position = GetNotes(position_vector);
}

void SPiece::Remove(int n)
{
    int x, dy;
    if (n > 7) {
        dy = 20;
        x = n % 8;
    } else {
        dy = 0;
        x = n;
    }

    if (colour == BLACK) {
        sprite.setPosition(525 + x * 18, 420 + dy);
        sprite.scale(0.3, 0.3);
    } else {
        sprite.setPosition(525 + x * 18, 25 + dy);
        sprite.scale(0.3, 0.3);
    }
}

sf::Sprite SPiece::GetSprite() const
{
    return sprite;
}

int SPiece::GetColour() const
{
    return colour;
}

int SPiece::GetType() const
{
    return type;
}

int SPiece::GetPosition() const
{
    return position_int;
}

std::vector<int> SPiece::GetValidMoves() const
{
    return valid_moves;
}

void SPiece::SetValidMoves(std::vector<int> valid) 
{
    this->valid_moves = valid;
}
