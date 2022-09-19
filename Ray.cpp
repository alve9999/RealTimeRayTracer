#include "Ray.h"

Ray::Ray(glm::vec3 aorigin, glm::vec3 adirection_vector, glm::vec3 acolour) {
	origin = aorigin;
	direction_vector = adirection_vector;
	colour = acolour;
}

glm::vec3 Ray::at(float t) {
	return origin + t * direction_vector;
}