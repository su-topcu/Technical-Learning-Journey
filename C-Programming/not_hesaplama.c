#include <stdio.h>
#define MAX_STUDENTS 5

//Function prototype to calculate the average score 
float calculateAverage(int grades[], int size);

int main() {
  //Array definition to store student grades
  int studentGrades[MAX_STUDENTS] = {85, 92, 78, 64, 90};

  printf("--- Engineering Faculty Grading System ---\n");

  //Displaying grades and performing a basic boundary check
  for (int i = 0; i < MAX_STUDENTS; i++) {
      if (studentGrades[i] < 0 || studentGrades[i] > 100) {
          printf("Error: Invalid grade detected at index %d!\n", i);
          return 1;
      }
      printf("Student %d Grade: %d\n", i + 1, studentGrades[i]);
  }

  //Call function to calculate the class average
  float classAverage = calculateAverage(studentGrades, MAX_STUDENTS);

  printf("--------------------------------------------\n");
  printf("Class Average Score: %.2f\n", classAverage);

  return 0;
}

//Function implementation for array processing
float calculateAverage(int grades[], int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
      sum += grades[i];
  }

  //Explicit type casting to prevent integer division data loss
  return (float)sum/size;
}
