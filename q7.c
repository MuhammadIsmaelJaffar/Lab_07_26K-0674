#include <stdio.h>

int main()
{
    int n, i, j;
    
    printf("Enter the number of rows for the pattern (maximum 10): ");
    scanf("%d", &n);
    
    if (n < 1 || n > 10)
    {
        printf("Invalid input! Please enter a number between 1 and 10.\n");
        return 0;
    }
    
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
    
    printf("\n");
    
    for (i = n; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
    
    printf("\n");
    
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d ", i * j);
        }
        printf("\n");
    }
    
    return 0;
}