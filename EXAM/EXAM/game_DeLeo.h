#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

enum building {
	Statuya,
	Chasovnya,
	Zerkov,
	Sobor,
	Tractir,
	Rinok,
	Farms,
	Torg_guild,
	Kazarms,
	Palisad,
	Konushni,
	Kamen_sten,
	Krepost,
	Chastokol,
	Tower,
	Ratusha,
	Posolstvo
};

enum resource {
	Gold,//золото
	Wood,//дерево
	Rock,//камень
	Token,//жетоны
	Cube1,//кубик1
	Cube2,//кубик2
	Cube3,//кубик3
	Add_cube //доп кубик
};

struct Sovetnik {
	string name; //имя советника
	string player_name; //имя игрока
};

struct Gamer {
	string name; //имя игрока
	bool sovetnik; //наличие советника
	vector <resource> resources;//ресурсы игрока
	int registr; //значение воинского регистра
	int score; //количество победных очков
	vector<building> buildings;//постройки игрока
};

class Game_Deleo
{
private:
	stack<Gamer> gamers;
	vector<Sovetnik> sovetniks;

	int year;//год
	int phase;//фаза
	string enemy;//враг
public:
	void phase1();
	void phase2();
	void phase3();
	void phase4();
	void phase5();
	void phase6();
	void phase7();
	void phase8();

	Game_Deleo();
	Game_Deleo(int number);
	Game_Deleo(const Game_Deleo& game);
	~Game_Deleo();

	void defense_level(const char* enemy, int kings_help, Gamer& gamer);
};