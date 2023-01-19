#include "game_DeLeo.h"
#include <iostream>
#include <fstream>
#include <string>

Game_Deleo::Game_Deleo()
{
	this->year = 1;
	this->phase = 1;
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

void Game_Deleo::phase246() {
	
};

/*void Game_Deleo::advisor_help(Gamer& gamer, Adviser& adviser)
{
	int j;
	if (adviser[0].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == adviser[0].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[0].advisor_name « " gived " « advisor[0].gamer_name « " 1 vp" « std::endl;

		gamer[j].victory_points++;
	}
	else if (advisor[1].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[1].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[1].advisor_name « " gived " « advisor[1].gamer_name « " 1 gold" « std::endl;

		gamer[j].gold++;
	}
	else if (advisor[2].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[2].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[2].advisor_name « " gived " « advisor[2].gamer_name « " 1 wood" « std::endl;

		gamer[j].wood++;
	}
	else if (advisor[3].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[3].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[3].advisor_name « " gived " « advisor[3].gamer_name « " 1 gold or 1 wood" « std::endl;

		std::cout « "gold?";
		std::string s;
		cin » s;
		if (s == "yes") gamer[j].gold++;
		else gamer[j].wood++;
	}
	else if (advisor[4].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[4].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[4].advisor_name « " gived " « advisor[4].gamer_name « " 1 milit" « std::endl;

		gamer[j].military_register++;
	}
	else if (advisor[5].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[5].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[5].advisor_name « " gived " « advisor[5].gamer_name « " 2 another resourse by your 1" « std::endl;

		std::cout « "What you wanna give?";
		std::string s;
		cin » s;
		if (s == "gold") gamer[j].gold -= 2;
		else if (s == "wood") gamer[j].wood -= 2;
		else if (s == "stone") gamer[j].stone -= 2;
		gamer[j].gold++;
		gamer[j].wood++;
		gamer[j].stone++;
	}
	else if (advisor[6].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[6].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[6].advisor_name « " gived " « advisor[6].gamer_name « " 1 resourse and 1 token" « std::endl;

		std::cout « "What you wanna have?";
		std::string s;
		cin » s;
		if (s == "gold") gamer[j].gold++;
		else if (s == "wood") gamer[j].wood++;
		else if (s == "stone") gamer[j].stone++;
	}
	else if (advisor[7].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[7].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[7].advisor_name « " gived " « advisor[7].gamer_name « " 2 gold" « std::endl;

		gamer[j].gold += 2;
	}
	else if (advisor[8].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[8].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[8].advisor_name « " gived " « advisor[8].gamer_name « " 1 wood and 1 gold or 1 wood and 1 stone" « std::endl;

		std::cout « "What you wanna have?";
		std::string s;
		cin » s;
		if (s == "gold") gamer[j].gold++;
		else if (s == "stone") gamer[j].stone++;
		gamer[j].wood++;
	}
	else if (advisor[9].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[9].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout << "The " « advisor[9].advisor_name « " gived " « advisor[9].gamer_name « " 2 militar and see the hightest enemy" « std::endl;

		gamer[j].military_register += 2;
		//watch enemy
	}
	else if (advisor[10].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[10].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[10].advisor_name « " gived " « advisor[10].gamer_name « " 1 stone and 1 wood or 1 stone and 1
			gold" « std::endl;

			std::cout « "What you wanna have?";
		std::string s;
		cin » s;
		if (s == "gold") gamer[j].gold++;
		else if (s == "wood") gamer[j].wood++;
		gamer[j].stone++;
	}
	else if (advisor[11].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[11].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[11].advisor_name « " gived " « advisor[11].gamer_name « " 2 resourses and 1 token" « std::endl;

		std::cout « "What you wanna have?";
		std::string s;
		cin » s;
		if (s == "gold") gamer[j].gold++;
		else if (s == "wood") gamer[j].wood++;
		else if (s == "stone") gamer[j].stone++;

		std::cout « "What you wanna have?";
		cin » s;
		if (s == "gold") gamer[j].gold++;
		else if (s == "wood") gamer[j].wood++;
		else if (s == "stone") gamer[j].stone++;

		gamer[j].token++;
	}
	else if (advisor[12].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[12].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[12].advisor_name « " gived " « advisor[12].gamer_name « " 3 stone" « std::endl;

		gamer[j].stone += 3;
	}
	else if (advisor[13].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[13].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[13].advisor_name « " gived " « advisor[13].gamer_name « " - 1 vp for 3 resourses" « std::endl;

		gamer[j].victory_points —;

		std::cout « "What you wanna have?";
		std::string s;
		cin » s;
		if (s == "gold") gamer[j].gold++;
		else if (s == "wood") gamer[j].wood++;
		else if (s == "stone") gamer[j].stone++;

		std::cout « "What you wanna have?";
		cin » s;
		if (s == "gold") gamer[j].gold++;
		else if (s == "wood") gamer[j].wood++;
		else if (s == "stone") gamer[j].stone++;

		std::cout « "What you wanna have?";
		cin » s;
		if (s == "gold") gamer[j].gold++;
		else if (s == "wood") gamer[j].wood++;
		else if (s == "stone") gamer[j].stone++;
	}
	else if (advisor[14].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[14].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[14].advisor_name « " gived " « advisor[14].gamer_name « " 1 gold 1 wood 1 stone" « std::endl;

		gamer[j].gold++;
		gamer[j].wood++;
		gamer[j].stone++;
	}
	else if (advisor[15].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[15].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[15].advisor_name « " gived " « advisor[15].gamer_name « " 4 gold" « std::endl;

		gold += 4;
	}
	else if (advisor[16].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[16].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[16].advisor_name « " gived " « advisor[16].gamer_name « " 2 resourses and see the hightest enemy and 3 vp" « std::endl;

		std::cout « "What you wanna have?";
		std::string s;
		cin » s;
		if (s == "gold") gamer[j].gold++;
		else if (s == "wood") gamer[j].wood++;
		else if (s == "stone") gamer[j].stone++;

		std::cout « "What you wanna have?";
		cin » s;
		if (s == "gold") gamer[j].gold++;
		else if (s == "wood") gamer[j].wood++;
		else if (s == "stone") gamer[j].stone++;

		gamer[j].victory_points += 3;

		//watch enemy
	}
	else if (advisor[17].gamer_name != "0")
	{
		for (int i = 0; i < gamers.size; i++)
		{
			if (gamer[i].name == advisor[17].gamer_name)
			{
				j = i;
				continue;
			}
		}
		std::cout « "The " « advisor[17].advisor_name « " gived " « advisor[17].gamer_name « " 1 gold 1 stone 1 wood and 1 military" « std::endl;

		gamer[j].gold++;
		gamer[j].wood++;
		gamer[j].stone++;
		gamer[j].military_register++;
	}*/


bool Game_Deleo::load_game(const std::string filename, Gamer& gamer, Adviser& adviser) {
	std::string a;
	int n = 0;
	std::fstream fs;
	fs.open(filename, std::fstream::in);
	while (std::getline(fs,a)) {
		if (n == 0) {
			gamer.name = a;
			n++;
		}
		if (n == 1) {
			gamer.gold = stoi(a);
			n++;
		}
		if (n == 2) {
			gamer.wood = stoi(a);
			n++;
		}
		if (n == 3) {
			gamer.stone = stoi(a);
			n++;
		}
		if (n == 4) {
			gamer.cube_1 = stoi(a);
			n++;
		}
		if (n == 5) {
			gamer.cube_2 = stoi(a);
			n++;
		}
		if (n == 6) {
			gamer.cube_3 = stoi(a);
			n++;
		}
		if (n == 7) {
			gamer.has_additional_cube = stoi(a);
			n++;
		}
		if (n == 8) {
			gamer.additional_cude = stoi(a);
			n++;
		}
		if (n == 9) {
			gamer.building_tokens = stoi(a);
			n++;
		}
		if (n == 10) {
			gamer.has_adviser = stoi(a);
			n++;
		}
		if (n == 11) {
			gamer.military_register = stoi(a);
			n++;
		}
		if (n == 12) {
			gamer.victory_points = stoi(a);
			n++;
		}
		if (n == 13) {
			gamer.buildings[0] = a;
			n++;
		}
		if (n == 14) {
			adviser.adviser_name = a;
			n++;
		}
		if (n == 15) {
			adviser.gamer_name = a;
			n++;
		}
		if (n == 16) {
			this->year = stoi(a);
			n++;
		}
		if (n == 17) {
			this->phase = stoi(a);
			n++;
		}
		if (n == 18) {
			this->enemy = a;
			n++;
		}
	}
	fs.close();
}
/*bool Game_Deleo::save_game(const std::string filename, Gamer& gamer, Adviser& adviser) {
	std::string a;
	int n = 0;
	std::fstream fs;
	fs.open(filename, std::fstream::out);
	while (n <= 18) {
		if (n == 0) {
			fs << gamer.name;
			fs << "\n";
			n++;
		}
		if (n == 1) {
			gamer.gold = stoi(a);
			n++;
		}
		if (n == 2) {
			gamer.wood = stoi(a);
			n++;
		}
		if (n == 3) {
			gamer.stone = stoi(a);
			n++;
		}
		if (n == 4) {
			gamer.cube_1 = stoi(a);
			n++;
		}
		if (n == 5) {
			gamer.cube_2 = stoi(a);
			n++;
		}
		if (n == 6) {
			gamer.cube_3 = stoi(a);
			n++;
		}
		if (n == 7) {
			gamer.has_additional_cube = stoi(a);
			n++;
		}
		if (n == 8) {
			gamer.additional_cude = stoi(a);
			n++;
		}
		if (n == 9) {
			gamer.building_tokens = stoi(a);
			n++;
		}
		if (n == 10) {
			gamer.has_adviser = stoi(a);
			n++;
		}
		if (n == 11) {
			gamer.military_register = stoi(a);
			n++;
		}
		if (n == 12) {
			gamer.victory_points = stoi(a);
			n++;
		}
		if (n == 13) {
			gamer.buildings[0] = a;
			n++;
		}
		if (n == 14) {
			adviser.adviser_name = a;
			n++;
		}
		if (n == 15) {
			adviser.gamer_name = a;
			n++;
		}
		if (n == 16) {
			this->year = stoi(a);
			n++;
		}
		if (n == 17) {
			this->phase = stoi(a);
			n++;
		}
		if (n == 18) {
			this->enemy = a;
			n++;
		}
	}
	fs.close();
}*/