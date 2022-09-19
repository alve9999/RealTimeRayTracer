#include "camera.h"
#include "common.h"
#include "Ray.h"

camera::camera(glm::vec3 aorigin, float fov,glm::vec3 atarget) {
	origin = aorigin;
	target = atarget;
	look_vector = glm::normalize(target - origin);
	aspect_ratio = float(screen_width) / float(screen_height);
	glm::vec3 left_edge_vector(0, 0, -sin(fov));
	glm::vec3 up_edge_vector(0, sin(fov)/aspect_ratio, 0);
	top_left = up_edge_vector + left_edge_vector;
}

Ray camera::get_ray(float height_offset, float width_offset){
	glm::vec3 offset_vector = look_vector;
	offset_vector.z += top_left.z * width_offset;
	offset_vector.y += top_left.y * height_offset;
}

