#include "material.h"
#include "common.h"

float glass::schlink_aproximation(float cos,float k) {
    float R = ((k - 1) / (k + 1)) * ((k - 1) / (k + 1));
    return R + (1 - R) * pow(1.0f - cos, 5);
}

glm::vec3 random_sphere_point() {
    glm::vec3 random_point;
    while (1) {
        random_point = glm::vec3(RAND * 2.0f - 1.0f, RAND * 2.0f - 1.0f, RAND * 2.0f - 1.0f);
        if (glm::length(random_point) < 1) {
            return random_point;
        }
    }
}


diffuse::diffuse(glm::vec3 aalbedo) {
    albedo = aalbedo;
}

metal::metal(glm::vec3 aalbedo, float afuzzines) {
    albedo = aalbedo;
    fuzzines = afuzzines;
}

glass::glass(glm::vec3 aalbedo, float arefractive_index) {
    albedo = aalbedo;
    refractive_index = arefractive_index;
}


glm::vec3 diffuse::reflect(glm::vec3 incoming_ray,glm::vec3 normal) {
    return glm::normalize(normal) + random_sphere_point();
}

glm::vec3 metal::reflect(glm::vec3 incoming_ray,glm::vec3 normal) {
	return incoming_ray - 2 * glm::dot(incoming_ray, normal) * normal;
}

glm::vec3 glass::reflect(glm::vec3 incoming_ray,glm::vec3 normal) {
    float k = 1 / refractive_index;
    float cos = glm::dot(glm::normalize(incoming_ray), glm::normalize(normal));
    float sin = sqrt(1 - cos * cos);

    if (cos > 0) {
        k = refractive_index;
    }

    if (sin * k > 1 || schlink_aproximation(cos, k) > RAND) {
        return incoming_ray - 2 * glm::dot(incoming_ray, normal) * normal;
    }

    glm::vec3 outgoing_perpendicular = k * (incoming_ray + cos * normal);
    return outgoing_perpendicular - (float)sqrt(1.0f - pow(glm::length(outgoing_perpendicular), 2)) * normal;
}
