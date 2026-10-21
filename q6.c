#include <stdio.h>

int main()
{
    int data[3][3];
    int key[3][3];
    int encrypted[3][3];
    int i, j;
    
    printf("Enter values for Data matrix (3x3):\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter value for row %d, col %d: ", i + 1, j + 1);
            scanf("%d", &data[i][j]);
        }
    }
    
    printf("\nEnter values for Key matrix (3x3):\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter value for row %d, col %d: ", i + 1, j + 1);
            scanf("%d", &key[i][j]);
        }
    }
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            encrypted[i][j] = (data[i][j] * key[i][j]) + (i + j);
        }
    }
    
    printf("\nEncrypted Matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%4d ", encrypted[i][j]);
        }
        printf("\n");
    }
    
    int max_encrypted = encrypted[0][0];
    int max_row = 0;
    int max_col = 0;
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (encrypted[i][j] > max_encrypted)
            {
                max_encrypted = encrypted[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    
    printf("\nMaximum Encrypted Value: %d at position (Row: %d, Column: %d)\n", max_encrypted, max_row + 1, max_col + 1);
    
    return 0;
}