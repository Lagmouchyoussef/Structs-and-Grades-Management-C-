# TPS (STRUCTURES AND MEMORY ALLOCATION)

## Exercise 1:

An industrial carpentry workshop manages a stock of wood panels. Each panel has a width, length, and thickness in millimeters, as well as a type of wood, which can be pine (code 0), oak (code 1), or beech (code 2).

1. Define a structure `panel` containing all the information related to a wood panel.
2. Write functions to input and display a wood panel (numeric input for the type of wood (e.g., 0), display the type of wood in characters (e.g., pine)).
3. Write a function that calculates the volume in cubic meters of a panel ((thickness * width * length) / 10^9).

## Exercise 2:

**Part A:** Consider the following structure:

| typedef struct Point( double x; double y; )point; |
|---|

1. Write a function `point create_point()` that declares a variable of type `point` and assigns its data.
2. Write a function `void display(point pt)` that displays the point as follows:
   **Example**: ( x , y ) = ( 10.50 , -03.50 ) .
3. Write a function `double distance(point pt_1, point pt_2)` that returns the distance between two points passed as arguments.
   To calculate the square root and power, use the predefined functions `sqrt()` and `pow()` from the math.h library.
   **Example**: `pow(100.0, 2.00) = (100.0)^2.00` and `sqrt(10.50) = \(\sqrt{10.50}\)`.

**Part B:** Consider the following structure.

| typedef struct Polygon( point tab[100]; )polygon; |
|---|

4. Using the `create_point()` function, write a function `polygon create_polygon()` that returns a polygon with 100 points (p_1, p_2, ..., p_100).
5. Write a function `double perimeter_polygon(polygon polygon)` that returns the perimeter of a polygon.
- Here is an example of a 9-sided polygon with 9 points (p_1, ..., p_9).
Perimeter(polygon) – distance(p_1, p_2) + distance(p_2, p_3) + distance(p_3, p_4) + distance(p_4, p_5) + distance(p_5, p_6) + distance(p_6, p_7) + distance(p_7, p_8) + distance(p_8, p_9) + distance(p_9, p_1).

6. Write a main program to test all these functions.

**Exercise 3:**

In this problem, we want to manage the grades of students in the 2nd year of the preparatory cycle at EMSI. We aim to establish a concrete solution by addressing the following:

You are asked to work with structures in C. The first structure represents the grade for each module, while the second structure represents all the information of a student. The student is identified by the following information (last name, first name, CNE, ...).

Structure 1:    Structure 2:

| typedef struct Module{ float Grade;} module; | typedef struct Student{ char last_name[50]; char *first_name; char *CNE; float Avg; module *Subject_grades;} student; |

- Write a program that consists of the following functions:
  1. A function `student create_student()` that declares a student and assigns their data (input by the user).
  2. A function `void display_student(student st)` that displays all the information about a student passed as a parameter.
  3. A function `student* student_list(int num_students)` that creates a list of students and returns it (each student in this list must have their information).
  4. A function `float student_average(module* modules)` that returns the average grade for a student.
  5. A function `void display_student_list(student* list, int num_students)` that displays all the students in the list along with their overall averages.
  6. A function `void top_student(student* list, int num_students)` that displays the name and first name of the top student.
  7. Test all these functions in a main program.
