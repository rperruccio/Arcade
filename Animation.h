#ifndef ANIMATION_H
    #define ANIMATION_H

#include <SDL.h>

class Animation
{
    public:
        Animation();
        virtual ~Animation();

        void    OnAnimate();

    private:
        int     currentFrame;

        int     frameInc;

        int     frameRate;

        long    oldTime;

    public:
        int     maxFrames;

        bool    oscilar;

    public:
        void    SetFrameRate(int rate);

        void    SetCurrentFrame(int frame);

        int     GetCurrentFrame();

};

#endif // ANIMATION_H
