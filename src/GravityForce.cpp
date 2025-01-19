#include "GravityForce.h"

GravityForce::GravityForce() {
    gravityVector = Vector2D(0, -9.81);
}

void GravityForce::updateForce(Particle& particle, double dt) {
    if (particle.getIsStatic()) return;

    Vector2D force = gravityVector * particle.getMass();

    particle.applyForce(force);
}

void GravityForce::setGravity(Vector2D& gravity) {
    gravityVector = gravity;
}

Vector2D GravityForce::getGravity() const{
    return gravityVector;
}