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
    float time = 30;
    int s_x = 10;
    int s_y = 300;
    //int score = 0;
    bool lose = false;
    bool win = false;
    bool start = false;

    sf::RenderWindow window(sf::VideoMode(width, height), "Mario return!");

    sf::Texture texture;
    if (!texture.loadFromFile("img/back.jpg"))
    {
        return -1;
    }

    nu::Mario* mario = nullptr;
    mario = new nu::Mario(s_x, s_y, 20);

    std::vector<nu::Grib*> gribs;
    for (int i = 0; i <= width; i += width / N)
        gribs.push_back(new nu::Grib(i, 0, 15, rand() % 7 + 1));

    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf")){
        std::cout << "ERROR: font was not loaded." << std::endl;
        return -1;
    }
    sf::Text text_time;
    text_time.setFont(font);
    text_time.setCharacterSize(24);
    text_time.setFillColor(sf::Color::Blue);

//    sf::Text text_score;
//    text_score.setFont(font);
//    text_score.setCharacterSize(24);
//    text_score.setPosition(200, 0);
//    text_score.setFillColor(sf::Color::Blue);

    sf::Text text_start;
    text_start.setFont(font);
    text_start.setCharacterSize(24);
    text_start.setPosition(600, 0);
    text_start.setFillColor(sf::Color::Blue);

    sf::Text text_exit;
    text_exit.setFont(font);
    text_exit.setCharacterSize(24);
    text_exit.setPosition(700, 0);
    text_exit.setFillColor(sf::Color::Blue);

    sf::Text text_lose;
    text_lose.setFont(font);
    text_lose.setCharacterSize(36);
    text_lose.setPosition(280, 200);
    text_lose.setFillColor(sf::Color::Red);

    sf::Text text_win;
    text_win.setFont(font);
    text_win.setCharacterSize(36);
    text_win.setPosition(200, 200);
    text_win.setFillColor(sf::Color::Blue);

    // Добавление иконки
    sf::Image icon;
    if (!icon.loadFromFile("img/paper_mario.png"))
        return -1;
    window.setIcon(32, 32, icon.getPixelsPtr());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(start && !lose && !win) {
            for (const auto &grib: gribs) {
                grib->Move();
                if (grib->GetY() > height) {
                    grib->SetVelocity(rand() % 5 + 1);
                    grib->SetY(0);
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                mario->MoveLeft();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                mario->MoveRight();
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard:: Up)){
//            mario->MoveUp();
//        }

            // Проверка столкновения
            for (int i = 0; i < gribs.size(); i++) {
                int X = mario->GetX();
                int Y = mario->GetY();
                float R = mario->GetR();

                int x = gribs[i]->GetX();
                int y = gribs[i]->GetY();
                float r = gribs[i]->GetR();

                float d = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));

                if (R + r >= d) {
                    lose = true;
                    std::cout << "You loser!";
                    //window.close();
//                delete gribs[i];
//                gribs.erase(gribs.begin() + i);
//                i--;
                }
            }
        }

        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        if(localPosition.x >= 695 && localPosition.x <= 740 && localPosition.y <= 30){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                window.close();
            }
        }
        sf::Vector2i localPosition2 = sf::Mouse::getPosition(window);
        if(localPosition.x >= 595 && localPosition.x <= 640 && localPosition.y <= 30){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                start = true;
                lose = false;
                win = false;
                time = 30;
                for (const auto &grib: gribs) {
                        grib->SetVelocity(rand() % 5 + 1);
                        grib->SetY(0);
                }
                mario->SetX(0);
            }
        }


        window.clear();

        sf::Sprite sprite;
        sprite.setTexture(texture);
        window.draw(sprite);

        if(start) {
            text_time.setString(std::string("Time: ") + std::to_string(int(time * 100) / 100));
            window.draw(text_time);
//            text_score.setString(std::string("Score: ") + std::to_string(score));
//            window.draw(text_score);
            window.draw(*mario->Get());
            for (const auto &grib: gribs)
                window.draw(*grib->Get());
            if (lose && !win) {
                text_lose.setString(std::string("You loser! "));
                window.draw(text_lose);
            }
            if (win && !lose) {
                text_win.setString(std::string("You win! Congratulations! "));
                window.draw(text_win);
            }
        }

        text_start.setString(std::string("Start"));
        window.draw(text_start);

        text_exit.setString(std::string("Exit"));
        window.draw(text_exit);

        window.display();
        // https://ravesli.com/urok-129-tajming-koda-vremya-vypolneniya-programmy/
        std::this_thread::sleep_for(40ms);
        if(start && !lose && !win) time -= 0.04;
        if(start && time <= 0){
            win = true;
            time = 0;
        }
    }
    for (const auto& grib : gribs)
        delete grib;
    gribs.clear();

    return 0;
}