cmake_minimum_required(VERSION 3.10)
project(datastruct)

set(CMAKE_CXX_STANDARD 11)

add_executable(datastruct main.cpp
        tree/AVL.cpp

        graph/graph_linklist.cpp graph/graph_matrix.cpp graph/GraphBreadthFirstSearch.cpp graph/GraphTopSort.cpp

        heap/Heap.cpp

        sort/InsertSort.cpp sort/MergeSort2.cpp sort/ShellSort.cpp


        graph/graph.h)