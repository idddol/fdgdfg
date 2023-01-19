#pragma once
#include <iostream>
#include <vector>
#include <string>

// Характеристики игрока
typedef struct Gamer {
	std::string name;
	int gold;
	int wood;
	int stone;
	int cube_1;
	int cube_2;
	int cube_3;
	bool has_additional_cube; // доп. кубик
	int additional_cude; // доп. кубик
	int building_tokens; // жетоны зданий
	bool has_adviser; // советник
	int military_register; // значение воинского реестра
	int victory_points; // победные очки
	std::vector<std::string> buildings; // вектор построек

} Gamer;

// советник и занявший его игрок
typedef struct Adviser {
	std::string adviser_name;
	std::string gamer_name;
	Adviser(std::string a_name, std::string g_name)
	{
		this->adviser_name = a_name;
		this->gamer_name = g_name;
	}
} Adviser;

class Game_Deleo
{
private:
	std::vector<Gamer> gamers;
	std::vector<Adviser> advisers;
	int year;
	int phase;
	std::string enemy;
public:
	Game_Deleo();
	~Game_Deleo();
	Game_Deleo(int number);
	Game_Deleo(const Game_Deleo&);

	void phase1();
	void phase3();
	void phase5();
	void phase7();
	void phase8();
};
