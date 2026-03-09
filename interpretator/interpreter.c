#include <stdio.h>
#include <stdlib.h>
#include "../parser/ast.h"

double eval(ASTNode *node){
	switch(node->type){
		case AST_NUM:
			return node->value;
		case AST_ADD:
			return eval(node->left) + eval(node->right);
		case AST_SUB:
			return eval(node->left) - eval(node->right);
		case AST_MUL:
			return eval(node->left) * eval(node->right);
		case AST_DIV:{
			double right = eval(node->right);
			if(right == 0){
				printf("error: division to zero\n");
				exit(1);
			}

			return eval(node->left) / right;
		}	
	}

	printf("ERROR: unknown node\n");
	exit(1);
}
