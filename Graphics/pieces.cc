#include "pieces.hh"
#include "places.hh"

Pieces::Pieces()
{
    // White textures
    sf::Texture w_pawn;
    sf::Texture w_rook;
    sf::Texture w_knight;
    sf::Texture w_bishop;
    sf::Texture w_king;
    sf::Texture w_queen;
    w_pawn.loadFromFile("texture/white/pawn.png");
    w_rook.loadFromFile("texture/white/rook.png");
    w_knight.loadFromFile("texture/white/knight.png");
    w_bishop.loadFromFile("texture/white/bishop.png");
    w_king.loadFromFile("texture/white/king.png");
    w_queen.loadFromFile("texture/white/queen.png");
    this->white_textures = { w_pawn, w_rook, w_knight, w_bishop, w_king, w_queen };
    // Black textures
    sf::Texture b_pawn;
    sf::Texture b_rook;
    sf::Texture b_knight;
    sf::Texture b_bishop;
    sf::Texture b_king;
    sf::Texture b_queen;
    b_pawn.loadFromFile("texture/black/pawn.png");
    b_rook.loadFromFile("texture/black/rook.png");
    b_knight.loadFromFile("texture/black/knight.png");
    b_bishop.loadFromFile("texture/black/bishop.png");
    b_king.loadFromFile("texture/black/king.png");
    b_queen.loadFromFile("texture/black/queen.png");
    this->black_textures.push_back(b_pawn);
    this->black_textures.push_back(b_rook);
    this->black_textures.push_back(b_knight);
    this->black_textures.push_back(b_bishop);
    this->black_textures.push_back(b_king);
    this->black_textures.push_back(b_queen);
    this->black_textures = { b_pawn, b_rook, b_knight, b_bishop, b_king, b_queen };

    // White sprites
    sf::Sprite w_p1(this->white_textures[0]), w_p2(this->white_textures[0]),
                w_p3(this->white_textures[0]), w_p4(this->white_textures[0]), 
                w_p5(this->white_textures[0]), w_p6(this->white_textures[0]), 
                w_p7(this->white_textures[0]), w_p8(this->white_textures[0]);
    sf::Sprite w_r1(this->white_textures[1]);
    sf::Sprite w_kn1(this->white_textures[2]);
    sf::Sprite w_b1(this->white_textures[3]);
    sf::Sprite w_ki(this->white_textures[4]);
    sf::Sprite w_qu(this->white_textures[5]);
    sf::Sprite w_b2(this->white_textures[3]);
    sf::Sprite w_kn2(this->white_textures[2]);
    sf::Sprite w_r2(this->white_textures[1]);
    this->white_sprites = 
    { w_p1, w_p2, w_p3, w_p4, w_p5, w_p6, w_p7, w_p8, 
      w_r1, w_kn1, w_b1, w_qu, w_ki, w_b2, w_kn2, w_r2 };
    // Black sprites
    sf::Sprite b_p1(this->black_textures[0]), b_p2(this->black_textures[0]),
                b_p3(this->black_textures[0]), b_p4(this->black_textures[0]), 
                b_p5(this->black_textures[0]), b_p6(this->black_textures[0]), 
                b_p7(this->black_textures[0]), b_p8(this->black_textures[0]);
    sf::Sprite b_r1(this->black_textures[1]);
    sf::Sprite b_kn1(this->black_textures[2]);
    sf::Sprite b_b1(this->black_textures[3]);
    sf::Sprite b_ki(this->black_textures[4]);
    sf::Sprite b_qu(this->black_textures[5]);
    sf::Sprite b_b2(this->black_textures[3]);
    sf::Sprite b_kn2(this->black_textures[2]);
    sf::Sprite b_r2(this->black_textures[1]);
    this->black_sprites = 
    { b_r1, b_kn1, b_b1, b_qu, b_ki, b_b2, b_kn2, b_r2,
      b_p1, b_p2, b_p3, b_p4, b_p5, b_p6, b_p7, b_p8 };
}

void Pieces::SetLocation()
{
    for (int i = 0; i < black_sprites.size(); i++) {
        black_sprites[i].setPosition(sf::Vector2f(60*(i % 8), 
	 				                (i < 8 ? 0:60)));
    }

    for (int i = 0; i < white_sprites.size(); i++) {
        white_sprites[i].setPosition(sf::Vector2f(60*(i % 8), 
	 				                (i < 8 ? 360:420)));
    }

    removed_black = 0;
    removed_white = 0;
}

void Pieces::PairLocation()
{
    white_locations = {
        // pawn ...
        "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", 
        // rook, knight, bishop, queen, king, bishop, knight, rook
        "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", 
    };

    black_locations = {
        // rook, knight, bishop, queen, king, bishop, knight, rook
        "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", 
        // pawn ...
        "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", 
    };
}

void Pieces::Move(int colour, int index, sf::Vector2f pos)
{
    if (colour == 0) {
        this->white_sprites[index].setPosition(pos);
        this->white_locations[index] = GetNotes(sf::Vector2i(pos));
    } else {
        this->black_sprites[index].setPosition(pos);
        this->black_locations[index] = GetNotes(sf::Vector2i(pos));
    }
}

void Pieces::Remove(int index, int colour)
{
    if (colour == 0) {
        this->white_locations[index] = "null";
        this->white_sprites[index].setPosition(525 + removed_white * 20, 25);
        this->white_sprites[index].setScale(0.3, 0.3);
        removed_white++;
    } else {
        this->black_locations[index] = "null";
        this->black_sprites[index].setPosition(525 + removed_black * 20, 420);
        this->black_sprites[index].setScale(0.3, 0.3);
        removed_black++;
    }
}


void Pieces::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (int i = 0; i < white_sprites.size(); i++) target.draw(white_sprites[i], state);
    for (int i = 0; i < black_sprites.size(); i++) target.draw(black_sprites[i], state);
}

std::vector<sf::Sprite> Pieces::GetWhiteSprites()
{
    return this->white_sprites;
}

std::vector<std::string> Pieces::GetWhiteLocations()
{
    return this->white_locations;
}

std::vector<sf::Sprite> Pieces::GetBlackSprites()
{
    return this->black_sprites;
}

std::vector<std::string> Pieces::GetBlackLocations()
{
    return this->black_locations;
}

