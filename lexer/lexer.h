#ifndef LEXER_H
#define LEXER_H

typedef enum{
	TOK_NUMBER,
	TOK_PLUS,
	TOK_MINUS,
	TOK_DIV,
	TOK_MUL,
	TOK_EOF,
	TOK_ERROR,
	TOK_LPAREN,
	TOK_RPAREN
} TokenType;

typedef struct{
	TokenType type;
	double value; 
}Token;

extern const char *cursor;
Token get_next_token(void);

#endif
