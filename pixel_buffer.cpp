#include "pixel_buffer.h"
#include "common.h"
#include "g-truc-glm-bf71a83/glm/glm.hpp"
#include "cuda_runtime.h"

pixel_buffer::pixel_buffer(int x_size, int y_size){
    length = x_size;
    cudaMallocManaged(&data, x_size * y_size * sizeof(glm::vec3));
}

glm::vec3* pixel_buffer::access(int x, int y) {
    return(&data[x * length + y]);
}
