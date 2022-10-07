#pragma once
#include "primitives.h"
#include "ray.h"
#include "g-truc-glm-bf71a83/glm/glm.hpp"
#include <vector>
#include <memory>
#include "common.h"

class scene {
public:
	std::vector<std::shared_ptr<primitives>> objects = {};
	glm::vec3 sky_colour = glm::vec3(1,1,1);

	scene();

	ray scene_hit(ray incoming_ray);

	glm::vec3 scene::trace_ray(ray incoming_ray);
};