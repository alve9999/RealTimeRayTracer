#include "g-truc-glm-bf71a83/glm/glm.hpp"

class Ray {
public:
	glm::vec3 origin;
	glm::vec3 direction_vector;
	glm::vec3 colour;

	Ray::Ray(glm::vec3 aorigin, glm::vec3 adirection_vector, glm::vec3 acolour);

	glm::vec3 at(float t);
};