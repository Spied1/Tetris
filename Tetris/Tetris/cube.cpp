//#include "cube.hpp"
//class cube contains information of textures
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cube.hpp"

cube::cube(int TposX, int TposY, int color_id = 0) 
	:posX(TposX), posY(TposY), color_idk(color_id) {
		if (color_id == 0) {
			if (!cubeT.loadFromFile("textures/cube/cube.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube.png" << std::endl;
			};
		}
		else if (color_id == 1) {
			if (!cubeT.loadFromFile("textures/cube/cube_blue.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_blue.png" << std::endl;
			};
		}
		else if (color_id == 2) {
			if (!cubeT.loadFromFile("textures/cube/cube_cyan.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_cyan.png" << std::endl;
			};
		}
		else if (color_id == 3) {
			if (!cubeT.loadFromFile("textures/cube/cube_green.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_green.png" << std::endl;
			};
		}
		else if (color_id == 4) {
			if (!cubeT.loadFromFile("textures/cube/cube_orange.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_orange.png" << std::endl;
			};
		}
		else if (color_id == 5) {
			if (!cubeT.loadFromFile("textures/cube/cube_purple.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_purple.png" << std::endl;
			};
		}
		else if (color_id == 6) {
			if (!cubeT.loadFromFile("textures/cube/cube_red.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_red.png" << std::endl;
			};
		}
		else if (color_id == 7) {
			if (!cubeT.loadFromFile("textures/cube/cube_yellow.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_yellow.png" << std::endl;
			};
		}
		cubeS.setPosition(sf::Vector2f(posX, posY));
		cubeT.setSmooth(false);
		cubeS.setTexture(cubeT);
	}