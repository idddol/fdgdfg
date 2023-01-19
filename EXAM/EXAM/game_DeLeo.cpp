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
	this->advisers.push_back({ "Jester", "" }); // шут
	this->advisers.push_back({ "Squire", "" }); // сквайр
	this->advisers.push_back({ "Architect", "" }); // зодчий
	this->advisers.push_back({ "Merchant", "" }); // купец
	this->advisers.push_back({ "Sergeant", "" }); // сержант
	this->advisers.push_back({ "Alchemist", "" }); // алхимик
	this->advisers.push_back({ "Astrologer", "" }); // звездочёт
	this->advisers.push_back({ "Treasurer", "" }); // казначей
	this->advisers.push_back({ "Huntress", "" }); // охотница
	this->advisers.push_back({ "General", "" }); // генерал
	this->advisers.push_back({ "Gunsmith", "" }); // оружейник
	this->advisers.push_back({ "Duchess", "" }); // герцогиня
	this->advisers.push_back({ "Hero", "" }); // герой
	this->advisers.push_back({ "Smuggler", "" }); // контрабандист
	this->advisers.push_back({ "Inventor", "" }); // изобретатель
	this->advisers.push_back({ "Wizard", "" }); // волшебник
	this->advisers.push_back({ "Queen", "" }); // королева
	this->advisers.push_back({ "King", "" }); // король
}

Game_Deleo::Game_Deleo(const Game_Deleo& c_game)
{
	// копирование игроков
	for (int i = 0; i < c_game.gamers.size(); i++)
	{
		if (this->gamers.size() < i + 1) // если это новый объект
			this->gamers.push_back(c_game.gamers[i]);
		else // если существуюший
			this->gamers[i] = c_game.gamers[i];
	}
	// копирование советников
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
		// на первой фазе выбираем только товар
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
		// выбираем по меньшему количеству зданий
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
		// если кандидат один
		if (candidates.size() == 1)
		{
			for (int i = 0; i < this->gamers.size(); i++)
				if (this->gamers[i].name == candidates[0].name) this->gamers[i].has_additional_cube = true;
		}
		// если их несколько то сравниваем по сумме товаров
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
			// если нашёлся кандидат
			if (count == 1)
			{
				for (int i = 0; i < this->gamers.size(); i++)
					if (this->gamers[i].name == new_candidates[0].name) this->gamers[i].has_additional_cube = true;
			}
			else
			{
				// если их несколько то выдаём товары всем
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
		// выдаём ПО тем у кого больше всего зданий
		std::cout << "##### Year " << this->year << " Phase 3. Royal award ######" << std::endl;
		std::vector<Gamer> candidates;
		int max_buildings = this->gamers[0].buildings.size();
		// поиск кандидатов
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
		// начисление очков
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
	// королевский посланник
	std::cout << "##### Year " << this->year << " Phase 5. Royal envoy ######" << std::endl;
	// выбираем по меньшему количеству зданий
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
	// если кандидат один
	if (candidates.size() == 1)
	{
		for (int i = 0; i < this->gamers.size(); i++)
			if (this->gamers[i].name == candidates[0].name) this->gamers[i].has_adviser = true;
	}
	// если их несколько то сравниваем по сумме товаров
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
		// если нашёлся кандидат
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
