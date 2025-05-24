
#include "binary_tree.h"
#include "operation_expression.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// convert an expression to a binary tree
binary_tree_t* expr_to_binary_tree(char* expr) {
	binary_tree_t* bt = new_binary_tree(char_print);
	bt->root = make_node(expr, 0, strlen(expr)-1);
	return bt;
}

//expression rules:
// 1. it only contains characters a-z, +, -, *, /, (, ) and no spaces
// 2. characters a-z are operands and only one character long
// 3. parentheses must be matched
// 4. operator '*' cannot be omitted
node_t* make_node(char* expr, int begin, int end) {
	int p = begin, q, r = end;
	node_t *n, *nl, *nr; // n->left, n->right
	
	// if expr is one character, it must be an operand.
	if(p == r) { return new_char_node(expr[p]); }

	// if expr starts with a parenthesis, find the matching parenthesis
	if(expr[p] == '(') {
		q = p;
		int p_cnt = 1;
		do {
			q += 1;
			if(expr[q] == '(') { p_cnt++; }
			if(expr[q] == ')') { p_cnt--; }
		} while(p_cnt > 0);
		
		//if expr is surrounded by parentheses, remove them
		if(q == r) {
			return make_node(expr, p+1, r-1);
		// the first part of expr enclosed by parentheses becomes the left child
		// and the rest becomes the right child
		} else {
			n = new_char_node(expr[q+1]);
			nl = make_node(expr, p+1, q-1);
			nr = make_node(expr, q+2, r);
			n->left = nl;
			n->right = nr;
			// if operator of n is * or / and the operator of nr is + or -, and nr is not an operand,
			// n is rotated left, which means that operation priority is changed
			if(ismuldiv(expr[q+1]) && (!isalpha(((char*)nr->element)[0]) || isplsub(((char*)nr->element)[0]))) {
				left_rotate(n);
				return nr;
			} else {
				return n;
			}
		}
	//if expr starts with a operand,
	} else if(isalpha(expr[p])) {
		// that single character becomes nl and the rest of expr becomes nr
		n = new_char_node(expr[p+1]);
		nl = make_node(expr, p, p);
		nr = make_node(expr, p+2, r);
		n->left = nl;
		n->right = nr;
		// this part is same as above
		if(ismuldiv(expr[p+1]) && (!isalpha(((char*)nr->element)[0]) || isplsub(((char*)nr->element)[0]))) {
			left_rotate(n);
			return nr;
		} else {
			return n;
		}
	}

}

node_t* new_char_node(char c) {
	char* s = (char*)malloc(sizeof(char*));
	*s = c;
	return new_node(s);
}

int ismuldiv(char c) {
	if(c == '/' || c == '*') {
		return 1;
	} else {
		return 0;
	}
}

int isplsub(char c) {
	if(c == '+' || c == '-') {
		return 1;
	} else {
		return 0;
	}	
}

void char_print(node_t* n) {
    printf("%s", (char*)n->element);
}