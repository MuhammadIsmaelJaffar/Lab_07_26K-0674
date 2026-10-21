#include <stdio.h>

int main()
{
    int marks[2][3][3];
    int class_num, student_num, subject_num;
    
    for (class_num = 0; class_num < 2; class_num++)
    {
        for (student_num = 0; student_num < 3; student_num++)
        {
            for (subject_num = 0; subject_num < 3; subject_num++)
            {
                printf("Enter marks for Class %d, Student %d, Subject %d: ", class_num + 1, student_num + 1, subject_num + 1);
                scanf("%d", &marks[class_num][student_num][subject_num]);
            }
        }
    }
    
    int total_marks[2][3] = {0};
    
    for (class_num = 0; class_num < 2; class_num++)
    {
        for (student_num = 0; student_num < 3; student_num++)
        {
            for (subject_num = 0; subject_num < 3; subject_num++)
            {
                total_marks[class_num][student_num] += marks[class_num][student_num][subject_num];
            }
        }
    }
    
    printf("\n--- Total Marks per Student ---\n");
    for (class_num = 0; class_num < 2; class_num++)
    {
        for (student_num = 0; student_num < 3; student_num++)
        {
            printf("Class %d, Student %d Total Marks: %d\n", class_num + 1, student_num + 1, total_marks[class_num][student_num]);
        }
    }
    
    int class_topper_marks[2];
    int class_topper_student[2];
    
    for (class_num = 0; class_num < 2; class_num++)
    {
        int max_marks = total_marks[class_num][0];
        int topper_index = 0;
        
        for (student_num = 1; student_num < 3; student_num++)
        {
            if (total_marks[class_num][student_num] > max_marks)
            {
                max_marks = total_marks[class_num][student_num];
                topper_index = student_num;
            }
        }
        
        class_topper_marks[class_num] = max_marks;
        class_topper_student[class_num] = topper_index + 1;
    }
    
    int overall_max_marks = total_marks[0][0];
    int overall_class = 1;
    int overall_student = 1;
    
    for (class_num = 0; class_num < 2; class_num++)
    {
        for (student_num = 0; student_num < 3; student_num++)
        {
            if (total_marks[class_num][student_num] > overall_max_marks)
            {
                overall_max_marks = total_marks[class_num][student_num];
                overall_class = class_num + 1;
                overall_student = student_num + 1;
            }
        }
    }
    
    printf("\n--- Final Results ---\n");
    for (class_num = 0; class_num < 2; class_num++)
    {
        printf("Top Performer of Class %d: Student %d with %d marks\n", class_num + 1, class_topper_student[class_num], class_topper_marks[class_num]);
    }
    
    printf("\nOverall Topper: Class %d, Student %d with %d marks\n", overall_class, overall_student, overall_max_marks);
    
    return 0;
}