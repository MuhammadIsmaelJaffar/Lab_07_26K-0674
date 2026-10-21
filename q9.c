#include <stdio.h>

int main()
{
    int num_departments;
    printf("Enter the number of departments: ");
    scanf("%d", &num_departments);
    
    float total_company_salary = 0;
    int dept, emp;
    
    for (dept = 1; dept <= num_departments; dept++)
    {
        int num_employees;
        printf("\nEnter the number of employees in Department %d: ", dept);
        scanf("%d", &num_employees);
        
        float total_dept_salary = 0;
        
        for (emp = 1; emp <= num_employees; emp++)
        {
            int days_worked;
            printf("Enter days worked for Department %d, Employee %d: ", dept, emp);
            scanf("%d", &days_worked);
            
            float salary = days_worked * 500.0;
            
            if (days_worked > 25)
            {
                salary += 2000.0;
            }
            
            total_dept_salary += salary;
            
            printf("Department %d, Employee %d: Days Worked = %d, Salary = Rs. %.2f\n", dept, emp, days_worked, salary);
        }
        
        printf("\nTotal salary paid in Department %d: Rs. %.2f\n", dept, total_dept_salary);
        total_company_salary += total_dept_salary;
    }
    
    printf("\nTotal salary paid across all departments combined: Rs. %.2f\n", total_company_salary);
    
    return 0;
}