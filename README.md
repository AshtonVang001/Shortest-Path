# shortest-path
Project for CSCI115
Shortest path given maps that contain different tiles, road, plain, forest mountain
Scan in text file, create adjacency matrix based on map, find shortest path given a start and end point
File List:
    dataStructures: folder //contains all the custom made data structures we will be using
        array: folder //this contains a class for a 2d array that will be used for the maps and andjacency matrix
            array.h
            array.cpp
        graph: folder //adjacency matrix that conatins functions to create a matrix based on the map and shortest path algorithm
            graph.h
            graph.cpp
        priorityQ: folder //for shortest path alg
            priorityQ.h
            priorityQ.cpp
        mapStuff: folder //contain everything related to maps that isn't part of a class
            mapFuncs: folder
                mapRead.cpp //function to read in text file and make corresponding 2d matrx
                printMap.cpp //function to print the map from the 2d array with colors and also to print shortest path
            maps: folder //holds text files of maps
                map1.txt
                map2.txt
                map3.txt
                map4.txt
                map5.txt
        main.cpp
        README.md
        