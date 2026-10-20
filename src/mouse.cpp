#include "sprite.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
//#include "basic_transform.h"
int main() {
    sf::RenderWindow window(sf::VideoMode({256, 256}), "Sprites lab", sf::State::Windowed);
    sf::Texture texture("assets/sword_diamond.png");
    sf::Texture texture2("assets/spritesheet_items.png");
    Sprite s(texture);
    Sprite s2(texture2);
    // Sprite s(texture2, { 0, 512 }, { 128, 640 }); // should be equivalent to using texture
    s.origin() = {0, 0};
    s.position() = {128, 128};
    s.scale() = {32,32};
    // s2.origin() = {114, 14};
    // s2.position() = {127, 128};
    // s2.scale().y = -1;
    // std::cout << (s2.position() == s.position())<< "\n";;

    std::cout << s.scale() << "scale is\n";
    // s.position().x = -1;
    // window.setMouseCursorVisible(false); // you can use this to hide the mouse
    std::cout << s.position() << "position is \n";
    std::cout << s.applyPoint2({2,2}) << " after apply point 2,2 \n";
    std::cout << s.applyPoint2({1,0})<< " after applypoint 1 0\n";
    std::cout << s.applyVector2({2,2})<< " after applyVector 2 2\n";
    //std::cout << s.scale() << " after apply vector\n";
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                return 0;
            }
        }
        s.position() = sf::Vector2f(sf::Mouse::getPosition(window));
        sf::RenderStates states{};
        window.clear(sf::Color::White);
        s.draw(window, states);
        window.display();
    }
    

    return 0;
}
