#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include "g-truc-glm-bf71a83/glm/glm.hpp"


const int screen_height = 2160;
const int screen_width = 3456;
const int depth = 1;

#define PI 3.141592

#define RAND ((float)rand() / RAND_MAX)



glm::vec3 element_mul(glm::vec3 v, glm::vec3 u);

typedef std::chrono::high_resolution_clock Clock;

#define timer_start auto t1 = Clock::now()

#define timer_end auto t2 = Clock::now();std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()

