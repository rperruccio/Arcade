#ifndef CAMARA_H
    #define CAMARA_H

#include <SDL.h>

#include "Define.h"


enum
{
    TARGET_MODE_NORMAL = 0,
    TARGET_MODE_CENTER
};

class Camara
{
    public:
        Camara();
        virtual ~Camara();

    public:
        static Camara  camaraControl;

    private:
        int     x;
        int     y;

        int*    targetX;
        int*    targetY;

    public:
        int     targetMode;

    public:
        void OnMove(int moveX, int moveY);

        void SetPos(int X, int Y);

        void SetTarget(int* X, int* Y);

        int GetX();

        int GetY();
};

#endif // CAMARA_H
