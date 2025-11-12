#include "binary.h"
#include <stdio.h> //scanf
#include <string.h> //strlen()

int convert(const char *input){
    int flag = 0;
    int i;
    int total = 0;
    
    int len = strlen(input);
    
    for ( i=0; input[i] != '\0'; i++) {
        if(input[i] == '1' || input[i] == '0') {
            flag += 1;
        }
    }

    if (len == flag){
        for ( i=0; i < len; i++){
            total = total * 2;

            if (input[i] == '1') {
                total = total + 1;
            }
        }
        return total;
        
    } else {
        return -1;
    }
    
}

