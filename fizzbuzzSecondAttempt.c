
#include "fizzbuzz.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char FIZZ[]="fizz";
const char BUZZ[]="buzz";
const char LUCK[]="luck";



/*
 * Process a single integer number to return a textual result
 * based on the fizzbuzz rules.
 *
 * The return value of the function is number or characters
 * written to the buffer, or 0 on error.
 */
int process_one_number(int numberToProcess, char* result_buffer)
{
}



/*
 * Process an array of numbers and populate the buffer with
 * the textual result
 *
 * The return value of the function is number or characters
 * written to the buffer, or 0 on error.
 */
int process_many_numbers(const int* numbersToProcess, int sizeOfNumbersArray, char* result_buffer)
{
    char each_number_result_buffer[10];
    int each_number_result;
    bool have_result = false;

    printf("Size of array: %d\n", sizeOfNumbersArray);

    // This is the main result buffer
    result_buffer[0] = '\0'; // Need to nul-terminate so result works

    for(int i = 0; i < sizeOfNumbersArray; i++)
    {
        each_number_result = process_one_number(numbersToProcess[i], each_number_result_buffer);
        if( each_number_result > 0 )
        {
            if( have_result ) strcat(result_buffer, " ");
            strcat(result_buffer, each_number_result_buffer);
            have_result = true;
        }
    }

    return strlen(result_buffer);
}