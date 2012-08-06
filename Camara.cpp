#include "Camara.h"

Camara Camara::camaraControl;

Camara::Camara()
{
    targetMode = TARGET_MODE_NORMAL;

    targetX = targetY = NULL;

    x = y = 0;
}

Camara::~Camara(){}

void Camara::OnMove(int moveX, int moveY)
{
    this->x += moveX;
    this->y += moveY;
}

int Camara::GetX()
{
    if (targetX != NULL)
    {
        if (targetMode == TARGET_MODE_CENTER)
            return *targetX - (WWIDTH / 2);

        return *targetX;
    }

    return this->x;
}

int Camara::GetY()
{
    if (targetY != NULL)
    {
        if (targetMode == TARGET_MODE_CENTER)
            return *targetY - (WHEIGHT / 2);

        return *targetY;
    }

    return this->y;
}

void Camara::SetPos(int X, int Y)
{
    this->x = X;
    this->y = Y;
}

void Camara::SetTarget(int* X, int* Y)
{
    this->targetX = X;
    this->targetY = Y;
}
