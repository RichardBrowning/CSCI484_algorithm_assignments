# Amortized Analysis Homework
I counstructed a C++ program to research this problem, which can be found in this folder

## Problem 1
Right side represents the stack top
1. Step 1

|stack A | 5 |
|-|-|

|stack B |
|-|

2. Step 2

|stack A | 7 | 5 |
|-|-|-|

|stack B |
|-|

3. Step 3
- pop from stack A, push to stack B

|stack A |
|-|

|stack B | 5 | 7 |
|-|-|-|

- pop from stack B

|stack A |
|-|

|stack B | 7 |
|-|-|

4. Step 4

|stack A | 3 |
|-|-|

|stack B | 7 |
|-|-|

5. Step 5

|stack A | 3 | 6 |
|-|-|-|

|stack B | 7 |
|-|-|

6. Step 6

|stack A | 3 | 6 | 9 |
|-|-|-|-|

|stack B | 7 |
|-|-|

7. Step 7

- pop from stack A, push to stack B. until stack A is empty

|stack A |
|-|

|stack B | 9 | 6 | 3 | 7 |
|-|-|-|-|-|

- pop from stack B

|stack A |
|-|

|stack B | 6 | 3 | 7 |
|-|-|-|-|

8. Step 8

|stack A |
|-|

|stack B | 3 | 7 |
|-|-|-|

9. Step 9

|stack A |
|-|

|stack B | 7 |

10. Step 10

|stack A |
|-|

|stack B |
|-|

Here is a sample output:
