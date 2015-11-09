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
	int line_counter = 1;
	short err = 0;
	short debug = 0;
	long block = 0;
	std::vector< VarInt * > BlockList;
	std::vector< char * > spaces;
	IDE *ide = 0;
	/*typedef struct yy_buffer_state * YY_BUFFER_STATE;*/
void printCurrentSpace();
#line 20 "parser.y"
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
#line 49 "y.tab.c"

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
   35,   36,   21,   23,   38,   39,   40,   41,    8,   42,
   43,   44,   45,   46,   48,    6,   49,   47,   37,   50,
   50,   50,   50,   50,   50,    5,    5,   30,    1,   51,
    1,    2,    2,   25,   25,   32,   32,
};
static const short yylen[] = {                            2,
    1,    2,    1,    1,    2,    2,    0,    3,    0,    3,
    0,    3,    0,    3,    0,    3,    0,    3,    0,    3,
    0,    3,    0,    3,    0,    3,    2,    0,    0,    7,
    0,    0,    0,    9,    2,    0,    3,    1,    0,    4,
    0,    0,    6,    1,    0,    0,    0,    0,   11,    0,
    0,    0,    0,    0,    0,   17,    0,    3,    3,    1,
    1,    1,    1,    1,    1,    1,    2,    1,    1,    0,
    4,    1,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
   66,   23,   13,   11,   15,    7,    9,   17,   19,   21,
   25,    3,    0,    0,    4,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    2,   67,    6,    5,
   68,   24,    0,   73,   72,    0,    0,   14,   75,   74,
   12,    0,   76,   77,   36,   16,    0,    0,    8,    0,
   10,    0,   38,   18,   20,   39,   22,   44,   26,   41,
   31,   70,   28,   27,    0,   35,   50,   60,   61,   62,
   63,   64,   65,    0,   45,    0,    0,    0,    0,    0,
   37,    0,   59,    0,    0,   42,   32,   71,    0,   51,
   46,   40,    0,    0,   29,    0,    0,   43,   33,    0,
   52,    0,    0,   30,    0,   47,    0,    0,    0,   34,
    0,   48,   53,    0,    0,   49,   54,    0,    0,   55,
    0,   57,   56,    0,   58,
};
static const short yydgoto[] = {                         13,
   36,   37,   14,   15,   16,   49,   21,   51,   22,   41,
   19,   38,   18,   46,   20,   54,   23,   24,   57,   25,
   32,   17,   59,   26,   42,   80,  100,   78,   94,   33,
  103,   47,   65,   76,   77,   93,   52,   84,   97,  109,
  114,   82,   96,  105,  115,  118,  123,  121,  124,   74,
   79,
};
static const short yysindex[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    1,    0, -250, -278, -262, -237, -253,
 -262, -262, -276, -276, -233, -262,    0,    0,    0,    0,
    0,    0, -227,    0,    0, -223, -252,    0,    0,    0,
    0, -255,    0,    0,    0,    0, -249, -232,    0, -275,
    0, -243,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -248,    0,    0,    0,    0,    0,
    0,    0,    0, -262,    0, -262, -214, -216, -262, -262,
    0, -230,    0, -245, -242,    0,    0,    0, -209,    0,
    0,    0, -239, -210,    0, -224,    1,    0,    0, -236,
    0, -238, -278,    0, -262,    0, -231, -278, -225,    0,
 -217,    0,    0, -226, -229,    0,    0,    1, -228,    0,
 -213,    0,    0, -222,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                       -14,
  -18,  -17,    0,   52,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   46,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -95,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 302
static const short yytable[] = {                         27,
   12,    1,   48,   69,   50,   28,    2,  107,   58,    3,
   31,   63,  111,    4,   53,   43,   44,    5,   69,   68,
   69,   70,   71,   72,   73,   34,   35,   39,   40,   56,
   60,   69,   45,    8,    9,   64,   10,   61,   75,   62,
   29,   66,   81,   67,   86,   87,   90,   91,   92,   95,
   11,   98,   99,  101,  104,  106,   83,  112,   85,  110,
   88,  113,   89,  117,  116,  120,  122,   30,  125,   55,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  102,    0,    0,    0,  108,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  119,    0,    0,    0,    0,    0,    0,
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
    3,    0,    0,    0,    4,    0,    0,    0,    5,    0,
    0,    0,    0,    0,    0,    6,    0,    0,    0,    0,
    0,    7,    0,    0,    8,    9,    0,   10,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,
    0,   11,
};
static const short yycheck[] = {                         14,
    0,    0,   21,  261,   22,  256,  257,  103,   26,  260,
  289,  267,  108,  264,  291,  269,  270,  268,  276,  295,
  296,  297,  298,  299,  300,  288,  289,  265,  266,  263,
  258,  289,  286,  284,  285,  291,  287,  261,  282,  292,
  291,  291,  291,  276,  259,  262,  277,  293,  291,  259,
  301,  291,  263,  278,  291,  294,   74,  283,   76,  291,
   79,  279,   80,  293,  291,  294,  280,   16,  291,   24,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   97,   -1,   -1,   -1,  105,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  118,   -1,   -1,   -1,   -1,   -1,   -1,
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
  260,   -1,   -1,   -1,  264,   -1,   -1,   -1,  268,   -1,
   -1,   -1,   -1,   -1,   -1,  275,   -1,   -1,   -1,   -1,
   -1,  281,   -1,   -1,  284,  285,   -1,  287,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  294,   -1,   -1,   -1,   -1,
   -1,  301,
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
"expresion : errStatement DOTCOMA",
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
"WhenContinue : condition THEN $$20 LEFT_BLOCK_BRACKED $$21 initial RIGHT_BLOCK_BRACKED $$22 WHEND $$23 DOTCOMA",
"$$24 :",
"$$25 :",
"$$26 :",
"$$27 :",
"$$28 :",
"$$29 :",
"ForContinue : mathematicExpresion TIMES $$24 LEFT_SQUARE_BRACKED $$25 WALK $$26 mathematicExpresion identif RIGHT_SQUARE_BRACKED $$27 LEFT_BLOCK_BRACKED $$28 initial RIGHT_BLOCK_BRACKED $$29 ForContinue2",
"$$30 :",
"ForContinue2 : FOREND $$30 DOTCOMA",
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
#line 249 "parser.y"

#include "lex.yy.c"
int test(const char *s, IDE * pide){
	line_counter= yylineno = 1;
	printf("Test?\n");
	ide = pide;
	char* ss = (char*)malloc(strlen(s)+1);
	ss[strlen(s)] = '\0';
	strcpy(ss,s);
	printf("file: \n %s\n", ss);
	YY_BUFFER_STATE buffer =yy_scan_string(ss);
	//yyin = fopen(s,"r");
	yyparse();
	//fclose(yyin);
	return 0;
}

void printResevedWord(QString word){
	ide->ui->langu->moveCursor (QTextCursor::End);
	ide->ui->langu->insertHtml (QString("<font color=\"#237355\"><b>").append(word).append("</b></font>"));
	ide->ui->langu->moveCursor (QTextCursor::End);
}

void printCurrentSpace(){
	ide->ui->langu->moveCursor (QTextCursor::End);
	if (spaces.size() > 0){
	ide->ui->langu->insertPlainText(spaces.front());
	free(spaces.front());
	spaces.erase(spaces.begin());
	}
	ide->ui->langu->moveCursor (QTextCursor::End);
}

void printNumberValue(int num){
	QVariant word(num);
	ide->ui->langu->moveCursor (QTextCursor::End);
	ide->ui->langu->insertHtml (QString("<font color=\"#B7CE06\">").append(word.toString()).append("</font>"));
	ide->ui->langu->moveCursor (QTextCursor::End);

}

void printIdentifier(QString id){
	ide->ui->langu->moveCursor (QTextCursor::End);
	ide->ui->langu->insertHtml (QString("<font color=\"#55aa66\"><b>").append(id).append("</b></font>"));
	ide->ui->langu->moveCursor (QTextCursor::End);

}

void printDirecction(QString dir){
	ide->ui->langu->moveCursor (QTextCursor::End);
	ide->ui->langu->insertHtml (QString("<font color=\"#55aa66\"><b>").append(dir).append("</b></font>"));
	ide->ui->langu->moveCursor (QTextCursor::End);

}

void printError(QString dir){
	ide->ui->langu->moveCursor (QTextCursor::End);
	ide->ui->langu->insertHtml (QString("<font color=\"#FF5555\"><b>").append(dir).append("</b></font>"));
	ide->ui->langu->moveCursor (QTextCursor::End);

}

void printDotComma(){
	ide->ui->langu->moveCursor (QTextCursor::End);
	ide->ui->langu->insertHtml (QString("<font color=\"#FFFFFF\"><b>;</b></font>"));
	ide->ui->langu->moveCursor (QTextCursor::End);
}

void printOperator(char op){
	ide->ui->langu->moveCursor (QTextCursor::End);
	ide->ui->langu->insertHtml (QString("<font color=\"#FFFFFF\"><b>").append(op).append("</b></font>"));
	ide->ui->langu->moveCursor (QTextCursor::End);
}
int yyerror(const char* s ) {
	yyerrok;
	//printError(yytext);
	fprintf(stderr,"%s: %s at line %ld\n", s, yytext,line_counter);
    	yyclearin;
	err = 1;
//	return err;
}

#line 500 "y.tab.c"

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
#line 89 "parser.y"
	{return 0;}
break;
case 6:
#line 95 "parser.y"
	{printDotComma();}
break;
case 7:
#line 96 "parser.y"
	{printResevedWord("For");}
break;
case 9:
#line 97 "parser.y"
	{printResevedWord("When");}
break;
case 11:
#line 103 "parser.y"
	{printResevedWord("Go");}
break;
case 13:
#line 104 "parser.y"
	{ printResevedWord("Value"); }
break;
case 15:
#line 105 "parser.y"
	{ printResevedWord("Turn"); }
break;
case 17:
#line 106 "parser.y"
	{ printResevedWord("Start"); }
break;
case 19:
#line 107 "parser.y"
	{ printResevedWord("Stop"); }
break;
case 21:
#line 108 "parser.y"
	{printResevedWord("Rest");}
break;
case 23:
#line 109 "parser.y"
	{printResevedWord("Define");}
break;
case 25:
#line 110 "parser.y"
	{printResevedWord("print");}
break;
case 27:
#line 115 "parser.y"
	{printDotComma();}
break;
case 28:
#line 116 "parser.y"
	{printResevedWord("Till");}
break;
case 29:
#line 116 "parser.y"
	{printResevedWord("Blocks");}
break;
case 30:
#line 117 "parser.y"
	{printDotComma();}
break;
case 31:
#line 122 "parser.y"
	{ printResevedWord("set");}
break;
case 32:
#line 123 "parser.y"
	{printResevedWord("out");}
break;
case 33:
#line 124 "parser.y"
	{printResevedWord("for");}
break;
case 34:
#line 125 "parser.y"
	{printDotComma();}
break;
case 35:
#line 129 "parser.y"
	{printDotComma();}
break;
case 36:
#line 130 "parser.y"
	{printResevedWord("On");}
break;
case 37:
#line 130 "parser.y"
	{printDotComma();}
break;
case 38:
#line 135 "parser.y"
	{printDotComma();}
break;
case 39:
#line 139 "parser.y"
	{printResevedWord("for");}
break;
case 40:
#line 139 "parser.y"
	{printDotComma();}
break;
case 41:
#line 144 "parser.y"
	{printResevedWord("as");}
break;
case 42:
#line 144 "parser.y"
	{printResevedWord("Blocks");}
break;
case 43:
#line 144 "parser.y"
	{printDotComma();}
break;
case 45:
#line 153 "parser.y"
	{printResevedWord("Then");}
break;
case 46:
#line 154 "parser.y"
	{printOperator('{');}
break;
case 47:
#line 156 "parser.y"
	{printOperator('}');}
break;
case 48:
#line 157 "parser.y"
	{printResevedWord("Whend");}
break;
case 49:
#line 157 "parser.y"
	{printDotComma();}
break;
case 50:
#line 163 "parser.y"
	{printResevedWord("Times");}
break;
case 51:
#line 164 "parser.y"
	{printOperator('[');}
break;
case 52:
#line 165 "parser.y"
	{printResevedWord("Walk");}
break;
case 53:
#line 165 "parser.y"
	{printOperator(']');}
break;
case 54:
#line 166 "parser.y"
	{printOperator('{');}
break;
case 55:
#line 168 "parser.y"
	{printOperator('}');}
break;
case 57:
#line 172 "parser.y"
	{printResevedWord("ForEnd");}
break;
case 58:
#line 172 "parser.y"
	{printDotComma();}
break;
case 60:
#line 182 "parser.y"
	{printOperator('=');}
break;
case 61:
#line 183 "parser.y"
	{printOperator('!');printOperator('=');}
break;
case 62:
#line 184 "parser.y"
	{printOperator('>');}
break;
case 63:
#line 185 "parser.y"
	{printOperator('<');}
break;
case 64:
#line 186 "parser.y"
	{printOperator('>');printOperator('=');}
break;
case 65:
#line 187 "parser.y"
	{printOperator('<');printOperator('=');}
break;
case 66:
#line 193 "parser.y"
	{
	yyerrok;
	printError(yytext);
	QVariant word(yylineno);
	ide->ui->errors->append(QString("[Error type 1]: encontrado ").append(yytext).append( " at line ").append(word.toString()).append("\n"));
	fprintf(stderr,"[Error type 1]: encontrado %s at line %ld \n", yytext,yylineno);
	yyclearin;
}
break;
case 67:
#line 202 "parser.y"
	{
	yyerrok;
	QVariant word(yylineno);
	printError(yytext);
	ide->ui->errors->append(QString("[Error type 1]: encontrado ").append(yytext).append( " at line ").append(word.toString()).append("\n"));
	fprintf(stderr,"[Error type n]: encontrado %s at line %ld \n", yytext,yylineno);
	yyclearin;
}
break;
case 68:
#line 219 "parser.y"
	{printIdentifier(yystack.l_mark[0].str);}
break;
case 70:
#line 224 "parser.y"
	{printOperator('+');}
break;
case 72:
#line 229 "parser.y"
	{
		printIdentifier(yystack.l_mark[0].str);
	}
break;
case 73:
#line 233 "parser.y"
	{printNumberValue(yystack.l_mark[0].integer);}
break;
case 74:
#line 238 "parser.y"
	{printDirecction("Straight");}
break;
case 75:
#line 239 "parser.y"
	{printf("in Back\n");printDirecction("Back");}
break;
case 76:
#line 243 "parser.y"
	{printDirecction("Left");}
break;
case 77:
#line 244 "parser.y"
	{printDirecction("Right");}
break;
#line 950 "y.tab.c"
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
