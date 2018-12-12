%option noyywrap
%option nounput
%{
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


#include "izraz.hpp"
#include "naredba.hpp"
#include "parser.tab.hpp"

%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%
puts          return puts_token;
begin         return begin_token;
end           return end_token;
if            return if_token;
else          return else_token;
until	      return until_token;
\*\*          {return stepen_token; } 
{LETTER}+     {yylval.s = new string(yytext); return id_token;}
($)?{DIGIT}+  {yylval.v = atoi(yytext); return num_token;}
'='           { return dodela_token;}
[.+\-*/<>;()=\n] return *yytext;
[ \t]       { } 
.             { cerr<<"Leksicka greska Nepoznat karakter: "<<*yytext<<endl; exit(EXIT_FAILURE); }
%%
