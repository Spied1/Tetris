#include"Game.hpp"
#include<iostream>
#include"Cube.hpp"

Game::Game() : win(sf::VideoMode(GameProperties::pole_size_x, GameProperties::pole_size_y), "Tetris"),
    vec(22, std::vector<int>(12)), collors_cords(22, std::vector<int>(12)), current_object(nullptr), pole_size({22, 12})
{

};

void Game::run()
{
    float x = 96;
    float y = -32;
    int object_stage = abs(rand()) % 8;
    int obj_id = abs(rand()) % 8;
    int objR = 0;
    sf::Clock clock;
    float timer = 0;

    int collor_id = abs(rand()) % 8;
    int game_stage = 1;
    while (game_stage == 1)
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        if (obj_id < 4)
        {
            objR = 2;
        }
        else
        {
            objR = 4;
        }

        sf::Event event;
        while (win.pollEvent(event))
        {
            event_checker(event, y, x, obj_id, object_stage);
        }
        if (timer > delay)
        {
            y += 16;
            timer = 0;
        }
        for (int i = 1; i < 11; i++)
        {
            if (vec[0][i] == 1)
            {
                game_over(game_stage);
            }
        }
        draw(y, x, obj_id, object_stage, collor_id, objR);
    }
}

void Game::event_checker(sf::Event event, float& y, float& x, int& obj_id, int& object_stage)
{
    if (event.type == sf::Event::Closed)
    {
        win.close();
    }
    else if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::S:
        case sf::Keyboard::Down:
            if (check(0, 16)) y += 16;
            break;

        case sf::Keyboard::W:
        case sf::Keyboard::Up:
            object_stage++;
            if (!check(16, 0))
            {
                if (!check(-16, 0)) object_stage--;
                else x -= (obj_id == 0) ? 32 : 16;
            }
            else if (!check(-16, 0))
            {
                if (!check(16, 0)) object_stage--;
                else x += (obj_id == 0) ? 32 : 16;
            }
            break;

        case sf::Keyboard::D:
        case sf::Keyboard::Right:
            if (check(16, 0)) x += 16;
            break;

        case sf::Keyboard::A:
        case sf::Keyboard::Left:
            if (check(-16, 0)) x -= 16;
            break;

        default:
            break;
        }
    }
}

void Game::poleMaker() 
{
    for (int i = 0; i != pole_size.x; i++)
    {
        vec[i][0] = 1;
        vec[i][11] = 1;

    }
    for (int i = 0; i != pole_size.y; i++)
    {
        //vec[0][i] = 1;
        vec[21][i] = 1;
    }
    float x = 0;
    float y = 0;

    std::pair<float, float> temp;
    for (int i = 0; i != pole_size.x; i++)
    {
        for (int j = 0; j != pole_size.y; j++)
        {
            if (vec[i][j] == 1)
            {
                //std::cout << "color:" << collors_cords[{j * 16, i * 16}] << std::endl;
                if (i > -1 && j > -1)
                {
                    Cube* temp_cube = new Cube(sf::Vector2f(j * 16, i * 16), collors_cords[i][j]);
                    win.draw(temp_cube->get_sprite());
                }
                else
                {
                    Cube* temp_cube = new Cube(sf::Vector2f(j * 16, i * 16), 0);
                    win.draw(temp_cube->get_sprite());
                }
                if (pole_bool == false)
                {
                    temp = { j * 16,i * 16 };
                    std::cout << j << " " << i << std::endl;
                    collision_cords.insert(temp);
                }
            }
        }
    }

    pole_bool = true;
}

void Game::nextfig() {
    for (int i = 5; i != -1; i--)
    {
        new Cube(sf::Vector2f(192 + i * 16, 80), 0);
        new Cube(sf::Vector2f(192 + i * 16, 176), 0);
    }

    for (int i = 0; i != 7; i++)
    {
        new Cube(sf::Vector2f(272, 176 - i * 16), 0);
    }
}
//functions to check for lines
bool Game::check(float xI, float yI)
{
    std::pair<float, float> temp = { xI,yI };
    for (auto collisions : collision_cords)
    {
        for (auto hitbox : current_object->get_hitbox_of_obj())
        {
            if (collisions.first == hitbox.x + xI && collisions.second == hitbox.y + yI)
            {
                return false;
            }
        }
    }
    return true;
}

//uses check for getting cordinate of pole for delete
float Game::check_for_line() 
{
    int pole_t = 0;
    for (int i = 1; i < pole_size.x - 1; i++) 
    {
        pole_t = 0;
        for (int j = 1; j < pole_size.y - 1; j++) 
        {
            if (vec[i][j] == 1) 
            {
                pole_t += 1;

                if (pole_t == 10) 
                {
                    return i;
                    std::cout << "line:" << i << std::endl;
                }
            }

        }
    }
    return -1;
}

