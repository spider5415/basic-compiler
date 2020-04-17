#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<string> args(argv, argv+argc);
    if (argc!=2){
        fprintf(stderr,"Invalid Argument\n");
        return 1;
    }
    printf(".intel_syntax noprefix\n");
    printf(".global main\n");
    printf("main:\n");
    printf("\tmov rax, %d\n", stoi(args[1]));
    printf("\tret\n");
    return 0;
}
