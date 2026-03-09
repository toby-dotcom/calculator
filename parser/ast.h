#ifndef AST_H
#define AST_H

typedef enum{
	AST_NUM,
	AST_ADD,
	AST_SUB,
	AST_MUL,
	AST_DIV
}ASTType;

typedef struct ASTNode{
	ASTType type;
	double value;

	struct ASTNode *left;
	struct ASTNode *right;
}ASTNode;

#endif
