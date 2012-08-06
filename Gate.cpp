#include "Gate.h"

Gate::Gate()
{
    hov = VERTICAL;
    pos = ARRIBA_IZQUIERDA;

    destino = NULL;
}

Gate::~Gate()
{
    //dtor
}

/*============================================================================*/
bool Gate::OnLoad(char* path, int width, int height, int maxFrames)
{
    if (Entity::OnLoad(path, width, height, maxFrames) == false)
        return false;

    return true;

}

/*============================================================================*/
void Gate::Set(int hov, int pos)
{
    this->hov = hov;
    this->pos = pos;
}

/*============================================================================*/
bool Gate::SetGate(Gate* g)
{
    if (g == NULL)
        return false;

    this->destino = g;
    return true;
}

/*============================================================================*/
void Gate::OnLoop()
{
    Entity::OnLoop();
}

/*============================================================================*/
void Gate::OnRender(SDL_Surface* pantalla)
{
    Entity::OnRender(pantalla);
}

/*============================================================================*/
void Gate::OnCleanup()
{
    Entity::OnCleanup();
}

/*============================================================================*/
void Gate::OnAnimate()
{
    Entity::OnAnimate();
}

/*============================================================================*/
bool Gate::OnCollision(Entity* e)
{
    if (e == NULL || destino == NULL)
        return false;

    float X = destino -> DestinoX(e);
    float Y = destino -> DestinoY(e);

    e -> SetPos(X, Y);


    printf("%f :: %f \n", X, Y);

    return true;
}

/*============================================================================*/
int Gate::GetHov()
{
    return this->hov;
}

/*============================================================================*/
float Gate::DestinoY(Entity* e)
{
    if (hov == 1)
        return this->y + this->height/ 2.0f - e -> height/2.0f;

    return this->y + e->height * (pos - 1) + this->height * pos;
}

/*============================================================================*/
float Gate::DestinoX(Entity* e)
{
    if (hov == 0)
        return 0;

    return this->x + e->width * (pos -1) - this->width * pos -10;
}
