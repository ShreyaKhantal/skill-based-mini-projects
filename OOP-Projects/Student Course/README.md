# Student-Course Management System

## Overview

The **Student-Course Management System** is a C++ console application designed to manage students, courses, and their enrollments. This system allows for the creation of students and courses, enrollment of students in courses, removal of students from courses, and display of course details and student information. Additionally, the system allows the calculation of the SGPA (Student Grade Point Average) based on enrolled courses and their respective grades.

## Features

1. **Add Student**: 
   - Create a new student by providing the student’s ID and name.
   
2. **Add Course**: 
   - Create a new course by providing the course ID and name.
   
3. **Enroll Student in Course**: 
   - Enroll a student in a course with a specified grade.
   
4. **Remove Student from Course**: 
   - Remove a student from a course and update the course and student records.
   
5. **Display Students in Course**: 
   - View the list of students enrolled in a particular course.
   
6. **Display Courses of Student**: 
   - View all the courses in which a student is enrolled.
   
7. **Calculate SGPA**: 
   - Calculate the SGPA for a student based on the grades of enrolled courses.
   
8. **Exit**: 
   - Exit the program.

## Technologies

- **Language**: C++
- **Programming Paradigm**: Object-Oriented Programming (OOP)
- **Key Concepts**: Inheritance, Polymorphism, Pointers, Dynamic Memory Allocation

## Class Structure

1. **Student Class**:
   - Contains details of each student, including ID, name, and enrolled courses.
   - Methods include enrolling in a course, removing from a course, displaying courses, and calculating SGPA.

2. **Course Class**:
   - Represents a course with an ID, name, and list of students enrolled.
   - Methods include adding students, removing students, and displaying the list of students enrolled in the course.

## How to Run

1. Ensure you have a C++ compiler (such as GCC or MSVC).
2. Create a file named `student_course_system.cpp` and paste the provided code into it.
3. Compile the code:
   ```bash
   g++ student_course_system.cpp -o student_course_system
   ```
4. Run the compiled application:
   ```bash
   ./student_course_system
   ```

## Usage

Upon running the program, you will see the following menu:

1. **Add Student**: 
   - Adds a student by entering their ID and name.
   
2. **Add Course**: 
   - Adds a course by entering the course ID and name.
   
3. **Enroll Student in Course**: 
   - Enroll a student in a course by selecting the student and the course and entering a grade.
   
4. **Remove Student from Course**: 
   - Remove a student from a course by selecting the student and the course.
   
5. **Display Students in Course**: 
   - Displays a list of all students enrolled in a selected course.
   
6. **Display Courses of Student**: 
   - Displays all courses a student is enrolled in.
   
7. **Calculate SGPA**: 
   - Calculates the SGPA for a student based on the grades in the enrolled courses.

8. **Exit**: 
   - Exits the program.

### Example of Operations

- **Add a Student**: 
  - Enter student ID (e.g., 101) and name (e.g., "John Doe").
  
- **Add a Course**: 
  - Enter course ID (e.g., 201) and course name (e.g., "Mathematics").
  
- **Enroll a Student**: 
  - Enroll "John Doe" in the "Mathematics" course and give a grade (e.g., 8.5).
  
- **Remove a Student**: 
  - Remove "John Doe" from the "Mathematics" course.
  
- **Display Students in Course**: 
  - View all students enrolled in the "Mathematics" course.
  
- **Calculate SGPA**: 
  - Calculate the SGPA for "John Doe" based on their enrolled courses and grades.
