#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <array>
#define MAX_WORD 256
#define WORD_MASK "%255s"
#define FILE_NAME "Text.txt"

int main(void){
    FILE * f;
    char wrd[MAX_WORD];
    int count = 0;
    std::array<std::string, 9999> data;

    if ( ! ( f = fopen(FILE_NAME, "r") ) ){
        fprintf(stderr, "Can't open input file!\n");
        exit(1);
    }

    while ( fscanf(f, WORD_MASK, wrd) == 1 )

    {

            data[count] = wrd;
            data[count] = data[count] + " ";
            //std::cout << data[count] << std::endl;
            count ++;
    }



    std::ofstream out("Text2.txt", std::ios::app);
    count --;
    if (out.is_open())

    {
    	std::cout << "Fopen" << std::endl;

    while (count != -1)
    	{
    	out << data[count];
    	count --;
    	}

    }
    out.close();

    if ( ferror(f) || fclose(f) ){
        fprintf(stderr, "Error reading file!\n");
        exit(1);
    }

    exit(0);
}
