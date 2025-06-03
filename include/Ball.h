#include <raylib.h>

#ifndef BALL_H
#define BALL_H

class Ball
{
public:
private:
    Vector2 m_velocity{};
    Vector2 m_acceleration{0, 9.8f * 100};
};

#endif