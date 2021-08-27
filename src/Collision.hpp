#pragma once
#include "GameObjects/Paddle.hpp"
#include "GameObjects/Ball.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

class Collision {
public:
    enum class WindowBorder {
        TOP,
        BOTTOM,
        LEFT,
        RIGHT
    };

    static bool paddleCollidingWithBall(Paddle& paddle, Ball& ball) {
        auto paddleBounds = paddle.getGlobalBounds();
        auto ballBounds = ball.getGlobalBounds();

        sf::FloatRect paddleIntersectionRect;
        sf::FloatRect ballIntersectionRect;

        switch (paddle.getOrientation()) {
            case Paddle::PaddleOrientation::LEFT:
                paddleIntersectionRect = sf::FloatRect{paddleBounds.left + paddleBounds.width, paddleBounds.top, 1, paddleBounds.height};
                ballIntersectionRect = sf::FloatRect{ballBounds.left, ballBounds.top, 1, ballBounds.height};
                break;
            case Paddle::PaddleOrientation::RIGHT:
                paddleIntersectionRect = sf::FloatRect{paddleBounds.left, paddleBounds.top, 1, paddleBounds.height};
                ballIntersectionRect = sf::FloatRect{ballBounds.left + ballBounds.width, ballBounds.top, 1, ballBounds.height};
                break;
            case Paddle::PaddleOrientation::DOWN:
                paddleIntersectionRect = sf::FloatRect{paddleBounds.left, paddleBounds.top, paddleBounds.width, 1};
                ballIntersectionRect = sf::FloatRect{ballBounds.left, ballBounds.top + ballBounds.height, ballBounds.width, 1};
                break;
        }

        return paddleIntersectionRect.intersects(ballIntersectionRect);
    }

    static bool ballCollidingWithWindow(Ball &ball, WindowBorder border) {
        auto ballBounds = ball.getGlobalBounds();
        auto windowSize = Game::getInstance().getWindow().getSize();

        float windowX = static_cast<float>(windowSize.x);
        float windowY = static_cast<float>(windowSize.y);

        sf::FloatRect windowIntersectionRect;
        sf::FloatRect ballIntersectionRect;
        
        switch (border) {
            case WindowBorder::TOP:
                ballIntersectionRect = sf::FloatRect{ballBounds.left, ballBounds.top, ballBounds.width, 1};
                windowIntersectionRect = sf::FloatRect{0, 0, windowX, 1};
                break;
            case WindowBorder::BOTTOM:
                ballIntersectionRect = sf::FloatRect{ballBounds.left, ballBounds.top + ballBounds.height, ballBounds.width, 1};
                windowIntersectionRect = sf::FloatRect{0, windowY, windowX, 1};
                break;
            case WindowBorder::LEFT:
                ballIntersectionRect = sf::FloatRect{ballBounds.left, ballBounds.top, 1, ballBounds.height};
                windowIntersectionRect = sf::FloatRect{0, 0, 1, windowY};
                break;
            case WindowBorder::RIGHT:
                ballIntersectionRect = sf::FloatRect{ballBounds.left + ballBounds.height, ballBounds.top, 1, ballBounds.height};
                windowIntersectionRect = sf::FloatRect{windowX, 0, 1, windowY};
                break;
        }

        return windowIntersectionRect.intersects(ballIntersectionRect);
    }

    /**
     * When a collision occurs with a paddle or window border, 
     * theres a chance the ball may glitch out, probably due to how
     * the floating point values are being compared. 
     * 
     * This function applies an offset that is equal to the ball's radius
     * in the direction opposite from the collision, giving the ball leeway to 
     * not glitch with what it collided with.
     * 
     * This should happen before the direction of the ball has been changed.
     * */ 
    static void applyCollisionOffset(Ball& ball, Ball::VectorComponent vector) {
        auto ballPos = ball.getPosition(); 
        int ballAngle = ball.getAngle();
        float ballRadius = ball.getRadius();

        if (vector == Ball::VectorComponent::X) {
            auto offset = std::cos(ballAngle) > 0 ? -ballRadius : ballRadius;
            ball.setPosition(ballPos.x + offset, ballPos.y);
        }
        else if (vector == Ball::VectorComponent::Y) {
            auto offset = std::sin(ballAngle) > 0 ? -ballRadius : ballRadius;
            ball.setPosition(ballPos.x, ballPos.y + offset);
        }        
    }
};