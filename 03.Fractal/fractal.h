#ifndef FRACTAL_H
#define FRACTAL_H
#include "image.h"

typedef enum {
    FRACTAL_JULIA,
    FRACTAL_SIERPINSKI,
    FRACTAL_MANDELBROT
} fractal_type;


static unsigned int clamp_iter_to_gray(int iteration, int max_iter);
void generate_julia(image_p img);
void generate_sierpinski(image_p img);
void generate_mandelbrot(image_p img);

#endif

