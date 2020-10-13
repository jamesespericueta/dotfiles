/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 1






/* First part of user declarations.  */
#line 69 "../lexer/theme-parser.y" /* glr.c:240  */

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "theme-parser.h"
ThemeWidget *rofi_theme = NULL;
void yyerror(YYLTYPE *yylloc, const char *what, const char* s);
int yylex (YYSTYPE *, YYLTYPE *);


static int check_in_range ( double index, double low, double high, YYLTYPE *loc )
{
    if ( index > high || index < low ){
        gchar *str = g_strdup_printf("Value out of range: \n\t\tValue: X = %.2lf;\n\t\tRange: %.2lf <= X <= %.2lf.", index, low, high );
        yyerror ( loc, loc->filename, str);
        g_free(str);
        return FALSE;
    }

    return TRUE;
}

static double hue2rgb(double p, double q, double t){
    t += (t<0)?1.0:0.0;
    t -= (t>1)?1.0:0.0;
    if( t < (1/6.0) ) {
         return p + (q - p) * 6 * t;
    }
    if( t < (1/2.0) ) {
         return q;
    }
    if( t < (2/3.0) ) {
        return p + (q - p) * (2/3.0 - t) * 6;
    }
    return p;
}
static ThemeColor hsl_to_rgb ( double h, double s, double l )
{
    ThemeColor colour;
    colour.alpha = 1.0;

    if(s <  0.001 && s > -0.001){
        colour.red = colour.green = colour.blue = l; // achromatic
    }else{

        double q = l < 0.5 ? l * (1 + s) : l + s - l * s;
        double p = 2 * l - q;
        colour.red   = hue2rgb(p, q, h + 1/3.0);
        colour.green = hue2rgb(p, q, h);
        colour.blue  = hue2rgb(p, q, h - 1/3.0);
    }

    return colour;
}
static ThemeColor hwb_to_rgb ( double h, double w, double b)
{
    ThemeColor retv = hsl_to_rgb ( h, 1.0, 0.5);
    retv.red   *= ( 1. - w - b );
    retv.red   += w;
    retv.green *= ( 1. - w - b );
    retv.green += w;
    retv.blue  *= ( 1. - w - b );
    retv.blue += w;
    return retv;
}

#line 122 "lexer/theme-parser.c" /* glr.c:240  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "lexer/theme-parser.h"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;

/* Copy the second part of user declarations.  */

#line 155 "lexer/theme-parser.c" /* glr.c:263  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify clang.  */
# define YYLONGJMP(Env, Val) (longjmp (Env, Val), YYASSERT (0))
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#ifndef YYASSERT
# define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNRULES -- Number of states.  */
#define YYNSTATES  253
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 12
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   327

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   286,   286,   292,   293,   296,   303,   308,   323,   332,
     341,   361,   362,   366,   383,   389,   402,   415,   431,   432,
     436,   438,   442,   461,   462,   466,   470,   477,   481,   486,
     494,   497,   501,   505,   509,   513,   517,   521,   525,   529,
     533,   537,   541,   546,   550,   554,   558,   566,   567,   571,
     572,   583,   584,   585,   586,   587,   590,   591,   594,   595,
     603,   604,   608,   609,   610,   611,   612,   613,   618,   626,
     631,   639,   647,   655,   669,   675,   681,   687,   694,   700,
     706,   713,   722,   730,   741,   742,   743,   744,   745,   752,
     753,   754,   762,   772,   782,   789,   796,   802,   808,   816,
     824,   830,   836,   839,   843,   849,   850,   853,   854,   857,
     858,   859,   860,   861,   865,   866,   870,   871,   875,   876,
     881,   885,   886,   889,   895,   896,   897
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"error from file parser\"",
  "\"invalid property value\"", "\"invalid property name\"",
  "\"invalid element name\"", "\"invalid defaults name\"",
  "\"invalid import value\"",
  "\"invalid argb color. Requires 8 (not 7) elements: argb:AARRGGBB.\"",
  "\"Integer number\"", "\"Floating-point number\"",
  "\"UTF-8 encoded string\"", "\"Character\"", "\"property name\"",
  "\"Color value by name\"", "\"Element name\"",
  "\"Boolean value (true or false)\"", "\"Hexidecimal color value\"",
  "\"Reference\"", "\"Name of element\"", "\"Center\"", "\"East\"",
  "\"West\"", "\"North\"", "\"South\"", "\"@media\"", "\"None\"",
  "\"Bold\"", "\"Italic\"", "\"Underline\"", "\"Strikethrough\"",
  "\"Small CAPS\"", "\"Dash\"", "\"Solid\"", "\"pixels\"", "\"mm\"",
  "\"em\"", "\"ch\"", "\"%\"", "\"Degrees\"", "\"Gradians\"",
  "\"Radians\"", "\"Turns\"", "\"Horizontal\"", "\"Vertical\"",
  "\"rgb[a] colorscheme\"", "\"hsl colorscheme\"", "\"hwb colorscheme\"",
  "\"cmyk colorscheme\"", "\"Parent left ('(')\"",
  "\"Parent right (')')\"", "\"comma separator (',')\"",
  "\"Optional comma separator (',')\"", "\"forward slash ('/')\"",
  "\"Percent sign ('%')\"", "\"List open ('[')\"", "\"List close (']')\"",
  "\"Add ('+')\"", "\"Subtract ('-')\"", "\"Multiply ('*')\"", "\"calc\"",
  "\"bracket open ('{')\"", "\"bracket close ('}')\"",
  "\"property separator (':')\"", "\"property close (';')\"",
  "\"Name separator (' ' or '.')\"", "\"Selector separator (',')\"",
  "\"Element section ('# {name} { ... }')\"", "\"White space\"",
  "\"Default settings section ( '* { ... }')\"", "\"Configuration block\"",
  "\"Transparent\"", "\"Inherit\"", "\"Width\"", "\"Height\"", "\"Min\"",
  "\"Monitor-ID\"", "\"Max\"", "\"-\"", "$accept", "t_main",
  "t_configuration_list", "t_entry_list", "t_media_entry_list",
  "t_name_prefix_optional", "t_entry", "t_config_property_list_optional",
  "t_config_property_list", "t_config_property",
  "t_property_list_optional", "t_property_list", "t_property",
  "t_property_element", "t_property_element_list_optional",
  "t_property_element_list", "t_property_position",
  "t_property_position_ew", "t_property_position_sn",
  "t_property_highlight_styles", "t_property_highlight_style",
  "t_property_distance_zero", "t_property_distance_unit",
  "t_property_distance_unit_math", "t_property_distance_unit_math2",
  "t_property_distance", "t_property_unit", "t_property_line_style",
  "t_property_color", "t_property_color_opt_alpha_c",
  "t_property_color_opt_alpha_ws", "t_property_color_value_angle",
  "t_property_color_value_unit", "t_property_color_value",
  "t_property_orientation", "t_property_name",
  "t_entry_name_path_selectors", "t_entry_name_path", YY_NULLPTR
};
#endif

