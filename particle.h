#ifndef PARTICLE_H
#define PARTICLE_H

#include "vec.h"

struct Particle {
	float mass, d;
	vec3 pos, velo, force, color;
	
	void Euler_Step(float h) {
		force += vec3(0, (-9.8) * mass, 0);
		velo += (h * force) / mass;
		pos += velo * h;
	}	
	void Reset_Forces() {
		force = vec3(0,0,0);
	}
	void Handle_Collision(float damping, float coeff_resititution) {
		
	}
};

#endif
