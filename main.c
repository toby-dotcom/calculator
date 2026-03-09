#include <stdio.h>
#include "parser/parser.h"
#include "interpretator/interpreter.h"

int main(){
	char input[256];

	printf("ENTER: ");
	fgets(input, sizeof(input), stdin);

	ASTNode *tree = parse(input);
	double result = eval(tree);

	printf("Result: %.1f\n", result);

	return 0;
}
