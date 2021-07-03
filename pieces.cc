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
    this->white_textures.push_back(w_pawn);
    this->white_textures.push_back(w_rook);
    this->white_textures.push_back(w_knight);
    this->white_textures.push_back(w_bishop);
    this->white_textures.push_back(w_king);
    this->white_textures.push_back(w_queen);
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
    this->white_sprites.push_back(w_p1);
    this->white_sprites.push_back(w_p2);
    this->white_sprites.push_back(w_p3);
    this->white_sprites.push_back(w_p4);
    this->white_sprites.push_back(w_p5);
    this->white_sprites.push_back(w_p6);
    this->white_sprites.push_back(w_p7);
    this->white_sprites.push_back(w_p8);
    this->white_sprites.push_back(w_r1);
    this->white_sprites.push_back(w_kn1);
    this->white_sprites.push_back(w_b1);
    this->white_sprites.push_back(w_ki);
    this->white_sprites.push_back(w_qu);
    this->white_sprites.push_back(w_b2);
    this->white_sprites.push_back(w_kn2);
    this->white_sprites.push_back(w_r2);
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
    this->black_sprites.push_back(b_p1);
    this->black_sprites.push_back(b_p2);
    this->black_sprites.push_back(b_p3);
    this->black_sprites.push_back(b_p4);
    this->black_sprites.push_back(b_p5);
    this->black_sprites.push_back(b_p6);
    this->black_sprites.push_back(b_p7);
    this->black_sprites.push_back(b_p8);
    this->black_sprites.push_back(b_r1);
    this->black_sprites.push_back(b_kn1);
    this->black_sprites.push_back(b_b1);
    this->black_sprites.push_back(b_ki);
    this->black_sprites.push_back(b_qu);
    this->black_sprites.push_back(b_b2);
    this->black_sprites.push_back(b_kn2);
    this->black_sprites.push_back(b_r2);
}

void Pieces::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (int i = 0; i < white_sprites.size(); i++) target.draw(white_sprites[i], state);
    for (int i = 0; i < black_sprites.size(); i++) target.draw(black_sprites[i], state);
}
