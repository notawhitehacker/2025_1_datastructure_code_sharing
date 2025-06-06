
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph.h"
#include "graph_search.h"

void add_edges(graph_t* g, int v_num) {
	srand(time(NULL));
	for(int i=0 ; i<v_num * 0.8 ; i++) {
		add_edge(g, rand()%v_num, rand()%v_num);
	}
}

int main() {
	int v_num = 50;
	graph_t* g = new_graph(v_num, 0);
	
	add_edges(g, v_num);
	
	initialize_vertex_info(g);
	BFS(g, 12);
	printf("1. BFS\n");
	print_connected_tree(g, 12);

	initialize_vertex_info(g);
	DFS(g, 12);
	printf("2. DFS\n");
	print_connected_tree(g, 12);

	printf("3. connected components\n");
	print_connected_component(g);
}






