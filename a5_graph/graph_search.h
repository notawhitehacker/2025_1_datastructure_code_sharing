
#ifndef GRAPH_SEARCH_T
#define GRAPH_SEARCH_T

#include "graph.h"

void BFS(graph_t* g, int start_vertex);
void DFS(graph_t* g, int start_vertex);
void DFS_visit(graph_t* g, vertex_t* u);
void initialize_vertex_info(graph_t* g);
void print_connected_tree(graph_t* g, int start_vertex);
void print_connected_component(graph_t* g);
void pct(graph_t* g, int start_vertex);

#endif



