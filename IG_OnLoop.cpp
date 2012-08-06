#include "StateInGame.h"

void StateInGame::OnLoop()
{
    for (int i = 0; i < Entity::entityList.size(); i++)
    {
        if (!Entity::entityList[i])
            continue;

        Entity::entityList[i]->OnLoop();
    }

    //Para las colisiones
    for (int i = 0; i < EntityCol::entityColList.size(); i++)
    {
        Entity* entidadA = EntityCol::entityColList[i].entidadA;
        Entity* entidadB = EntityCol::entityColList[i].entidadB;

        if (entidadA == NULL || entidadB == NULL)
            continue;

        if (entidadA -> OnCollision(entidadB))
            entidadB -> OnCollision(entidadA);
    }

    EntityCol::entityColList.clear();
}
