#include "StateInGame.h"

StateInGame StateInGame::instance;

StateInGame::StateInGame()
{
}

StateInGame::~StateInGame(){}

StateInGame* StateInGame::GetInstance()
{
    return &instance;
}
