#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

//class cube contains information of textures

class cube 
{
public:
	int posibl = 0;
	int posX = 0;
	int posY = 0;
	int color_idk = 0;
	sf::Texture cubeT;
	sf::Sprite cubeS;

	cube(int TposX, int TposY, int color_id);

};