# Determinant Calculator v1.0

## Contents:
 - Main program
	 - dc.exe
 - Source code
	 - dc_vector.cpp
 - Documentation
	 - README.md (this file)

## Function and Features:
 - Calculates the value of a user-defined determinant
	 - Unlimited dimension of determinant
 - Detects non-numerical inputs in a row
	 - Correct error before calculation

## Instructions:
1. Enter the dimension ```n``` of the ```n```x```n``` determinant
2. Enter the elements row by row (seperate them with spaces ```'\n'```)
	2a. If erroneuos input is detected, please key in the WHOLE ROW again
3. Both the determinant and the value will be printed on the screen
4. Press 'Return' to exit the program

## Concepts:
  The algorithm uses the recursive divide-and-conquer approach when implementing the calculation.
The elements in the first row of the matrix are used to perform cofactor expansion. Then
recursion takes place to do the same task until the matrix dimension becomes 2x2. The result is
then returned for further manipulation.

  In order not to deal with the chore of deleting dynamic arrays created with "new" commands and
the error-prone pointers, "vector" class is introduced to carry the user-defined matrices for its
automatic memory allocation property.

## Language Used and Tested Environment:
C++ (compiled with MinGW G++), Windows 10 on Intel i5 with 4GB RAM
