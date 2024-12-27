#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void generate_julia(image_p img);
void generate_sierpinski(image_p img);
void generate_mandelbrot(image_p img);

static void test_image_creation() {
    image_p img = image_create(100, 50);
    assert(img != NULL);
    assert(img->width == 100);
    assert(img->height == 50);
    image_delete(img);
    printf("test_image_creation passed!\n");
}

static void test_julia_generation() {
    image_p img = image_create(200, 150);
    assert(img != NULL);

    generate_julia(img);
    for (int i = 0; i < 10; i++) {
        int x = rand() % 200;
        int y = rand() % 150;
        pixel_data color = get_pixel(img, x, y);
        assert(color <= 255 && "Julia color out of range");
    }

    image_delete(img);
    printf("test_julia_generation passed!\n");
}

static void test_sierpinski_generation() {
    image_p img = image_create(200, 150);
    assert(img != NULL);

    generate_sierpinski(img);
    for (int y = 0; y < 150; y++) {
        for (int x = 0; x < 200; x++) {
            pixel_data color = get_pixel(img, x, y);
            assert((color == 0 || color == 255) && "Sierpinski: invalid color");
        }
    }

    image_delete(img);
    printf("test_sierpinski_generation passed!\n");
}

static void test_mandelbrot_generation() {
    image_p img = image_create(200, 150);
    assert(img != NULL);

    generate_mandelbrot(img);
    for (int i = 0; i < 10; i++) {
        int x = rand() % 200;
        int y = rand() % 150;
        pixel_data color = get_pixel(img, x, y);
        assert(color <= 255 && "Mandelbrot color out of range");
    }

    image_delete(img);
    printf("test_mandelbrot_generation passed!\n");
}

int main(void) {
    srand(1234);

    test_image_creation();
    test_julia_generation();
    test_sierpinski_generation();
    test_mandelbrot_generation();

    printf("All fractal tests finished.\n");
    return 0;
}
