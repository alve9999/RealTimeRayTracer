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
#include "Ray.h"

void trace_ray(Ray ray) {

}

int main(int argc, char* argv[]) {
    //sets random number generator
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));

    //init SDL
    SDL_container window;

    //initialise the pixel buffer into unified memory
    pixel_buffer image(screen_height, screen_width);

    timer_start;
    timer_end;
    window.render_pixel_buffer(image);



    return 0;
}

