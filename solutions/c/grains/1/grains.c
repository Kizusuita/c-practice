#include "grains.h"

uint64_t square(uint8_t index) {
    if (index < 1 || index > 64)
        return 0;

    uint64_t grains = 1;
    for (uint8_t i = 1; i < index; i++) {
        grains *= 2;
    }

    return grains;
}

uint64_t total(void) {
    uint64_t sum = 0;
    for (uint8_t i = 1; i <= 64; i++){
        sum += square(i);
    } 
    
    return sum;
}

/*
So, I'm just going to make a comment block here to explain everything, since this is my first C program. I'll work through it like I did bash. 

#include ~ preprocessor directive, it runs BEFORE code is compiled.
"grains.h" ~ the QUOTES are important, it means it's a local header file, from the project directory. SYSTEM header files will be written with <> i.e., <stdio.h> The header file declares the function prototypes that the .c file has to define. So... future reference, look at the header file to see what exercism wants you to write dork.

The header tells the complier like "yo, these functions exist btw," and the .c file says "aight, here's what they do bro" <3

uint64_t square(uint8_t index) {} ~ This is how you define functions. 
uint64_t = the return type, this means this particular function returns a 64-bit unsigned integer, aka ONLY whole numbers and CAN'T be negative. If you wanted negative, you'd just type int64_t.

square(<>) ~ just the name of the function, you're not that dumb.

uint8_t --> another data type, this one means unsigned 8-bit integer, so ONLY whole numbers 0-255, cuz that's the max num with 8 bits turned on.

So that function is gonna take a smaller number, and return a (maybe) much bigger number.

The for loop syntax is literally bash's considering I use C-style for loops. It's for (A; B; C) { D; } Where --->
A = Runs once before loop (aka the variable)
B = Checked BEFORE every iteration
C = Ran AFTER every iteration
D = Body

uint64_t total(void) ~ See above BUT "void" means the function takes NO args

In C, you declare literally everything explicitly - type, size, when it exists, etc. It doesn't assume ANYTHING or handle memory for you in any capacity. Hence the type declaration (uint64_t)
*/

