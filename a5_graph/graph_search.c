
#include <stdlib.h>

#include "graph.h"
#include "graph_search.h"
#include "queue.h"
#include "linkedlist.h"

int dfs_time;
int edge_cnt;
int vertex_cnt;

void BFS(graph_t* g, int start_vertex) {
	vertex_t *v, *u;
	queue_t* q = new_queue(g->vertices_num, NULL);

	v = g->vertices[start_vertex];
	v->searched = 1;
	v->dist = 0;
	enqueue_queue(q, g->vertices[start_vertex]);

	while(!queue_is_empty(q)) {
		u = (vertex_t*)dequeue_queue(q);
		for(node_t* n=g->adj[u->key]->head ; n!=NULL ; n=n->next) {
			v = (vertex_t*)n->element;
			if(!v->searched) {
				v->searched = 1;
				v->dist = u->dist + 1;
				v->prev = u->key;
				enqueue_queue(q, v);
			}
		}
	}
}

void initialize_vertex_info(graph_t* g) {
	vertex_t* v;
	for(int i=0 ; i<g->vertices_num ; i++) {
		v = g->vertices[i];
		v->searched = 0;
		v->prev = -1;
		v->dist = 0xffffffff;
		v->discovery_time = 0;
		v->finish_time = 0;
	}
}

void DFS(graph_t* g, int start_vertex) {
	dfs_time = 0;
	DFS_visit(g, g->vertices[start_vertex]);
}

void DFS_visit(graph_t* g, vertex_t* u) {
	dfs_time++;
	vertex_t* v;
	u->discovery_time = dfs_time;
	u->searched = 1;
	for(node_t* n=g->adj[u->key]->head ; n!=NULL ; n=n->next) {
		v = (vertex_t*)n->element;
		if(!v->searched) {
			v->prev = u->key;
			DFS_visit(g, v);
		}
	}
	dfs_time++;
	u->finish_time = dfs_time;
	u->searched = 1;
}

void print_connected_tree(graph_t* g, int start_vertex) {
	edge_cnt = 0;
	vertex_cnt = 0;
	pct(g, start_vertex);
	printf("edges: %d / vertices: %d\n", edge_cnt, vertex_cnt);
}

void pct(graph_t* g, int start_vertex) {
	node_t* n = g->adj[start_vertex]->head;
	int cnt = 0;
	while(n != NULL) {
		vertex_t* v = (vertex_t*)n->element;
		if(v->prev == start_vertex) {
			cnt++;
			edge_cnt++;
			vertex_cnt++;
			printf("%d - ", start_vertex);
			pct(g, v->key);
		}
		n = n->next;
	}
	if(cnt == 0) {
		vertex_cnt++;
		printf("%d\n", start_vertex);
	}
}

void print_connected_component(graph_t* g) {
	initialize_vertex_info(g);
	for(int i=0 ; i<g->vertices_num ; i++) {
		if(g->vertices[i]->discovery_time == 0) {
			DFS(g, i);
			printf("-> ");
			print_connected_tree(g, i);
		}
	}
}




