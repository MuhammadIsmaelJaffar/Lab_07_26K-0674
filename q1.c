#include <stdio.h>

int main()
{
    int seats[10][4];
    int total_rows = 10;
    int total_cols = 4;
    int i, j;
    
    for (i = 0; i < total_rows; i++)
    {
        for (j = 0; j < total_cols; j++)
        {
            seats[i][j] = 0;
        }
    }
    
    int num_reservations;
    printf("How many seats do you want to reserve: ");
    scanf("%d", &num_reservations);
    
    for (int k = 0; k < num_reservations; k++)
    {
        int row, seat;
        printf("Enter row number (1-10): ");
        scanf("%d", &row);
        printf("Enter seat number (1-4): ");
        scanf("%d", &seat);
        
        if (row < 1 || row > 10 || seat < 1 || seat > 4)
        {
            printf("Invalid input. Please enter valid row and seat numbers.\n");
            k--;
            continue;
        }
        
        if (seats[row - 1][seat - 1] == 1)
        {
            printf("Seat already booked\n");
            k--;
        }
        else
        {
            seats[row - 1][seat - 1] = 1;
            printf("Seat reserved successfully.\n");
        }
    }
    
    printf("\nCurrent Seating Arrangement:\n");
    for (i = 0; i < total_rows; i++)
    {
        printf("Row %2d: ", i + 1);
        for (j = 0; j < total_cols; j++)
        {
            printf("%d ", seats[i][j]);
        }
        printf("\n");
    }
    
    int fully_booked_count = 0;
    for (i = 0; i < total_rows; i++)
    {
        int row_sum = 0;
        for (j = 0; j < total_cols; j++)
        {
            row_sum += seats[i][j];
        }
        if (row_sum == total_cols)
        {
            fully_booked_count++;
        }
    }
    
    printf("\nTotal fully booked rows: %d\n", fully_booked_count);
    
    return 0;
}