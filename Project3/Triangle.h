#pragma once
#include <SFML/Graphics/ConvexShape.hpp>

#include "Shape.h"

class Triangle :public Shape
{
public:
    Triangle(Position p = {}, const sf::Color& color = sf::Color::Red, float radius = 100) : triangle{ new sf::ConvexShape() }
    {
        triangle->setFillColor(color);
        triangle->setPosition(p.x, p.y);
        triangle->setPointCount(3);
        triangle->setPoint(0, sf::Vector2f{ 100, 100 });
        triangle->setPoint(1, sf::Vector2f{ 200, 100 });
        triangle->setPoint(2, sf::Vector2f{ 0, 0 });
    }

    sf::ConvexShape* GetShape() const override
    {
        return triangle;
    }
    Position GetPosition() const override
    {
        return { triangle->getPosition().x, triangle->getPosition().y };
    }

    void SetPoints(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3)
    {
        triangle->setPoint(0, p1);
        triangle->setPoint(1, p2);
        triangle->setPoint(2, p3);
    }

private:
    sf::ConvexShape* triangle;
};
