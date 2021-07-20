#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *f(int m)
{
    char buf[6];
    int x;

    if (m == 1 && x--)
    {
        strcpy(buf,"ABCDEF");
        return buf;
    }
    else if (m == 2)
    {
        char* msg = (char*)malloc(100);
        strcpy(msg, "ABCDEF");
        return msg;
    }

}

int main(){
    
    char *m;
    m = f(1);
    //write a character, of unsigned char type, to stdout.
    putchar(m[0]);
    free(m);
    m=NULL;
    return 0;
}