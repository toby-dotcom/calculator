#include <ctype.h>
#include "lexer.h"

const char *cursor;
Token get_next_token(void){
	Token tok;

	while(*cursor == ' '){
		cursor++;
	}
	if(*cursor == '\0'){
		tok.type = TOK_EOF;
		return tok;
	}

	if(isdigit(*cursor)){
		tok.type = TOK_NUMBER;
		double value = 0;

		while(isdigit(*cursor)){
			value = value * 10 + (*cursor - '0');
			cursor++;
		}

		tok.value = value;
		return tok;
	}

	switch(*cursor){
		case '+':
			tok.type = TOK_PLUS;
			cursor++;
			return tok;
		case '-':
			tok.type = TOK_MINUS;
			cursor++;
			return tok;
		case '*':
			tok.type = TOK_MUL;
			cursor++;
			return tok;
		case '/':
			tok.type = TOK_DIV;
			cursor++;
			return tok;
		case '(':
			tok.type = TOK_LPAREN;
			cursor++;
			return tok;
		case ')':
			tok.type = TOK_RPAREN;
			cursor++;
			return tok;
	}

	tok.type = TOK_ERROR;
	return tok;
}
