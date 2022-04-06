#include <SFML/Graphics.hpp>
#include <mario.hpp>
#include <grib.hpp>
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include <math.h>

using namespace std::chrono_literals;

int main() {
    const int width = 760;
    const int height = 428;
    const int N = 10;
    float time = 10;

    sf::Texture texture;
    if (!texture.loadFromFile("img/back.jpg"))
    {
        return -1;
    }

    nu::Mario* mario = nullptr;
    mario = new nu::Mario(10, 300, 20);

    std::vector<nu::Grib*> gribs;
    for (int i = 0; i <= width; i += width / N)
        gribs.push_back(new nu::Grib(i, 0, 15, rand() % 7 + 1));

    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf")){
        std::cout << "ERROR: font was not loaded." << std::endl;
        return -1;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);

    // Добавление иконки
//    sf::Image icon;
//    if (!icon.loadFromFile("img/bird32.png"))
//        return -1;
//    window.setIcon(32, 32, icon.getPixelsPtr());


    sf::RenderWindow window(sf::VideoMode(width, height), "Mario return!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        for (const auto& grib : gribs)
        {
            grib->Move();
            if (grib->GetY() > height)
            {
                grib->SetVelocity(rand() % 5 + 1);
                grib->SetY(0);
            }
        }
        

        window.clear();

        sf::Sprite sprite;
        sprite.setTexture(texture);
        window.draw(sprite);
        text.setString(std::string("Time: ") + std::to_string(round(time*100)/100));
        window.draw(text);
        window.draw(*mario->Get());
        for(const auto& grib : gribs)
            window.draw(*grib->Get());
        window.display();

        // https://ravesli.com/urok-129-tajming-koda-vremya-vypolneniya-programmy/
        std::this_thread::sleep_for(20ms);
        time -= 0.02;
        if(time == 0)
            window.close();
    }
    for (const auto& grib : gribs)
        delete grib;
    gribs.clear();

    return 0;
}