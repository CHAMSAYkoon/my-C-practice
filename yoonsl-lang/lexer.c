#include<stdio.h>
#include<token.h>
#include<string.h>

typedef struct {
	int position;
	int nextPosition;
	char ch;
}lexer;

void readChar(sourceCode) {
	if (lexer.nextPosition >= strlen(sourceCode)) {
		lexer.ch = "\0";
	} else {
		// <= here
	}
}

void nextToken() {
	FILE = *sourceCode;
	sorceCode = fopen(test.txt, r);

	if (sourceCode == NULL) {
		printf("Can not open source code file\n");
	} else {
		
	}
}