#define YYPACT_NINF -199
#define YYTABLE_NINF -38

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const short int yypact[] =
{
    -199,    29,   -32,  -199,   -10,    -3,    47,    23,  -199,    15,
      48,  -199,  -199,    27,    47,  -199,  -199,    55,   121,    47,
    -199,   -48,    49,  -199,  -199,    99,    61,    74,    47,  -199,
      47,    48,   134,   187,    44,  -199,  -199,    85,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,   104,   118,   129,   135,   172,   180,
     160,  -199,  -199,   154,  -199,   111,   130,   219,  -199,    10,
      -2,  -199,  -199,   156,  -199,  -199,   176,    49,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,   148,  -199,   148,   207,
    -199,   216,   207,   207,   207,   192,  -199,   196,   189,    22,
    -199,  -199,  -199,  -199,  -199,    58,    44,    10,  -199,    18,
     203,  -199,  -199,  -199,  -199,  -199,  -199,   200,     2,   204,
      14,   147,    16,    24,   193,   184,  -199,   240,    51,    44,
      22,  -199,   123,    83,    10,   210,   201,   202,  -199,   252,
     259,    26,   207,   207,  -199,  -199,  -199,  -199,   207,   207,
     207,   207,  -199,   220,  -199,  -199,  -199,   100,    22,    22,
      22,   148,    22,    22,  -199,   208,   -28,   -28,    85,   221,
     207,   217,   222,    85,   223,    85,   224,   207,   212,  -199,
    -199,  -199,  -199,  -199,   123,   123,   -28,   218,    93,    48,
      94,   227,   269,   226,   207,   207,   231,   207,   232,   207,
      85,  -199,   106,    47,  -199,   225,    48,   103,  -199,  -199,
     233,   234,   229,   233,  -199,   233,  -199,   236,   238,  -199,
     230,    47,   113,    47,   207,   239,   207,    85,   241,   243,
     207,  -199,  -199,   235,    47,   237,  -199,  -199,   242,   244,
    -199,  -199,   233,  -199,   245,  -199,   233,  -199,   248,  -199,
     250,  -199,  -199
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const unsigned char yydefact[] =
{
       3,     0,     5,     1,     0,     2,    18,     0,    11,     0,
       0,     6,   120,     0,    19,    20,    22,     0,     0,    23,
     124,     0,   121,     4,    21,     0,     0,     0,    24,    25,
      23,   123,   126,    89,    32,    33,    34,   107,    36,   102,
      35,    51,    56,    57,    58,    59,    62,    63,    66,    64,
      65,    67,   118,   119,     0,     0,     0,     0,     0,    47,
       0,   103,    30,     0,    41,    52,    53,    43,    60,     0,
      69,    44,    46,     0,    14,    26,     0,   122,   125,    91,
      90,    84,    85,    86,    87,    88,    89,    68,    89,     0,
     104,     0,     0,     0,     0,     0,    49,     0,    48,     0,
      27,    54,    55,    61,    42,    89,     0,    38,    69,     0,
       0,    13,    81,    82,   117,   116,   108,   115,   117,     0,
       0,   109,     0,     0,     0,     0,    45,     0,    71,     0,
       0,    77,    80,     0,    39,     0,     0,     0,   114,     0,
       0,     0,     0,     0,   110,   112,   111,   113,     0,     0,
       0,     0,    28,     0,    50,    70,    72,     0,     0,     0,
       0,    89,     0,     0,    40,     0,    12,    12,   107,     0,
       0,     0,     0,   107,     0,   107,     0,     0,     0,    73,
      75,    76,    74,    83,    78,    79,    12,     0,    12,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,    29,    12,    23,    15,     0,     0,     0,    16,    93,
     105,     0,     0,   105,   100,   105,    97,     0,     0,    17,
       0,    23,     0,    23,     0,     0,     0,   107,     0,     0,
       0,    99,     8,     0,    23,     0,   106,    92,     0,     0,
     101,    96,   105,     9,     0,     7,   105,    95,     0,    10,
       0,    98,    94
};

  /* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -199,  -199,  -199,  -199,  -145,    -4,  -199,  -199,  -199,   282,
     -30,  -199,    32,   177,  -199,  -199,  -199,   246,   249,  -199,
     251,   -60,   -58,    73,   173,   -21,   -31,   -78,   253,  -198,
    -157,   211,   -92,   -86,  -199,  -199,  -144,   274
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,     1,     2,     5,   188,   189,    11,    13,    14,    15,
      27,    28,    29,    63,    97,    98,    64,    65,    66,    67,
      68,    69,   131,   132,   133,   108,    86,    87,    71,   225,
      90,   120,   116,   117,    72,    17,    21,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const short int yytable[] =
{
      76,    10,   123,    88,    70,   119,   121,   121,   112,   107,
     113,   191,   139,   -12,    30,   228,   196,   229,   198,    31,
     105,   106,   190,     7,   114,   115,   114,   115,   143,     3,
     149,   151,   128,   129,   114,   115,   114,   115,    16,     4,
       8,   202,   187,   218,   248,   207,    16,   134,   250,   -37,
     172,   173,     6,   135,   140,   171,   174,   175,   176,   177,
      75,    12,   222,   -37,    20,     8,   142,     9,   148,   136,
     239,    60,   130,    18,   164,    88,   150,    19,   170,    81,
      82,    83,    84,   183,   193,   200,    81,    82,    83,    84,
      23,    79,    80,    81,    82,    83,    84,   155,   156,    85,
     180,   181,   182,   213,    70,   215,    85,   217,   212,    33,
      34,    35,    36,    85,    37,    32,    38,    39,    40,    25,
      41,    42,    43,    44,    45,    73,    46,    47,    48,    49,
      50,    51,   236,    26,   161,    44,    45,    74,   242,    89,
     238,   162,   163,    52,    53,    54,    55,    56,    57,    58,
      78,   179,    42,    43,    91,    59,   204,   208,   162,   163,
      60,     8,     8,   205,   205,   223,   109,   110,    92,   219,
      31,    61,    62,   220,     8,   234,   205,   158,   159,    93,
      31,    79,    80,   160,   206,    94,   206,   144,   145,   146,
     147,   233,    95,   235,    33,    34,    35,    36,   206,    37,
      96,    38,    39,    40,   244,    41,    42,    43,    44,    45,
      99,    46,    47,    48,    49,    50,    51,   114,   115,   100,
      79,    80,    81,    82,    83,    84,   118,   115,    52,    53,
      54,    55,    56,    57,    37,   184,   185,    39,   -31,   111,
      59,   127,    85,   124,   125,    60,    46,    47,    48,    49,
      50,    51,   -31,   126,   137,   138,    61,    62,   152,   141,
     154,   165,   168,   166,   167,    54,    55,    56,    57,   169,
     186,   178,   194,   192,   195,   197,   199,   201,   209,   210,
     203,   211,   214,   216,   227,   224,   226,   221,   230,   231,
     237,    61,   240,   232,   241,   247,    24,   246,   243,   251,
     245,   252,   153,   157,   122,    77,     0,     0,   249,     0,
       0,     0,   102,     0,   101,     0,     0,     0,   103,     0,
     104
};

static const short int yycheck[] =
{
      30,     5,    94,    34,    25,    91,    92,    93,    86,    69,
      88,   168,    10,    16,    62,   213,   173,   215,   175,    67,
      10,    11,   167,    26,    10,    11,    10,    11,   120,     0,
     122,   123,    10,    11,    10,    11,    10,    11,     6,    71,
      68,   186,    70,   200,   242,   189,    14,   107,   246,    51,
     142,   143,    62,    35,    52,   141,   148,   149,   150,   151,
      28,    14,   206,    65,    16,    68,    52,    70,    52,    51,
     227,    61,    50,    50,   134,   106,    52,    62,    52,    35,
      36,    37,    38,   161,   170,   177,    35,    36,    37,    38,
      63,    33,    34,    35,    36,    37,    38,   128,   129,    55,
     158,   159,   160,   195,   125,   197,    55,   199,   194,    10,
      11,    12,    13,    55,    15,    66,    17,    18,    19,    64,
      21,    22,    23,    24,    25,    64,    27,    28,    29,    30,
      31,    32,   224,    12,    51,    24,    25,    63,   230,    54,
     226,    58,    59,    44,    45,    46,    47,    48,    49,    50,
      16,    51,    22,    23,    50,    56,    63,    63,    58,    59,
      61,    68,    68,    70,    70,    62,    10,    11,    50,    63,
      67,    72,    73,   203,    68,    62,    70,    54,    55,    50,
      67,    33,    34,    60,   188,    50,   190,    40,    41,    42,
      43,   221,    20,   223,    10,    11,    12,    13,   202,    15,
      20,    17,    18,    19,   234,    21,    22,    23,    24,    25,
      50,    27,    28,    29,    30,    31,    32,    10,    11,    65,
      33,    34,    35,    36,    37,    38,    10,    11,    44,    45,
      46,    47,    48,    49,    15,   162,   163,    18,    51,    63,
      56,    52,    55,    51,    52,    61,    27,    28,    29,    30,
      31,    32,    65,    57,    51,    55,    72,    73,    65,    55,
      20,    51,    10,    62,    62,    46,    47,    48,    49,    10,
      62,    51,    55,    52,    52,    52,    52,    65,    51,    10,
      62,    55,    51,    51,    55,    52,    52,    62,    52,    51,
      51,    72,    51,    63,    51,    51,    14,    55,    63,    51,
      63,    51,   125,   130,    93,    31,    -1,    -1,    63,    -1,
      -1,    -1,    66,    -1,    65,    -1,    -1,    -1,    67,    -1,
      67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    81,    82,     0,    71,    83,    62,    26,    68,    70,
      85,    86,    14,    87,    88,    89,    92,   115,    50,    62,
      16,   116,   117,    63,    89,    64,    12,    90,    91,    92,
      62,    67,    66,    10,    11,    12,    13,    15,    17,    18,
      19,    21,    22,    23,    24,    25,    27,    28,    29,    30,
      31,    32,    44,    45,    46,    47,    48,    49,    50,    56,
      61,    72,    73,    93,    96,    97,    98,    99,   100,   101,
     105,   108,   114,    64,    63,    92,    90,   117,    16,    33,
      34,    35,    36,    37,    38,    55,   106,   107,   106,    54,
     110,    50,    50,    50,    50,    20,    20,    94,    95,    50,
      65,    98,    97,   100,   108,    10,    11,   101,   105,    10,
      11,    63,   107,   107,    10,    11,   112,   113,    10,   113,
     111,   113,   111,   112,    51,    52,    57,    52,    10,    11,
      50,   102,   103,   104,   101,    35,    51,    51,    55,    10,
      52,    55,    52,   112,    40,    41,    42,    43,    52,   112,
      52,   112,    65,    93,    20,   106,   106,   104,    54,    55,
      60,    51,    58,    59,   101,    51,    62,    62,    10,    10,
      52,   113,   112,   112,   112,   112,   112,   112,    51,    51,
     102,   102,   102,   107,   103,   103,    62,    70,    84,    85,
      84,   110,    52,   113,    55,    52,   110,    52,   110,    52,
     112,    65,    84,    62,    63,    70,    85,   116,    63,    51,
      10,    55,   113,   112,    51,   112,    51,   112,   110,    63,
      90,    62,   116,    62,    52,   109,    52,    55,   109,   109,
      52,    51,    63,    90,    62,    90,   112,    51,   113,   110,
      51,    51,   112,    63,    90,    63,    55,    51,   109,    63,
     109,    51,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    80,    81,    82,    82,    83,    83,    84,    84,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    87,    87,
      88,    88,    89,    90,    90,    91,    91,    92,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   102,   102,   103,   103,   103,   103,   104,   104,
     104,   105,   105,   105,   106,   106,   106,   106,   106,   107,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   109,   109,   110,   110,   111,
     111,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   116,   116,   116,   117,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     0,     5,     0,     2,     5,     4,     5,
       6,     1,     0,     5,     4,     9,     9,    10,     0,     1,
       1,     2,     1,     0,     1,     1,     2,     4,     6,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     1,     2,     1,     1,     3,     1,     0,     1,     1,
       3,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     2,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     5,     1,     1,     1,     1,     1,     0,
       1,     1,     9,     7,    12,    10,     9,     7,    11,     8,
       7,     9,     1,     1,     2,     0,     2,     0,     2,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     3,     2
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,    71,     0
};

/* Error token number */
#define YYTERROR 1


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)



