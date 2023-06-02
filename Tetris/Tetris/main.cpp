#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include <windows.h>
#include <stdlib.h>
#include<algorithm>
#include<set>



float sizeX = 192+108;
float sizeY = 352;
float delay = 0.5;
std::pair<int, int> polesize = { 22,12 };
float pointOfSpawnX = sizeX / 2;
float pointOfSpawnY = sizeY - 10;
sf::RenderWindow win(sf::VideoMode(sizeX, sizeY), "Tetris");
std::vector<std::vector<int>> vec(polesize.first, std::vector<int>(polesize.second));
std::set<std::pair<float, float>> collision_cords;
int points = 0;
std::vector<std::vector<int>> collors_cords(polesize.first, std::vector<int>(polesize.second));
std::vector<std::pair<float, float>> hitboxofobj(4);
bool pole_bool = 0;
class cube {
public:
	int posibl = 0;
	int posX = 0;
	int posY = 0;
	int color_idk = 0;
	sf::Texture cubeT;
	sf::Sprite cubeS;
	cube(int TposX, int TposY, int color_id = 0) :posX(TposX), posY(TposY), color_idk(color_id) {
		if (color_id == 0) {
			if (!cubeT.loadFromFile("D:/gamety/Tetris/textures/cube/cube.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube.png" << std::endl;
			};
		}
		else if (color_id == 1) {
			if (!cubeT.loadFromFile("D:/gamety/Tetris/textures/cube/cube_blue.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_blue.png" << std::endl;
			};
		}
		else if (color_id == 2) {
			if (!cubeT.loadFromFile("D:/gamety/Tetris/textures/cube/cube_cyan.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_cyan.png" << std::endl;
			};
		}
		else if (color_id == 3) {
			if (!cubeT.loadFromFile("D:/gamety/Tetris/textures/cube/cube_green.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_green.png" << std::endl;
			};
		}
		else if (color_id == 4) {
			if (!cubeT.loadFromFile("D:/gamety/Tetris/textures/cube/cube_orange.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_orange.png" << std::endl;
			};
		}
		else if (color_id == 5) {
			if (!cubeT.loadFromFile("D:/gamety/Tetris/textures/cube/cube_purple.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_purple.png" << std::endl;
			};
		}
		else if (color_id == 6) {
			if (!cubeT.loadFromFile("D:/gamety/Tetris/textures/cube/cube_red.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_red.png" << std::endl;
			};
		}
		else if (color_id == 7) {
			if (!cubeT.loadFromFile("D:/gamety/Tetris/textures/cube/cube_yellow.png")) {
				std::cout << "No texture D:/gamety/Tetris/textures/cube/cube_yellow.png" << std::endl;
			};
		}
		cubeS.setPosition(sf::Vector2f(posX, posY));
		cubeT.setSmooth(false);
		cubeS.setTexture(cubeT);
		win.draw(cubeS);
	}

};




void poleMaker() {
	;
	for (int i = 0; i != polesize.first; i++) {
		vec[i][0] = 1;
		vec[i][11] = 1;

	}
	for (int i = 0; i != polesize.second; i++) {
		//vec[0][i] = 1;
		vec[21][i] = 1;
	}
	float x = 0;
	float y = 0;
	
	std::pair<float, float> temp;
	for (int i = 0; i != polesize.first; i++) {
		for (int j = 0; j != polesize.second; j++) {
			if (vec[i][j] == 1) {
				//std::cout << "color:" << collors_cords[{j * 16, i * 16}] << std::endl;
				if (i > -1 && j > -1) {
					new cube(j * 16, i * 16, collors_cords[i][j]);
				}
				else {
					new cube(j * 16, i * 16, 0);
				}
				if (pole_bool == false) {
					temp = { j * 16,i * 16 };
					std::cout << j << " " << i << std::endl;
					collision_cords.insert(temp);
				}
			}
		}
	}



	pole_bool = true;
}

class object {
	// I, S, Z, O, T, L, J
	// 0, 1, 2, 3, 4, 5, 6
public:
	std::vector < std::vector<int>> vec;
	object(int i, float x = pointOfSpawnX, float y = pointOfSpawnY, int object_stage = 0, int color_id = 0) {
		if (i == 0) {
			if (object_stage == 0) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y},{x - 2 * 16,y},{x + 1 * 16,y} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure I,stage 0 " << std::endl;
			}
			else if (object_stage == 1) {
				hitboxofobj = { {x ,y},{x,y - 1 * 16},{x,y - 2 * 16},{x,y + 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure I,stage 1 " << std::endl;
			}
			/*	std::cout << "figure I,stage 1 " << std::endl;
			iObj = {{1,1,1,1}};
			for (int i = 0; i < 1; i++) {
				for (int j = 0; j < 4; j++) {
					if (iObj[i][j] == 1) {
						new cube(x - j * 16, y - i * 16);
					}
				}
			}
		}*/
		}
		else if (i == -1) {
			new cube(x, y, color_id);
		}
		else if (i == 1) {
			if (object_stage == 0) {
				hitboxofobj = { {x ,y},{x,y - 1 * 16},{x - 1 * 16,y - 1 * 16},{x + 1 * 16,y} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure Z,stage 0 " << std::endl;
			}
			else if (object_stage == 1) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y },{x,y - 1 * 16},{x - 1 * 16,y + 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure Z,stage 1 " << std::endl;
			}
		}
		else if (i == 2) {
			if (object_stage == 0) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y},{x,y - 1 * 16},{x + 1 * 16,y - 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure S,stage 0 " << std::endl;
			}
			else if (object_stage == 1) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y },{x - 1 * 16,y - 1 * 16},{x,y + 1 * 16} };;
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure S,stage 1 " << std::endl;
			}
		}
		else if (i == 3) {

			hitboxofobj = { {x ,y},{x + 1 * 16,y + 1 * 16},{x,y + 1 * 16},{x + 1 * 16,y} };
			for (auto ku : hitboxofobj) {
				new cube(ku.first, ku.second, color_id);
			}
			std::cout << "figure O,stage 0 " << std::endl;
		}
		else if (i == 4) {
			if (object_stage == 0) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y},{x + 1 * 16,y},{x,y + 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure T,stage 0 " << std::endl;
			}
			else if (object_stage == 1) {
				hitboxofobj = { {x ,y},{x ,y + 1 * 16},{x,y - 1 * 16},{x + 1 * 16 ,y} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure T,stage 1 " << std::endl;
			}
			else if (object_stage == 2) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y },{x + 1 * 16,y},{x,y - 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure T,stage 2 " << std::endl;
			}
			else if (object_stage == 3) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y },{x,y - 1 * 16},{x,y + 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure T,stage 3 " << std::endl;
			}
		}
		else if (i == 5) {
			if (object_stage == 0) {
				hitboxofobj = { {x ,y},{x,y + 1 * 16},{x,y - 1 * 16},{x + 1 * 16,y + 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure L,stage 0 " << std::endl;
			}
			else if (object_stage == 1) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y},{x + 1 * 16,y},{x - 1 * 16 ,y + 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure L,stage 1 " << std::endl;
			}
			else if (object_stage == 2) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y - 1 * 16 },{x,y - 1 * 16},{x,y + 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure L,stage 2 " << std::endl;
			}
			else if (object_stage == 3) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y },{x + 1 * 16,y},{x + 1 * 16,y - 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure L,stage 3 " << std::endl;
			}
		}
		else if (i == 6) {
			if (object_stage == 0) {
				hitboxofobj = { {x ,y},{x,y + 1 * 16},{x,y - 1 * 16},{x - 1 * 16,y + 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure L,stage 0 " << std::endl;
			}
			else if (object_stage == 1) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y},{x + 1 * 16,y},{x - 1 * 16 ,y - 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure L,stage 1 " << std::endl;
			}
			else if (object_stage == 2) {
				hitboxofobj = { {x ,y},{x + 1 * 16,y - 1 * 16 },{x,y - 1 * 16},{x,y + 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure L,stage 2 " << std::endl;
			}
			else if (object_stage == 3) {
				hitboxofobj = { {x ,y},{x - 1 * 16,y },{x + 1 * 16,y},{x + 1 * 16,y + 1 * 16} };
				for (auto ku : hitboxofobj) {
					new cube(ku.first, ku.second, color_id);
				}
				std::cout << "figure L,stage 3 " << std::endl;
			}
		}
		else if (i == 7) {
			hitboxofobj = { {x ,y} };
			for (auto ku : hitboxofobj) {
				new cube(ku.first, ku.second, color_id);
			}
			std::cout << "figure BOMB,stage 0 " << std::endl;
		}
	}
};

void nextfig() {

	for (int i = 5; i != -1; i--) {
		new cube(192 + i * 16, 80, 0);
		new cube(192 + i * 16, 176, 0);
	}
	for (int i = 0; i != 7; i++) {
		new cube(272, 176 - i * 16, 0);
	}

	//object next(3, 272 - 48, 144 - 16, 1, 1);
	//object first(obj_id, x, y, object_stage % objR, collor_id);
}
bool check(float xI, float yI) {
	std::pair<float, float> temp = { xI,yI };
	for (auto collisions : collision_cords) {
		for (auto hitbox : hitboxofobj) {
			if (collisions.first == hitbox.first + xI && collisions.second == hitbox.second + yI) {
				return false;
			}
		}
	}
	return true;
}

float check_for_line() {
	int pole_t = 0;
	for (int i = 1; i < polesize.first - 1; i++) {
		pole_t = 0;
		for (int j = 1; j < polesize.second - 1; j++) {
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

void recolision() {
	std::set<std::pair<float, float>> temp_col;
	float tt = 0;
	float jt = 0;
	for (int t = 0; t < polesize.first; t++) {
		for (int j = 0; j < polesize.second; j++) {
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
	std::vector<std::vector<int>> tempvec(polesize.first, std::vector<int>(polesize.second));
	std::vector<std::vector<int>> tempcol(polesize.first, std::vector<int>(polesize.second));
	for (int i = 0; i != polesize.first; i++) {
		tempvec[i][0] = 1;
		tempvec[i][11] = 1;
		tempcol[i][0] = 0;
		tempcol[i][11] = 0;
	}
	for (int i = 0; i != polesize.second; i++) {
		tempvec[21][i] = 1;
	}

	for (int i = t; i != polesize.first; i++) {
		for (int j = 1; j != polesize.second; j++) {
			tempvec[i][j] = vec[i][j];
			tempcol[i][j] = collors_cords[i][j];
		}
	}
	for (int i = t; i != 0; i--) {
		for (int j = 1; j != polesize.second; j++) {
			tempvec[i][j] = vec[i - 1][j];
			tempcol[i][j] = collors_cords[i - 1][j];
		}
	}
	vec = tempvec;
	collors_cords = tempcol;
	recolision();
}

void linedel(int obj_id,float x,float y) {
	int k = 0;
	if (check_for_line() != -1) {
		k = check_for_line();
		if (obj_id == 7) {
			std::vector<std::pair<int,int>> coords;
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
			for (int i = 1; i < polesize.second; i++) {
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


void event_checker(sf::Event event, float& y, float& x, int& obj_id, int& object_stage) {
	if (event.type == sf::Event::Closed) {
		win.close();
	}
	else if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

			std::cout << "Down was pressed" << std::endl;
			if (check(0, 16) == true) {
				y += 16;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (obj_id == 1) {
				obj_id = 0;
			}
			else if (obj_id == 0) {
				obj_id = 1;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			object_stage++;
			if (!check(16, 0)) {
				if (!check(-16, 0)) {
					object_stage--;
				}
				else {
					if (obj_id == 0) {
						x -= 32;
					}
					else
						x -= 16;
				}
			}
			else if (!check(-16, 0)) {
				if (!check(+16, 0)) {
					object_stage--;
				}
				else {
					if (obj_id == 0) {
						x += 32;
					}
					else
						x += 16;
				}
			}
			std::cout << "Down was pressed" << std::endl;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

			std::cout << "Right was pressed" << std::endl;
			if (check(16, 0) == true) {
				x += 16;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			std::cout << "Right was pressed" << std::endl;
			if (check(-16, 0) == true) {
				x -= 16;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			std::cout << "Left was pressed" << std::endl;
			if (check(x, y) == true) {
				x += 16;
			}
		}
	}
}

void draw(float& y, float& x, int& obj_id, int& object_stage, int& collor_id, int& objR) {
	sf::Text point;
	if (!check(0, 16) == true) {
		int color_id = collor_id;

		if (x > -1 && y > -1) {
			for (auto ku : hitboxofobj) {
				collision_cords.insert(ku);
				std::pair<float, std::pair<float, int>> temp;
				int t1 = ku.first / 16;
				int t2 = ku.second / 16;
				collors_cords[t2][t1] = color_id;
				int a = ku.first;
				int b = ku.second;
				vec[b / 16][a / 16] = 1;
				x = 96;
				y = -32;
				obj_id = abs(rand()) % 8;
				//obj_id = 7;
				object_stage = abs(rand()) % objR;
				collor_id = abs(rand()) % 8;
			}
		}
	}
	win.clear();
	sf::Font font;
	font.loadFromFile("D:/gamety/Tetris/textures/cubic.ttf");
	point.setFont(font);
	point.setCharacterSize(24);
	point.setString(std::to_string(points));
	point.setPosition(272 - 74, 144 - 16);
	win.draw(point);
	object first(obj_id, x, y, object_stage % objR, collor_id);
	linedel(obj_id,x,y);
	poleMaker();
	nextfig();
	win.display();
}

void game_over(int& game_stage) {
	std::cout << "Game Over";
	game_stage = 0;
}

int main() {
	float x = 96;
	float y = -32;
	int object_stage = abs(rand()) % 8;
	int obj_id = abs(rand()) % 8;
	int objR = 0;
	sf::Clock clock;
	float timer = 0;
	
	int collor_id = abs(rand()) % 8;
	int game_stage = 1;
	while (game_stage == 1) {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		if (obj_id < 4) {
			objR = 2;
		}
		else {
			objR = 4;
		}

		sf::Event event;

		while (win.pollEvent(event)) {

			event_checker(event, y, x, obj_id, object_stage);

		}
		if (timer > delay) {
			y += 16;
			timer = 0;
			//std::cout << "delka" << std::endl;
		}
		for (int i = 1; i < 11; i++) {
			if (vec[0][i] == 1) {
				game_over(game_stage);
			}
		}
		draw(y, x, obj_id, object_stage, collor_id, objR);
	}
	return 0;
}