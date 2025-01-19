#include "Renderer.h"

Renderer::Renderer(int width, int height) : window(sf::VideoMode(width, height), "Physics Engine") {
    window.setFramerateLimit(60);
}

void Renderer::clear() {
    window.clear(sf::Color::White);
}

void Renderer::draw(const std::vector<Particle>& particles) {
    for (const auto& particle : particles) {
        sf::CircleShape shape(10.0f); //10 pixel radius
        shape.setFillColor(sf::Color::Blue);

        // Convert physics coordinates to screen coordinates
        Vector2D pos = particle.getPosition();
        shape.setPosition(pos.getX(), window.getSize().y - pos.getY());

        window.draw(shape);
    }
}

void Renderer::display() {
    window.display();
}

bool Renderer::isOpen() const{
    return window.isOpen();
}

void Renderer::handleEvents() {
    sf::Event event;
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}