#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)


static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YYDPRINTF(Args)                        \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
  } while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char *what)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (what);
  if (!yyvaluep)
    return;
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char *what)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, what);
  YYFPRINTF (yyoutput, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YYFPRINTF (stderr, "%s ", Title);                               \
        yy_symbol_print (stderr, Type, Value, Location, what);        \
        YYFPRINTF (stderr, "\n");                                       \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

struct yyGLRStack;
static void yypstack (struct yyGLRStack* yystackp, size_t yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (struct yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static _Noreturn void
yyFail (yyGLRStack* yystackp, YYLTYPE *yylocp, const char *what, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yylocp, what, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static _Noreturn void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp, YYLTYPE *yylocp, const char *what)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = (yystackp->yysplitPoint == YY_NULLPTR);
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yylocp);
  YYUSE (what);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (yylocp, what, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;

  switch (yyn)
    {
        case 2:
#line 286 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    // Dummy at this point.
}
#line 1232 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 3:
#line 292 "../lexer/theme-parser.y" /* glr.c:816  */
    {}
#line 1238 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 4:
#line 293 "../lexer/theme-parser.y" /* glr.c:816  */
    {}
#line 1244 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 5:
#line 296 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        // There is always a base widget.
        if (rofi_theme == NULL ){
            rofi_theme_reset();
            ((*yyvalp).theme) =  rofi_theme;
        }
  }
#line 1256 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 6:
#line 303 "../lexer/theme-parser.y" /* glr.c:816  */
    {
   }
#line 1263 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 7:
#line 308 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ThemeWidget *widget = ((*yyvalp).theme) = g_slice_new0 ( ThemeWidget );
    for ( GList *liter = g_list_first ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.list)); liter; liter = g_list_next ( liter ) ) {
        for ( GList *iter = g_list_first ( (GList*)liter->data ); widget && iter ; iter = g_list_next ( iter ) ) {
            widget = rofi_theme_find_or_create_name ( widget, iter->data );
        }
        g_list_free_full ( (GList*)liter->data, g_free );
        widget->set = TRUE;
        rofi_theme_widget_add_properties ( widget, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list));
    }
    if ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) ) {
        g_hash_table_destroy ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) );
    }
    g_list_free ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.list) );
}
#line 1283 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 8:
#line 323 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ThemeWidget *widget = ((*yyvalp).theme) = g_slice_new0( ThemeWidget ) ;
    widget = rofi_theme_find_or_create_name ( widget, "*" );
    widget->set = TRUE;
    rofi_theme_widget_add_properties ( widget, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list));
    if ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) ) {
        g_hash_table_destroy ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) );
    }
}
#line 1297 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 9:
#line 332 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ThemeWidget *widget = ((*yyvalp).theme) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.theme) ;
    widget = rofi_theme_find_or_create_name ( widget, "*" );
    widget->set = TRUE;
    rofi_theme_widget_add_properties ( widget, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list));
    if ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) ) {
        g_hash_table_destroy ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) );
    }
}
#line 1311 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 10:
#line 341 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ThemeWidget *widget = ((*yyvalp).theme) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.theme) ;
    for ( GList *liter = g_list_first ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.list)); liter; liter = g_list_next ( liter ) ) {
        for ( GList *iter = g_list_first ( (GList*)liter->data ); widget && iter ; iter = g_list_next ( iter ) ) {
            widget = rofi_theme_find_or_create_name ( widget, iter->data );
        }
        g_list_free_full ( (GList*)liter->data, g_free );
        widget->set = TRUE;
        rofi_theme_widget_add_properties ( widget, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list));
    }
    if ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) ) {
        g_hash_table_destroy ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) );
    }
    g_list_free ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.list) );
}
#line 1331 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 11:
#line 361 "../lexer/theme-parser.y" /* glr.c:816  */
    {}
