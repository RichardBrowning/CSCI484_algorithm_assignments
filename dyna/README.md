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
- $A_1 \times A_2 \times A_3 \times A_4 = min((A_1\cdot A_2\cdot A_3) \cdot A_4, (A_1\cdot A_2)\cdot (A_3\cdot A_4), A_1\cdot (A_2\cdot A_3\cdot A_4) = min(12000 \cdot 25, 1200 \cdot 10000, 30 \cdot 10000) = 300000$
###### Resulting matrix:
||1|2|3|4|
|:-:|:-:|:-:|:-:|:-:|
|1|0|1200|700|1400|
|2|X|0|400|650|
|3|X|X|0|10000|
|4|X|X|X|0|
##### 
