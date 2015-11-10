#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
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

	/*typedef struct yy_buffer_state * YY_BUFFER_STATE;*/
void printCurrentSpace();
#line 31 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	char* str;
	char* space;
	int integer;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 60 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define DEFINE 257
#define AS 258
#define BLOCKS 259
#define VALUE_SENTENCE 260
#define SET 261
#define OUT 262
#define FOR 263
#define GO 264
#define BACK 265
#define STRAIGHT 266
#define TILL 267
#define TURN 268
#define LEFT 269
#define RIGHT 270
#define KEEP 271
#define GOING 272
#define SKIP 273
#define KEEPEND 274
#define FOR_CYCLE 275
#define TIMES 276
#define LEFT_SQUARE_BRACKED 277
#define WALK 278
#define RIGHT_SQUARE_BRACKED 279
#define FOREND 280
#define WHEN 281
#define THEN 282
#define WHEND 283
#define START 284
#define STOP 285
#define ON 286
#define REST 287
#define VALUE 288
#define IDENTIFIER 289
#define WHITE_SPACE 290
#define DOTCOMA 291
#define OPERATOR 292
#define LEFT_BLOCK_BRACKED 293
#define RIGHT_BLOCK_BRACKED 294
#define EQUAL 295
#define NOT_EQUAL 296
#define HIGH 297
#define LESS 298
#define EQUAL_HIGH 299
#define EQUAL_LESS 300
#define PRINT 301
#define EMPTY 302
#define END 0
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    3,    3,    3,    7,    3,    9,    3,
   11,    4,   13,    4,   15,    4,   17,    4,   18,    4,
   20,    4,   22,    4,   24,    4,   10,   26,   27,   10,
   28,   29,   31,   12,   14,   33,   14,   16,   34,   19,
   35,   36,   21,   23,   38,   40,   41,   42,    8,   43,
   44,   45,   46,   47,   49,    6,   50,   48,   39,   39,
   37,   51,   51,   51,   51,   51,   51,    5,    5,   30,
    1,   52,    1,    2,    2,   25,   25,   32,   32,
};
static const short yylen[] = {                            2,
    1,    2,    1,    1,    2,    2,    0,    3,    0,    3,
    0,    3,    0,    3,    0,    3,    0,    3,    0,    3,
    0,    3,    0,    3,    0,    3,    2,    0,    0,    7,
    0,    0,    0,    9,    2,    0,    3,    1,    0,    4,
    0,    0,    6,    1,    0,    0,    0,    0,   11,    0,
    0,    0,    0,    0,    0,   17,    0,    3,    1,    0,
    3,    1,    1,    1,    1,    1,    1,    1,    2,    1,
    1,    0,    4,    1,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
   68,   23,   13,   11,   15,    7,    9,   17,   19,   21,
   25,    3,    0,    0,    4,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    2,   69,    6,    5,
   70,   24,    0,   75,   74,    0,    0,   14,   77,   76,
   12,    0,   78,   79,   36,   16,    0,    0,    8,    0,
   10,    0,   38,   18,   20,   39,   22,   44,   26,   41,
   31,   72,   28,   27,    0,   35,   50,   62,   63,   64,
   65,   66,   67,    0,   45,    0,    0,    0,    0,    0,
   37,    0,   61,    0,    0,   42,   32,   73,    0,   51,
   46,   40,    0,    0,   29,    0,    0,   43,   33,    0,
   52,   59,    0,    0,   30,    0,   47,    0,    0,    0,
   34,    0,   48,   53,    0,    0,   49,   54,    0,    0,
   55,    0,   57,   56,    0,   58,
};
static const short yydgoto[] = {                        102,
   36,   37,   14,   15,   16,   49,   21,   51,   22,   41,
   19,   38,   18,   46,   20,   54,   23,   24,   57,   25,
   32,   17,   59,   26,   42,   80,  100,   78,   94,   33,
  104,   47,   65,   76,   77,   93,   52,   84,  103,   97,
  110,  115,   82,   96,  106,  116,  119,  124,  122,  125,
   74,   79,
};
static const short yysindex[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    1,    0,    6, -271, -268, -239, -261,
 -268, -268, -263, -263, -240, -268,    0,    0,    0,    0,
    0,    0, -228,    0,    0, -230, -259,    0,    0,    0,
    0, -262,    0,    0,    0,    0, -256, -242,    0, -284,
    0, -246,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -254,    0,    0,    0,    0,    0,
    0,    0,    0, -268,    0, -268, -221, -223, -268, -268,
    0, -237,    0, -252, -249,    0,    0,    0, -216,    0,
    0,    0, -247, -218,    0, -232,    1,    0,    0, -244,
    0,    0, -245, -271,    0, -268,    0, -243, -271, -233,
    0, -227,    0,    0, -238, -234,    0,    0,    1, -231,
    0, -229,    0,    0, -235,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -257,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -226,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -226,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                        10,
  -21,  -19,    0,   38,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   36,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -87,
    0,    0,    0,    0,    0,    0,    0,    0,  -57,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
#define YYTABLESIZE 307
static const short yytable[] = {                         48,
   12,    1,   50,   71,   63,   29,   58,   43,   44,   13,
   68,   69,   70,   71,   72,   73,  108,   31,   71,   34,
   35,  112,   56,   27,   45,   39,   40,   53,   64,   60,
   61,   71,   62,   67,   66,   75,   81,   86,   87,   90,
   91,   92,   95,   98,   99,  101,  105,  111,  107,  113,
  123,  114,  117,   30,   83,  126,   85,   88,  118,   55,
   89,  120,  121,    0,    0,    0,    0,   60,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  109,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    1,    2,    0,    0,
    3,   28,    2,    0,    4,    3,    0,    0,    5,    4,
    0,    0,    0,    5,    0,    6,    0,    0,    0,    0,
    0,    7,    0,    0,    8,    9,    0,   10,    0,    8,
    9,    0,   10,    0,    0,    1,    0,    0,    0,    0,
    0,   11,    0,    0,    0,    0,   11,
};
static const short yycheck[] = {                         21,
    0,    0,   22,  261,  267,    0,   26,  269,  270,    0,
  295,  296,  297,  298,  299,  300,  104,  289,  276,  288,
  289,  109,  263,   14,  286,  265,  266,  291,  291,  258,
  261,  289,  292,  276,  291,  282,  291,  259,  262,  277,
  293,  291,  259,  291,  263,  278,  291,  291,  294,  283,
  280,  279,  291,   16,   74,  291,   76,   79,  293,   24,
   80,  119,  294,   -1,   -1,   -1,   -1,  294,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  106,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,   -1,   -1,
  260,  256,  257,   -1,  264,  260,   -1,   -1,  268,  264,
   -1,   -1,   -1,  268,   -1,  275,   -1,   -1,   -1,   -1,
   -1,  281,   -1,   -1,  284,  285,   -1,  287,   -1,  284,
  285,   -1,  287,   -1,   -1,  294,   -1,   -1,   -1,   -1,
   -1,  301,   -1,   -1,   -1,   -1,  301,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 303
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"DEFINE","AS","BLOCKS",
"VALUE_SENTENCE","SET","OUT","FOR","GO","BACK","STRAIGHT","TILL","TURN","LEFT",
"RIGHT","KEEP","GOING","SKIP","KEEPEND","FOR_CYCLE","TIMES",
"LEFT_SQUARE_BRACKED","WALK","RIGHT_SQUARE_BRACKED","FOREND","WHEN","THEN",
"WHEND","START","STOP","ON","REST","VALUE","IDENTIFIER","WHITE_SPACE","DOTCOMA",
"OPERATOR","LEFT_BLOCK_BRACKED","RIGHT_BLOCK_BRACKED","EQUAL","NOT_EQUAL",
"HIGH","LESS","EQUAL_HIGH","EQUAL_LESS","PRINT","EMPTY","\"end of file\"",
"illegal-symbol",
};
static const char *yyrule[] = {
"$accept : initial",
"initial : expresion",
"initial : expresion initial",
"initial : END",
"expresion : simple_expresion",
"expresion : errStatement simple_expresion",
"expresion : errStatement END",
"$$1 :",
"expresion : FOR_CYCLE $$1 ForContinue",
"$$2 :",
"expresion : WHEN $$2 WhenContinue",
"$$3 :",
"simple_expresion : GO $$3 GoContinue",
"$$4 :",
"simple_expresion : VALUE_SENTENCE $$4 ValueContinue",
"$$5 :",
"simple_expresion : TURN $$5 TurnTurnOnContinue",
"$$6 :",
"simple_expresion : START $$6 StartStopContinue",
"$$7 :",
"simple_expresion : STOP $$7 StartStopContinue",
"$$8 :",
"simple_expresion : REST $$8 RestForContinue",
"$$9 :",
"simple_expresion : DEFINE $$9 DefineContinue",
"$$10 :",
"simple_expresion : PRINT $$10 PrintContinue",
"GoContinue : Ydirection DOTCOMA",
"$$11 :",
"$$12 :",
"GoContinue : Ydirection TILL $$11 aValue BLOCKS $$12 DOTCOMA",
"$$13 :",
"$$14 :",
"$$15 :",
"ValueContinue : mathematicExpresion SET $$13 OUT $$14 FOR $$15 identif DOTCOMA",
"TurnTurnOnContinue : turndirection DOTCOMA",
"$$16 :",
"TurnTurnOnContinue : ON $$16 DOTCOMA",
"StartStopContinue : DOTCOMA",
"$$17 :",
"RestForContinue : FOR $$17 aValue DOTCOMA",
"$$18 :",
"$$19 :",
"DefineContinue : identif AS $$18 BLOCKS $$19 DOTCOMA",
"PrintContinue : aValue",
"$$20 :",
"$$21 :",
"$$22 :",
"$$23 :",
"WhenContinue : condition THEN $$20 LEFT_BLOCK_BRACKED $$21 block RIGHT_BLOCK_BRACKED $$22 WHEND $$23 DOTCOMA",
"$$24 :",
"$$25 :",
"$$26 :",
"$$27 :",
"$$28 :",
"$$29 :",
"ForContinue : mathematicExpresion TIMES $$24 LEFT_SQUARE_BRACKED $$25 WALK $$26 mathematicExpresion identif RIGHT_SQUARE_BRACKED $$27 LEFT_BLOCK_BRACKED $$28 block RIGHT_BLOCK_BRACKED $$29 ForContinue2",
"$$30 :",
"ForContinue2 : FOREND $$30 DOTCOMA",
"block : initial",
"block :",
"condition : aValue comparator aValue",
"comparator : EQUAL",
"comparator : NOT_EQUAL",
"comparator : HIGH",
"comparator : LESS",
"comparator : EQUAL_HIGH",
"comparator : EQUAL_LESS",
"errStatement : error",
"errStatement : errStatement error",
"identif : IDENTIFIER",
"mathematicExpresion : aValue",
"$$31 :",
"mathematicExpresion : aValue OPERATOR $$31 mathematicExpresion",
"aValue : IDENTIFIER",
"aValue : VALUE",
"Ydirection : STRAIGHT",
"Ydirection : BACK",
"turndirection : LEFT",
"turndirection : RIGHT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 267 "parser.y"

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

#line 538 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 100 "parser.y"
	{return 0;}
break;
case 6:
#line 106 "parser.y"
	{return 0;}
break;
case 7:
#line 107 "parser.y"
	{printResevedWord("For");}
break;
case 9:
#line 108 "parser.y"
	{printResevedWord("When");}
break;
case 11:
#line 114 "parser.y"
	{printResevedWord("Go");}
break;
case 13:
#line 115 "parser.y"
	{ printResevedWord("Value"); }
break;
case 15:
#line 116 "parser.y"
	{ printResevedWord("Turn"); }
break;
case 17:
#line 117 "parser.y"
	{ printResevedWord("Start"); }
break;
case 19:
#line 118 "parser.y"
	{ printResevedWord("Stop"); }
break;
case 21:
#line 119 "parser.y"
	{printResevedWord("Rest");}
break;
case 23:
#line 120 "parser.y"
	{printResevedWord("Define");}
break;
case 25:
#line 121 "parser.y"
	{printResevedWord("print");}
break;
case 27:
#line 126 "parser.y"
	{printDotComma();}
break;
case 28:
#line 127 "parser.y"
	{printResevedWord("Till");}
break;
case 29:
#line 127 "parser.y"
	{printResevedWord("Blocks");}
break;
case 30:
#line 128 "parser.y"
	{printDotComma();}
break;
case 31:
#line 133 "parser.y"
	{ printResevedWord("set");}
break;
case 32:
#line 134 "parser.y"
	{printResevedWord("out");}
break;
case 33:
#line 135 "parser.y"
	{printResevedWord("for");}
break;
case 34:
#line 136 "parser.y"
	{printDotComma();}
break;
case 35:
#line 140 "parser.y"
	{printDotComma();}
break;
case 36:
#line 141 "parser.y"
	{printResevedWord("On");}
break;
case 37:
#line 141 "parser.y"
	{printDotComma();}
break;
case 38:
#line 146 "parser.y"
	{printDotComma();}
break;
case 39:
#line 150 "parser.y"
	{printResevedWord("for");}
break;
case 40:
#line 150 "parser.y"
	{printDotComma();}
break;
case 41:
#line 155 "parser.y"
	{printResevedWord("as");}
break;
case 42:
#line 155 "parser.y"
	{printResevedWord("Blocks");}
break;
case 43:
#line 155 "parser.y"
	{printDotComma();}
break;
case 45:
#line 164 "parser.y"
	{printResevedWord("Then");}
break;
case 46:
#line 165 "parser.y"
	{printOperator('{');}
break;
case 47:
#line 167 "parser.y"
	{printOperator('}');}
break;
case 48:
#line 168 "parser.y"
	{printResevedWord("Whend");}
break;
case 49:
#line 168 "parser.y"
	{printDotComma();}
break;
case 50:
#line 175 "parser.y"
	{printResevedWord("Times");}
break;
case 51:
#line 176 "parser.y"
	{printOperator('[');}
break;
case 52:
#line 177 "parser.y"
	{printResevedWord("Walk");}
break;
case 53:
#line 177 "parser.y"
	{printOperator(']');}
break;
case 54:
#line 178 "parser.y"
	{printOperator('{');}
break;
case 55:
#line 180 "parser.y"
	{printOperator('}');}
break;
case 57:
#line 184 "parser.y"
	{printResevedWord("ForEnd");}
break;
case 58:
#line 184 "parser.y"
	{printDotComma();}
break;
case 62:
#line 200 "parser.y"
	{printOperator('=');}
break;
case 63:
#line 201 "parser.y"
	{printOperator('!');printOperator('=');}
break;
case 64:
#line 202 "parser.y"
	{printOperator('>');}
break;
case 65:
#line 203 "parser.y"
	{printOperator('<');}
break;
case 66:
#line 204 "parser.y"
	{printOperator('>');printOperator('=');}
break;
case 67:
#line 205 "parser.y"
	{printOperator('<');printOperator('=');}
break;
case 68:
#line 211 "parser.y"
	{
	yyerrok;
	printError(yytext);
	QVariant word(yylineno);
	ide->ui->errors->append(QString("[Error type 1]: encontrado ").append(yytext).append( " at line ").append(word.toString()).append("\n"));
	fprintf(stderr,"[Error type 1]: encontrado %s at line %ld \n", yytext,yylineno);
	yyclearin;
}
break;
case 69:
#line 220 "parser.y"
	{
	yyerrok;
	QVariant word(yylineno);
	printError(yytext);
	ide->ui->errors->append(QString("[Error type 1]: encontrado ").append(yytext).append( " at line ").append(word.toString()).append("\n"));
	fprintf(stderr,"[Error type n]: encontrado %s at line %ld \n", yytext,yylineno);
	yyclearin;
}
break;
case 70:
#line 237 "parser.y"
	{printIdentifier(yystack.l_mark[0].str);}
break;
case 72:
#line 242 "parser.y"
	{printOperator('+');}
break;
case 74:
#line 247 "parser.y"
	{
		printIdentifier(yystack.l_mark[0].str);
	}
break;
case 75:
#line 251 "parser.y"
	{printNumberValue(yystack.l_mark[0].integer);}
break;
case 76:
#line 256 "parser.y"
	{printDirecction("Straight");}
break;
case 77:
#line 257 "parser.y"
	{printf("in Back\n");printDirecction("Back");}
break;
case 78:
#line 261 "parser.y"
	{printDirecction("Left");}
break;
case 79:
#line 262 "parser.y"
	{printDirecction("Right");}
break;
#line 988 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
