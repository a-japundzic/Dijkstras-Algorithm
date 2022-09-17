#include "dijkstra.h"
#include "graph.h"
#include "cs136-trace.h"
#include <assert.h>

// This module provides Dijkstra's Algorithm
// to find all the shortest paths in a graph from a source vertex

const int NO_PATH = -1;
const int MAX_VERTICES = 1023;

// time: O(n^2)

// see dijkstra.h
void dijkstra(const struct graph *g, int source, int prev_vertex[], 
              int distance[]) {
  int V = graph_get_vertices(g);
  assert(V <= MAX_VERTICES);
  
  assert(1 <= source);
  assert(source <= V);
  
  int current_vertex = NO_PATH;
  int smallest_dist = 0;
  int edge_weight = 0;
  const int dist_len = V;
  
  int visited[1024] = {0}; 
  
  distance[source] = 0;
  
  while (1) {
    for (int i = 1; i <= dist_len; i++) {
      if (visited[i] == 0 && distance[i] != NO_PATH) {
        current_vertex = i;
        smallest_dist = distance[i];
        
        for (int j = i; j <= dist_len; j++) {
          if (visited[j] == 0 && distance[j] < smallest_dist && 
              distance[j] != NO_PATH) {
            current_vertex = j;
            smallest_dist = distance[i];
          }
        }
        
        break;
      }
     
    }
    
    if (current_vertex == NO_PATH) {
      break;
    }
    
    for (int i = 1; i <= dist_len; i++) {
      if (visited[i] == 0 && i != current_vertex) {
        edge_weight = graph_get_edge(g, current_vertex, i);
          
        if (edge_weight != NO_EDGE) {
          edge_weight += distance[current_vertex]; 
          
          if (distance[i] == NO_PATH || edge_weight < distance[i]) {
            distance[i] = edge_weight;
            
            prev_vertex[i] = current_vertex;
          }
        }
      }
    }
    
    visited[current_vertex] = 1;
    current_vertex = NO_PATH;
  }
  
}
