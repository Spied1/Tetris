#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Object.hpp"
#include<set>

class Game
{

private:
    bool pole_bool = 0;
    int points = 0;
    float delay = 0.5;
    sf::Vector2f pole_size;
    Object* current_object;
    std::set<std::pair<float, float>> collision_cords;
    std::vector<std::vector<int>> vec;
    std::vector<std::vector<int>> collors_cords;
    sf::RenderWindow win;
    std::set<std::pair<int, std::vector<int>>> hitbox_of_objects;

    void event_checker(sf::Event event, float& y, float& x, int& obj_id, int& object_stage);

    void poleMaker();

    void nextfig();

    bool check(float xI, float yI);

    float check_for_line();

    void recolision();

    void linexfixer(int t);

    void linedel(int obj_id, float x, float y);

    void draw(float& y, float& x, int& obj_id, int& object_stage, int& collor_id, int& objR);

    void game_over(int& game_stage);

public:
    Game();

    void run();
};