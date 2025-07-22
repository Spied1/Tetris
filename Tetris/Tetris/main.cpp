#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include <windows.h>
#include <stdlib.h>
#include<algorithm>
#include<set>
#include"GameProperties.cpp"


//class cube contains information of textures
class Cube {
public:
    int posibl = 0;
    sf::Vector2f m_position;
    int color_idk = 0;
    sf::Texture cube_texture;
    sf::Sprite cube_sprite;

    Cube(sf::Vector2f position, int color_id = 0) :m_position(position), color_idk(color_id) {
        if (color_id == 0) {
            if (!cube_texture.loadFromFile("D:/Tetris/Tetris/Textures/cube/cube.png")) {
                std::cout << "No texture D:/gamety/Tetris/textures/cube/cube.png" << std::endl;
            };
        }
        else if (color_id == 1) {
            if (!cube_texture.loadFromFile("D:/Tetris/Tetris/Textures/cube/cube_blue.png")) {
                std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_blue.png" << std::endl;
            };
        }
        else if (color_id == 2) {
            if (!cube_texture.loadFromFile("D:/Tetris/Tetris/Textures/cube/cube_cyan.png")) {
                std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_cyan.png" << std::endl;
            };
        }
        else if (color_id == 3) {
            if (!cube_texture.loadFromFile("D:/Tetris/Tetris/Textures/cube/cube_green.png")) {
                std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_green.png" << std::endl;
            };
        }
        else if (color_id == 4) {
            if (!cube_texture.loadFromFile("D:/Tetris/Tetris/Textures/cube/cube_orange.png")) {
                std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_orange.png" << std::endl;
            };
        }
        else if (color_id == 5) {
            if (!cube_texture.loadFromFile("D:/Tetris/Tetris/Textures/cube/cube_purple.png")) {
                std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_purple.png" << std::endl;
            };
        }
        else if (color_id == 6) {
            if (!cube_texture.loadFromFile("D:/Tetris/Tetris/Textures/cube/cube_red.png")) {
                std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_red.png" << std::endl;
            };
        }
        else if (color_id == 7) {
            if (!cube_texture.loadFromFile("D:/Tetris/Tetris/Textures/cube/cube_yellow.png")) {
                std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_yellow.png" << std::endl;
            };
        }
        cube_sprite.setPosition(sf::Vector2f(position.x, position.y));
        cube_texture.setSmooth(false);
        cube_sprite.setTexture(cube_texture);
    }

    sf::Sprite get_sprite()
    {
        return cube_sprite;
    }
};

