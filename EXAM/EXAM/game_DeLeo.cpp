#include "game_DeLeo.h"
#include <iostream>

Game_Deleo::Game_Deleo()
{
	this->year = 1;
	this->phase = 1;
}

Game_Deleo::Game_Deleo(int number) {
	for (int i = 0; i < number; i++)
		this->gamers.push(Gamer{});
}

Game_Deleo::Game_Deleo(int gamers_count)
{
	this->year = 1;
	this->phase = 1;
	for (int i = 0; i < gamers_count; i++)
	{
		this->gamers.push_back(Gamer());
		std::cout << "Name >> ";
		std::cin >> this->gamers[i].name;
		this->gamers[i].has_additional_cube = false;
		this->gamers[i].building_tokens = 17;
		this->gamers[i].has_adviser = false;
		this->gamers[i].military_register = 0;
		this->gamers[i].victory_points = 0;
	}
	this->advisers.push_back({ "Jester", "" }); // ���
	this->advisers.push_back({ "Squire", "" }); // ������
	this->advisers.push_back({ "Architect", "" }); // ������
	this->advisers.push_back({ "Merchant", "" }); // �����
	this->advisers.push_back({ "Sergeant", "" }); // �������
	this->advisers.push_back({ "Alchemist", "" }); // �������
	this->advisers.push_back({ "Astrologer", "" }); // ���������
	this->advisers.push_back({ "Treasurer", "" }); // ��������
	this->advisers.push_back({ "Huntress", "" }); // ��������
	this->advisers.push_back({ "General", "" }); // �������
	this->advisers.push_back({ "Gunsmith", "" }); // ���������
	this->advisers.push_back({ "Duchess", "" }); // ���������
	this->advisers.push_back({ "Hero", "" }); // �����
	this->advisers.push_back({ "Smuggler", "" }); // �������������
	this->advisers.push_back({ "Inventor", "" }); // ������������
	this->advisers.push_back({ "Wizard", "" }); // ���������
	this->advisers.push_back({ "Queen", "" }); // ��������
	this->advisers.push_back({ "King", "" }); // ������
}

Game_Deleo::Game_Deleo(const Game_Deleo& c_game)
{
	// ����������� �������
	for (int i = 0; i < c_game.gamers.size(); i++)
	{
		if (this->gamers.size() < i + 1) // ���� ��� ����� ������
			this->gamers.push_back(c_game.gamers[i]);
		else // ���� ������������
			this->gamers[i] = c_game.gamers[i];
	}
	// ����������� ����������
	for (int i = 0; i < 18; i++)
	{
		if (this->advisers.size() < i + 1)
			this->advisers.push_back(c_game.advisers[i]);
		else
			this->advisers[i] = c_game.advisers[i];
	}
	this->year = c_game.year;
	this->phase = c_game.phase;
	this->enemy = c_game.enemy;
}

Game_Deleo::~Game_Deleo()
{
}