#line 1337 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 12:
#line 362 "../lexer/theme-parser.y" /* glr.c:816  */
    {}
#line 1343 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 13:
#line 367 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    for ( GList *liter = g_list_first ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.list)); liter; liter = g_list_next ( liter ) ) {
        ThemeWidget *widget = rofi_theme;
        for ( GList *iter = g_list_first ( (GList*)liter->data ); widget && iter ; iter = g_list_next ( iter ) ) {
            widget = rofi_theme_find_or_create_name ( widget, iter->data );
        }
        g_list_free_full ( (GList*)liter->data, g_free );
        widget->set = TRUE;
        rofi_theme_widget_add_properties ( widget, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list));
    }
    if ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) ) {
        g_hash_table_destroy ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) );
    }
    g_list_free ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.list) );
}
#line 1363 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 14:
#line 383 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    rofi_theme_widget_add_properties ( rofi_theme, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list));
    if ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) ) {
        g_hash_table_destroy ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) );
    }
}
#line 1374 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 15:
#line 389 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    gchar *name = g_strdup_printf("@media ( %s: %d )",(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval), (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival));
    ThemeWidget *widget = rofi_theme_find_or_create_name ( rofi_theme, name );
    widget->set = TRUE;
    widget->media = g_slice_new0(ThemeMedia);
    widget->media->type = rofi_theme_parse_media_type ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval) );
    widget->media->value = (double)(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival);
    for ( unsigned int i = 0; i < (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->num_widgets;i++) {
        ThemeWidget *d = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->widgets[i];
        rofi_theme_parse_merge_widgets(widget, d);
    }
    g_free ( name );
}
#line 1392 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 16:
#line 402 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    gchar *name = g_strdup_printf("@media ( %s: %f )",(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval), (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval));
    ThemeWidget *widget = rofi_theme_find_or_create_name ( rofi_theme, name );
    widget->set = TRUE;
    widget->media = g_slice_new0(ThemeMedia);
    widget->media->type = rofi_theme_parse_media_type ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval) );
    widget->media->value = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval);
    for ( unsigned int i = 0; i < (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->num_widgets;i++) {
        ThemeWidget *d = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->widgets[i];
        rofi_theme_parse_merge_widgets(widget, d);
    }
    g_free ( name );
}
#line 1410 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 17:
#line 415 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    gchar *name = g_strdup_printf("@media ( %s: %d px )",(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.sval), (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.ival));
    ThemeWidget *widget = rofi_theme_find_or_create_name ( rofi_theme, name );
    widget->set = TRUE;
    widget->media = g_slice_new0(ThemeMedia);
    widget->media->type = rofi_theme_parse_media_type ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.sval) );
    widget->media->value = (double)(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.ival);
    for ( unsigned int i = 0; i < (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->num_widgets;i++) {
        ThemeWidget *d = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->widgets[i];
        rofi_theme_parse_merge_widgets(widget, d);
    }
    g_free ( name );
}
#line 1428 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 18:
#line 431 "../lexer/theme-parser.y" /* glr.c:816  */
    {}
