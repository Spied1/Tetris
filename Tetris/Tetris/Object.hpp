#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"GameProperties.cpp"
#include"Cube.hpp"

class Object
{
private:
    std::vector<sf::Vector2f> hitbox_of_obj;
    std::vector<sf::Sprite> object_sprites;
    std::vector <std::vector<int>> vec;
    std::vector<Cube*> cubes;

public:
    Object(int i, float x = GameProperties::pole_size_x / 2, float y = GameProperties::pole_size_y - 10, int object_stage = 0, int color_id = 0);

    std::vector<sf::Sprite>& get_objects_sprites();

    std::vector<sf::Vector2f>& get_hitbox_of_obj();

    ~Object();
};