#include "game_DeLeo.h"
#include <iostream>

Game_Deleo::Game_Deleo()
{
	year = 1;
	phase = 0;
	enemy = "";
};

Game_Deleo::Game_Deleo(int number) {
	for (int i = 0; i < number; i++)
		this->gamers.push(Gamer{});
};

Game_Deleo::~Game_Deleo()
{
};

void Game_Deleo::phase1() {

};

void Game_Deleo::phase3() {

};

void Game_Deleo::phase5() {

};

void Game_Deleo::phase7() {

};

void Game_Deleo::phase8() {

};