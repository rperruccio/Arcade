#include "StateInGame.h"
//otra prueba lala
void StateInGame::OnActivate()
{
    if (Area::areaControl.OnLoad("./Maps/1.area") == NULL)
        return;


    if ((Zero.OnLoad("./Imagenes/Zero.png", 50, 50, 10)) == NULL)
        return;

    Zero.x = 250;
    Zero.y = 100;
    Zero.SetColFrame(0);
    Entity::entityList.push_back(&Zero);


    Gate* gate1 = new Gate();
    if ((gate1->OnLoad("./Imagenes/Gate.png", 20, 60, 1)) == NULL)
        return;

    gate1 -> x = 0;
    gate1 -> y = 600;
    gate1 -> SetColFrame(0);
    Entity::entityList.push_back(gate1);

    Gate* gate2 = new Gate();
    if ((gate2->OnLoad("./Imagenes/Gate.png", 20, 60, 1)) == NULL)
        return;

    gate2 -> x = 980;
    gate2 -> y = 20;
    gate2 -> SetColFrame(0);
    gate2 -> Set(1, 1);
    Entity::entityList.push_back(gate2);


    gate1 -> SetGate(gate2);
    gate2 -> SetGate(gate1);


    Camara::camaraControl.targetMode = TARGET_MODE_NORMAL;
    Camara::camaraControl.SetPos(0, 0);
}