#line 1434 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 20:
#line 436 "../lexer/theme-parser.y" /* glr.c:816  */
    {
}
#line 1441 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 21:
#line 438 "../lexer/theme-parser.y" /* glr.c:816  */
    {
}
#line 1448 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 22:
#line 442 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    char *error = NULL;
    if ( config_parse_set_property ( (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property), &error ) ) {
        // TODO Generate error.
#ifdef FATAL_CONFIG_ERROR
        yyerror ( &((*yylocp)), (*yylocp).filename, error );
#else
        g_warning("%s:%d:%d: %s\n", (*yylocp).filename, (*yylocp).first_line, (*yylocp).first_column, error);
#endif
        g_free(error);
    }
    // We don't keep any reference to this after this point, so the property can be free'ed.
    rofi_theme_property_free ( (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property) );
}
#line 1467 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 23:
#line 461 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).property_list) = NULL; }
#line 1473 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 24:
#line 462 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).property_list) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property_list); }
#line 1479 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 25:
#line 466 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).property_list) = g_hash_table_new_full ( g_str_hash, g_str_equal, NULL, (GDestroyNotify)rofi_theme_property_free );
    g_hash_table_replace ( ((*yyvalp).property_list), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property)->name, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property) );
  }
#line 1488 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 26:
#line 470 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    // Old will be free'ed, and key/value will be replaced.
    g_hash_table_replace ( ((*yyvalp).property_list), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property)->name, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property) );
  }
#line 1497 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 27:
#line 477 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).property) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property);
    ((*yyvalp).property)->name = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.sval);
   }
#line 1506 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 28:
#line 481 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_LINK );
        ((*yyvalp).property)->name = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.sval);
        ((*yyvalp).property)->value.link.name = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.sval);
    }
#line 1516 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 29:
#line 486 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_LINK );
        ((*yyvalp).property)->name = (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.sval);
        ((*yyvalp).property)->value.link.name = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.sval);
        ((*yyvalp).property)->value.link.def_value = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.property);
    }
#line 1527 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 30:
#line 494 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_INHERIT );
    }
#line 1535 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 31:
#line 497 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_INTEGER );
        ((*yyvalp).property)->value.i = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
    }
#line 1544 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 32:
#line 501 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_DOUBLE );
        ((*yyvalp).property)->value.f = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval);
    }
#line 1553 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 33:
#line 505 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_STRING );
        ((*yyvalp).property)->value.s = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval);
    }
#line 1562 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 34:
#line 509 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_CHAR );
        ((*yyvalp).property)->value.c = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.cval);
    }
#line 1571 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 35:
#line 513 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_LINK );
        ((*yyvalp).property)->value.link.name = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval);
    }
#line 1580 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 36:
#line 517 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_BOOLEAN );
        ((*yyvalp).property)->value.b = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.bval);
    }
#line 1589 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 37:
#line 521 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_PADDING );
        ((*yyvalp).property)->value.padding = (RofiPadding){ (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance), rofi_theme_property_copy_distance((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance)), rofi_theme_property_copy_distance((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance)), rofi_theme_property_copy_distance((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance)) };
}
#line 1598 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 38:
#line 525 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_PADDING );
        ((*yyvalp).property)->value.padding = (RofiPadding){ (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance), rofi_theme_property_copy_distance((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance)), rofi_theme_property_copy_distance((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance)) };
}
#line 1607 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 39:
#line 529 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_PADDING );
        ((*yyvalp).property)->value.padding = (RofiPadding){ (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance), (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance), rofi_theme_property_copy_distance((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance)) };
}
#line 1616 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 40:
#line 533 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_PADDING );
        ((*yyvalp).property)->value.padding = (RofiPadding){ (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.distance), (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance), (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance) };
}
#line 1625 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 41:
#line 537 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_POSITION );
        ((*yyvalp).property)->value.i = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.wloc);
}
#line 1634 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 42:
#line 541 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_HIGHLIGHT );
        ((*yyvalp).property)->value.highlight.style = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival)|ROFI_HL_COLOR;
        ((*yyvalp).property)->value.highlight.color = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.colorval);
}
#line 1644 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 43:
#line 546 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_HIGHLIGHT );
        ((*yyvalp).property)->value.highlight.style = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 1653 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 44:
#line 550 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_COLOR );
        ((*yyvalp).property)->value.color = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.colorval);
}
#line 1662 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 45:
#line 554 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_LIST );
        ((*yyvalp).property)->value.list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.list);
}
#line 1671 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 46:
#line 558 "../lexer/theme-parser.y" /* glr.c:816  */
    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_ORIENTATION );
        ((*yyvalp).property)->value.i = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 1680 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 47:
