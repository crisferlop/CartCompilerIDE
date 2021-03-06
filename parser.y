%{
	#include <stdio.h>
	#include <string.h>
	#include <vector>
	#include "varint.h"
	#include "ide.h"
	#include "stdlib.h"
	#include "qvariant.h"
	#include <QTextBlock>

	int line_counter = 1;
	short err = 0;
	short debug = 0;
	long block = 0;
	std::vector< VarInt * > BlockList;
	IDE *ide = 0;
	int pos = 0;
	QTextCursor cursor;

	QColor reservedWord(35,115,85);
	QColor normalToken(255,255,255);
	QColor directions(85,170,102);
	QColor errorColor(255,85,85);
	QColor identifierColor(18,122,122);
	QColor numberValueColor(18,122,122);

	//typedef struct yy_buffer_state * YY_BUFFER_STATE;
void printCurrentSpace();
%}

%union{
	char* str;
	char* space;
	int integer;
}


%token DEFINE
%token AS
%token BLOCKS
%token VALUE_SENTENCE
%token SET
%token OUT
%token FOR
%token GO
%token <str> BACK
%token <str> STRAIGHT
%token TILL
%token TURN
%token LEFT
%token RIGHT
%token KEEP
%token GOING
%token SKIP
%token KEEPEND
%token FOR_CYCLE
%token TIMES
%token LEFT_SQUARE_BRACKED
%token WALK
%token RIGHT_SQUARE_BRACKED
%token FOREND
%token WHEN
%token THEN
%token WHEND
%token START
%token STOP
%token ON
%token REST
%token <integer> VALUE
%token <str> IDENTIFIER
%token <space> WHITE_SPACE
%token DOTCOMA
%token OPERATOR
%token LEFT_BLOCK_BRACKED
%token RIGHT_BLOCK_BRACKED

%token EQUAL
%token NOT_EQUAL
%token HIGH
%token LESS
%token EQUAL_HIGH
%token EQUAL_LESS
%token PRINT
%token <space>EMPTY;
%token END 0 "end of file"

%type <integer> mathematicExpresion
%type <integer> aValue
%type <str> error


%start initial


%%

initial:
	expresion
	| expresion initial
	| END {return 0;}
;

expresion:
	simple_expresion
	| errStatement simple_expresion
	| errStatement END {return 0;}
	| FOR_CYCLE {printResevedWord("For");} ForContinue
	| WHEN {printResevedWord("When");} WhenContinue
;



simple_expresion:
	GO {printResevedWord("Go");} GoContinue
	| VALUE_SENTENCE { printResevedWord("Value"); } ValueContinue
	| TURN { printResevedWord("Turn"); } TurnTurnOnContinue
	| START { printResevedWord("Start"); } StartStopContinue
	| STOP { printResevedWord("Stop"); } StartStopContinue
	| REST {printResevedWord("Rest");} RestForContinue
	| DEFINE {printResevedWord("Define");} DefineContinue
	| PRINT {printResevedWord("print");} PrintContinue
;


GoContinue:
	Ydirection DOTCOMA {printDotComma();}
	| Ydirection TILL {printResevedWord("Till");} aValue BLOCKS {printResevedWord("Blocks");}
	DOTCOMA {printDotComma();}
;

ValueContinue:
	mathematicExpresion 
	SET { printResevedWord("set");}
	OUT {printResevedWord("out");}
	FOR {printResevedWord("for");}
 	identif DOTCOMA {printDotComma();}
;

TurnTurnOnContinue:
	turndirection DOTCOMA {printDotComma();}
	| ON {printResevedWord("On");} DOTCOMA {printDotComma();}
;


StartStopContinue:
	DOTCOMA {printDotComma();}
;

RestForContinue:
	FOR {printResevedWord("for");} aValue DOTCOMA {printDotComma();}
;


DefineContinue:
	identif  AS {printResevedWord("as");} BLOCKS {printResevedWord("Blocks");} DOTCOMA {printDotComma();}
;

PrintContinue:
	aValue
;


WhenContinue:
	condition THEN {printResevedWord("Then");}
	LEFT_BLOCK_BRACKED {printOperator('{');}
	block
	RIGHT_BLOCK_BRACKED {printOperator('}');}
	WHEND {printResevedWord("Whend");} DOTCOMA {printDotComma();}
;



ForContinue:
	mathematicExpresion
	TIMES {printResevedWord("Times");}
	LEFT_SQUARE_BRACKED {printOperator('[');}
	WALK {printResevedWord("Walk");} mathematicExpresion identif RIGHT_SQUARE_BRACKED {printOperator(']');}
	LEFT_BLOCK_BRACKED {printOperator('{');}
	block
	RIGHT_BLOCK_BRACKED {printOperator('}');}
	ForContinue2
;
ForContinue2:
	FOREND {printResevedWord("ForEnd");} DOTCOMA {printDotComma();} 
;


block:
	initial
	| /***/
;


condition:
    aValue comparator aValue
  ;


comparator:
    EQUAL {printOperator('=');}
    | NOT_EQUAL {printOperator('!');printOperator('=');}
    | HIGH {printOperator('>');}
    | LESS {printOperator('<');}
    | EQUAL_HIGH {printOperator('>');printOperator('=');}
    | EQUAL_LESS {printOperator('<');printOperator('=');}
;


