#pragma once
#include "g-truc-glm-bf71a83/glm/glm.hpp"
#include "cuda_runtime.h"

class pixel_buffer {
public:
    glm::vec3* data;
    int length;
    pixel_buffer(int x_size, int y_size);
    float sampels = 1;

    glm::vec3* access(int x, int y);
};


