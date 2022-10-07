#pragma once
#include "ray.h"
class material{
public:
	virtual glm::vec3 reflect(glm::vec3 incoming_ray, glm::vec3 normal) { return glm::vec3(); };
	glm::vec3 albedo;
};

class diffuse : public material {
public:
	diffuse(glm::vec3 aalbedo);
	glm::vec3 reflect(glm::vec3 incoming_ray, glm::vec3 normal);
};

class metal : public material {
public:
	float fuzzines;
	metal(glm::vec3 aalbedo, float afuzzines);
	glm::vec3 reflect(glm::vec3 incoming_ray, glm::vec3 normal);
};

class glass : public material {
public:
	glass(glm::vec3 aalbedo, float arefractive_index);
	float refractive_index;
	glm::vec3 reflect(glm::vec3 incoming_ray, glm::vec3 normal);

	float glass::schlink_aproximation(float cos, float k);
};