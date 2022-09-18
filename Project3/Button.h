#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

enum class TypeOfShape
{
    Circle,
    Triangle,
    Rectangle
};

class Button : public Shape
{
public:
    Button(TypeOfShape type) :  m_type{ type },
								but{ new sf::RectangleShape{sf::Vector2f(100, 50) } },
								texture{new sf::Texture}
    {
        SetTexture();
    }
    void SetPosition(const Position& pos)
    {
        but->setPosition(pos.x, pos.y);
    }
    bool IsButtonPressed(sf::RenderWindow& window) const
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        return but->getGlobalBounds().contains(mousePos.x, mousePos.y);
    }
    sf::Shape* GetShape() const override
    {
        return but;
    }
    Position GetPosition() const override
    {
        return { but->getPosition().x, but->getPosition().y };
    }

    Shape* CreateShape(Position pos)
    {
        switch (m_type)
        {
        case TypeOfShape::Circle:
            return new Circle(pos);
        case TypeOfShape::Triangle:
            return new Triangle(pos);
        case TypeOfShape::Rectangle:
            return new Rectangle(pos);
        }
    }
private:
    void SetTexture()
    {
        if (!texture->loadFromFile("../Textures/click.png"))
            throw std::exception{ "Texture dont loaded" };
        but->setTexture(texture);
    }

    TypeOfShape m_type;
    sf::RectangleShape* but;
    sf::Texture* texture;
};