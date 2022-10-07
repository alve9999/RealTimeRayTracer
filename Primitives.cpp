#include "Primitives.h"
#include "g-truc-glm-bf71a83/glm/glm.hpp"
#include "ray.h"
#include "material.h"
#include "common.h"

ray primitives::check_hit(ray incoming_ray, float& t){
	return ray();
}
sphere::sphere(glm::vec3 aorigin, float aradius, material* amaterial) {
	origin = aorigin;
	radius = aradius;
	object_material = amaterial;
}

plane::plane(glm::vec3 anormal, float ad, material* amaterial) {
	d = ad;
	normal = anormal;
	object_material = amaterial;
}

ray plane::check_hit(ray incoming_ray,float& t) {
	float dot_res = glm::dot(normal, incoming_ray.direction_vector);
	if (abs(dot_res) > 1e-6) {
		if (((glm::dot(normal, incoming_ray.origin) + d) / dot_res) > t) {
			glm::vec3 ray_origin = incoming_ray.at((glm::dot(normal, incoming_ray.origin) + d) / dot_res);
			glm::vec3 direction_vector = object_material->reflect(incoming_ray.direction_vector, normal);
			glm::vec3 colour = element_mul(object_material->albedo, incoming_ray.colour);
			return ray(ray_origin, direction_vector, colour);
		}
	}
	return ray();
}

ray sphere::check_hit(ray incoming_ray,float& t) {
	glm::vec3 b = (incoming_ray.origin - origin);
	float a = 2 * (glm::dot(incoming_ray.direction_vector, b));
	float discriminant = pow(a, 2)-4*pow(incoming_ray.direction_vector.length(),2)*(pow(b.length(), 2) - pow(radius,2));
	if (discriminant > 0) {
		if ( (-a -sqrt(discriminant)) / (2*pow(incoming_ray.direction_vector.length(),2)) > t ) {
			glm::vec3 ray_origin = incoming_ray.at((-a - sqrt(discriminant)) / (2 * pow(incoming_ray.direction_vector.length(), 2)));
			glm::vec3 direction_vector = object_material->reflect(incoming_ray.direction_vector, ray_origin-origin);
			glm::vec3 colour = element_mul(object_material->albedo, incoming_ray.colour);
			return ray(ray_origin,direction_vector,colour);
		}
		else if((-a + sqrt(discriminant)) / (2 * pow(incoming_ray.direction_vector.length(), 2)) > t) {
			glm::vec3 ray_origin = incoming_ray.at((-a + sqrt(discriminant)) / (2 * pow(incoming_ray.direction_vector.length(), 2)));
			glm::vec3 direction_vector = object_material->reflect(incoming_ray.direction_vector, ray_origin - origin);
			glm::vec3 colour = element_mul(object_material->albedo,incoming_ray.colour);
			return ray(ray_origin, direction_vector, colour);
		}
	}
	else {
		return ray();
	}
}