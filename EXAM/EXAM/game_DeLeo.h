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
	Gold,//������
	Wood,//������
	Rock,//������
	Token,//������
	Cube1,//�����1
	Cube2,//�����2
	Cube3,//�����3
	Add_cube //��� �����
};

struct Sovetnik {
	string name; //��� ���������
	string player_name; //��� ������
};

struct Gamer {
	string name; //��� ������
	bool sovetnik; //������� ���������
	vector <resource> resources;//������� ������
	int registr; //�������� ��������� ��������
	int score; //���������� �������� �����
	vector<building> buildings;//��������� ������
};

class Game_Deleo
{
private:
	stack<Gamer> gamers;
	vector<Sovetnik> sovetniks;

	int year;//���
	int phase;//����
	string enemy;//����
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