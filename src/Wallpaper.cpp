#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "../include/Wallpaper.hpp"

std::optional<sf::Sprite> LoadRandomWallpaper(sf::Texture& texture)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 7);
    int wallpaperNumber = distribution(generator);

    const char* wallpaperPath = nullptr;
    switch (wallpaperNumber)
    {
    case 1:
        wallpaperPath = "assets/Wallpapers/Wallpaper1.jpg";
        break;
    case 2:
        wallpaperPath = "assets/Wallpapers/Wallpaper2.jpg";
        break;
    case 3:
        wallpaperPath = "assets/Wallpapers/Wallpaper3.jpg";
        break;
    case 4:
        wallpaperPath = "assets/Wallpapers/Wallpaper4.jpg";
        break;
    case 5:
        wallpaperPath = "assets/Wallpapers/Wallpaper5.png";
        break;
    case 6:
        wallpaperPath = "assets/Wallpapers/Wallpaper6.jpg";
        break;
    case 7:
        wallpaperPath = "assets/Wallpapers/Wallpaper7.jpg";
        break;
    }

    if (!wallpaperPath || !texture.loadFromFile(wallpaperPath))
    {
        std::cout << "No se pudo cargar el wallpaper." << std::endl;
        return std::nullopt;
    }

    sf::Sprite sprite(texture);
    const sf::Vector2u size = texture.getSize();
    sprite.setScale({
        1920.f / static_cast<float>(size.x),
        1080.f / static_cast<float>(size.y)
    });
    sprite.setPosition({0.f, 0.f});

    return sprite;
}
