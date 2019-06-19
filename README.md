# Rotate Matrix
This repository contains a single file C++ console program for rotating a matrix in place. It prompts the user to enter the matrix dimension as an interger n. It then generates and initializes an nxn matrix and rotates it 4 times until it is returned to the original position. It handles matrices of arbitrary size including the trivial cases of 0 and 1. Enter a negative number to terminate the program.

This is based on a Leet Code puzzle. The algorithm generalizes the concept of a swap to be performed on 4 values. It operates on "shells" of the matrix. For example, a 4x4 matrix would swap the values in the outer cells before proceding to the inner 2x2 matrix.
