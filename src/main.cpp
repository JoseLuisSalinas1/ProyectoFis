#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({1200, 800}),
        "SS United States - My First SFML Game"
    );

    window.setFramerateLimit(60);

    sf::Texture shipTexture;

    if (!shipTexture.loadFromFile("assets/SSUnitedStates.png"))
    {
        std::cout << "No funciona la textura." << std::endl;
        return -1;
    }

    sf::Sprite ship(shipTexture);
    ship.setScale({0.5f, 0.5f});

    ship.setPosition({100.f, 100.f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color(30, 30, 45));

        window.draw(ship);

        window.display();
    }

    return 0;
}


