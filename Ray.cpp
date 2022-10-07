#include "ray.h"
#include "cuda_runtime.h"

ray::ray(glm::vec3 aorigin, glm::vec3 adirection_vector, glm::vec3 acolour) {
	origin = aorigin;
	direction_vector = adirection_vector;
	colour = acolour;
}

ray::ray() {
	origin = glm::vec3(0, 0, 0);
	direction_vector = glm::vec3(0, 0, 0);
	colour = glm::vec3(0, 0, 0);
}

ray::ray(glm::vec3 acolour) {
	origin = glm::vec3(0, 0, 0);
	direction_vector = glm::vec3(0, 0, 0);
	colour = acolour;
}

glm::vec3 ray::at(float t) {
	return origin + t * direction_vector;
}