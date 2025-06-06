

#include <stdlib.h>

#include "graph.h"
#include "linkedlist.h"


graph_t* new_graph(int vertices_num, int directed) {
	graph_t* g = (graph_t*)malloc(sizeof(graph_t));

	g->adj = (linked_list_t**)malloc(sizeof(linked_list_t*)*vertices_num);
	for(int i=0 ; i<vertices_num ; i++) {
		g->adj[i] = new_linked_list(compare, NULL);
	}

	g->vertices = (vertex_t**)malloc(sizeof(vertex_t*)*vertices_num);
	for(int i=0 ; i<vertices_num ; i++) {
		g->vertices[i] = new_vertex(i);
	}

	g->directed = directed;
	g->vertices_num = vertices_num;

	return g;
}

void add_edge(graph_t* g, int start, int end) {
	if(start == end) { return; }
	node_t* n = new_node(g->vertices[end]);
	if(find_node(g->adj[start], n) == NULL) {
		add_node(g->adj[start], n);
	} else {
		free(n);
	}
	if(!g->directed) {
		g->directed = 1;
		add_edge(g, end, start);
		g->directed = 0;
	}
}

vertex_t* new_vertex(int key) {
	vertex_t* v = (vertex_t*)malloc(sizeof(vertex_t));
	v->key = key;
	v->searched = 0;
	v->prev = -1;
	v->dist = 0xffffffff;
	v->discovery_time = -1;
	v->finish_time = -1;
	return v;
}

int compare(void* n1, void* n2) {
	vertex_t* v1 = (vertex_t*)((node_t*)n1)->element;
	vertex_t* v2 = (vertex_t*)((node_t*)n2)->element;
	if(v1->key == v2->key) { return 1; }
	else return 0;
}



