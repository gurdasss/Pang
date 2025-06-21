#include <raylib.h>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player(const Vector2 &initialPosition)
        : m_position{initialPosition} {}

    void updateX(float x) { m_position.x += x; }
    void shootLaser();
    void draw() const;

private:
    Vector2 m_position{};
};

inline void Player::draw() const
{
    // a polygon with three sides
    // rotated at -90 degree
    // with radius of 20
    DrawPoly(m_position, 3, 20, -90, RED);
}

#endif