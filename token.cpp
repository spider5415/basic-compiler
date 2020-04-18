#include <string>
#include <vector>
#include "util.hpp"
#include "token.hpp"

using namespace std;

TokenStream::TokenStream(const string &s):ptr(0){
    int n=s.size();
    int i=0;
    while(i<n){
        if (isspace(s[i])){i++; continue;}
        if (isdigit(s[i])){
            string t;
            while(isdigit(s[i])) t+=s[i++];
            tokens.pb({TK_NUMBER,t});
            continue;
        }
        if (s[i]=='+' || s[i]=='-'){
            tokens.pb({TK_OPERATOR,string(1,s[i++])});
            continue;
        }
        error("Unexpected Character");
    }
    tokens.pb({TK_EOF,""});
}

string TokenStream::getToken(TokenKind kind){
    Token t = pop();
    if (t.kind!=kind) error("Unexpected Token");
    return t.val;
}
