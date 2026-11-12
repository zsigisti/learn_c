#include <stdio.h>

struct Student {
    int id;
    int age;
    float grade;

};

float calculateAvarage(struct Student student[], int count) {
    int i;
    float sum = 0;
    for (i = 0; i < count; i++) {
        sum = (float)student[i].grade + sum;
    }
    return (float)sum / count;

}

float findLargest(struct Student student[], int count) {
    int i;
    float largest = student[0].grade;
    for (i = 1; i < count; i++) {
        if (student[i].grade > largest) {
            largest = student[i].grade;
        }
    }
    return largest;
}

int main() {
    struct Student students[50];
    int choice;
    int count = 0;
    do {
        printf("1. Add a student\n");
        printf("2. Display all students\n");
        printf("3. Calculate average grade\n");
        printf("4. Find student with highest grade\n");
        printf("5. Search student by ID\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count == 50) {
                    printf("all 50 slots filled\n");
                    return 0;
                } else {
                    printf("student ID: %d\n", count);
                    printf("age?\n");
                    scanf("%d", &students[count].age);
                    printf("grade?\n");
                    scanf("%f", &students[count].grade);
                    printf("student has been succesfuly added with ID: %d\n",count);
                    count++;
                }
                break;
            case 2:
                if (count == 0) {
                    printf("No students have been added yet\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        printf("student ID: %d\n", students[i].id);
                        printf("age: %d\n", students[i].age);
                        printf("grade: %.2f\n", students[i].grade);
                    }
                }
                break;
            case 3:
                printf("avarage grade: %f\n", calculateAvarage(students, count));
                break;
            case 4:
                printf("best grade is: %f\n", findLargest(students, count));
        }

    } while (choice != 0);

}

// not finished, i might come back to this