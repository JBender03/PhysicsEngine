#ifndef FORCE_GENERATOR_H
#define FORCE_GENERATOR_H

#include "Particle.h"
#include "Vector2D.h"

class ForceGenerator
{
    public:
        virtual ~ForceGenerator() {} // Deconstructor

        virtual void updateForce(Particle& particle, double dt) = 0;
};

#endif