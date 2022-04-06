#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "mario.hpp"
#include "grib.hpp"
#include <vector>

//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace std::chrono_literals;

int main()
{
    float time = 10;
    float sx = 50;
    float sy = 500;
    int score = 0;

    // Создание окна с известными размерами и названием
    sf::RenderWindow window(sf::VideoMode(760, 428), "Mario lets go!");

    // Подгрузка фонового изображения
    sf::Texture texture;
    if (!texture.loadFromFile("img/back.jpg"))
    {
        std::cout << "ERROR when loading back.jpg" << std::endl;
        return false;
    }
    sf::Sprite back;
    back.setTexture(texture);

    // Подгрузка шрифта и создание отображения счета
    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        std::cout << "ERROR: font was not loaded." << std::endl;
        return -1;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);

    // Добавление иконки
    sf::Image icon;
    if (!icon.loadFromFile("img/mario32.png"))
    {
        return -1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    // Генерация объектов
    std::vector<nu::Grib*> gribs;
    gribs.push_back(new nu::Grib(200, 310, 25));
    gribs.push_back(new nu::Grib(350, 310, 25));
    gribs.push_back(new nu::Grib(550, 310, 25));

    // Подгрузка картинок и завершение программы, если они не загрузились
    for (const auto& grib : gribs)
        if (!grib->Setup())
            return -1;

    //nu::Mario mario(sx, sy, 20);
    nu::Mario* mario = nullptr;
    //mario = new nu::Mario(sx, sy, 20);
    //marios.push_back(new nu::Mario(sx, sy, 20));
    //nu::Mario* mario = new nu::Mario(sx, sy, 20);

    // Цикл работает до тех пор, пока окно открыто
    while (window.isOpen())
    {
        // Переменная для хранения события
        sf::Event event;
        // Цикл по всем событиям
        while (window.pollEvent(event)) {
            // Обработка событий, если нажат крестик, то окно закрывается
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

            //if (mario != nullptr)
            //    delete mario;
            mario = new nu::Mario(sx, sy, 20);

            if (!mario->Setup())
            {
                delete mario;
                window.close();
                return -1;
            }
//            time = 60;
        }


        // Вывод на экрaна
        window.clear();

        // Вывод фона
        window.draw(back);

        // Вывод счета
        text.setString(std::string("Time: ") + std::to_string(time));
        window.draw(text);

//        for(const auto& grib : gribs)
//            window.draw(*grib->Get());
        if(mario != nullptr)
            window.draw(*mario->Get());

        for (const auto& grib : gribs)
            window.draw(*grib->Get());

        // Отобразить на окне все, что есть в буфере
        window.display();

        // https://ravesli.com/urok-129-tajming-koda-vremya-vypolneniya-programmy/
        std::this_thread::sleep_for(40ms);
        time -= 0.04;
        if(time == 0)
            window.close();
    }

    if (mario != nullptr)
        delete mario;

    return 0;
}