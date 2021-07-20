#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Ref:
//https://stackoverflow.com/questions/2602823/in-c-c-whats-the-simplest-way-to-reverse-the-order-of-bits-in-a-byte/2602885
unsigned char reverse(unsigned char b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}
//Ref:
//https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte=' ';
    int i=0;
    int j=0;

    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

//e.g.
//char array is ['a','b']
//'a'=01100001
//'b'=01100010
//'a','b' = 0110000101100010
//after reversed: it should be 0100011010000110
//the idea is to iterate the string from tail to head
//Then for each char using divide and conquer solution. 1 char is 8-bit ahd divide it to 2 4-bits blocks.
//and divide it to 4 2-bits blocks.
//after division, we change the order of each 2-bits blocks and merge back to 4 bits, and 8 bits.

void reverse_bytes(char* arr, int size){
    for (int i=size-1;i>=0;i--){
        // printf("this char is %c\n",arr[i]);
        // printf("before bit arr is: ");
        // printBits(sizeof(arr[i]), &arr[i]);
        arr[i]=reverse(arr[i]);
        // printf("after bit arr is: ");
        printBits(sizeof(arr[i]), &arr[i]);
        // printf("after char is %c\n",arr[i]);
        // printf("========\n");

    }


}



int main()
{
    char arr[2]={'a','b'};
    reverse_bytes(arr,2);
    return 0;
}