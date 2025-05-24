
#include "binary_tree.h"

#ifndef OPERATION_EXPRESSION_H
#define OPERATION_EXPRESSION_H

binary_tree_t* expr_to_binary_tree(char* expr);
node_t* make_node(char* expr, int begin, int end);

node_t* new_char_node(char c);
int ismuldiv(char c);
int isplsub(char c);
void char_print(node_t* n);


#endif
