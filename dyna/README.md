## Question 1
### Answer: With matrix 
- $A_1: \; 30\times 1$
- $A_2: \; 1\times 40$
- $A_3: \; 40\times 10$
- $A_4: \; 10\times 25$
#### Blanks
##### 1
- $A_1 \times A_2 = 30 \times 1 \times 40 = 1200$
- $A_2 \times A_3 = 1 \times 40 \times 10 = 400$
- $A_3 \times A_4 = 40 \times 10 \times 25 = 10000$
###### Resulting matrix:
||1|2|3|4|
|:-:|:-:|:-:|:-:|:-:|
|1|0|1200|||
|2|X|0|400||
|3|X|X|0|10000|
|4|X|X|X|0|
##### 2
- $A_! \times A_2 \times A_3 = min((A_1\cdot A_2)\cdot A_3, A_1\cdot (A_2\cdot A_3) = min(1200 \cdot 10, 30 \cdot 400) = 12000$
- $A_2 \times A_3 \times A_4 = min((A_2\cdot A_3)\cdot A_4, A_2\cdot (A_3\cdot A_4) = min(400 \cdot 25, 1 \cdot 10000) = 10000$
###### Resulting matrix:
||1|2|3|4|
|:-:|:-:|:-:|:-:|:-:|
|1|0|1200|700||
|2|X|0|400|650|
|3|X|X|0|10000|
|4|X|X|X|0|
##### 3
- $A_1 \times A_2 \times A_3 \times A_4 = min((A_1\cdot A_2\cdot A_3) \cdot A_4, (A_1\cdot A_2)\cdot (A_3\cdot A_4), A_1\cdot (A_2\cdot A_3\cdot A_4)) = min(12000 \cdot 25, 1200 \cdot 10000, 30 \cdot 10000) = 300000$
###### Resulting matrix:
||1|2|3|4|
|:-:|:-:|:-:|:-:|:-:|
|1|0|1200|700|1400|
|2|X|0|400|650|
|3|X|X|0|10000|
|4|X|X|X|0|
##### 


## Question 4
The longest Increasing Subsequence Problem (LIS)
1. Describe a completely brute-force solution to the problem for a sequence of length n.  Give an approximate order of magnitude for the work involved. (explain your answer)

Brute force solution:
for each element in the sequence, check if it is greater than the previous element. If it is, add it to the subsequence. If it is not, start a new subsequence. Keep track of the longest subsequence. The length of the longest subsequence is the solution to the problem.
```
for i = 1 to n
    for j = i+1 to n
        if X[j] > X[i]
            add X[j] to subsequence
        else
            start new subsequence
```
The total number of comparisons is approximately $\sum_{i=1}^{n-1} i = \frac{n(n-1)}{2}$ meaning that the eventual time complexity is $O(n^2)$

2. The Longest Increasing Subsequence problem can be solved using dynamic programming.

|5|2|7|12|6|4|14|8|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|1|1|2|3|2|2|4|3|

3. Unlike our previous examples, when we complete the table, the last entry, L[n], is not yet the solution to our problem.  Recall that L[j] equals the length of the longest subsequence ending at index j.  There is no reason why the longest subsequence necessarily ends with the last entry in the sequence.  What is the final step needed to solve the problem of finding the maximum length? 

The last digit is not necessarily the end of the longest subsequence.
The final step is to find the maximum value in the table. This is the length of the longest subsequence.

4. Write pseudocode for the heart of the dynamic programming algorithm to find the length of the longest increasing subsequence, that is, how to fill out the L table.  (Note that you are not finding the increasing sequence itself)

```
L[1] = 1
for i = 2 to n
    L[i] = 1
    for j = 1 to i-1
        if X[j] < X[i] and L[j] >= L[i]
            L[i] = L[j] + 1
```

5. Let the work units for the algorithm of part (d) be comparisons of X-values and comparisons of L-values.  Describe the kind of sequence of length n that results in the best case.  Describe the kind of sequence of length n that results in the worst case.  Give a fairly precise order-of-magnitude for the work in each case. Explain your answers. 

In the case that work unit is comparison of values.
Worst Case: the sequence is sorted in descending order. 
Work:
- X-values: for each element from 1 to n-1, all previous elements are compared. A total of $\sum_{i=1}^{n-1} i = \frac{n(n-1)}{2}$ comparisons.
- L-values: i comparisons are made to update L
Time complexity: $O(n^2)$

Best case: the sequence is already sorted ascending.
Work:
- X-values: for each i, onyl 1 comparison is needed
- L-values: Each L[i] is updated once, setting L[i] = L[i-1] + 1
Time complexity: $O(n)$

The source code of the algorithm is included in the same folder.