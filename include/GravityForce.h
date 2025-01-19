#ifndef GRAVITY_FORCE_H
#define GRAVITY_FORCE_H

#include "ForceGenerator.h"

class GravityForce: public ForceGenerator {
    private:
        Vector2D gravityVector;

    public:
        GravityForce();

        void updateForce(Particle& particle, double dt) override;
        
        void setGravity(Vector2D& gravity);

        Vector2D getGravity() const;
};

#endif