
#include "binary_tree.h"
#include "operation_expression.h"

#include <stdio.h>

int main() {
    char* expr[7];
    expr[0] = "(((a+b)*c)-d)";
    expr[1] = "(a+b)*(c-d)+(e/f)-(g*h)+(i+j-k)/l";
    expr[2] = "((x*y)+(z-a)/b)-(c+d)*(e/f)+g-h";
    expr[3] = "(a+(b*c)-(d/e))+((f+g)*h)-(i/j)+k";
    expr[4] = "((m+n)*(o-p)/q)+(r*s)-(t/u)+v-w+x";
    expr[5] = "(a*b)+(c/d)-(e+f)*(g-h)+(i/j)-k+l";
    expr[6] = "((x+y)*(z-a)+(b/c))-d+e*(f-g)/h+i";

    binary_tree_t* bt[7];
    for(int i=0 ; i<7 ; i++) {
        bt[i] = expr_to_binary_tree(expr[i]);
    }

    for(int i=0 ; i<7 ; i++) {
        printf("----------------------\n");
        printf("%d : %s\n", i, expr[i]);
        printf("inOrder : "); inOrder_traversal(bt[i], bt[i]->root); printf("\n");
        printf("preOrder : "); preOrder_traversal(bt[i], bt[i]->root); printf("\n");
        printf("postOrder : "); postOrder_traversal(bt[i], bt[i]->root); printf("\n");
        printf("levelOrder : "); levelOrder_traversal(bt[i], bt[i]->root); printf("\n");
    }
}
