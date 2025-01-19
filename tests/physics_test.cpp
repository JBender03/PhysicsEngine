#include "Particle.h"
#include <iostream>
#include <cassert>

void printParticleState(const std::string& testName, const Particle& p) {
    std::cout << "\n" << testName << ":\n";
    std::cout << "Position: " << p.getPosition().toString() << "\n";
    std::cout << "Velocity: " << p.getVelocity().toString() << "\n";
    std::cout << "Acceleration: " << p.getAcceleration().toString() << "\n";
    std::cout << "Kinetic Energy: " << p.getKineticEnergy() << "\n";
}

void runTests() {
    std::cout << "Starting Particle Tests...\n";

    // Test 1: Default Construction
    Particle p1;
    std::cout << "\nTest 1 - Default Constructor:";
    printParticleState("Default Particle", p1);

    // Test 2: Custom Construction
    Particle p2(Vector2D(1.0, 2.0), Vector2D(3.0, 4.0));
    std::cout << "\nTest 2 - Custom Constructor:";
    printParticleState("Custom Particle", p2);

    // Test 3: Force Application
    Particle p3(Vector2D(0,0), Vector2D(0,0));
    Vector2D force(10.0, 0.0);  // 10N force in x direction
    p3.applyForce(force);
    std::cout << "\nTest 3 - After Force Application:";
    printParticleState("Force Test Particle", p3);

    // Test 4: Update/Integration
    double dt = 0.1;  // 0.1 second timestep
    for (int i = 0; i < 10; ++i){
        p3.update(dt);
        std::cout << "\nTest 4 - After Update (dt=0.1s):";
        printParticleState("Updated Particle", p3);
    }

    /*
    // Test 5: Static Particle
    Particle p4(Vector2D(0,0));
    p4.setIsStatic(true);
    Vector2D force2(10.0, 0.0);
    p4.applyForce(force2);
    p4.update(dt);
    std::cout << "\nTest 5 - Static Particle (should not move):";
    printParticleState("Static Particle", p4);
    */

    std::cout << "\nAll tests completed.\n";
}

int main() {
    runTests();
    return 0;
}