#include "Character.h"

Character::Character()
{
    accion = ACCION_PARADO;

    canJump = false;

}

Character::~Character()
{
    //dtor
}

bool Character::OnLoad(char* path, int width, int height, int maxFrames)
{
    if (Entity::OnLoad(path, width, height, maxFrames) == false)
        return false;

    return true;

}

void Character::OnLoop()
{
    Entity::OnLoop();
    if (this->speedX == 0)
        accion = ACCION_PARADO;
    else
        accion = ACCION_CAMINANDO;
}

void Character::OnRender(SDL_Surface* pantalla)
{
    if (pantalla == NULL)
        return;

    Entity::OnRender(pantalla);
}

void Character::OnCleanup()
{
    Entity::OnCleanup();
}

void Character::OnAnimate()
{
    if (speedX != 0)
    {
        animControl.maxFrames = 10;
        colFrame = 2;
    }
    else
    {
        animControl.maxFrames = 10;
        colFrame = 0;
    }

    Entity::OnAnimate();
}

bool Character::OnCollision(Entity* e)
{

}




