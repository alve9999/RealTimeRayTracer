#pragma once
#include "ray.h"
#include "g-truc-glm-bf71a83/glm/glm.hpp"
#include "material.h"
//base class for all objects that can exist in a schene
class primitives{
public:
	material* object_material;
	virtual ray check_hit(ray incoming_ray,float& t);
};

class plane : public primitives {
public:
	glm::vec3 normal; //the normal vector for the plane
	float d; //the value for d in the plane equation ax + bx + cx + d = 0
	plane(glm::vec3 anormal, float ad,material* amaterial);
	ray check_hit(ray incoming_ray, float& t);
};

class sphere : public primitives {
public:
	glm::vec3 origin;
	float radius;
	sphere(glm::vec3 aorigin,float aradius, material* amaterial);
	ray check_hit(ray incoming_ray, float& t);
};
