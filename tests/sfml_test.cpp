#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    std::cout << "Starting SFML test..." << std::endl;

    try {
        sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        std::cout << "Window created" << std::endl;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}