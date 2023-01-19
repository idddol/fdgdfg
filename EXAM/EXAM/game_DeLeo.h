#pragma once
#include <iostream>
#include <vector>
#include <string>

// �������������� ������
typedef struct Gamer {
	std::string name;
	int gold;
	int wood;
	int stone;
	int cube_1;
	int cube_2;
	int cube_3;
	bool has_additional_cube; // ���. �����
	int additional_cude; // ���. �����
	int building_tokens; // ������ ������
	bool has_adviser; // ��������
	int military_register; // �������� ��������� �������
	int victory_points; // �������� ����
	std::vector<std::string> buildings; // ������ ��������

} Gamer;

// �������� � �������� ��� �����
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
