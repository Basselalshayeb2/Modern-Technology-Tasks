#include "fractal.h"
#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH  800
#define HEIGHT 600

int main(int argc, char* argv[])
{
    fractal_type chosen_fractal = FRACTAL_JULIA;
    const char* output_filename = "fractal_output.pgm";

    if (argc > 1) {
        if (strcmp(argv[1], "julia") == 0) {
            chosen_fractal = FRACTAL_JULIA;
        } else if (strcmp(argv[1], "sierpinski") == 0) {
            chosen_fractal = FRACTAL_SIERPINSKI;
        } else if (strcmp(argv[1], "mandelbrot") == 0) {
            chosen_fractal = FRACTAL_MANDELBROT;
        } else {
            fprintf(stderr, "Unknown fractal type '%s'. Use 'julia', 'sierpinski', or 'mandelbrot'.\n", argv[1]);
            return 1;
        }
    }
    if (argc > 2) {
        output_filename = argv[2];
    }

    image_p img = image_create(WIDTH, HEIGHT);
    if (!img) {
        fprintf(stderr, "Failed to create image.\n");
        return 1;
    }

    switch (chosen_fractal) {
        case FRACTAL_JULIA:
            printf("Generating Julia set...\n");
            generate_julia(img);
            break;
        case FRACTAL_SIERPINSKI:
            printf("Generating Sierpinski carpet...\n");
            generate_sierpinski(img);
            break;
        case FRACTAL_MANDELBROT:
            printf("Generating Mandelbrot set...\n");
            generate_mandelbrot(img);
            break;
        default:
            fprintf(stderr, "Invalid fractal type.\n");
            image_delete(img);
            return 1;
    }

    printf("Saving to '%s'...\n", output_filename);
    if (image_save_pgm(img, output_filename) != 0) {
        fprintf(stderr, "Failed to save PGM '%s'\n", output_filename);
        image_delete(img);
        return 1;
    }

    image_delete(img);
    printf("Done.\n");
    return 0;
}