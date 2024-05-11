# algorithm-speed-test
C++ algorithms speed tests

## DFS Test

Testing the DFS algorithm implemented in three ways: in global memory, in classes and by references.
([file with solve](https://github.com/SilverFoxxxy/algorithm-speed-test/blob/checkpoint1/Test%20DFS.cpp))

| **Тest** | **Global** | **Class** | **Reference** |
| -------- |:----------:| ---------:| ------------- |
| 1        | 0.597      | 0.608     |  0.618        |
| 2        | 0.592      | 0.594     |  0.616        |
| 3        | 0.594      | 0.607     |  0.621        |
| 4        | 0.597      | 0.608     |  0.639        |
| 5        | 0.597      | 0.603     |  0.637        |
| 6        | 0.607      | 0.61      |  0.628        |
| 7        | 0.601      | 0.608     |  0.633        |
| 8        | 0.599      | 0.603     |  0.622        |
| 9        | 0.6        | 0.605     |  0.621        |
| 10       | 0.609      | 0.618     |  0.625        |

### Measurement data in graph form
![](https://github.com/SilverFoxxxy/algorithm-speed-test/blob/checkpoint1/graphic1.png)

## Dijkstra Test

Testing Dijkstra's algorithm implemented in three ways: using a manual heap, a priority queue and a multiset.
([file with solve](https://github.com/SilverFoxxxy/algorithm-speed-test/blob/checkpoint1/Test%20Dijkstra.cpp))

| **Тest** | **Heap** | **Priority queue** | **Multiset** |
| -------- |:--------:| ------------------:| ------------ |
| 1        | 0.305    | 0.329              |  0.342       |
| 2        | 0.308    | 0.331              |  0.338       |
| 3        | 0.304    | 0.332              |  0.345       |
| 4        | 0.315    | 0.339              |  0.374       |
| 5        | 0.307    | 0.330              |  0.360       |
| 6        | 0.304    | 0.327              |  0.345       |
| 7        | 0.308    | 0.328              |  0.350       |
| 8        | 0.309    | 0.333              |  0.344       |
| 9        | 0.306    | 0.329              |  0.339       |
| 10       | 0.306    | 0.325              |  0.343       |

### Measurement data in graph form
![](https://github.com/SilverFoxxxy/algorithm-speed-test/blob/checkpoint1/graphic2.png)

