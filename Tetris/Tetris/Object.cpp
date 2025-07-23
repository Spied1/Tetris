#include"Object.hpp"

const std::vector<std::vector<std::vector<sf::Vector2f>>> SHAPES = 
{
    // 0 — I
    {
        {{0,0}, {-16,0}, {-32,0}, {16,0}},
        {{0,0}, {0,-16}, {0,-32}, {0,16}}
    },
    // 1 — J
    {
        {{0,0}, {0,-16}, {-16,-16}, {16,0}},
        {{0,0}, {-16,0}, {0,-16}, {-16,16}}
    },
    // 2 — L
    {
        {{0,0}, {-16,0}, {0,-16}, {16,-16}},
        {{0,0}, {-16,0}, {-16,-16}, {0,16}}
    },
    // 3 — квадрат
    {
        {{0,0}, {16,16}, {0,16}, {16,0}}
    },
    // 4 — T
    {
        {{0,0}, {-16,0}, {16,0}, {0,16}},
        {{0,0}, {0,16}, {0,-16}, {16,0}},
        {{0,0}, {-16,0}, {16,0}, {0,-16}},
        {{0,0}, {-16,0}, {0,-16}, {0,16}}
    },
    // 5 — S
    {
        {{0,0}, {0,16}, {0,-16}, {16,16}},
        {{0,0}, {-16,0}, {16,0}, {-16,16}},
        {{0,0}, {-16,-16}, {0,-16}, {0,16}},
        {{0,0}, {-16,0}, {16,0}, {16,-16}}
    },
    // 6 — Z
    {
        {{0,0}, {0,16}, {0,-16}, {-16,16}},
        {{0,0}, {-16,0}, {16,0}, {-16,-16}},
        {{0,0}, {16,-16}, {0,-16}, {0,16}},
        {{0,0}, {-16,0}, {16,0}, {16,16}}
    },
    // 7 — точка
    {
        {{0,0}}
    }
};

Object::Object(int i, float x, float y, int object_stage, int color_id)
{
    if (i < 0 || i >= SHAPES.size()) return;

    const auto& shape_stages = SHAPES[i];
    int stage = object_stage % shape_stages.size();

    for (const auto& offset : shape_stages[stage])
    {
        sf::Vector2f pos(x + offset.x, y + offset.y);
        hitbox_of_obj.push_back(pos);

        Cube* temp = new Cube(pos, color_id);
        object_sprites.push_back(temp->get_sprite());
        cubes.push_back(temp);
    }
}


std::vector<sf::Sprite>& Object::get_objects_sprites()
{
    return object_sprites;
}

std::vector<sf::Vector2f>& Object::get_hitbox_of_obj()
{
    return hitbox_of_obj;
}

Object::~Object()
{
    for (Cube* cube : cubes)
        delete cube;
    cubes.clear();
}