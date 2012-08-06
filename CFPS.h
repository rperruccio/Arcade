#ifndef CFPS_H
    #define CFPS_H

#include <SDL.h>

class CFPS
{
    public:
        CFPS();
        virtual ~CFPS();

    public:
        static CFPS fpsControl;

    public:
        void    OnLoop();

        int     GetFPS();

        float   GetSpeedFactor();

    private:
        int     oldTime;
        int     lastTime;

        float   speedFactor;

        int     numFrames;
        int     frames;
};

#endif // CFPS_H