#line 566 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).list) = NULL; }
#line 1686 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 48:
#line 567 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).list) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.list); }
#line 1692 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 49:
#line 571 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).list) = g_list_append ( NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval)); }
#line 1698 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 50:
#line 572 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).list) = g_list_append ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.list), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval) );
}
#line 1706 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 51:
#line 583 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).wloc) =WL_CENTER;}
#line 1712 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 54:
#line 586 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).wloc) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.wloc)|(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.wloc);}
#line 1718 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 55:
#line 587 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).wloc) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.wloc)|(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.wloc);}
#line 1724 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 56:
#line 590 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).wloc) = WL_EAST;}
#line 1730 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 57:
#line 591 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).wloc) = WL_WEST;}
#line 1736 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 58:
#line 594 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).wloc) = WL_NORTH;}
#line 1742 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 59:
#line 595 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).wloc) = WL_SOUTH;}
#line 1748 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 60:
#line 603 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);}
#line 1754 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 61:
#line 604 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival)|(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);}
#line 1760 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 62:
#line 608 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_HL_NONE; }
#line 1766 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 63:
#line 609 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_HL_BOLD; }
#line 1772 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 64:
#line 610 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_HL_UNDERLINE; }
#line 1778 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 65:
#line 611 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_HL_STRIKETHROUGH; }
#line 1784 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 66:
#line 612 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_HL_ITALIC; }
#line 1790 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 67:
#line 613 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_HL_SMALL_CAPS; }
#line 1796 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 68:
#line 618 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance).base.distance = (double) (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance).base.type     = ROFI_PU_PX;
    ((*yyvalp).distance).base.left     = NULL;
    ((*yyvalp).distance).base.right    = NULL;
    ((*yyvalp).distance).base.modtype  = ROFI_DISTANCE_MODIFIER_NONE;
    ((*yyvalp).distance).style    = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 1809 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 69:
#line 626 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).distance) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance);}
#line 1815 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 70:
#line 631 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->distance = (double)(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance_unit)->type     = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance_unit)->left     = NULL;
    ((*yyvalp).distance_unit)->right    = NULL;
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_NONE;
}
#line 1828 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 71:
#line 639 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->distance = (double)(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance_unit)->type     = ROFI_PU_PX;
    ((*yyvalp).distance_unit)->left     = NULL;
    ((*yyvalp).distance_unit)->right    = NULL;
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_NONE;
}
#line 1841 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 72:
#line 647 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->distance = (double)(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).distance_unit)->type     = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance_unit)->left     = NULL;
    ((*yyvalp).distance_unit)->right    = NULL;
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_NONE;
}
#line 1854 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 73:
#line 655 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->distance = 0;
    ((*yyvalp).distance_unit)->type     = ROFI_PU_PX;
    ((*yyvalp).distance_unit)->left     = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right    = 0;
    ((*yyvalp).distance_unit)->modtype  = ROFI_DISTANCE_MODIFIER_GROUP;
}
#line 1867 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 74:
#line 669 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left  = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_MULTIPLY;
}
#line 1878 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 75:
#line 675 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left  = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_DIVIDE;
}
#line 1889 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 76:
#line 681 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left  = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_MODULO;
}
#line 1900 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 77:
#line 687 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance_unit) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
}
#line 1908 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 78:
#line 694 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_ADD;
}
#line 1919 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 79:
#line 700 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_SUBTRACT;
}
#line 1930 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 80:
#line 706 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance_unit) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
}
#line 1938 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 81:
#line 713 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance).base.distance = (double)(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance).base.type     = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance).base.left = NULL;
    ((*yyvalp).distance).base.right = NULL;
    ((*yyvalp).distance).base.modtype = ROFI_DISTANCE_MODIFIER_NONE;
    ((*yyvalp).distance).style    = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 1951 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 82:
#line 722 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance).base.distance = (double)(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).distance).base.type     = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance).base.modtype  = ROFI_DISTANCE_MODIFIER_NONE;
    ((*yyvalp).distance).base.left = NULL;
    ((*yyvalp).distance).base.right = NULL;
    ((*yyvalp).distance).style    = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 1964 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 83:
#line 730 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).distance).base.distance = 0; 
    ((*yyvalp).distance).base.type     = ROFI_PU_PX;
    ((*yyvalp).distance).base.left = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance).base.right = NULL;
    ((*yyvalp).distance).base.modtype  = ROFI_DISTANCE_MODIFIER_GROUP;
    ((*yyvalp).distance).style    = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 1977 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 84:
