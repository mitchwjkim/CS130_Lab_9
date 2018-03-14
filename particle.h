#ifndef PARTICLE_H
#define PARTICLE_H

#include "vec.h"

struct Particle {
	float mass;
	float d = 0;
	vec3 pos, velo, force, color;
	
	vec3 Interpolate(vec3 x, vec3 y, float t) {
		return x * (1 - t) + y * t;
	}

	vec3 Get_Particle_Color(float d) {
		if ( d < 0.1) {
			return vec3(1, 1, 0);
		}
		else if ( d < 1.5 ) {
			return Interpolate(vec3(1, 1, 0),vec3(1, 0, 0), (d - 0.1) / 1.4);
		}
		else if ( d < 2 ) {
			return vec3(1, 0, 0);
		}
		else if ( d < 3 ) {
			return Interpolate(vec3(1, 0, 0), vec3(0.5, 0.5, 0.5), d - 2);
		}
		else {
			return vec3(0.5,0.5,0.5);
		}
	}
	
	void Euler_Step(float h) {
		force += vec3(0, (-9.8) * mass, 0);
		velo += (h * force) / mass;
		pos += velo * h;
		d += h;
		color = Get_Particle_Color(d);
	}	
	void Reset_Forces() {
		force = vec3(0,0,0);
	}
	void Handle_Collision(float damping, float coeff_resititution) {
		if(pos[1] < 0) {
			pos[1] = 0;
			if(velo[1] < 0) {
				velo[1] = -1.0 * coeff_resititution * velo[1];
				velo[1] *= damping;
				velo[2] *= damping;
			}
		}
	}
};

#endif
