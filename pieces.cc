#include "pieces.hh"

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
      w_r1, w_kn1, w_b1, w_ki, w_qu, w_b2, w_kn2, w_r2 };
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
    { b_r1, b_kn1, b_b1, b_ki, b_qu, b_b2, b_kn2, b_r2,
      b_p1, b_p2, b_p3, b_p4, b_p5, b_p6, b_p7, b_p8 };
}

void Pieces::SetLocation()
{
    for (int i = 0; i < black_sprites.size(); i++) {
        //black_sprites[i].setPosition(sf::Vector2f(100*(i % 8), 
	 	//			                (i < 8 ? 0:100)));
        for (int j = 0; j < locations.size(); j++) {
            if (std::get<1>(black[j]) == std::get<1>(locations[j])) {
                black_sprites[i].setPosition(sf::Vector2f(std::get<0>(std::get<0>(locations[j])), std::get<1>(std::get<0>(locations[j]))));
            }
        }
    }

    for (int i = 0; i < white_sprites.size(); i++) {
        //white_sprites[i].setPosition(sf::Vector2f(100*(i % 8), 
	 	//			                (i < 8 ? 600:700)));
        for (int j = 0; j < locations.size(); j++) {
            if (std::get<1>(white[j]) == std::get<1>(locations[j])) {
                white_sprites[i].setPosition(sf::Vector2f(std::get<0>(std::get<0>(locations[j])), std::get<1>(std::get<0>(locations[j]))));
            }
        }
    }
}

void Pieces::PairLocation()
{
    //TODO
    locations = {
        {{0, 0}, "a8"}, {{0, 100}, "a7"}, {{0, 200}, "a6"}, {{0, 300}, "a5"}, 
        {{0, 400}, "a4"}, {{0, 500}, "a3"}, {{0, 600}, "a2"}, {{0, 700}, "a1"},
        {{100, 0}, "b8"}, {{100, 100}, "b7"}, {{100, 200}, "b6"}, {{100, 300}, "b5"}, 
        {{100, 400}, "b4"}, {{100, 500}, "b3"}, {{100, 600}, "b2"}, {{100, 700}, "b1"},
        {{200, 0}, "c8"}, {{200, 100}, "c7"}, {{200, 200}, "c6"}, {{200, 300}, "c5"}, 
        {{200, 400}, "c4"}, {{200, 500}, "c3"}, {{200, 600}, "c2"}, {{200, 700}, "c1"},
        {{300, 0}, "d8"}, {{300, 100}, "d7"}, {{300, 200}, "d6"}, {{300, 300}, "d5"}, 
        {{300, 400}, "d4"}, {{300, 500}, "d3"}, {{300, 600}, "d2"}, {{300, 700}, "d1"},
        {{400, 0}, "e8"}, {{400, 100}, "e7"}, {{400, 200}, "e6"}, {{400, 300}, "e5"}, 
        {{400, 400}, "e4"}, {{400, 500}, "e3"}, {{400, 600}, "e2"}, {{400, 700}, "e1"},
        {{500, 0}, "f8"}, {{500, 100}, "f7"}, {{500, 200}, "f6"}, {{500, 300}, "f5"}, 
        {{500, 400}, "f4"}, {{500, 500}, "f3"}, {{500, 600}, "f2"}, {{500, 700}, "f1"},
        {{600, 0}, "g8"}, {{600, 100}, "g7"}, {{600, 200}, "g6"}, {{600, 300}, "g5"}, 
        {{600, 400}, "g4"}, {{600, 500}, "g3"}, {{600, 600}, "g2"}, {{600, 700}, "g1"},
        {{700, 0}, "h8"}, {{700, 100}, "h7"}, {{700, 200}, "h6"}, {{700, 300}, "h5"}, 
        {{700, 400}, "h4"}, {{700, 500}, "h3"}, {{700, 600}, "h2"}, {{700, 700}, "h1"},
    };

    white = {
        {white_sprites[0], "a2"}, {white_sprites[1], "b2"}, {white_sprites[2], "c2"}, {white_sprites[3], "d2"},
        {white_sprites[4], "e2"}, {white_sprites[5], "f2"}, {white_sprites[6], "g2"}, {white_sprites[7], "h2"},
        {white_sprites[8], "a1"}, {white_sprites[9], "b1"}, {white_sprites[10], "c1"}, {white_sprites[11], "d1"},
        {white_sprites[12], "e1"}, {white_sprites[13], "f1"}, {white_sprites[14], "g1"}, {white_sprites[15], "h1"},
    };

    black = {
        {black_sprites[0], "a8"}, {black_sprites[1], "b8"}, {black_sprites[2], "c8"}, {black_sprites[3], "d8"},
        {black_sprites[4], "e8"}, {black_sprites[5], "f8"}, {black_sprites[6], "g8"}, {black_sprites[7], "h8"},
        {black_sprites[8], "a7"}, {black_sprites[9], "b7"}, {black_sprites[10], "c7"}, {black_sprites[11], "d7"},
        {black_sprites[12], "e8"}, {black_sprites[13], "f8"}, {black_sprites[14], "g8"}, {black_sprites[15], "h8"},
    };
}

void Pieces::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (int i = 0; i < white_sprites.size(); i++) target.draw(white_sprites[i], state);
    for (int i = 0; i < black_sprites.size(); i++) target.draw(black_sprites[i], state);
}