#line 741 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_PU_PX; }
#line 1983 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 85:
#line 742 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_PU_MM; }
#line 1989 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 86:
#line 743 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_PU_EM; }
#line 1995 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 87:
#line 744 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_PU_CH; }
#line 2001 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 88:
#line 745 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_PU_PERCENT; }
#line 2007 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 89:
#line 752 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_HL_SOLID; }
#line 2013 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 90:
#line 753 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_HL_SOLID; }
#line 2019 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 91:
#line 754 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).ival) = ROFI_HL_DASH;  }
#line 2025 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 92:
#line 762 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    ((*yyvalp).colorval).alpha = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval).red   = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.ival)/255.0;
    ((*yyvalp).colorval).green = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival)/255.0;
    ((*yyvalp).colorval).blue  = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.ival)/255.0;
}
#line 2039 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 93:
#line 772 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    ((*yyvalp).colorval).alpha = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval).red   = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival)/255.0;
    ((*yyvalp).colorval).green = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.ival)/255.0;
    ((*yyvalp).colorval).blue  = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.ival)/255.0;
}
#line 2053 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 94:
#line 782 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    ((*yyvalp).colorval).alpha = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval); ((*yyvalp).colorval).red   = (((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.fval)/100.0; ((*yyvalp).colorval).green = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fval)/100.0; ((*yyvalp).colorval).blue  = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval)/100.0;
}
#line 2064 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 95:
#line 789 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    ((*yyvalp).colorval).alpha = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval); ((*yyvalp).colorval).red   = (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.fval)/100.0; ((*yyvalp).colorval).green = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.fval)/100.0; ((*yyvalp).colorval).blue  = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval)/100.0;
}
#line 2075 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 96:
#line 796 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    double h = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fval), w = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), b = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval) = hwb_to_rgb ( h, w, b );
    ((*yyvalp).colorval).alpha = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
}
#line 2085 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 97:
#line 802 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    double h = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), w = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval), b = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval) = hwb_to_rgb ( h, w, b );
    ((*yyvalp).colorval).alpha = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
}
#line 2095 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 98:
#line 808 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).colorval).alpha = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    double  c= (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval.fval), m= (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fval), y= (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), k= (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval).red   = (1.0-c)*(1.0-k);
    ((*yyvalp).colorval).green = (1.0-m)*(1.0-k);
    ((*yyvalp).colorval).blue  = (1.0-y)*(1.0-k);
}
#line 2107 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 99:
#line 816 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).colorval).alpha = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    double  c= (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.fval), m= (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), y= (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval), k= (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval).red   = (1.0-c)*(1.0-k);
    ((*yyvalp).colorval).green = (1.0-m)*(1.0-k);
    ((*yyvalp).colorval).blue  = (1.0-y)*(1.0-k);
}
#line 2119 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 100:
#line 824 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    double h = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), s = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval), l = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval) = hsl_to_rgb ( h, s, l );
    ((*yyvalp).colorval).alpha = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
}
#line 2129 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 101:
#line 830 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    double h = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fval), s = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), l = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval) = hsl_to_rgb ( h, s, l );
    ((*yyvalp).colorval).alpha = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
}
#line 2139 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 102:
#line 836 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).colorval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.colorval);
}
#line 2147 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 103:
#line 839 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).colorval).alpha = 0.0;
    ((*yyvalp).colorval).red = ((*yyvalp).colorval).green = ((*yyvalp).colorval).blue = 0.0;
}
#line 2156 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 104:
#line 843 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).colorval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.colorval);
    ((*yyvalp).colorval).alpha  = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval);
}
#line 2165 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 105:
#line 849 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = 1.0; }
#line 2171 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 106:
#line 850 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval);}
#line 2177 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 107:
#line 853 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = 1.0; }
#line 2183 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 108:
#line 854 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval);}
#line 2189 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 109:
#line 857 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval)/360.0;    if ( ! check_in_range ( (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval), 0, 360, &((*yylocp)))){YYABORT;}}
#line 2195 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 110:
#line 858 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval)/360.0;    if ( ! check_in_range ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval), 0, 360, &((*yylocp)))){YYABORT;}}
#line 2201 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 111:
#line 859 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval)/(2*G_PI); if ( ! check_in_range ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval), 0.0, (2*G_PI), &((*yylocp)))){YYABORT;}}
#line 2207 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 112:
#line 860 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval)/400.0;    if ( ! check_in_range ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval), 0, 400, &((*yylocp)))){YYABORT;}}
#line 2213 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 113:
#line 861 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);          if ( ! check_in_range ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval), 0.0, 1.0, &((*yylocp)))){YYABORT;}}
#line 2219 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 114:
#line 865 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval)/100.0; if ( !check_in_range ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval), 0, 100, &((*yylocp)))){YYABORT;}}
#line 2225 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 115:
#line 866 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval);       if ( !check_in_range ( (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval), 0.0, 1.0, &((*yylocp)))){YYABORT;}}
#line 2231 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 116:
#line 870 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval); }
#line 2237 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 117:
#line 871 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).fval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival); }
#line 2243 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 118:
#line 875 "../lexer/theme-parser.y" /* glr.c:816  */
    {  ((*yyvalp).ival) = ROFI_ORIENTATION_HORIZONTAL; }
#line 2249 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 119:
#line 876 "../lexer/theme-parser.y" /* glr.c:816  */
    {  ((*yyvalp).ival) = ROFI_ORIENTATION_VERTICAL;   }
#line 2255 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 120:
#line 881 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).sval) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval); }
#line 2261 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 121:
#line 885 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).list) = g_list_append  ( NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.list) ); }
#line 2267 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 122:
#line 886 "../lexer/theme-parser.y" /* glr.c:816  */
    {
    ((*yyvalp).list) = g_list_append ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.list), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.list));
}
#line 2275 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 123:
#line 889 "../lexer/theme-parser.y" /* glr.c:816  */
    {
   ((*yyvalp).list) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.list);
}
#line 2283 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 124:
#line 895 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).list) = g_list_append ( NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval) );}
#line 2289 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 125:
#line 896 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).list) = g_list_append ( (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.list), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval));}
#line 2295 "lexer/theme-parser.c" /* glr.c:816  */
    break;

  case 126:
#line 897 "../lexer/theme-parser.y" /* glr.c:816  */
    { ((*yyvalp).list) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.list); }
#line 2301 "lexer/theme-parser.c" /* glr.c:816  */
    break;


#line 2305 "lexer/theme-parser.c" /* glr.c:816  */
      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char *what)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (what);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, const char *what)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval, &yys->yyloc, what);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YYFPRINTF (stderr, "%s unresolved", yymsg);
          else
            YYFPRINTF (stderr, "%s incomplete", yymsg);
          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, what);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-199)))

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yytable_value) \
  0

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline void
yygetLRActions (yyStateNum yystate, int yytoken,
                int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yypact_value_is_default (yypact[yystate])
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YYASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yynewSize;
  size_t yyn;
  size_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            {
              YYDPRINTF ((stderr, "Removing dead stacks.\n"));
            }
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            {
              YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
                          (unsigned long int) yyi, (unsigned long int) yyj));
            }
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
            size_t yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
                 size_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YYASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print Args;               \
} while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
                 yyRuleNum yyrule, const char *what)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
             (unsigned long int) yyk, yyrule - 1,
             (unsigned long int) yyrline[yyrule]);
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval
                       , &(((yyGLRStackItem const *)yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       , what);
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YYFPRINTF (stderr, " (unresolved)");
      YYFPRINTF (stderr, "\n");
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp, const char *what)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((1, yyrhs, yyk, yyrule, what));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp, yylocp, what);
    }
  else
    {
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((0, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule, what));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp, what);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
             yybool yyforceEval, const char *what)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval, &yyloc, what);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        {
          YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
                     (unsigned long int) yyk, yyrule - 1));
        }
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval, &yyloc);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
                  "Reduced stack %lu by rule #%d; action deferred.  "
                  "Now in state %d.\n",
                  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
                                (unsigned long int) yyk,
                                (unsigned long int) yyi));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = YY_NULLPTR;

      if (yystackp->yytops.yycapacity
          > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
        (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
                                  (yystackp->yytops.yycapacity
                                   * sizeof yynewStates[0]));
      if (yynewStates == YY_NULLPTR)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
        (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                             (yystackp->yytops.yycapacity
                              * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == YY_NULLPTR)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp, const char *what);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, const char *what)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, what));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, what));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp, const char *what)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, what);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, what);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp, what);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
               (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]));
          else
            YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]),
                       (unsigned long int) (yystates[yyi-1]->yyposn + 1),
                       (unsigned long int) yystates[yyi]->yyposn);
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, YYLTYPE *yylocp, const char *what)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (yylocp, what, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState* yys1, int yyn1,
                    yyGLRStack *yystackp, const char *what)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp, what);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YYASSERT (yyoption != YY_NULLPTR);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (yynrhs > 0)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp, what);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          {
            int yychar_current = yychar;
            YYSTYPE yylval_current = yylval;
            YYLTYPE yylloc_current = yylloc;
            yychar = yyoption->yyrawchar;
            yylval = yyoption->yyval;
            yylloc = yyoption->yyloc;
            YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
            yychar = yychar_current;
            yylval = yylval_current;
            yylloc = yylloc_current;
          }
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, const char *what)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp, what);
              return yyreportAmbiguity (yybest, yyp, yylocp, what);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YYASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, what);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other, &yydummy, what);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval, yylocp, what);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, what);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, const char *what)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , what));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                   size_t yyposn, YYLTYPE *yylocp, const char *what)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
                  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], what);
          if (yyflag == yyerr)
            {
              YYDPRINTF ((stderr,
                          "Stack %lu dies "
                          "(predicate failure or explicit user error).\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yySymbol yytoken;
          int yyaction;
          const short int* yyconflicts;

          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
          if (yychar == YYEMPTY)
            {
              YYDPRINTF ((stderr, "Reading a token: "));
              yychar = yylex (&yylval, &yylloc);
            }

          if (yychar <= YYEOF)
            {
              yychar = yytoken = YYEOF;
              YYDPRINTF ((stderr, "Now at end of input.\n"));
            }
          else
            {
              yytoken = YYTRANSLATE (yychar);
              YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
            }

          yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

          while (*yyconflicts != 0)
            {
              YYRESULTTAG yyflag;
              size_t yynewStack = yysplitStack (yystackp, yyk);
              YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
                          (unsigned long int) yynewStack,
                          (unsigned long int) yyk));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts], what);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, yylocp, what));
              else if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr, "Stack %lu dies.\n",
                              (unsigned long int) yynewStack));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction], what);
              if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr,
                              "Stack %lu dies "
                              "(predicate failure or explicit user error).\n",
                              (unsigned long int) yyk));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

