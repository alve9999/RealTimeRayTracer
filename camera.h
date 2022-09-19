#pragma once
#include "g-truc-glm-bf71a83/glm/glm.hpp"
#include "Ray.h"

class camera{
public:
	glm::vec3 origin;
	float aspect_ratio;
	glm::vec3 top_left;
	glm::vec3 target;
	glm::vec3 look_vector;
	camera(glm::vec3 aorigin, float fov, glm::vec3 atarget);
	Ray get_ray(float height_offset,float width_offset);
};

