#include "myprintf.h"
#include "string.h"

int main(){
    char mystring[50] = "Hello ITI 46\n";
    myprintf( mystring ,strlen(mystring));
    return 0;
}