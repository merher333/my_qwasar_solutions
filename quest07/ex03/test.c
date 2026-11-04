#include <stdio.h>

char* rcapitalize(char* param_1);

int main() {
    char* result = rcapitalize("a FiRSt LiTTlE TESt");
    printf("%s\n", result);  // should print "A firsT littlE tesT"
    return 0;
}
