## Question 1
Given the graph, the following matrix was fed to the Dijkstra's algorithm.

||a|b|c|d|e|f|
|-|-|-|-|-|-|-|
|a|$\infty$|1|3|$\infty$|$\infty$|$\infty$|
|b|1|$\infty$|1|$\infty$|$\infty$|1|
|c|3|1|$\infty$|2|4|$\infty$|
|d|$\infty$|$\infty$|2|$\infty$|1|2|
|e|$\infty$|$\infty$|4|1|$\infty$|1|
|f|$\infty$|1|$\infty$|2|1|$\infty$|

(1) IN = {a}
| |a|b|c|d|e|f|
|-|-|-|-|-|-|-|
|d|0|1|3|$\infty$|$\infty$|$\infty$|
|s|-|a|a|a|a|a|

(2) IN = {a, b}
| |a|b|c|d|e|f|
|-|-|-|-|-|-|-|
|d|0|1|2|$\infty$|$\infty$|2|
|s|-|a|b|a|a|b|

(3) IN = {a, b, c}
| |a|b|c|d|e|f|
|-|-|-|-|-|-|-|
|d|0|1|2|4|6|2|
|s|-|a|b|c|c|b|

(4) IN = {a, b, c, f}
| |a|b|c|d|e|f|
|-|-|-|-|-|-|-|
|d|0|1|2|4|3|2|
|s|-|a|b|c|f|b|

(5) IN = {a, b, c, f, e}
| |a|b|c|d|e|f|
|-|-|-|-|-|-|-|
|d|0|1|2|4|3|2|
|s|-|a|b|c|f|b|

(6) IN = {a, b, c, f, e, d}
| |a|b|c|d|e|f|
|-|-|-|-|-|-|-|
|d|0|1|2|4|3|2|
|s|-|a|b|c|f|b|

d and s are unchanged.

End of optimization. 
I have also constructed a program for this. The program is written in c++.
The program was run with the source node as node a. The destination is user-determined.
Full output
![Full output](./images/full1.png)

## Question 2
Given the graph, the following matrix was fed to the Dijkstra's algorithm:
||0|1|2|3|
|-|-|-|-|-|
|0|$\infty$|5|$\infty$|2|
|1|3|$\infty$|3|-4|
|2|$\infty$|$\infty$|$\infty$|4|
|3|-1|$\infty$|-2|$\infty$|

(1) IN = {0}
| |0|1|2|3|
|-|-|-|-|-|
|d|0|5|$\infty$|2|
|s|-|0|0|0|

(2) IN = {0, 3}
| |0|1|2|3|
|-|-|-|-|-|
|d|0|5|0|2|
|s|-|0|3|0|

(3) IN = {0, 3, 2}
| |0|1|2|3|
|-|-|-|-|-|
|d|0|5|0|2|
|s|-|0|3|0|

(4) IN = {0, 3, 2, 1}
| |0|1|2|3|
|-|-|-|-|-|
|d|0|5|0|2|
|s|-|0|3|0|

End of optimization.

(2)The algorithm gives the shortest path from 0 to 3 is 0-1-3, with path length 1. node 3 is the first node into IN. As Node 1 is into IN later, but the distance for 3 was not re-evaluated. A similar situation happens to the path from 0 to 2. The Dijkstra's algorithm fails when there are negative weights, because with negative.

5. Huffman tree problem
![](./images/HuffmanTree.png)

7. Counter Example:
| Task i | s(i) | f(i) |
|--------|------|------|
|1|1|7|
|2|6|9|
|3|8|12|

A = {2} rejecting task 1 and task 3
However, the optional solution is A={1, 3}