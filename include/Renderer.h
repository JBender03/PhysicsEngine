#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Particle.h"
#include <vector>

class Renderer {
    private:
        sf::RenderWindow window;
        std::vector<sf::CircleShape> particleShapes;

    public:
        Renderer(int width = 800, int height = 600);
        void clear();
        void draw(const std::vector<Particle>& particles);
        void display();
        bool isOpen() const;
        void handleEvents();
};

#endif