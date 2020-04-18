#include <iostream>
#include <cstdarg>

using namespace std;

void error(const char *fmt, ...)
{
    va_list ap;
    va_start(ap,fmt);
    vfprintf(stderr,fmt,ap);
    fprintf(stderr,"\n");
    exit(1);
}
