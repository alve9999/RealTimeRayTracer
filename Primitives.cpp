#include "Primitives.h"
#include "g-truc-glm-bf71a83/glm/glm.hpp"
#include "Ray.h"

sphere::sphere(glm::vec3 aorigin, float aradius) {
	origin = aorigin;
	radius = aradius;
}

plane::plane(glm::vec3 aorigin, glm::vec3 anormal) {
	origin = aorigin;
	normal = anormal;
}

Ray plane::check_hit(Ray incoming_ray) {
	float dot = glm::dot(normal, incoming_ray.direction_vector);
	if (abs(dot) > 1e-6) {
		//return
	}
	else {
		return Ray(glm::vec3(0,0,0), glm::vec3(0,0,0), glm::vec3(0,0,0));
	}
}

Ray sphere::check_hit(Ray incoming_ray) {
	glm::vec3 b = (incoming_ray.origin - origin);
	float a = 2 * (glm::dot(incoming_ray.direction_vector, b));
	float discriminant = pow(a, 2)-4*pow(incoming_ray.direction_vector.length(),2)*(pow(b.length(), 2) - pow(radius,2));
	if (discriminant < 0) {
		if ( (-a -sqrt(discriminant)) / (2*pow(incoming_ray.direction_vector.length(),2)) > 0 ) {
			//return
		}
		else {
			//return
		}
	}
	else {
		return Ray(glm::vec3(), glm::vec3(), glm::vec3());
	}
}