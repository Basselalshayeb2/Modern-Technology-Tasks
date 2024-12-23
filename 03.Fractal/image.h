#ifndef IMAGE_H
#define IMAGE_H

typedef unsigned int pixel_coord; 
typedef unsigned int pixel_data;

struct image {
    pixel_coord width, height;
    pixel_data *data;
};

typedef struct image image_t;
typedef struct image* image_p;

image_p image_create(pixel_coord width, pixel_coord height);

void clear_image(image_p picture);

void fill_random(image_p picture);

void image_delete(image_p picture);

int image_save_pgm(image_p picture, const char *filename);

void image_set_pixel(image_p picture, pixel_coord x, pixel_coord y, pixel_data color);

pixel_data get_pixel(image_p picture, pixel_coord x, pixel_coord y);

#endif
