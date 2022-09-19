#pragma once
#include <SFML/Graphics/CircleShape.hpp>

#include "Shape.h"

class Circle :public Shape
{
public:
    Circle(Position p, const sf::Color& color = sf::Color::Blue, float radius = 100) : circle{ new sf::CircleShape(radius) }
    {
        circle->setFillColor(color);
        circle->setPosition(p.x, p.y);
    }

    sf::CircleShape* GetShape() const override
    {
        return circle;
    }
    Position GetPosition() const override
    {
        return { circle->getPosition().x, circle->getPosition().y };
    }

    void SetRadius(float radius)
    {
        circle->setRadius(radius);
    }
    
    ~Circle()
    {
        delete circle;
    }

private:
    sf::CircleShape* circle;
};
