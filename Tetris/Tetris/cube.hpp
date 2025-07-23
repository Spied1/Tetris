#pragma once
#include<SFML/Graphics.hpp>

class Cube
{
private:
    int posibl = 0;
    sf::Vector2f m_position;
    int color_idk = 0;
    sf::Texture cube_texture;
    sf::Sprite cube_sprite;

public:
    Cube(sf::Vector2f position, int color_id = 0);

    sf::Sprite& get_sprite();
};