void Game_Deleo::phase1()
{
	std::cout << "##### Year " << this->year << " Phase 1. Help of the king ######" << std::endl;
	if (this->year == 1 && this->phase == 1) {
		// �� ������ ���� �������� ������ �����
		for (int i = 0; i < this->gamers.size(); i++)
		{
			std::string product;
			std::cout << "Gamer " << this->gamers[i].name << ", choose your product: gold/wood/stone" << std::endl;
			std::cin >> product;
			if (product == "gold") this->gamers[i].gold++;
			else if (product == "wood") this->gamers[i].wood++;
			else if (product == "stone") this->gamers[i].stone++;
		}
	}
	else
	{
		// �������� �� �������� ���������� ������
		std::vector<Gamer> candidates;
		int min_buildings = this->gamers[0].buildings.size();
		for (auto g : this->gamers)
		{
			if (g.buildings.size() < min_buildings)
			{
				min_buildings = g.buildings.size();
				candidates.clear();
				candidates.push_back(g);
			}
			else if (g.buildings.size() == min_buildings)
			{
				candidates.push_back(g);
			}
		}
		// ���� �������� ����
		if (candidates.size() == 1)
		{
			for (int i = 0; i < this->gamers.size(); i++)
				if (this->gamers[i].name == candidates[0].name) this->gamers[i].has_additional_cube = true;
		}
		// ���� �� ��������� �� ���������� �� ����� �������
		else {
			std::vector<Gamer> new_candidates;
			int count = 0;
			int sum_min = candidates[0].gold + candidates[0].wood + candidates[0].stone;
			for (auto c : candidates)
			{
				int sum_p = c.gold + c.wood + c.stone;
				if (sum_p < sum_min)
				{
					sum_min = c.gold + c.wood + c.stone;
					new_candidates.clear();
					new_candidates.push_back(c);
				}
				else if (sum_min == sum_p) new_candidates.push_back(c);
			}
			// ���� ������� ��������
			if (count == 1)
			{
				for (int i = 0; i < this->gamers.size(); i++)
					if (this->gamers[i].name == new_candidates[0].name) this->gamers[i].has_additional_cube = true;
			}
			else
			{
				// ���� �� ��������� �� ����� ������ ����
				for (int i = 0; i < this->gamers.size(); i++)
				{
					for (auto nc : new_candidates)
						if (nc.name == this->gamers[i].name)
						{
							std::string product;
							std::cout << "Gamer " << this->gamers[i].name << ", choose your product: gold/wood/stone";
							std::cin >> product;
							if (product == "gold") this->gamers[i].gold++;
							else if (product == "wood") this->gamers[i].wood++;
							else if (product == "stone") this->gamers[i].stone++;
						}
				}
			}
		}
	}

void Game_Deleo::phase3()
	{
		// ����� �� ��� � ���� ������ ����� ������
		std::cout << "##### Year " << this->year << " Phase 3. Royal award ######" << std::endl;
		std::vector<Gamer> candidates;
		int max_buildings = this->gamers[0].buildings.size();
		// ����� ����������
		for (auto g : this->gamers)
		{
			if (g.buildings.size() > max_buildings)
			{
				max_buildings = g.buildings.size();
				candidates.clear();
				candidates.push_back(g);
			}
			else if (g.buildings.size() == max_buildings) candidates.push_back(g);
		}
		// ���������� �����
		for (int i = 0; i < this->gamers.size(); i++)
		{
			for (auto c : candidates)
			{
				if (this->gamers[i].name == c.name)
				{
					std::cout << "Gamer " << c.name << " receives victory point" << std::endl;
					this->gamers[i].victory_points++;
				}
			}
		}
	}

void Game_Deleo::phase5()
{
	// ����������� ���������
	std::cout << "##### Year " << this->year << " Phase 5. Royal envoy ######" << std::endl;
	// �������� �� �������� ���������� ������
	std::vector<Gamer> candidates;
	int min_buildings = this->gamers[0].buildings.size();
	for (auto g : this->gamers)
	{
		if (g.buildings.size() < min_buildings)
		{
			min_buildings = g.buildings.size();
			candidates.clear();
			candidates.push_back(g);
		}
		else if (g.buildings.size() == min_buildings)
		{
			candidates.push_back(g);
		}
	}
	// ���� �������� ����
	if (candidates.size() == 1)
	{
		for (int i = 0; i < this->gamers.size(); i++)
			if (this->gamers[i].name == candidates[0].name) this->gamers[i].has_adviser = true;
	}
	// ���� �� ��������� �� ���������� �� ����� �������
	else {
		std::vector<Gamer> new_candidates;
		int count = 0;
		int sum_min = candidates[0].gold + candidates[0].wood + candidates[0].stone;
		for (auto c : candidates)
		{
			int sum_p = c.gold + c.wood + c.stone;
			if (sum_p < sum_min)
			{
				sum_min = c.gold + c.wood + c.stone;
				new_candidates.clear();
				new_candidates.push_back(c);
			}
			else if (sum_min == sum_p) new_candidates.push_back(c);
		}
		// ���� ������� ��������
		if (count == 1)
		{
			for (int i = 0; i < this->gamers.size(); i++)
				if (this->gamers[i].name == new_candidates[0].name) this->gamers[i].has_adviser = true;
		}
	}
	for (auto g : this->gamers) std::cout << "Gamer " << g.name << " now has royal envoy" << std::endl;
}


void Game_Deleo::phase7() {

}

void Game_Deleo::phase8() {

}
