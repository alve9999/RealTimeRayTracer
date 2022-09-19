#pragma once
#include "Ray.h"
#include "g-truc-glm-bf71a83/glm/glm.hpp"
//base class for all objects that can exist in a schene
class primitives{
public:
	virtual Ray check_hit(Ray incoming_ray){};
};

class plane : public primitives {
public:
	glm::vec3 origin,normal;
	plane(glm::vec3 aorigin, glm::vec3 anormal);
	Ray check_hit(Ray incoming_ray);
};

class sphere : public primitives {
public:
	glm::vec3 origin;
	float radius;
	sphere(glm::vec3 aorigin,float aradius);
	Ray check_hit(Ray incoming_ray);
};
