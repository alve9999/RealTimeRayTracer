#include "pixel_buffer.h"
#include "common.h"
#include "g-truc-glm-bf71a83/glm/glm.hpp"
#include "cuda_runtime.h"
#include <stdio.h>
#include <stdlib.h>

pixel_buffer::pixel_buffer(int x_size, int y_size){
    length = y_size;
    glm::vec3* data = (glm::vec3*)malloc(y_size * x_size * sizeof(glm::vec3));
}

glm::vec3* pixel_buffer::access(int x, int y) {
    return(&data[y * length + x]);
}
