#include <iostream>
#include <vector>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define isNum(x) ('0'<=(x)&&(x)<='9')

using namespace std;

int readInt(const string &s, int &i){
    int ret=0;
    if (!isNum(s[i])){
        fprintf(stderr,"Invalid Expression\n");
        exit(1);
    }
    while(isNum(s[i])){
        ret=ret*10+(s[i]-'0');
        i++;
    }
    return ret;
}

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

    string exp = args[0];
    int n = exp.size();
    int i=0;
    printf("\tmov rax, %d\n", readInt(exp,i));
    while(i<n){
        if (exp[i]=='+'){
            i++;
            printf("\tadd rax, %d\n", readInt(exp,i));
            continue;
        }
        if (exp[i]=='-'){
            i++;
            printf("\tsub rax, %d\n", readInt(exp,i));
            continue;
        }
        fprintf(stderr,"Invalid Expression\n");
        return 1;
    }
    printf("\tret\n");
    return 0;
}
