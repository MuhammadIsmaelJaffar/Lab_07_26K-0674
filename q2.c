#include <stdio.h>

int main()
{
    int grid[3][3];
    int i, j;
    int is_valid = 1;
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter value for row %d, col %d: ", i + 1, j + 1);
            scanf("%d", &grid[i][j]);
        }
    }
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] < 0 || grid[i][j] > 9)
            {
                is_valid = 0;
            }
        }
    }
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] == 0)
            {
                continue;
            }
            
            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    if (r == i && c == j)
                    {
                        continue;
                    }
                    
                    if (grid[r][c] == grid[i][j])
                    {
                        is_valid = 0;
                    }
                }
            }
        }
    }
    
    if (is_valid == 1)
    {
        printf("Valid Grid\n");
    }
    else
    {
        printf("Invalid Grid\n");
    }
    
    return 0;
}