//recolision of wall game
void Game::recolision() {
    std::set<std::pair<float, float>> temp_col;
    float tt = 0;
    float jt = 0;
    for (int t = 0; t < pole_size.x; t++) 
    {
        for (int j = 0; j < pole_size.y; j++) 
        {
            if (vec[t][j] == 1) 
            {
                tt = t * 16;
                jt = j * 16;

                temp_col.insert({ jt,tt });
            }
        }
    }
    collision_cords = temp_col;
}

void Game::linexfixer(int t) 
{
    std::vector<std::vector<int>> tempvec(pole_size.x, std::vector<int>(pole_size.y));
    std::vector<std::vector<int>> tempcol(pole_size.x, std::vector<int>(pole_size.y));
    for (int i = 0; i != pole_size.x; i++) 
    {
        tempvec[i][0] = 1;
        tempvec[i][11] = 1;
        tempcol[i][0] = 0;
        tempcol[i][11] = 0;
    }
    for (int i = 0; i != pole_size.y; i++) 
    {
        tempvec[21][i] = 1;
    }

    for (int i = t; i != pole_size.x; i++) 
    {
        for (int j = 1; j != pole_size.y; j++)
        {
            tempvec[i][j] = vec[i][j];
            tempcol[i][j] = collors_cords[i][j];
        }
    }
    for (int i = t; i != 0; i--) 
    {
        for (int j = 1; j != pole_size.y; j++) 
        {
            tempvec[i][j] = vec[i - 1][j];
            tempcol[i][j] = collors_cords[i - 1][j];
        }
    }
    vec = tempvec;
    collors_cords = tempcol;
    recolision();
}

void Game::linedel(int obj_id, float x, float y) 
{
    int k = 0;
    if (check_for_line() != -1) 
    {
        k = check_for_line();
        if (obj_id == 7) 
        {
            std::vector<std::pair<int, int>> coords;
            coords.push_back({ x,y });
            coords.push_back({ x + 1,y });
            coords.push_back({ x - 1,y });
            coords.push_back({ x,y + 1 });
            coords.push_back({ x,y - 1 });
            for (auto x : coords) 
            {
                vec[x.first][x.second] = 0;
                for (int ku = 0; ku < collision_cords.size(); ku++) 
                {
                    if (collision_cords.find({ x.first * 16 ,x.second * 16 }) != collision_cords.end()) 
                    {
                        collision_cords.erase(collision_cords.find({ x.first * 16,x.second * 16 }));
                    }
                }
            }
        }
        else 
        {
            for (int i = 1; i < pole_size.y; i++) 
            {
                vec[k][i] = 0;
                for (int ku = 0; ku < collision_cords.size(); ku++) 
                {
                    if (collision_cords.find({ i * 16 ,k * 16 }) != collision_cords.end()) 
                    {
                        collision_cords.erase(collision_cords.find({ i * 16,k * 16 }));

                    }
                }

            }
        }
        linexfixer(k);
        delay = delay - 0.05;
        points = points + 10;
    }

}

//main function,draws wall game
void Game::draw(float& y, float& x, int& obj_id, int& object_stage, int& collor_id, int& objR)
{
    sf::Text point;
    if (!check(0, 16) == true)
    {
        int color_id = collor_id;
        if (x > -1 && y > -1)
        {
            for (auto ku : current_object->get_hitbox_of_obj())
            {
                collision_cords.insert(std::pair<float, float>(ku.x, ku.y));
                std::pair<float, std::pair<float, int>> temp;
                int t1 = ku.x / 16;
                int t2 = ku.y / 16;
                collors_cords[t2][t1] = color_id;
                int a = ku.x;
                int b = ku.y;
                vec[b / 16][a / 16] = 1;
                x = 96;
                y = -32;
                obj_id = abs(rand()) % 8;
                object_stage = abs(rand()) % objR;
                collor_id = abs(rand()) % 8;
            }
        }
    }
    win.clear();
    sf::Font font;
    font.loadFromFile("D:/Tetris/Tetris/Textures/cubic.ttf");
    point.setFont(font);
    point.setCharacterSize(24);
    point.setString(std::to_string(points));
    point.setPosition(272 - 74, 144 - 16);
    win.draw(point);
    current_object = new Object(obj_id, x, y, object_stage % objR, collor_id);
    for (auto sprite : current_object->get_objects_sprites())
    {
        win.draw(sprite);
    }

    linedel(obj_id, x, y);
    poleMaker();
    nextfig();
    win.display();
}

void Game::game_over(int& game_stage)
{
    std::cout << "Game Over";
    game_stage = 0;
}