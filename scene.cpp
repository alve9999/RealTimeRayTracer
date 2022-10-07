#include "scene.h"
#include "primitives.h"
#include <vector>
#include <memory>
#include "ray.h"
#include "common.h"
#include "cuda_runtime.h"

scene::scene() {
	//add scene objects here
    glm::vec3 center(0, -1000, 0);
    diffuse* diffuse1 = new diffuse(glm::vec3(0.5, 0.5, 0.5));
    sphere sphere1(center, 1000.0f, diffuse1);
    objects.push_back(std::make_shared<sphere>(sphere1));
    glass* material1 = new glass(glm::vec3(1,1,1),1.5);
    objects.push_back(std::make_shared<sphere>(glm::vec3(0, 1, 0), 1.0, material1));
    diffuse* material2 = new diffuse(glm::vec3(0.4, 0.2, 0.1));
    objects.push_back(std::make_shared<sphere>(glm::vec3(-4, 1, 0), 1.0, material2));
    metal* material3 = new metal(glm::vec3(0.7, 0.6, 0.5),1);
    objects.push_back(std::make_shared<sphere>(glm::vec3(4, 1, 0), 1.0, material3));
}

ray scene::scene_hit(ray incoming_ray) {
    float t = 0;
    ray outgoing_ray = ray(element_mul(sky_colour,incoming_ray.colour));
    for (int i = 0; i < objects.size(); i++) {
        ray returned_ray = objects[i]->check_hit(incoming_ray,t);
        if (returned_ray.direction_vector != glm::vec3(0, 0, 0)) {
            outgoing_ray = returned_ray;
        }
    }
    return outgoing_ray;
}

glm::vec3 scene::trace_ray(ray incoming_ray) {

    for (int i = 0; i < depth; i++) {
        incoming_ray = scene_hit(incoming_ray);
        if (incoming_ray.direction_vector == glm::vec3(0, 0, 0)) {
            break;
        }
    }
    return incoming_ray.colour;
}