#pragma once
#include "cuda_runtime.h"
#include "g-truc-glm-bf71a83/glm/glm.hpp"


class ray {
public:
	glm::vec3 origin;
	glm::vec3 direction_vector;
	glm::vec3 colour;
	ray(glm::vec3 aorigin, glm::vec3 adirection_vector, glm::vec3 acolour);
	ray();
	ray(glm::vec3 acolour);

	glm::vec3 at(float t);
};