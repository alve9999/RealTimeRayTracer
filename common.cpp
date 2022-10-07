#include "common.h"

glm::vec3 element_mul(glm::vec3 v, glm::vec3 u) {
	return glm::vec3(v.x * u.x, v.y * u.y, v.z * u.z);
}