#include <stdio.h>

int main()
{
    float sales[4][5];
    float total_sales_salesman[4] = {0};
    float total_sales_product[5] = {0};
    int i, j;
    
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("Enter sales for Salesman %d, Product %d: ", i + 1, j + 1);
            scanf("%f", &sales[i][j]);
        }
    }
    
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            total_sales_salesman[i] += sales[i][j];
        }
    }
    
    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 4; i++)
        {
            total_sales_product[j] += sales[i][j];
        }
    }
    
    float max_product_sales = total_sales_product[0];
    int expensive_product = 1;
    for (j = 1; j < 5; j++)
    {
        if (total_sales_product[j] > max_product_sales)
        {
            max_product_sales = total_sales_product[j];
            expensive_product = j + 1;
        }
    }
    
    float final_amounts[4];
    for (i = 0; i < 4; i++)
    {
        if (total_sales_salesman[i] > 10000)
        {
            final_amounts[i] = total_sales_salesman[i] + (total_sales_salesman[i] * 0.10);
        }
        else
        {
            final_amounts[i] = total_sales_salesman[i];
        }
    }
    
    printf("\n--- Sales Summary ---\n");
    for (i = 0; i < 4; i++)
    {
        printf("Salesman %d Total Sales: %.2f\n", i + 1, total_sales_salesman[i]);
    }
    
    printf("\n");
    for (j = 0; j < 5; j++)
    {
        printf("Product %d Total Sales: %.2f\n", j + 1, total_sales_product[j]);
    }
    
    printf("\nMost Expensive Product: Product %d\n", expensive_product);
    
    printf("\nFinal Amounts after Bonus:\n");
    for (i = 0; i < 4; i++)
    {
        if (total_sales_salesman[i] > 10000)
        {
            printf("Salesman %d: %.2f (Bonus Applied)\n", i + 1, final_amounts[i]);
        }
        else
        {
            printf("Salesman %d: %.2f (No Bonus)\n", i + 1, final_amounts[i]);
        }
    }
    
    return 0;
}