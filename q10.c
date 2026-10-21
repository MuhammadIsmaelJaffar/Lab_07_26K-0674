#include <stdio.h>

int main()
{
    int num_classes;
    printf("Enter the number of classes: ");
    scanf("%d", &num_classes);
    
    float total_school_marks = 0;
    int total_school_subjects = 0;
    int class_idx, student_idx, subject_idx;
    
    for (class_idx = 1; class_idx <= num_classes; class_idx++)
    {
        int num_students;
        printf("\nEnter the number of students in Class %d: ", class_idx);
        scanf("%d", &num_students);
        
        float total_class_marks = 0;
        int total_class_subjects = 0;
        
        for (student_idx = 1; student_idx <= num_students; student_idx++)
        {
            int num_subjects;
            printf("Enter the number of subjects for Class %d, Student %d: ", class_idx, student_idx);
            scanf("%d", &num_subjects);
            
            float total_student_marks = 0;
            int has_failed = 0;
            
            for (subject_idx = 1; subject_idx <= num_subjects; subject_idx++)
            {
                float marks;
                printf("Enter marks for subject %d: ", subject_idx);
                scanf("%f", &marks);
                
                total_student_marks += marks;
                
                if (marks < 40)
                {
                    has_failed = 1;
                }
            }
            
            float average_marks = total_student_marks / num_subjects;
            
            total_class_marks += total_student_marks;
            total_class_subjects += num_subjects;
            
            if (has_failed)
            {
                printf("Class %d, Student %d: Total Marks = %.2f, Average = %.2f, Result = Fail\n", class_idx, student_idx, total_student_marks, average_marks);
            }
            else
            {
                printf("Class %d, Student %d: Total Marks = %.2f, Average = %.2f, Result = Pass\n", class_idx, student_idx, total_student_marks, average_marks);
            }
        }
        
        float class_average = total_class_marks / total_class_subjects;
        
        printf("\nTotal marks in Class %d: %.2f, Class Average: %.2f\n", class_idx, total_class_marks, class_average);
        
        total_school_marks += total_class_marks;
        total_school_subjects += total_class_subjects;
    }
    
    float school_average = total_school_marks / total_school_subjects;
    
    printf("\nTotal marks across all classes: %.2f, Overall School Average: %.2f\n", total_school_marks, school_average);
    
    return 0;
}