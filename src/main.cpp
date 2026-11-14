#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

using namespace std;

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({1200, 800}),
        "Soot & Shrapnel");

    window.setFramerateLimit(60);

    sf::Texture shipTexture;
    sf::Texture USSIowaTexture;
    sf::Texture SSJeremiah;

    if (!shipTexture.loadFromFile("assets/SSUnitedStates.png"))
    {
        cout << "No funciona la textura." << std::endl;
        return -1;
    }

    if (!USSIowaTexture.loadFromFile("assets/USSIowa.png"))
    {
        cout << "No Funciona la Textura." << endl;
        return -1;
    }

    if (!SSJeremiah.loadFromFile("assets/JeremiahOBrien.png"))
    {
        cout << "No Funciona La Textura" << endl;
        return -1;
    }

    sf::Sprite SSJeremiahOBrien(SSJeremiah);
    SSJeremiahOBrien.setScale({0.2f, 0.2f});
    SSJeremiahOBrien.setPosition({50.f, 400.f});

    sf::Sprite ship(shipTexture);
    ship.setScale({0.3f, 0.3f});
    ship.setPosition({50.f, 200.f});



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
