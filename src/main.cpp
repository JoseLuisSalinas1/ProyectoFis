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

    sf::View camera;

    sf::Texture shipTexture;
    sf::Texture USSIowaTexture;
    sf::Texture SSJeremiah;
    sf::Texture OceanTexture;

    OceanTexture.setRepeated(true);

    if (!shipTexture.loadFromFile("assets/SSUnitedStates.png"))
    {
        cout << "No funciona la textura." << endl;
        return -1;
    }

    if (!USSIowaTexture.loadFromFile("assets/USSIowa.png"))
    {
        cout << "No Funciona la Textura." << endl;
        return -1;
    }

    if (!SSJeremiah.loadFromFile("assets/SSJeremiahOBrien.png"))
    {
        cout << "No Funciona La Textura" << endl;
        return -1;
    }

    if (!OceanTexture.loadFromFile("assets/ocean.png"))
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

    sf::Sprite Ocean(OceanTexture);
    // Ocean.setScale({0.15f, 0.15f});
    Ocean.setTextureRect(sf::IntRect({250, 250}, {5000, 5000}));
    Ocean.setScale({0.3f, 0.3f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            ship.move({0.5f, 0.f});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
        {
            ship.rotate(sf::degrees(0.3f));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
        {
            ship.rotate(sf::degrees(-0.3f));
        }

        window.clear(sf::Color(30, 30, 45));
        window.draw(Ocean);
        window.draw(ship);
        camera.setCenter(ship.getPosition());
        // window.draw(SSJeremiahOBrien);
        window.display();
    }
    return 0;
}
