#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "Shape.h"

class Rectangle :public Shape
{
public:
    Rectangle(Position p, const sf::Color& color = sf::Color::Green, float radius = 100) : rectangle{ new sf::RectangleShape() }
    {
        rectangle->setFillColor(color);
        rectangle->setPosition(p.x, p.y);
        rectangle->setSize(sf::Vector2f(200.f, 300.f));
    }

    sf::RectangleShape* GetShape() const override
    {
        return rectangle;
    }
    Position GetPosition() const override
    {
        return { rectangle->getPosition().x, rectangle->getPosition().y };
    }

    void SetSize(float x, float y)
    {
        rectangle->setSize(sf::Vector2f(x, y));
    }

private:
    sf::RectangleShape* rectangle;
};
