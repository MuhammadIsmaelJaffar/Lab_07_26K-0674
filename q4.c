#include <stdio.h>

int main()
{
    float cube[3][3][3];
    int x, y, z;
    
    for (z = 0; z < 3; z++)
    {
        for (x = 0; x < 3; x++)
        {
            for (y = 0; y < 3; y++)
            {
                printf("Enter temperature for point [%d][%d][%d]: ", x + 1, y + 1, z + 1);
                scanf("%f", &cube[x][y][z]);
            }
        }
    }
    
    float layer_averages[3];
    for (z = 0; z < 3; z++)
    {
        float sum = 0;
        for (x = 0; x < 3; x++)
        {
            for (y = 0; y < 3; y++)
            {
                sum += cube[x][y][z];
            }
        }
        layer_averages[z] = sum / 9.0;
    }
    
    int hottest_layer = 0;
    float max_layer_avg = layer_averages[0];
    for (z = 1; z < 3; z++)
    {
        if (layer_averages[z] > max_layer_avg)
        {
            max_layer_avg = layer_averages[z];
            hottest_layer = z;
        }
    }
    
    float max_temp = cube[0][0][0];
    int max_x = 0;
    int max_y = 0;
    int max_z = 0;
    
    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            for (z = 0; z < 3; z++)
            {
                if (cube[x][y][z] > max_temp)
                {
                    max_temp = cube[x][y][z];
                    max_x = x;
                    max_y = y;
                    max_z = z;
                }
            }
        }
    }
    
    printf("\n--- Layer Averages ---\n");
    for (z = 0; z < 3; z++)
    {
        printf("Layer %d Average Temperature: %.2f\n", z + 1, layer_averages[z]);
    }
    
    printf("\nHottest Layer: Layer %d with average temperature %.2f\n", hottest_layer + 1, max_layer_avg);
    
    printf("\nMaximum Temperature Point:\n");
    printf("Temperature: %.2f at Coordinates (x: %d, y: %d, z: %d)\n", max_temp, max_x + 1, max_y + 1, max_z + 1);
    
    return 0;
}