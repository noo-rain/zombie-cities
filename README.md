# zombie-cities

This project was created for CSCI 2270 Data Structures at University of Colorado Boulder. This program will build a graph from a zombieCitiesInfection.txt file that contains the name of ten cities and the distances between them stored as an adjacency matrix. Once the graph is built, this program will display a menu with the following options:
1. Print vertices
2. Find districts 
3. Find shortest path
4. Find shortest weighted path
5. Zombie Infection!
6. Quit

(1) Print vertices will display the vertices and their adjacent vertices to the user. The vertices all contain a district ID, which will also be displayed. 

(2) Find districts will cause a depth-first search through the graph to find connected cities. Connected cities are connected directly through an edge or indirectly though another vertex. When assigning district IDs, the program will start at one verte and assign it and its connected vertices a district ID. Call print vertices again to verify this. 

(3) The program will first determine if the two cities that the user inputs are connected. If they are in different cities, print "No safe path between cities." If the cities are in the same district, the program will run a breadth first search that returns the number of edges to traverse and the names of the cities along the shortest path. 

(4) To find the shortest weighted path, the program will run Dijkstra's algorithm to find the shortest distance between two cities. 

(5) The adjacency matrix contains an infection parameter that is maintained in the vertex. This is an indicator variable to determine whether a city has been infected by the zombie plague. When the user selects this option, an infection process begins at t=0. For the first time step, any existing cities that are infected will begin infecting their adjacent neighbors. In a single time step, a city may only be infected if one of its neighbors was already infected at the start of that time step. When the user selects this option, this simulation will run and output how many time steps the graph took to allow the zombie infection to run its course.

