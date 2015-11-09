%option yylineno
%option noyywrap

%{

#include "y.tab.h"
#include <string.h> 
//extern long line_counter;
char * identifierstr = 0;

#define yyterminate() return END

%}
Define Define
as as
Blocks Blocks

Value Value
set set
out out
for for

Go Go

Back Back
Straight Straight

Till Till

Turn Turn

Left Left
Right Right


Keep Keep
going going
Skip Skip
Keepend Keepend


For For

Times Times

LeftSquareBracked \[

Walk Walk

RightSquareBracked \]

ForEnd ForEnd


When When

Then Then

Whend Whend

Start Start

Stop Stop

On On

Rest Rest

Print print

numericValue (0|[1-9][0-9]*)
value	{numericValue}

identifierAux [A-Za-z_]
identifier {identifierAux}[A-Za-z_0-9]*

whitespace (\ |\t|\r|\n)+
end	\;
operator \-|\+
equal \=
notEqual !\=
high \>
less \<
equalHigh \>\=
equalLess \<\=

LeftBlockBracked \{
RightBlockBracked \}


%%

{end}		{
		return DOTCOMA;
		}



{Define} {return DEFINE;}
{as} {return AS;}
{Blocks} {return BLOCKS;}

{Value} {return VALUE_SENTENCE;}
{set} {return SET;}
{out} {return OUT;}
{for} {return FOR;}

{Go} {return GO;}
{Back} {yylval.str = strdup(yytext);return BACK;}
{Straight} {yylval.str = strdup(yytext);return STRAIGHT;}
{Till} {return TILL;}
{Turn} {return TURN;}
{Left} {return LEFT;}
{Right} {return RIGHT;}

{Keep} {return KEEP;}
{going} {return GOING;}
{Skip} {return SKIP;}
{Keepend} {return KEEPEND;}
{For} {return FOR_CYCLE;}
{Times} {return TIMES;}
{LeftSquareBracked} {return LEFT_SQUARE_BRACKED;}
{Walk} {return WALK;}
{RightSquareBracked} {return RIGHT_SQUARE_BRACKED;}
{ForEnd} {return FOREND;}


{When} {return WHEN;}
{Then} {return THEN;}
{Whend} {return WHEND;}
{Start} {return START;}
{Stop} {return STOP;}
{On} {return ON;}
{Rest} {return REST;}
{value} {
	yylval.integer=atoi(yytext);
	return VALUE;}
{Print} {return PRINT;}

{identifier} {
	free( identifierstr);
	identifierstr = (char*)malloc(sizeof(char)*yyleng + sizeof(char));
	memcpy(identifierstr, yytext, yyleng);
	identifierstr[sizeof(char)*yyleng] = '\0';
	yylval.str = identifierstr;
	return IDENTIFIER;}

{whitespace} {
	/**
	int current = 0;
	while(current < yyleng){
	if (yytext[current] == '\n' | yytext[current++] == '\r')line_counter++;
	}
	*/
	if (strcmp(yytext,"") == 0){identifierstr = (char*)malloc(sizeof(char)*yyleng + sizeof(char));yylval.space = identifierstr;return WHITE_SPACE;}
	free( identifierstr);
	identifierstr = (char*)malloc(sizeof(char)*yyleng + sizeof(char));
	memcpy(identifierstr, yytext, yyleng);
	identifierstr[sizeof(char)*yyleng] = '\0';
	spaces.push_back(identifierstr);
	identifierstr = 0;
	yylval.space = identifierstr;
	printCurrentSpace();
}


{operator} {return OPERATOR;}
{LeftBlockBracked} {return LEFT_BLOCK_BRACKED;}
{RightBlockBracked} {return RIGHT_BLOCK_BRACKED;}

{equal} {return EQUAL;}
{notEqual} {return NOT_EQUAL;}
{high} {return HIGH;}
{less} {return LESS;}
{equalHigh} {return EQUAL_HIGH;}
{equalLess} {return EQUAL_LESS;}


%%

//int yywrap() { return 1;}
