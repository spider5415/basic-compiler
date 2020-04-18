#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

#include <string>
#include <vector>

using namespace std;

enum TokenKind {
    TK_OPERATOR,
    TK_NUMBER,
    TK_EOF
};

struct Token {
    int pos;
    TokenKind kind;
    string val;
};

class TokenStream {
private:
    const string prog;
    vector<Token> tokens;
    int ptr;
public:
    TokenStream(const string &s);
    inline Token& front(){return tokens[ptr];}
    inline Token& pop(){return tokens[ptr++];}
    string getToken(TokenKind kind);
    inline int getInt(){return stoi(getToken(TK_NUMBER));}

    void error(const char *fmt, ...);
    void error(int pos, const char *fmt, ...);
};

#endif
