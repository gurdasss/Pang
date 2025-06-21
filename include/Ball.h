#include "Circle2D.h"
#include <raylib.h>
#include <iostream>

#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    Ball(const Vector2 &initialPosition)
        : m_ball{initialPosition, 20.0f}
    {
        m_ball.setTint(DARKGRAY);
    }

    void draw(float delta);

private:
    Circle2D m_ball{};
    Vector2 m_velocity{500, 0};
    Vector2 m_acceleration{0, 9.8f * 100};

    void updateVelocity(float delta);
    void updatePosition(float delta);
    void applyWallCollision();
};

// need to reapply inline keyword
// to member functions because
// they are defined outside the class
// definition

inline void Ball::draw(float delta)
{
    updateVelocity(delta);
    updatePosition(delta);
    applyWallCollision();
    DrawCircleV(m_ball.getPosition(), m_ball.getRadius(), m_ball.getTint());
}

inline void Ball::updateVelocity(float delta)
{
    // x velocity is zero so don't need to compute it now
    // m_velocity.x += m_acceleration.x * delta;
    m_velocity.y += m_acceleration.y * delta;
}

inline void Ball::updatePosition(float delta)
{
    m_ball.setX(m_ball.getX() + m_velocity.x * delta);
    m_ball.setY(m_ball.getY() + m_velocity.y * delta);
}

inline void Ball::applyWallCollision()
{
    static const float screenH{static_cast<float>(GetScreenHeight())};

    static const float ballRadius{m_ball.getRadius()};

    constexpr float bounceFactor{0.5f};

    if (m_ball.getY() + ballRadius > screenH)
    {
        m_velocity.y = -m_velocity.y * bounceFactor;

        // ensure that gravitational acceleration
        // does'nt sink the ball object in the ground
        m_ball.setY(screenH - ballRadius);

        // apply friction once the ball object
        // is on the ground
        constexpr float friction{2};

        if (m_velocity.x > 0)
        {
            m_velocity.x -= friction;

            if (m_velocity.x < 0)
                m_velocity.x = 0;
        }
        else if (m_velocity.y < 0)
        {
            m_velocity.x += friction;
            if (m_velocity.x > 0)
                m_velocity.x = 0;
        }
    }

    static const float screenW{static_cast<float>(GetScreenWidth())};

    if (m_ball.getX() + ballRadius > screenW)
    {
        m_velocity.x = -m_velocity.x * bounceFactor;
        m_ball.setX(screenW - ballRadius);
    }
    else if (m_ball.getX() - ballRadius < 0)
    {
        m_velocity.x = -m_velocity.x * bounceFactor;
        m_ball.setX(ballRadius);
    }
}

#endif