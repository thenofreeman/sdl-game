#pragma once

#include "Sprite.h"

class Action
{
    public:
        virtual ~Action() { }
        virtual void execute(Sprite* sprite) = 0;

    public:

};

class PositionAAction : public Action
{
    public:
        virtual ~PositionAAction() { }

        virtual void execute(Sprite* sprite) override
        {
            sprite->setPosition({ 100, 100 });
        }

};

class PositionBAction : public Action
{
    public:
        virtual ~PositionBAction() { }

        virtual void execute(Sprite* sprite) override
        {
            sprite->setPosition({ 200, 200 });
        }

};