#include "Entity.h"

std::vector<Entity*> Entity::entityList;

Entity::Entity()
{
    imagen = NULL;

    x = y = 0.0f;
    width = height = 0;

    moveLeft = moveRight = false;

    type = ENTITY_TYPE_GENERIC;

    dead = false;
    flags = ENTITY_FLAG_GRAVITY;

    dir = IZQUIERDA;
    moving = false;

    speedX = speedY = 0;
    accelX = accelY = 0;

    maxSpeedX = 10;
    maxSpeedY = 10;

    colFrame = 2;
    filaFrame = 0;

    colX = 0;
    colY = 0;
    colWidth = 0;
    colHeight = 0;

    canJump = false;

}

Entity::~Entity(){}

bool Entity::OnLoad(char* path, int width, int height, int maxFrames)
{
    if ((imagen = Superficie::OnLoad(path)) == NULL)
        return false;

    //Superficie::Transparente(imagen, 255, 0, 255);

    this->width = width;
    this->height = height;

    animControl.maxFrames = maxFrames;

    return true;
}

void Entity::OnLoop()
{
    /*
    if (moving == false)
    {
        StopMove();
    }
    else
    {
        if (dir == DERECHA)
        {
            accelX = -0.5f;
        }
        else
        {
            accelX = 0.5f;
        }
    }
    */

    if (moveLeft == false && moveRight == false)
        StopMove();

    if (moveLeft)
    {
        accelX = -0.5f;
    }
    else
    {
        if (moveRight)
            accelX = 0.5f;
    }

    if (flags & ENTITY_FLAG_GRAVITY)
        accelY = GRAVITY * 2;

    speedX += accelX * CFPS::fpsControl.GetSpeedFactor();
    speedY += accelY * CFPS::fpsControl.GetSpeedFactor();

    if (speedX > maxSpeedX) speedX = maxSpeedX;
    if (speedX < -maxSpeedX) speedX = -maxSpeedX;

    if (speedY > maxSpeedY) speedY = maxSpeedY;
    if (speedY < -maxSpeedY) speedY = -maxSpeedY;


    OnAnimate();
    OnMove(speedX, speedY);
}

void Entity::OnRender(SDL_Surface* pantalla)
{
    if (pantalla == NULL || imagen == NULL)
        return;

    Superficie::OnDraw(pantalla, imagen, x - Camara::camaraControl.GetX(), y - Camara::camaraControl.GetY(), colFrame * width, (filaFrame + animControl.GetCurrentFrame()) * height, width, height);

}

void Entity::OnCleanup()
{
    if (imagen)
        SDL_FreeSurface(imagen);

    imagen = NULL;

}

void Entity::OnAnimate()
{
    /*
    switch (accion)
    {
        case ACCION_PARADO:     colFrame = 0;   break;
        case ACCION_CAMINANDO:  colFrame = 2;   break;
        case ACCION_CORRIENDO:  colFrame = 4;   break:
        case ACCION_SALTANDO:   colFrame = 6;   break;
    }
    */
    if (moveLeft)
    {
        colFrame = 2;
    }
    else
    {
        colFrame = 3;
    }
    if (speedX == 0)
        colFrame = 0;

    animControl.OnAnimate();
}

bool Entity::OnCollision(Entity* e)
{

}

