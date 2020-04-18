#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include "util.hpp"
#include "token.hpp"

using namespace std;

TokenStream::TokenStream(const string &s):prog(s),ptr(0)
{
    int n=s.size();
    int i=0;
    while(i<n){
        if (isspace(s[i])){i++; continue;}
        int pos=i;
        if (isdigit(s[i])){
            string t;
            while(isdigit(s[i])) t+=s[i++];
            tokens.pb({pos,TK_NUMBER,t});
            continue;
        }
        if (s[i]=='+' || s[i]=='-'){
            tokens.pb({pos,TK_OPERATOR,string(1,s[i++])});
            continue;
        }
        error(pos, "Unexpected Character");
    }
    tokens.pb({n,TK_EOF,""});
}

string TokenStream::getToken(TokenKind kind)
{
    if (front().kind!=kind) error("Unexpected Token");
    return pop().val;
}

void TokenStream::error(const char *fmt, ...)
{
    va_list ap;
    va_start(ap,fmt);
    cout<<prog<<"\n";
    fprintf(stderr,"%*s", front().pos, "");
    rep(i,front().val.size()){
        if (i==0) fprintf(stderr,"^");
        else fprintf(stderr,"~");
    }
    fprintf(stderr," ");
    vfprintf(stderr,fmt,ap);
    fprintf(stderr,"\n");
    exit(1);
}

void TokenStream::error(int pos, const char *fmt, ...)
{
    va_list ap;
    va_start(ap,fmt);
    cout<<prog<<"\n";
    fprintf(stderr,"%*s", pos, "");
    fprintf(stderr,"^ ");
    vfprintf(stderr,fmt,ap);
    fprintf(stderr,"\n");
    exit(1);
}
