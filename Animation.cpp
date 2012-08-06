#include "Animation.h"

Animation::Animation()
{
    currentFrame = 0;
    maxFrames = 0;
    frameInc = 1;

    frameRate = 100;
    oldTime = 0;

    oscilar = false;
}

Animation::~Animation()
{
    //dtor
}

void Animation::OnAnimate(){
    if (oldTime + frameRate > SDL_GetTicks())
        return;

    oldTime = SDL_GetTicks();

    currentFrame += frameInc;

    if (oscilar){
        if (frameInc > 0){
            if (currentFrame >= maxFrames)
                frameInc = -frameInc;
        }else{
            if (currentFrame <= 0)
                frameInc = -frameInc;
        }
    }else{
        if (currentFrame >= maxFrames)
            currentFrame = 0;
    }
}

void Animation::SetFrameRate(int rate)
{
    this->frameRate = rate;
}

void Animation::SetCurrentFrame(int frame)
{
    if (frame < 0 || frame > maxFrames)
        return;

    this->currentFrame = frame;
}

int Animation::GetCurrentFrame()
{
    return currentFrame;
}
