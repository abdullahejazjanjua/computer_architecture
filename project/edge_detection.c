#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int Gx[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
int Gy[3][3] = { {-1, -2, -1}, { 0,  0,  0}, { 1,  2,  1} };

unsigned char clamp(double value) 
{
    if (value < 0) return 0;
    if (value > 255) return 255;
    return (unsigned char)value;
}

void sobel_filter(unsigned char *input, unsigned char *output, int width, int height) 
{

    #pragma omp parallel for collapse(2) schedule(static)
    for (int y = 1; y < height - 1; y++) 
    {
        for (int x = 1; x < width - 1; x++) 
        {
            double sumX = 0.0;
            double sumY = 0.0;

            for (int i = -1; i <= 1; i++) 
            {
                for (int j = -1; j <= 1; j++) 
                {
                    unsigned char pixel = input[(y + i) * width + (x + j)]; 
                    sumX += pixel * Gx[i + 1][j + 1]; 
                    sumY += pixel * Gy[i + 1][j + 1]; 
                }
            }

            double magnitude = sqrt((sumX * sumX) + (sumY * sumY));
            output[y * width + x] = clamp(magnitude);
        }
    }
}

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Usage: %s <input_image_path>\n", argv[0]);
        return 1;
    }

    int width, height, channels;
    unsigned char *img = stbi_load(argv[1], &width, &height, &channels, 1);
    if (img == NULL) 
    {
        printf("Error loading image.\n");
        return 1;
    }
    printf("Input: %s (%dx%d)\n", argv[1], width, height);

    unsigned char *output_img = (unsigned char *)malloc(width * height * sizeof(unsigned char));

    int thread_counts[] = {1, 2, 4, 8, 16};
    int num_tests = 5;
    double serial_time = 0.0;

    printf("\n--- Performance Benchmarking Results ---\n");
    printf("%-10s | %-12s | %-10s | %-10s\n", "Threads", "Time (s)", "Speedup", "Efficiency");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) 
    {
        int t = thread_counts[i];

        omp_set_num_threads(t);

        double start = omp_get_wtime();

        sobel_filter(img, output_img, width, height);

        double end = omp_get_wtime();
        double time_taken = end - start;

        if (t == 1) 
        {
            serial_time = time_taken;
        }

        double speedup = serial_time / time_taken;

        double efficiency = speedup / t;

        printf("%-10d | %-12.6f | %-10.2fx | %-10.2f\n", t, time_taken, speedup, efficiency);
    }
    printf("------------------------------------------------------\n");

    stbi_write_png("sobel_output.png", width, height, 1, output_img, width);
    printf("\nFinal output saved to 'sobel_output.png'\n");

    stbi_image_free(img);
    free(output_img);
    return 0;
}