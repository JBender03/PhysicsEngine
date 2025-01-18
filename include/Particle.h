#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector2D.h"

class Particle {
    private:
        Vector2D position;
        Vector2D velocity;
        Vector2D acceleration;
        double mass;
        double inverseMass;
        double damping;
        bool isStatic;

    public:
        Particle(Vector2D pos = Vector2D(0, 0),
                 Vector2D vel = Vector2D(0, 0),
                 Vector2D acc = Vector2D(0, 0),
                 double m = 1.0,
                 double damp = 0.99,
                 bool stat = false);

        Vector2D getPosition() const;
        Vector2D getVelocity() const;
        Vector2D getAcceleration() const;
        double getMass() const;
        double getInverseMass() const;
        double getDamping() const;
        bool getIsStatic() const;
        double getKineticEnergy() const;

        void setPosition(Vector2D& pos);
        void setVelocity(Vector2D& vel);
        void setAcceleration(Vector2D& acc);
        void setMass(double m);
        void setInverseMass(double m);
        void setDamping(double d);
        void setIsStatic(bool s);

        void update(double dt);

        void applyForce(Vector2D& force);

        void clearForces();

};

#endif