void Entity::OnMove(float moveX, float moveY)
{
    canJump = false;

    if (moveX == 0 && moveY == 0)
        return;

    double newX = 0;
    double newY = 0;

    moveX *= CFPS::fpsControl.GetSpeedFactor();
    moveY *= CFPS::fpsControl.GetSpeedFactor();

    if (moveX != 0)
    {
        if (moveX >= 0)     newX = CFPS::fpsControl.GetSpeedFactor();
        else                newX = -CFPS::fpsControl.GetSpeedFactor();
    }

    if (moveY != 0)
    {
        if (moveY >= 0)     newY = CFPS::fpsControl.GetSpeedFactor();
        else                newY
         = -CFPS::fpsControl.GetSpeedFactor();
    }

    while (true)
    {
        if (flags & ENTITY_FLAG_GHOST)
        {
            PosValid((int)(x + newX), (int)(y + newY));

            x += newX;
            y += newY;
        }
        else
        {
            if (PosValid((int)(x + newX), (int)(y)))
            {
                x += newX;
            }
            else
            {
                speedX = 0;
            }

            if (PosValid((int)(x), (int)(y + newY)))
            {
                y += newY;
            }
            else
            {
                if (moveY > 0)
                    canJump = true;

                speedY = 0;
            }
        }

        moveX -= newX;
        moveY -= newY;

        if  (newX > 0 && moveX <= 0)  newX = 0;
        if  (newX < 0 && moveX >= 0)  newX = 0;

        if  (newY > 0 && moveY <= 0)  newY = 0;
        if  (newY < 0 && moveY >= 0)  newY = 0;

        if (moveX == 0) newX = 0;
        if (moveY == 0) newY = 0;

        if (newX == 0 && newY == 0)     break;
        if (moveX == 0 && moveY == 0)   break;
    }

}

void Entity::StopMove()
{
    if (speedX > 0)
        accelX = -1;

    if (speedX < 0)
        accelX = 1;

    if (speedX < 2.0f && speedX > -2.0f)
    {
        accelX = 0;
        speedX = 0;
    }
}

bool Entity::Choca(int oX, int oY, int oW, int oH)
{
    int izquierda1, izquierda2;
    int derecha1, derecha2;
    int arriba1, arriba2;
    int abajo1, abajo2;

    int tX = (int)x + colX;
    int tY = (int)y + colY;

    izquierda1 = tX;
    izquierda2 = oX;

    derecha1 = izquierda1 + width - 1 - colWidth;
    derecha2 = oX + oW - 1;

    arriba1 = tY;
    arriba2 = oY;

    abajo1 = arriba1 + height - 1 -colHeight;
    abajo2 = oY + oH - 1;

    if (abajo1 < arriba2)       return false;
    if (arriba1 > abajo2)       return false;

    if (derecha1 < izquierda2)  return false;
    if (izquierda1 > derecha2)  return false;

    return true;
}

bool Entity::PosValid(int X, int Y)
{
    bool ret = true;

    int startX = (X + colX) / TILE_SIZE;
    int startY = (Y + colY) / TILE_SIZE;

    int endX = ((X + colX) + width - colWidth - 1) / TILE_SIZE;
    int endY = ((Y + colY) + height - colHeight - 1) / TILE_SIZE;

    for (int i = startY; i <= endY; i++)
    {
        for (int z = startX; z <= endX; z++)
        {
            Tile* tile = Area::areaControl.GetTile(z * TILE_SIZE, i * TILE_SIZE);

            if (PosValidTile(tile) == false)
                ret = false;
        }
    }

    if (flags & ENTITY_FLAG_MAPONLY)
    {}
    else
    {
        for (int i = 0; i < entityList.size(); i++)
        {
            if (PosValidEntity(entityList[i], X, Y) == false)
                ret = false;
        }
    }

    return ret;
}

bool Entity::PosValidTile(Tile* t)
{
    if (t == NULL)
        return true;

    if (t->typeID == TYPE_BLOCK)
        return false;

    return true;
}

bool Entity::PosValidEntity(Entity* e, int X, int Y)
{
    if (this != e && e != NULL && e->dead == false && e->flags ^ ENTITY_FLAG_MAPONLY &&
        e->Choca(X + colX, Y + colY, width - colWidth -1, height - colHeight - 1) == true)
    {
        EntityCol ec;

        ec.entidadA = this;
        ec.entidadB = e;

        EntityCol::entityColList.push_back(ec);

        return false;
    }

    return true;
}

bool Entity::Jump()
{
    if (!canJump)
        return false;

    speedY = -maxSpeedY;
    return true;
}

//======================================================================//
void Entity::SetColFrame(int f)
{
    colFrame = f;
}


void Entity::SetPos(float X, float Y)
{
    this->x = X;
    this->y = Y;
}
