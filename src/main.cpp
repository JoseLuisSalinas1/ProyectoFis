#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <cmath>
using namespace std;

// float ShipMovementWithAngle;

int Wallpaper();
int Menu();

float rotation = 0;

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Soot & Shrapnel");
    window.setFramerateLimit(60);
    
    int Wallpaper();

    sf::View camera;
    camera = window.getDefaultView();

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
    ship.setPosition({700.f, 700.f});
    ship.setOrigin({1150.f, 128.f});

    sf::Sprite Ocean(OceanTexture);
    // Ocean.setScale({0.15f, 0.15f});
    Ocean.setTextureRect(sf::IntRect({0, 0}, {5000, 5000}));
    // Ocean.setScale({0.3f, 0.3f});

    while (window.isOpen())
    {
        float properRadians = rotation * ((2 * 3.1415926535) / 360);
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (const auto *wheel = event->getIf<sf::Event::MouseWheelScrolled>())
            {
                if (wheel->delta > 0)
                {
                    camera.zoom(0.9f);
                }
                if (wheel->delta < 0)
                {
                    camera.zoom(1.1f);
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            // double rotation = ship.getRotation().asDegrees();
            ship.move({cos((properRadians)) * 2, sin((properRadians)) * 2});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            // double rotation = ship.getRotation().asDegrees();
            ship.move({cos((properRadians)) * -2, sin((properRadians)) * -2});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
        {
            ship.rotate(sf::degrees(0.2f));
            rotation = rotation + 0.2;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
        {
            ship.rotate(sf::degrees(-0.2f));
            rotation = rotation - 0.2;
        }

        window.clear(sf::Color(30, 30, 45));
        window.setView(camera);
        window.draw(Ocean);
        window.draw(ship);
        camera.setCenter({(ship.getPosition().x), (ship.getPosition().y)});
        // window.draw(SSJeremiahOBrien);
        window.display();
    }
    return 0;
}
