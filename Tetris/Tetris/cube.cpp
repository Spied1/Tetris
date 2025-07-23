#include"Cube.hpp"
#include<iostream>
#include<string>

Cube::Cube(sf::Vector2f position, int color_id) :
    m_position(position), color_idk(color_id) 
{
    std::string texture_path = "D:/Tetris/Tetris/Textures/cube/cube_" + std::to_string(color_id) + ".png";
    cube_texture.loadFromFile(texture_path);
    cube_sprite.setPosition(sf::Vector2f(position.x, position.y));
    cube_texture.setSmooth(false);
    cube_sprite.setTexture(cube_texture);
}

sf::Sprite& Cube::get_sprite()
{
    return cube_sprite;
}