errStatement:
 	error
{
	yyerrok;
	printError(yytext);
	QVariant word(yylineno);
	ide->ui->errors->append(QString("[Error type 1]: encontrado ").append(yytext).append( " at line ").append(word.toString()).append("\n"));
	fprintf(stderr,"[Error type 1]: encontrado %s at line %ld \n", yytext,yylineno);
	yyclearin;
}
	| errStatement error
{
	yyerrok;
	QVariant word(yylineno);
	printError(yytext);
	ide->ui->errors->append(QString("[Error type 1]: encontrado ").append(yytext).append( " at line ").append(word.toString()).append("\n"));
	fprintf(stderr,"[Error type n]: encontrado %s at line %ld \n", yytext,yylineno);
	yyclearin;
} 
;







identif:
IDENTIFIER {printIdentifier($1);}
;

mathematicExpresion:
    aValue
    | aValue OPERATOR {printOperator('+');} mathematicExpresion
;

aValue:
    IDENTIFIER 
	{
		printIdentifier($1);
	}

    | VALUE	{printNumberValue($1);}
    ;


Ydirection:
    STRAIGHT {printDirecction("Straight");}
    | BACK	{printf("in Back\n");printDirecction("Back");}
;

turndirection:
    LEFT	{printDirecction("Left");}
    | RIGHT	{printDirecction("Right");}
;


%%

#include "lex.yy.c"
int test(char *s, IDE * pide){
	pos = 0;
	line_counter= yylineno = 1;
	ide = pide;
	YY_BUFFER_STATE buffer =yy_scan_string(s);
	//yyin = fopen(s,"r");
	int position(ide->ui->langu->textCursor().position());
	//ide->ui->langu->setFocus();
	ide->ui->langu->moveCursor(QTextCursor::End);
	ide->ui->langu->moveCursor(QTextCursor::Start,QTextCursor::KeepAnchor);
	cursor = QTextCursor(ide->ui->langu->textCursor());
	yyparse();
	//QTextCursor cursor(ide->ui->langu->textCursor());
	//ide->ui->langu->moveCursor(QTextCursor::End);
	//cursor.setCharFormat(charFormat);
	//qDebug() << "End: "<<cursor.position() ;
	cursor.setPosition(position);
	ide->ui->langu->setTextCursor(cursor);
	//fclose(yyin);
	return 0;
}


void setFormat(int length, QColor pColor){
	//QTextCursor cursor(ide->ui->langu->textCursor());
	QTextCharFormat charFormat = cursor.charFormat();
        charFormat.setFont(QFont("Ubuntu", 11, QFont::Bold));
        charFormat.setForeground(QBrush(pColor));
	cursor.setCharFormat(charFormat);
	cursor.movePosition(QTextCursor::Right,QTextCursor::KeepAnchor,length);
	//ide->ui->langu->setTextCursor(cursor);
}


void printResevedWord(QString word){
	setFormat(word.length(), reservedWord);
	//ide->ui->langu->moveCursor(yyleng,QTextCursor::KeepAnchor);
	//ide->ui->langu->moveCursor (QTextCursor::End);
	//ide->ui->langu->insertHtml (QString("<font color=\"#237355\"><b>").append(word).append("</b></font>"));
	//ide->ui->langu->moveCursor (QTextCursor::End);
}

void printCurrentSpace(){
	//ide->ui->langu->moveCursor (QTextCursor::End);
	setFormat(yyleng, normalToken);
	//ide->ui->langu->moveCursor (QTextCursor::End);
}

void printNumberValue(int num){
	QVariant word(num);
	//ide->ui->langu->moveCursor (QTextCursor::End);
	setFormat(word.toString().length(), numberValueColor);
	//ide->ui->langu->insertHtml (QString("<font color=\"#B7CE06\">").append(word.toString()).append("</font>"));
	//ide->ui->langu->moveCursor (QTextCursor::End);

}

void printIdentifier(QString id){
	setFormat(id.length(), identifierColor);
	//ide->ui->langu->moveCursor (QTextCursor::End);
	//ide->ui->langu->insertHtml (QString("<font color=\"#55aa66\"><b>").append(id).append("</b></font>"));
	//ide->ui->langu->moveCursor (QTextCursor::End);

}

void printDirecction(QString dir){
	setFormat(dir.length(), directions);	
	//ide->ui->langu->moveCursor (QTextCursor::End);
	//ide->ui->langu->insertHtml (QString("<font color=\"#55aa66\"><b>").append(dir).append("</b></font>"));
	//ide->ui->langu->moveCursor (QTextCursor::End);

}

void printError(QString dir){
	//ide->ui->langu->moveCursor (QTextCursor::End);
	setFormat(dir.length(), errorColor);
	//ide->ui->langu->insertHtml (QString("<font color=\"#FF5555\"><b>").append(dir).append("</b></font>"));
	//ide->ui->langu->moveCursor (QTextCursor::End);

}

void printDotComma(){
	setFormat(1, normalToken);
	//ide->ui->langu->textCursor().setPosition(pos,QTextCursor::KeepAnchor);
	//ide->ui->langu->moveCursor(yyleng,QTextCursor::KeepAnchor);
	//ide->ui->langu->moveCursor (QTextCursor::End);
	//ide->ui->langu->insertHtml (QString("<font color=\"#FFFFFF\"><b>;</b></font>"));
	//ide->ui->langu->moveCursor (QTextCursor::End);
}

void printOperator(char op){
	setFormat(1, normalToken);
	//ide->ui->langu->moveCursor (QTextCursor::End);
	//ide->ui->langu->insertHtml (QString("<font color=\"#FFFFFF\"><b>").append(op).append("</b></font>"));
	//ide->ui->langu->moveCursor (QTextCursor::End);
}
int yyerror(const char* s ) {
	yyerrok;
	//printError(yytext);
	fprintf(stderr,"%s: %s at line %ld\n", s, yytext,line_counter);
    	yyclearin;
	err = 1;
//	return err;
}

