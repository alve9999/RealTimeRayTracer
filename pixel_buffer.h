#pragma once
#include "g-truc-glm-bf71a83/glm/glm.hpp"

class pixel_buffer {
public:
    glm::vec3* data;
    int length;
    pixel_buffer(int x_size, int y_size);

    glm::vec3* access(int x, int y);
};


