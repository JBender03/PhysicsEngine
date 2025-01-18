#include "Particle.h"

Particle::Particle(Vector2D pos, Vector2D vel, Vector2D acc, double m, double damp, bool stat) {
    position = pos;
    velocity = vel;
    acceleration = acc;
    mass = m;
    inverseMass = 1/m;
    damping = damp;
    isStatic = stat;
}

Vector2D Particle::getPosition() const {return position;}
Vector2D Particle::getVelocity() const {return velocity;}
Vector2D Particle::getAcceleration() const {return acceleration;}
double Particle::getMass() const {return mass;}
double Particle::getInverseMass() const {return inverseMass;}
double Particle::getDamping() const {return damping;}
bool Particle::getIsStatic() const {return isStatic;}
double Particle::getKineticEnergy() const {
    double v = velocity.getMagnitude();
    return (0.5 * mass * v * v);
}

void Particle::setPosition(Vector2D& pos) {position = pos;}
void Particle::setVelocity(Vector2D& vel) {velocity = vel;}
void Particle::setAcceleration(Vector2D& acc) {acceleration = acc;}
void Particle::setMass(double m) {
    mass = m;
    inverseMass = 1/m;
}
void Particle::setInverseMass(double m) {
    inverseMass = m;
    mass = 1/m;
}
void Particle::setDamping(double d) {damping = d;}
void Particle::setIsStatic(bool s) {isStatic = s;}

void Particle::update(double dt){
    if (isStatic) return;

    /*

    // semi-implicit Euler

    // Update velocity
    velocity = velocity + acceleration * dt;

    // Apply damping
    velocity = velocity * damping;

    // Update position using new velocity
    position = position + velocity * dt;

    // Clear forces/acceleration for next frame
    clearForces();

    */

    // Velocity Verlet

    // Calculate and update position
    position = position + velocity * dt + acceleration * 0.5 * dt * dt;

    // Calculate and update velocity
    Vector2D new_acceleration = Vector2D(0, 0); // update later if exterior forces are introduced
    velocity = velocity + (acceleration + new_acceleration) * (dt * 0.5);
    acceleration = new_acceleration; // same as clearForces()
}

void Particle::applyForce(Vector2D& force) {
    if (isStatic) return;

    // F = ma, a = F/m = F * (1/m)
    acceleration = acceleration + force * inverseMass;
}

void Particle::clearForces(){
    acceleration = Vector2D(0, 0);
}