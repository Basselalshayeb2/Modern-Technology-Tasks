#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "image.h"


image_p image_create(pixel_coord width, pixel_coord height)
{
    image_t *v = malloc(sizeof(image_t));
    if (!v) {
        fprintf(stderr, "Failed to allocate image structure.\n");
        return NULL;
    }
    v->width = width;
    v->height = height;
    v->data = malloc(sizeof(pixel_data) * width * height);
    if (!v->data) {
        fprintf(stderr, "Failed to allocate image data.\n");
        free(v);
        return NULL;
    }
    return v;
}

void clear_image(image_p picture)
{
    memset(picture->data, 0, sizeof(pixel_data) * picture->width * picture->height);
}

void fill_random(image_p picture)
{
    pixel_data *p = picture->data;
    for (pixel_coord z = 0; z < picture->height * picture->width; ++z, ++p) {
        *p = (pixel_data)(rand() % 256);
    }
}

void image_delete(image_p picture)
{
    if (!picture) return;
    free(picture->data);
    free(picture);
}

int image_save_pgm(image_p picture, const char *filename)
{
    if (!picture || !filename) {
        fprintf(stderr, "image_save_pgm: invalid arguments.\n");
        return 1;
    }

    FILE *to = fopen(filename, "w");
    if (!to) {
        perror("Failed to open output file");
        return 1;
    }

    // ASCII P2 format
    fprintf(to, "P2\n%u %u\n255\n", picture->width, picture->height);

    pixel_data *p = picture->data;
    for (pixel_coord y = 0; y < picture->height; ++y) {
        for (pixel_coord x = 0; x < picture->width; ++x) {
            fprintf(to, "%u", *(p++));
            if (x == picture->width - 1)
                fputc('\n', to);
            else
                fputc(' ', to);
        }
    }

    fclose(to);
    return 0;
}

void image_set_pixel(image_p picture, pixel_coord x, pixel_coord y, pixel_data color)
{
    assert(("Out of range (x,y)", x < picture->width && y < picture->height));
    picture->data[picture->width * y + x] = color;
}

pixel_data get_pixel(image_p picture, pixel_coord x, pixel_coord y)
{
    assert(("Out of range (x,y)", x < picture->width && y < picture->height));
    return picture->data[picture->width * y + x];
}
