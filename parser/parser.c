#include <stdlib.h>
#include <stdio.h>
#include "../lexer/lexer.h"
#include "parser.h"

static Token current_token;

static void advance(void){
	current_token = get_next_token();
}

static ASTNode* new_node(ASTType type, double value, ASTNode *left, ASTNode *right){
	ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));

	node->type = type;
	node->value = value;
	node->left = left;
	node->right = right;

	return node;
}

static ASTNode* parse_expr(void);
static ASTNode* parse_term(void);
static ASTNode* parse_factor(void);

static ASTNode* parse_factor(void){
	ASTNode *node;

	if(current_token.type == TOK_NUMBER){
		node = new_node(AST_NUM, current_token.value, NULL, NULL);
		advance();
		return node;
	}

	if(current_token.type == TOK_LPAREN){
		advance();
		node = parse_expr();
		if(current_token.type != TOK_RPAREN){
			printf("Error: expected ')' \n");
			exit(1);
		}

		advance();
		return node;
	}
	printf("Error: unexpected token\n");
	exit(1);

}

static ASTNode* parse_term(void){
	ASTNode *node = parse_factor();

	while(current_token.type == TOK_MUL || current_token.type == TOK_DIV){
		TokenType op = current_token.type;
		advance();

		if(op == TOK_MUL){
			node = new_node(AST_MUL, 0, node, parse_factor());
		}
		else
			node = new_node(AST_DIV, 0, node, parse_factor());
		
	}
	return node;
}

static ASTNode* parse_expr(void){
	ASTNode *node = parse_term();

	while(current_token.type == TOK_PLUS || current_token.type == TOK_MINUS){
		TokenType op = current_token.type;
		advance();

		if(op == TOK_PLUS)
			node = new_node(AST_ADD, 0, node, parse_term());
		else
			node = new_node(AST_SUB, 0, node, parse_term());
	}

	return node;
}

ASTNode* parse(const char *input){
	cursor = input;
	advance();
	return parse_expr();
}














