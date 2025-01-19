#include "Particle.h"
#include "GravityForce.h"
#include "Renderer.h"
#include <vector>
#include <iostream>
#include <stdexcept>

int main() {
    try {
        std::cout << "Starting render test..." << std::endl;
        
        // Create renderer
        std::cout << "Attempting to create renderer..." << std::endl;
        Renderer renderer(800, 600);
        std::cout << "Created renderer successfully" << std::endl;

        // Create particles
        std::vector<Particle> particles;
        particles.emplace_back(Vector2D(400, 500));
        particles.emplace_back(Vector2D(200, 400));
        particles.emplace_back(Vector2D(600, 300));
        std::cout << "Created particles" << std::endl;

        // Create gravity
        GravityForce gravity;
        std::cout << "Created gravity" << std::endl;

        double dt = 1.0/60.0;
        std::cout << "Starting main loop..." << std::endl;

        while (renderer.isOpen()) {
            renderer.handleEvents();

            for (auto& particle : particles) {
                gravity.updateForce(particle, dt);
                particle.update(dt);
            }

            renderer.clear();
            renderer.draw(particles);
            renderer.display();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }

    return 0;
}