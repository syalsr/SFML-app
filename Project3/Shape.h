#pragma once
#include <random>
#include <SFML/Graphics/Shape.hpp>

struct Position
{
    float x{};
    float y{};
};
class Shape
{
public:
    Shape() = default;

    static Position GetRandomPosition(int max_x, int max_y)
    {
        std::random_device myRandomDevice;
        unsigned seed = myRandomDevice();
        std::default_random_engine myRandomEngine(seed);
        std::uniform_int_distribution<> myUnifIntDist_x(0, max_x);
        std::uniform_int_distribution<> myUnifIntDist_y(0, max_y);
        return { static_cast<float>(myUnifIntDist_x(myRandomEngine)),
                    static_cast<float>(myUnifIntDist_y(myRandomEngine))
        };
    }

    virtual sf::Shape* GetShape() const = 0;
    virtual Position GetPosition() const = 0;

    virtual ~Shape() = default;

};