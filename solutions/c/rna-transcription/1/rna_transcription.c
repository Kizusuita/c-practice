#include "rna_transcription.h"
#include <stddef.h>  // for size_t
#include <stdlib.h>  // for malloc, free

char *to_rna(const char *dna){
    if (!dna) return NULL; // If it's empty, stop

    size_t len = 0;
    while (dna[len] != '\0') { // Since in C the end of a string is \0, I can count until then to find the length of the string 
        len++;
    }

    char *rna = malloc(len + 1);
    if (!rna) return NULL; 

    for (size_t i = 0; i < len; i++) {
        switch (dna[i]) {
            case 'G': 
                rna [i] = 'C'; 
                break;
            case 'C':
                rna[i] = 'G';
                break;
            case 'T':
                rna[i] = 'A';
                break;
            case 'A':
                rna[i] = 'U';
                break;
            default:
                free(rna);
                return NULL;
        }
    }

    rna[len] = '\0';
    return rna;
}

/*
So this is fun. Yay.

In C, strings aren't... strings. They're just arrays of chars ending with a null terminator (\0). So no... I don't have to read into arrays or anything to get specific substrings, it is already like that. Sorta.

When you see a function return type like "char *", it's saying "I'm gonna return this pointer to characters." because... * means pointer!

Pointer means the variable doesn't actually hold the character itself, but instead the memory address where the characters live.

const = the function pinky promises it's not gonna modify the data in any way, it's a *constant*

In this context, it means it's gonna take in the string of chars called "dna" but it's not gonna change it. You can READ but NO WRITE in permission terms. 

"size_t" is another data type. It's specfically a special int type used to represent size and lengths, i.e., how many bytes something takes in memory/string length/array length/etc. 

Before future me has the same question, NO you can't just declare it as an int. uint8/16/etc mean this is EXACTLY how big this thing is, where size_t is like "i want this to fit somehow based on the machine"

"malloc" means memory allocation. In actual like definition it's "a function in <stdlib.h> that asks the os for a block of memory on the heap". A heap is a dynamic memory bank that you explicitly allocate (malloc) and free (free). 

malloc's normal syntax is void *malloc(size_t size), and if it fails it returns NULL. void * is just a generic pointer in C, it's not a type of any sort it's literally just ... nothing. just points to somewhere in memory. you literally cast it to whatever you want .... like "char *rna = malloc(len + 1)", telling the complier to treat it like a string of chars. also sidenote, you want the +1 when using strings bc strings always end in the null identifier :')

Any time you assign memory, you wanna check it. So after assigning something = malloc, the line right after should be if (!variable) return NULL;

ALWAYS, ALWAYS, ALWAYS free memory when you are done with it. If you don't, you will create memory leaks, which are no bueno. 
*/