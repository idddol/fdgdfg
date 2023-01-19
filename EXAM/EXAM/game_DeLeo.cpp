#include "game_DeLeo.h"
#include <iostream>

Game_Deleo::Game_Deleo()
{

	year = 1;
	phase = 0;
	enemy = "";
}

Game_Deleo::Game_Deleo(int number) {
	for (int i = 0; i < number; i++)
		this->gamers.push(Gamer{});
}

Game_Deleo::Game_Deleo(const Game_Deleo& game) {
	this->phase = game.phase;
	this->year = game.year;
	this->enemy = game.enemy;
	this->sovetniks = game.sovetniks;
	this->gamers = game.gamers;
}

Game_Deleo::~Game_Deleo()
{
}

void Game_Deleo::phase1() {

}

void Game_Deleo::phase3() {

}

void Game_Deleo::phase5() {

}

void Game_Deleo::phase7() {

}

void Game_Deleo::phase8() {

}

void Game_Deleo::defense_level(const char* enemy, int king_help, Gamer& gamer) {

}