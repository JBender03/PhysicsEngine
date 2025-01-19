#include "Particle.h"
#include "GravityForce.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

void printParticleState(const Particle& p) {
    std::cout << "Position: " << p.getPosition().toString() 
              << " Velocity: " << p.getVelocity().toString() << std::endl;
}

int main() {
    // Create particles at different heights
    std::vector<Particle> particles;
    particles.push_back(Particle(Vector2D(0, 10)));  // 10m high
    particles.push_back(Particle(Vector2D(0, 20)));  // 20m high
    particles.push_back(Particle(Vector2D(0, 30)));  // 30m high

    // Create gravity force
    GravityForce gravity;

    // Simulation parameters
    double dt = 0.016;  // ~60fps
    double totalTime = 0.0;
    double simulationDuration = 5.0;  // Run for 5 seconds

    // Simulation loop
    while (totalTime < simulationDuration) {
        std::cout << "\nTime: " << totalTime << "s" << std::endl;
        
        // Update each particle
        for (auto& particle : particles) {
            gravity.updateForce(particle, dt);
            particle.update(dt);
            printParticleState(particle);
        }

        totalTime += dt;
        
        // Sleep to slow down output
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}