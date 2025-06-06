
#ifndef GRAPH_H
#define GRAPH_H

#include "linkedlist.h"

typedef struct vertex_t {
	int key;
	int searched;
	int prev;
	int dist;
	int discovery_time;
	int finish_time;
} vertex_t;

typedef struct graph_t {
	linked_list_t** adj; // edge
	vertex_t** vertices; // vertex
	int directed;
	int vertices_num;
} graph_t;

graph_t* new_graph(int vertices_num, int directed);

void add_edge(graph_t* g, int start, int end);
vertex_t* new_vertex(int key);

int compare(void* n1, void* n2);

#endif





