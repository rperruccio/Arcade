#include "Player.h"

Player::Player()
{
    maxSpeedY = 20;

    poderUno = NONE;
    poderDos = NONE;
    poderTres = NONE;

    defendiendo = false;

    colX = 0;
    colWidth = 20;
    colY = 10;
    colHeight = 17;
}

Player::~Player()
{
    //dtor
}

bool Player::OnLoad(char* path, int width, int height, int maxFrames)
{
    if (Character::OnLoad(path, width, height, maxFrames) == false)
        return false;

    return true;

}

void Player::OnLoop()
{
    Character::OnLoop();
}

void Player::OnRender(SDL_Surface* pantalla)
{
    if (pantalla == NULL || imagen == NULL)
        return;

    Superficie::OnDraw(pantalla, imagen, x - Camara::camaraControl.GetX(), y - Camara::camaraControl.GetY(), (dir + accion) * width, (filaFrame + animControl.GetCurrentFrame()) * height, width, height);

}

void Player::OnCleanup()
{
    Character::OnCleanup();
}

void Player::OnAnimate()
{
    if (speedX != 0)
    {
        animControl.maxFrames = 10;
    }
    else
    {
        animControl.maxFrames = 10;
    }

    Character::OnAnimate();
}

bool Player::OnCollision(Entity* e)
{
    return true;
}

void Player::Defender()
{
    defendiendo = !defendiendo;
    accion = ACCION_CAMINANDO;
    if (defendiendo)
        accion = ACCION_PARADO;
}
