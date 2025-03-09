#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float grade;
} Module;

typedef struct {
    char last_name[50];
    char *first_name;
    char *CNE;
    float average;
    Module *subject_grades;
} Student;

Student create_student() {
    Student s;
    printf("Enter last name: ");
    scanf("%s", s.last_name);
    s.first_name = (char *)malloc(50 * sizeof(char));
    printf("Enter first name: ");
    scanf("%s", s.first_name);
    s.CNE = (char *)malloc(20 * sizeof(char));
    printf("Enter CNE: ");
    scanf("%s", s.CNE);
    s.subject_grades = (Module *)malloc(5 * sizeof(Module));
    printf("Enter grades for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s.subject_grades[i].grade);
    }
    return s;
}

void display_student(Student s) {
    printf("Last Name: %s\n", s.last_name);
    printf("First Name: %s\n", s.first_name);
    printf("CNE: %s\n", s.CNE);
    printf("Grades:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: %.2f\n", i + 1, s.subject_grades[i].grade);
    }
}

Student* create_student_list(int num_students) {
    Student *list = (Student *)malloc(num_students * sizeof(Student));
    for (int i = 0; i < num_students; i++) {
        printf("Enter details for student %d:\n", i + 1);
        list[i] = create_student();
    }
    return list;
}

float calculate_average(Module *grades) {
    float sum = 0.0;
    for (int i = 0; i < 5; i++) {
        sum += grades[i].grade;
    }
    return sum / 5;
}

void display_student_list(Student *list, int num_students) {
    for (int i = 0; i < num_students; i++) {
        display_student(list[i]);
        list[i].average = calculate_average(list[i].subject_grades);
        printf("Average: %.2f\n", list[i].average);
    }
}

void find_top_student(Student *list, int num_students) {
    float max_average = 0.0;
    int top_index = 0;
    for (int i = 0; i < num_students; i++) {
        if (list[i].average > max_average) {
            max_average = list[i].average;
            top_index = i;
        }
    }
    printf("Top Student: %s %s with an average of %.2f\n", list[top_index].last_name, list[top_index].first_name, max_average);
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    Student *student_list = create_student_list(num_students);
    display_student_list(student_list, num_students);
    find_top_student(student_list, num_students);

    for (int i = 0; i < num_students; i++) {
        free(student_list[i].first_name);
        free(student_list[i].CNE);
        free(student_list[i].subject_grades);
    }
    free(student_list);

    return 0;
}