//class object contains hitboxes
class Object
{
private:
    std::vector<sf::Vector2f> hitbox_of_obj;
    std::vector<sf::Sprite> object_sprites;
    // I, S, Z, O, T, L, J
    // 0, 1, 2, 3, 4, 5, 6
public:
    std::vector <std::vector<int>> vec;
    Object(int i, float x = GameProperties::pole_size_x / 2, float y = GameProperties::pole_size_y - 10, int object_stage = 0, int color_id = 0)
    {
        if (i == 0)
        {
            if (object_stage == 0)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y},{x - 2 * 16,y},{x + 1 * 16,y} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 1)
            {
                hitbox_of_obj = { {x ,y},{x,y - 1 * 16},{x,y - 2 * 16},{x,y + 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
        }
        else if (i == -1)
        {
            Cube* temp = new Cube(sf::Vector2f(x, y), color_id);
            object_sprites.push_back(temp->get_sprite());
        }
        else if (i == 1)
        {
            if (object_stage == 0)
            {
                hitbox_of_obj = { {x ,y},{x,y - 1 * 16},{x - 1 * 16,y - 1 * 16},{x + 1 * 16,y} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 1)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y },{x,y - 1 * 16},{x - 1 * 16,y + 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
        }
        else if (i == 2)
        {
            if (object_stage == 0)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y},{x,y - 1 * 16},{x + 1 * 16,y - 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 1)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y },{x - 1 * 16,y - 1 * 16},{x,y + 1 * 16} };;
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
        }
        else if (i == 3)
        {
            hitbox_of_obj = { {x ,y},{x + 1 * 16,y + 1 * 16},{x,y + 1 * 16},{x + 1 * 16,y} };
            for (auto ku : hitbox_of_obj)
            {
                Cube* temp = new Cube(ku, color_id);
                object_sprites.push_back(temp->get_sprite());
            }
        }
        else if (i == 4)
        {
            if (object_stage == 0)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y},{x + 1 * 16,y},{x,y + 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 1)
            {
                hitbox_of_obj = { {x ,y},{x ,y + 1 * 16},{x,y - 1 * 16},{x + 1 * 16 ,y} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 2)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y },{x + 1 * 16,y},{x,y - 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 3)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y },{x,y - 1 * 16},{x,y + 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
        }
        else if (i == 5)
        {
            if (object_stage == 0)
            {
                hitbox_of_obj = { {x ,y},{x,y + 1 * 16},{x,y - 1 * 16},{x + 1 * 16,y + 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 1)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y},{x + 1 * 16,y},{x - 1 * 16 ,y + 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 2)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y - 1 * 16 },{x,y - 1 * 16},{x,y + 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 3)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y },{x + 1 * 16,y},{x + 1 * 16,y - 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            }
        else if (i == 6)
        {
            if (object_stage == 0)
            {
                hitbox_of_obj = { {x ,y},{x,y + 1 * 16},{x,y - 1 * 16},{x - 1 * 16,y + 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 1)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y},{x + 1 * 16,y},{x - 1 * 16 ,y - 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 2)
            {
                hitbox_of_obj = { {x ,y},{x + 1 * 16,y - 1 * 16 },{x,y - 1 * 16},{x,y + 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            else if (object_stage == 3)
            {
                hitbox_of_obj = { {x ,y},{x - 1 * 16,y },{x + 1 * 16,y},{x + 1 * 16,y + 1 * 16} };
                for (auto ku : hitbox_of_obj)
                {
                    Cube* temp = new Cube(ku, color_id);
                    object_sprites.push_back(temp->get_sprite());
                }
            }
            }
        else if (i == 7)
        {
            hitbox_of_obj = { {x ,y} };
            for (auto ku : hitbox_of_obj)
            {
                Cube* temp = new Cube(ku, color_id);
                object_sprites.push_back(temp->get_sprite());
            }
            }
  }

  std::vector<sf::Sprite> get_objects_sprites()
  {
      return object_sprites;
  }

  std::vector<sf::Vector2f> get_hitbox_of_obj()
  {
      return hitbox_of_obj;
  }
};

class Game
{
public:
    Game() : win(sf::VideoMode(GameProperties::pole_size_x, GameProperties::pole_size_y), "Tetris"),
        vec(22, std::vector<int>(12)),
        collors_cords(22, std::vector<int>(12))
    {
        current_object = nullptr;
        pole_size = { 22,12 };
    };

    void run()
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
                //std::cout << "delka" << std::endl;
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


    //checks buttons event
    void event_checker(sf::Event event, float& y, float& x, int& obj_id, int& object_stage) {
        if (event.type == sf::Event::Closed)
        {
            win.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                if (check(0, 16) == true)
                {
                    y += 16;
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                if (obj_id == 1)
                {
                    obj_id = 0;
                }
                else if (obj_id == 0)
                {
                    obj_id = 1;
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                object_stage++;
                if (!check(16, 0))
                {
                    if (!check(-16, 0))
                    {
                        object_stage--;
                    }
                    else
                    {
                        if (obj_id == 0)
                        {
                            x -= 32;
                        }
                        else
                            x -= 16;
                    }
                }
                else if (!check(-16, 0))
                {
                    if (!check(+16, 0))
                    {
                        object_stage--;
                    }
                    else {
                        if (obj_id == 0)
                        {
                            x += 32;
                        }
                        else
                            x += 16;
                    }
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                if (check(16, 0) == true)
                {
                    x += 16;
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if (check(-16, 0) == true)
                {
                    x -= 16;
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (check(x, y) == true)
                {
                    x += 16;
                }
            }
        }
    }

    //function to make main pole 
    void poleMaker() {
        ;
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

    void nextfig() {
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
    bool check(float xI, float yI)
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
    float check_for_line() {
        int pole_t = 0;
        for (int i = 1; i < pole_size.x - 1; i++) {
            pole_t = 0;
            for (int j = 1; j < pole_size.y - 1; j++) {
                if (vec[i][j] == 1) {
                    pole_t += 1;

                    if (pole_t == 10) {
                        return i;
                        std::cout << "line:" << i << std::endl;
                    }
                }

            }
        }
        return -1;
    }

    //recolision of wall game
    void recolision() {
        std::set<std::pair<float, float>> temp_col;
        float tt = 0;
        float jt = 0;
        for (int t = 0; t < pole_size.x; t++) {
            for (int j = 0; j < pole_size.y; j++) {
                if (vec[t][j] == 1) {
                    tt = t * 16;
                    jt = j * 16;

                    temp_col.insert({ jt,tt });
                }
            }
        }
        collision_cords = temp_col;
    }

    void linexfixer(int t) {
        std::vector<std::vector<int>> tempvec(pole_size.x, std::vector<int>(pole_size.y));
        std::vector<std::vector<int>> tempcol(pole_size.x, std::vector<int>(pole_size.y));
        for (int i = 0; i != pole_size.x; i++) {
            tempvec[i][0] = 1;
            tempvec[i][11] = 1;
            tempcol[i][0] = 0;
            tempcol[i][11] = 0;
        }
        for (int i = 0; i != pole_size.y; i++) {
            tempvec[21][i] = 1;
        }

        for (int i = t; i != pole_size.x; i++) {
            for (int j = 1; j != pole_size.y; j++) {
                tempvec[i][j] = vec[i][j];
                tempcol[i][j] = collors_cords[i][j];
            }
        }
        for (int i = t; i != 0; i--) {
            for (int j = 1; j != pole_size.y; j++) {
                tempvec[i][j] = vec[i - 1][j];
                tempcol[i][j] = collors_cords[i - 1][j];
            }
        }
        vec = tempvec;
        collors_cords = tempcol;
        recolision();
    }

    void linedel(int obj_id, float x, float y) {
        int k = 0;
        if (check_for_line() != -1) {
            k = check_for_line();
            if (obj_id == 7) {
                std::vector<std::pair<int, int>> coords;
                coords.push_back({ x,y });
                coords.push_back({ x + 1,y });
                coords.push_back({ x - 1,y });
                coords.push_back({ x,y + 1 });
                coords.push_back({ x,y - 1 });
                for (auto x : coords) {
                    vec[x.first][x.second] = 0;
                    for (int ku = 0; ku < collision_cords.size(); ku++) {
                        if (collision_cords.find({ x.first * 16 ,x.second * 16 }) != collision_cords.end()) {
                            collision_cords.erase(collision_cords.find({ x.first * 16,x.second * 16 }));

                        }
                    }
                }
            }
            else {
                for (int i = 1; i < pole_size.y; i++) {
                    vec[k][i] = 0;
                    for (int ku = 0; ku < collision_cords.size(); ku++) {
                        if (collision_cords.find({ i * 16 ,k * 16 }) != collision_cords.end()) {
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
    void draw(float& y, float& x, int& obj_id, int& object_stage, int& collor_id, int& objR)
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

    //end of game,closes game
    void game_over(int& game_stage)
    {
        std::cout << "Game Over";
        game_stage = 0;
    }
};

int main() {
    Game game;

    game.run();

    return 0;
}