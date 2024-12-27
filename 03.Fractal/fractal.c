#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "image.h"
#include "fractal.h"

static unsigned int clamp_iter_to_gray(int iteration, int max_iter)
{
    if (iteration >= max_iter) return 0;
    return (unsigned int)(255 - (255.0f * iteration / max_iter));
}

void generate_julia(image_p img)
{
    float cRe = -0.7f;
    float cIm =  0.27015f;
    int   max_iter = 300;

    float scaleX = 3.0f / (float)img->width;
    float scaleY = 2.0f / (float)img->height;

    for (unsigned int py = 0; py < img->height; py++) {
        for (unsigned int px = 0; px < img->width; px++) {
            float zx = 1.5f * (px - img->width / 2) * scaleX;
            float zy =       (py - img->height / 2) * scaleY;

            int iteration = 0;
            while ((zx*zx + zy*zy < 4.0f) && (iteration < max_iter)) {
                float tmp = zx*zx - zy*zy + cRe;
                zy = 2.0f*zx*zy + cIm;
                zx = tmp;
                iteration++;
            }
            pixel_data color = clamp_iter_to_gray(iteration, max_iter);
            image_set_pixel(img, px, py, color);
        }
    }
}

void generate_sierpinski(image_p img)
{
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            image_set_pixel(img, x, y, 255);
        }
    }

    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            unsigned int tx = x;
            unsigned int ty = y;
            unsigned char color = 255;  // white
            while (tx > 0 || ty > 0) {
                if ((tx % 3 == 1) && (ty % 3 == 1)) {
                    color = 0; // black
                    break;
                }
                tx /= 3;
                ty /= 3;
            }
            image_set_pixel(img, x, y, color);
        }
    }
}

void generate_mandelbrot(image_p img)
{
    int max_iter = 300;

    float minX = -2.0f, maxX = 1.0f;
    float minY = -1.0f, maxY = 1.0f;

    float scaleX = (maxX - minX) / (float)img->width;
    float scaleY = (maxY - minY) / (float)img->height;

    for (unsigned int py = 0; py < img->height; py++) {
        for (unsigned int px = 0; px < img->width; px++) {
            float cx = minX + px * scaleX;
            float cy = minY + py * scaleY;

            float zx = 0.0f;
            float zy = 0.0f;
            int iteration = 0;
            while ((zx*zx + zy*zy < 4.0f) && (iteration < max_iter)) {
                float tmp = zx*zx - zy*zy + cx;
                zy = 2.0f*zx*zy + cy;
                zx = tmp;
                iteration++;
            }
            pixel_data color = clamp_iter_to_gray(iteration, max_iter);
            image_set_pixel(img, px, py, color);
        }
    }
}

