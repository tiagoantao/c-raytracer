#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NX 20000
#define NY 10000


void create_ray_direction(
        float* lower_left_corner,
        float* horizontal,
        float* vertical,
        float u, float v,
        float* direction) {
    direction[0] = lower_left_corner[0];
    direction[1] = lower_left_corner[1];
    direction[2] = lower_left_corner[2];

    direction[0] += u * horizontal[0];
    direction[1] += u * horizontal[1];
    direction[2] += u * horizontal[2];

    direction[0] += v * vertical[0];
    direction[1] += v * vertical[1];
    direction[2] += v * vertical[2];
}


float length(float* v) {
    return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}


void unit_vector(float* v, float* u){
    float l = length(v);
    u[0] = v[0] / l;
    u[1] = v[1] / l;
    u[2] = v[2] / l;
}


bool hit_sphere(float* center, float radius, float* origin, float* direction){
    return false;
}


void color(float* origin, float* direction, float* color) {
    float unit_direction[3];
    //float* unit_direction = (float*)malloc(3 * sizeof(float));
    
    float t;
    t=unit_direction[1];
    unit_vector(direction, unit_direction);
    t = unit_direction[1];
    t = 0.5 * (unit_direction[1] + 1.0);
    color[0] = (1-t) + t*0.5;
    color[1] = (1-t) + t*0.7;
    color[2] = (1-t) + t*1.0;
    color[0] = (1-t) + t*0.5;
    //free(unit_direction);
}


void raytrace(int* image) {
    float lower_left_corner[3] = {-2, -1, -1};
    float horizontal[3] = {4, 0, 0};
    float vertical[3] = {0, 2, 0};
    float origin[3] = {0, 0, 0};

    for (int j = 0; j < NY; j++) {
        for (int i = 0; i < NX; i++) {
            float u = (float)i / NX;
            float v = (float)j / NY;

            float direction[3];
            create_ray_direction(lower_left_corner, horizontal, vertical, u, v, direction);
            float col[3];
            color(origin, direction, col);
            int ir = floor(255.99 * col[0]);
            int ig = floor(255.99 * col[1]);
            int ib = floor(255.99 * col[2]);
            int offset = NX*3*(NY-j-1) + 3*i;
            
            image[offset] = ir;
            image[offset + 1] = ig;
            image[offset + 2] = ib;
        }
    }
}


void dump_ppm(int* image) {
    FILE* f = fopen("out.ppm", "w");
    fprintf(f, "P3\n%d %d\n255\n", NX, NY);

    for (int i = 0; i < NX * NY; i++) {
        fprintf(f, "%d %d %d\n", image[i*3], image[i*3 + 1], image[i*3 + 2]);
    }
    fclose(f);
}


int main() {
    int* image = (int*)malloc(NX*NY*3 * sizeof(int));
    raytrace(image);
//dump_ppm(image);
    free(image);
    return 0;
}
