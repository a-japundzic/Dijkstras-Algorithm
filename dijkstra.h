// This module provides Dijkstra's Algorithm
// to find all the shortest paths in a graph from a source vertex

#include "graph.h"

extern const int NO_PATH;
extern const int MAX_VERTICES;

// dijkstra(g, source, prev_vertex, distance) modifies the two arrays
//   prev_vertex and distance to store the result of Dijkstra's algorithm
//   on graph g from the source vertex
// notes: V is the number of vertices in graph g
//        distance[0] and prev_vertex[0] are not modified and can be ignored
//        distance[i] is the path distance from source to i or NO_PATH
//         (distance[source] => 0)
//       prev_vertex[i] is vertex prior to i in the path from source to i
//         or NO_PATH if i is unreachable from source or i == source
//         (for example: source -> ... -> prev_vertex[i] -> i)
// requires: V <= MAX_VERTICES
//           1 <= source <= V
//           distance, prev_vertex are valid and length V + 1 [not asserted]
// effects: modifies prev_vertex, distance
void dijkstra(const struct graph *g, int source, int prev_vertex[], 
              int distance[]);