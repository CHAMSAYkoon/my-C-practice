#include<stdio.h>

typedef struct {
	TokenType type;
	char *literal;
	
	char ILLEGAL = "ILEGAL";
	char eof = EOF;

	char IDENT = "IDENT";
	char INT = "INT";

	char ASSIGN = "=";
	char PLUS = "+";
	char MINUS = "-";
	char MULTI = "*";
	char DIVIS = "/";

	char LPAREN = "(";
	char RPAREN = ")";
	char LBRACE = "{";
	char RBRACE = "}";

	char SEMICOLON = ";";

	char FUNCTION = "fn";	
}token;
