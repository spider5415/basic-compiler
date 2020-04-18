#include <iostream>
#include <vector>

#include "util.hpp"
#include "token.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    vector<string> args(argv+1, argv+argc); argc--;
    if (argc!=1){
        fprintf(stderr,"Invalid Argument\n");
        return 1;
    }
    printf(".intel_syntax noprefix\n");
    printf(".global main\n");
    printf("main:\n");

    TokenStream ts(args[0]);
    printf("\tmov rax, %d\n", ts.getInt());
    while(ts.front().kind!=TK_EOF){
        string op = ts.getToken(TK_OPERATOR);
        if (op=="+"){
            printf("\tadd rax, %d\n", ts.getInt());
            continue;
        }
        if (op=="-"){
            printf("\tsub rax, %d\n", ts.getInt());
            continue;
        }
        error("Internal Error");
    }
    printf("\tret\n");
    return 0;
}
