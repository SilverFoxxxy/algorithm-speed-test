# algorithm-speed-test
C++ algorithms speed tests

## Tested algorithms
- [DFS][DFS test]
- [Dijkstra's algoritm][Dijkstra's algoritm test]

## DFS test

Testing the DFS algorithm implemented in three ways: in global memory, in classes and by references 
([file with solve](https://github.com/SilverFoxxxy/algorithm-speed-test/blob/checkpoint1/Test%20DFS.cpp)).

| **Тest** | **Global** |  **Class**  | **Reference** |
|:--------:|:----------:|:---------:|:-------------:|
| 1        | 0.597      | 0.608       |  0.618        |
| 2        | 0.592      | 0.594       |  0.616        |
| 3        | 0.594      | 0.607       |  0.621        |
| 4        | 0.597      | 0.608       |  0.639        |
| 5        | 0.597      | 0.603       |  0.637        |
| 6        | 0.607      | 0.61        |  0.628        |
| 7        | 0.601      | 0.608       |  0.633        |
| 8        | 0.599      | 0.603       |  0.622        |
| 9        | 0.6        | 0.605       |  0.621        |
| 10       | 0.609      | 0.618       |  0.625        |
|          | **100%**   | **101.18%** |  **103.23%**  |

### Results
The depth-first search algorithm in classes and using pass-by-reference works slower than DFS in global memory by 1.18% and 3.23%, respectively.

### Conclusion
The time difference is not very large, so you can choose the option that is convenient for you or more suitable in your case.

## Dijkstra's algoritm test

Testing Dijkstra's algorithm implemented in three ways: using a heap, a priority queue and a multiset 
([file with solve](https://github.com/SilverFoxxxy/algorithm-speed-test/blob/checkpoint1/Test%20Dijkstra.cpp)).

| **Тest** | **Heap** | **Priority queue** | **Multiset** |
|:--------:|:--------:|:------------------:|:------------:|
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
|          | **100%** | **107.52%**        |  **113.28%** |

### Results
The Dijkstra's algorithm using a priority queue and multiset works slower than using a heap by 7.52% and 13.28%, respectively.

### Conclusion
Dijkstra's algorithm using a heap is faster, but the solution is very large, unlike using a priority queue or a multiset. So the best option is to use a priority queue if speed is not that important.

## Thanks
[](https://media3.giphy.com/media/3oEdva9BUHPIs2SkGk/200w.gif?cid=6c09b952q75q5lx3yedb4po0kq108iyiy9o0b81unscw5viv&ep=v1_gifs_search&rid=200w.gif&ct=g)
