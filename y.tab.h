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
extern YYSTYPE yylval;
