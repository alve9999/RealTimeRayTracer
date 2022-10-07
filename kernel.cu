#pragma once
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <iostream>
#include "common.h"
#include <cstdlib>
#include "SDL.h"
#include <chrono>
#include "pixel_buffer.h"
#include "SDL_container.h"
#include "g-truc-glm-bf71a83/glm/glm.hpp"
#include "ray.h"
#include "camera.h"
#include "scene.h"

void render(glm::vec3* image, camera* main_camera, scene* main_scene,float sampels) {
    for (int i = 0; i < screen_height * screen_width; i++) {
        ray tracing_ray = main_camera->get_ray(((i % screen_width - screen_width/2) * 2 + ((RAND) - 0.5)) / screen_width, (2 * (std::floor((float)i / screen_height) - screen_height/2) + (RAND - 0.5)) / screen_height);
        glm::vec3 ray_colour = main_scene->trace_ray(tracing_ray);
        glm::vec3 pixel_colour = image[i / screen_width * screen_width + i % screen_width];
        pixel_colour = (pixel_colour * (sampels - 1.0f) / sampels + ray_colour / sampels);
    }
}



int main(int argc, char* argv[]) {
    //sets random number generator
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));

    //init SDL
    SDL_container window;


    glm::vec3* image = (glm::vec3*)malloc(screen_height*screen_width*sizeof(glm::vec3));
    for (int i = 0; i < screen_height * screen_width; i++) {
        image[i / screen_width * screen_width + i % screen_width] = glm::vec3(0, 0, 0);
    }
    float sampels = 0;

    //init scene
    scene* main_scene;
    main_scene = new scene();

    //init camera
    camera* main_camera;
    main_camera = new camera(glm::vec3(0,0,0),PI*2/3,glm::vec3(1, 1, 0));


    while (1) {
        render(image, main_camera, main_scene,sampels);
        window.render_pixel_buffer(image);
        sampels += 1;
        std::cout << sampels;
    }



    return 0;
}

