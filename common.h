#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>

const int screen_height = 2160;
const int screen_width = 3456;

#define PI 3.141592
#define RAND ((float)rand() / RAND_MAX)

typedef std::chrono::high_resolution_clock Clock;

#define timer_start auto t1 = Clock::now()

#define timer_end auto t2 = Clock::now();std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()

