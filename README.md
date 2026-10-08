# Campus-Shortest-Route-Finder
A college campus has several locations such as the Main Gate, Library, Computer Department, Laboratory and Auditorium. The locations are connected by roads, and each road has a distance.
Campus Shortest Route Finder – Dijkstra's Algorithm

Project Overview

This project implements a Campus Shortest Route Finder in C using Dijkstra's Algorithm.

A college campus contains several locations such as the Main Gate, Library, Computer Department, Laboratory, and Auditorium. These locations are connected by roads, and each road has a distance.

The program allows the user to:

Enter the campus road network.

Represent the network using an adjacency matrix.

Select a source location.

Find the shortest distance from the selected source to every other location.

Display the shortest path to each destination.

Display the distance from the source to all locations.

Objectives

Represent a weighted graph using an adjacency matrix.

Implement Dijkstra's shortest-path algorithm.

Find the shortest distance from a selected source to all other locations.

Display the shortest path to each destination.

State the time complexity of the implemented solution.

Sample Campus Locations

No.

Location

1

Main Gate

2

Library

3

Computer Department

4

Laboratory

5

Auditorium

Input

The program accepts:

Number of locations.

Location names/numbers.

Distance between connected locations.

Source location.

0 for the diagonal of the adjacency matrix.

A suitable INF value for locations that do not have a direct connection.

All edge weights must be non-negative.

Menu

The program provides the following menu:

Enter Campus Graph

Display Adjacency Matrix

Select Source Location

Find Shortest Distance

Display Shortest Paths

Display Distance from Source to All Locations

Exit

Algorithm Used

The project uses Dijkstra's Algorithm, a greedy shortest-path algorithm for finding the shortest paths from one source vertex to all other vertices in a weighted graph with non-negative edge weights.

Basic Steps

Initialize the distance of the source vertex to 0.

Initialize the distance of all other vertices to INF.

Mark all vertices as unvisited.

Select the unvisited vertex having the minimum distance.

Mark the selected vertex as visited.

Update the distances of its adjacent vertices if a shorter path is found.

Store the predecessor/parent of each updated vertex.

Repeat until all required vertices are processed.

Use the parent array to reconstruct and display the shortest paths.

Graph Representation

The campus road network is represented using an adjacency matrix.

For example:

0     4     INF   9     12
4     0     3     INF   INF
INF   3     0     2     INF
9     INF   2     0     3
12    INF   INF   3     0

Where:

0 represents the distance from a location to itself.

A positive value represents the distance between directly connected locations.

INF represents no direct connection.

Shortest Path Output

For each destination, the program displays:

Destination

Shortest Distance

Shortest Path

Library

4

Main Gate → Library

Computer Department

7

Main Gate → Library → Computer Department

Laboratory

9

Main Gate → ... → Laboratory

Auditorium

12

Main Gate → ... → Auditorium

The actual distances and paths depend on the graph entered by the user.

Path Reconstruction

A parent/predecessor array is maintained while running Dijkstra's algorithm.

When a shorter path to a vertex is found, its parent is updated. After the algorithm finishes, the parent array is used to reconstruct the complete shortest path from the source to the destination.

Time Complexity

The implementation uses an adjacency matrix and repeatedly searches for the unvisited vertex with the minimum distance.

Therefore, the time complexity is:

O(V²)

where V is the number of vertices/locations.

Space Complexity

The adjacency matrix requires:

O(V²)

space.

The distance, visited, and parent arrays require:

O(V)

additional space.

Therefore, the overall space complexity is:

O(V²)

AOA Concepts Covered

Weighted Graph

Greedy Method

Dijkstra's Algorithm

Shortest Path

Adjacency Matrix

Parent/Predecessor Array

Time Complexity

Space Complexity

Implementation Requirements

Language: C

Graph representation: Adjacency Matrix

Algorithm: Dijkstra's Algorithm

Program type: Menu-driven

Edge weights: Non-negative

Path reconstruction: Parent/Predecessor array

How to Run

Save the program with a .c extension.

Compile the program using a C compiler.

Run the executable.

Select Enter Campus Graph.

Enter the campus locations and road distances.

Display the adjacency matrix if required.

Select the source location.

Run Dijkstra's algorithm.

Display the shortest distances and corresponding paths.

Conclusion

The Campus Shortest Route Finder demonstrates how Dijkstra's Algorithm can be used to determine the shortest routes between locations in a campus road network. The project uses an adjacency matrix to represent the weighted graph and a parent array to reconstruct the shortest paths.
