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

    // Load ship image
    sf::Texture shipTexture;

    if (!shipTexture.loadFromFile("assets/SSUnitedStates.png"))
    {
        std::cout << "Could not load ship image!" << std::endl;
        return -1;
    }

    // Create sprite using texture
    sf::Sprite ship(shipTexture);

    // Position ship
    ship.setPosition({100.f, 100.f});

    // Game loop
    while (window.isOpen())
    {
        // Handle events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // Clear screen
        window.clear(sf::Color(30, 30, 45));

        // Draw ship
        window.draw(ship);

        // Display everything
        window.display();
    }

    return 0;
}


