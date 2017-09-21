
#include "fizzbuzz.h"
#include <string.h>

const char FIZZ[]="fizz";
const char BUZZ[]="buzz";

/*
 * Process a single integer number to return a textual result
 * based on the fizzbuzz rules.
 *
 * The return value of the function is number or characters
 * written to the buffer, or 0 on error.
 */
int process_one_number(int numberToProcess, char* result_buffer)
{
    int result_count = 0;
    result_buffer[0] = '\0'; // Need to nul-terminate so result works

    if ( numberToProcess % 3 == 0 )
    {
        strcat(result_buffer, FIZZ);
    }

    if ( numberToProcess % 5 == 0 )
    {
        strcat(result_buffer, BUZZ);
    }


    return strlen(result_buffer);
}

/*
 * Process an array of numbers and populate the buffer with
 * the textual result
 *
 * The return value of the function is number or characters
 * written to the buffer, or 0 on error.
 */
int process_many_numbers(int* numbersToProcess[], char* result_buffer)
{

    return 0;
}