static void
yyreportSyntaxError (yyGLRStack* yystackp, const char *what)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (&yylloc, what, YY_("syntax error"));
#else
  {
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  size_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
  size_t yysize = yysize0;
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected").  */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;
          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytokenName (yyx);
                {
                  size_t yysz = yysize + yytnamerr (YY_NULLPTR, yytokenName (yyx));
                  yysize_overflow |= yysz < yysize;
                  yysize = yysz;
                }
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  {
    size_t yysz = yysize + strlen (yyformat);
    yysize_overflow |= yysz < yysize;
    yysize = yysz;
  }

  if (!yysize_overflow)
    yymsg = (char *) YYMALLOC (yysize);

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yyarg[yyi++]);
              yyformat += 2;
            }
          else
            {
              yyp++;
              yyformat++;
            }
        }
      yyerror (&yylloc, what, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (&yylloc, what, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp, const char *what)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yySymbol yytoken;
        if (yychar == YYEOF)
          yyFail (yystackp, &yylloc, what, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc, what);
          }
        YYDPRINTF ((stderr, "Reading a token: "));
        yychar = yylex (&yylval, &yylloc);
        if (yychar <= YYEOF)
          {
            yychar = yytoken = YYEOF;
            YYDPRINTF ((stderr, "Now at end of input.\n"));
          }
        else
          {
            yytoken = YYTRANSLATE (yychar);
            YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
          }
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, &yylloc, what, YY_NULLPTR);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yytable[yyj],
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys, what);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, &yylloc, what, YY_NULLPTR);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char *what)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (yytrue)
        {
          yyRuleNum yyrule;
          int yyaction;
          const short int* yyconflicts;

          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
               yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, what);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, what));
            }
          else
            {
              yySymbol yytoken;
              if (yychar == YYEMPTY)
                {
                  YYDPRINTF ((stderr, "Reading a token: "));
                  yychar = yylex (&yylval, &yylloc);
                }

              if (yychar <= YYEOF)
                {
                  yychar = yytoken = YYEOF;
                  YYDPRINTF ((stderr, "Now at end of input.\n"));
                }
              else
                {
                  yytoken = YYTRANSLATE (yychar);
                  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
                }

              yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
               yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, what);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, what));
            }
        }

      while (yytrue)
        {
          yySymbol yytoken_to_shift;
          size_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, &yylloc, what));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, &yylloc, what, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, what));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
           yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack, what);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              int yyaction;
              const short int* yyconflicts;
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              yygetLRActions (yystate, yytoken_to_shift, &yyaction,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
                          (unsigned long int) yys,
                          yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, what));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, what);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (&yylloc, what, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc, what);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          size_t yysize = yystack.yytops.yysize;
          size_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                 yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                  if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys, what);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YYFPRINTF (stderr, " -> ");
    }
  YYFPRINTF (stderr, "%d@%lu", yys->yylrState,
             (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YYFPRINTF (stderr, "<null>");
  else
    yy_yypstack (yyst);
  YYFPRINTF (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)                                                         \
    ((YYX) == YY_NULLPTR ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YYFPRINTF (stderr, "%3lu. ",
                 (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
        {
          YYASSERT (yyp->yystate.yyisState);
          YYASSERT (yyp->yyoption.yyisState);
          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
                     yyp->yystate.yyresolved, yyp->yystate.yylrState,
                     (unsigned long int) yyp->yystate.yyposn,
                     (long int) YYINDEX (yyp->yystate.yypred));
          if (! yyp->yystate.yyresolved)
            YYFPRINTF (stderr, ", firstVal: %ld",
                       (long int) YYINDEX (yyp->yystate
                                             .yysemantics.yyfirstVal));
        }
      else
        {
          YYASSERT (!yyp->yystate.yyisState);
          YYASSERT (!yyp->yyoption.yyisState);
          YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
                     yyp->yyoption.yyrule - 1,
                     (long int) YYINDEX (yyp->yyoption.yystate),
                     (long int) YYINDEX (yyp->yyoption.yynext));
        }
      YYFPRINTF (stderr, "\n");
    }
  YYFPRINTF (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
               (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  YYFPRINTF (stderr, "\n");
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc



#line 900 "../lexer/theme-parser.y" /* glr.c:2584  */


