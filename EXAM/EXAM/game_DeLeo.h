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

} gamers;

// �������� � �������� ��� �����
typedef struct Adviser {
	std::string advisers_name;
	std::string gamers_name;
	Adviser(std::string a_name, std::string g_name)
	{
		this->advisers_name = a_name;
		this->gamers_name = g_name;
	}
} Adviser;

class Game_Deleo
{
private:
	std::vector<gamers> gamers;
	std::vector<Adviser> advisers;
	int year;
	int phase;
	std::string enemy;
public:
	Game_Deleo();
	~Game_Deleo();
	Game_Deleo(int gamers_count);
	Game_Deleo(const Game_Deleo& c_game);

	bool load_game(const std::string filename, Gamer& gamers, Adviser& adviser);
	bool save_game(const std::string filename, Gamer& gamers, Adviser& adviser);
	void adviser_help(Gamer& gamers, Adviser& advisers);

	void phase1();
	void phase3();
	void phase5();
	void phase7();
	void phase8();
	void phase246_adviser();
};
