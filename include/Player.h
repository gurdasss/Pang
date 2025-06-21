#include "Line2D.h"
#include <raylib.h>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player(const Vector2 &initialPosition)
        : m_position{initialPosition} {}

    void updateX(float x);
    void shootLaser();
    void draw();

private:
    Vector2 m_position{};
    float m_radius{20.0f};
    Line2D m_laser{};

    void updateLaser();
};

inline void Player::shootLaser()
{
    m_laser.setStartPos(m_position);
    m_laser.setEndPos(m_position);
    m_laser.setTint(RED);
}

inline void Player::updateLaser()
{
    m_laser.setEndPosY(m_laser.getEndPosY() - 2.0f);
}

inline void Player::updateX(float x)
{
    if (m_position.x + m_radius > static_cast<float>(GetScreenWidth()))
    {
        m_position.x = static_cast<float>(GetScreenWidth()) - m_radius;
        return;
    }
    else if (m_position.x - m_radius < 0)
    {
        m_position.x = m_radius;
        return;
    }

    m_position.x += x;
}

inline void Player::draw()
{
    if (m_laser.getEndPosY() <= 0)
    {
        m_laser.setTint(BLANK);
    }
    else
        updateLaser();
    // a polygon with three sides
    // rotated at -90 degree
    // with radius of 20
    DrawPoly(m_position, 3, m_radius, -90, RED);
    DrawLineV(m_laser.getStartPos(), m_laser.getEndPos(), m_laser.getTint());
}

#endif