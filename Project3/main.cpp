#include <filesystem>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <optional>

#include "Button.h"
#include "Shape.h"


template<typename T, typename = std::enable_if<std::is_convertible_v<T, Shape*>>>
void Draw(sf::RenderWindow& window, const std::vector<T*>& shapes)
{
    for (auto&& shape : shapes)
        window.draw(*shape->GetShape());
}

std::optional<Shape*> CheckMakerButtons(sf::RenderWindow& window, std::vector<Button*> maker_buttons, int WindowWidth, int WindowHeight)
{
    for(auto&& button : maker_buttons)
    {
	    if(button->IsButtonPressed(window))
	    {
            return  button->CreateShape(Shape::GetRandomPosition(WindowWidth / 2, WindowHeight / 2));
	    }
    }
    return std::nullopt;
}

std::vector<Button*> CreateMakerButton()
{
    auto* buttonCircle = new Button{ TypeOfShape::Circle };
    buttonCircle->SetPosition({ 0,0 });

    auto* buttonRectangle = new Button{ TypeOfShape::Rectangle };
    buttonRectangle->SetPosition({ 110,0 });

    auto* buttonTriangle = new Button{ TypeOfShape::Triangle };
    buttonTriangle->SetPosition({ 220,0 });

    return { buttonCircle, buttonRectangle, buttonTriangle };
}

int main()
{
    int WindowWidth = 1000;
    int WindowHeight = 800;

    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "SFML works!");

    std::vector<Button*> button_shapes = CreateMakerButton();
    std::vector<Shape*> shapes;

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseButtonPressed)
            {
	            if(event.key.code == sf::Mouse::Left)
	            {
                    std::optional<Shape*> shape = CheckMakerButtons(window, 
													  button_shapes,
													  WindowWidth, WindowHeight
                    );
                    if (shape.has_value())
                    {
                        shapes.push_back(shape.value());
                    }
	            }
            }
        }

        window.clear();
        Draw(window, button_shapes);
        Draw(window, shapes);
        window.display();
    }

    return 0;
}