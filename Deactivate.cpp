#include "StateInGame.h"

void StateInGame::OnDeactivate()
{
    Area::areaControl.OnCleanup();

    for (int i = 0; i < Entity::entityList.size(); i++)
    {
        if (!Entity::entityList[i])
            continue;

        Entity::entityList[i]->OnCleanup();
    }

    Entity::entityList.clear();
}
