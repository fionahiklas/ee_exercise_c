
#include "fizzbuzz.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char FIZZ[]="fizz";
const char BUZZ[]="buzz";
const char LUCK[]="luck";


// ////////////////////////////////////////////////////////// //
// Copied from the first attempt as these are handy functions //
// ////////////////////////////////////////////////////////// //

static inline bool divides_by_not_zero(int numberToProcess, int divisor)
{
    return ( numberToProcess != 0 && numberToProcess % divisor == 0 );
}

static inline bool divides_by_three(int numberToProcess)
{
    return divides_by_not_zero(numberToProcess, 3);
}

static inline bool divides_by_five(int numberToProcess)
{
    return divides_by_not_zero(numberToProcess, 5);
}

static inline bool contains_digit_three(int numberToProcess)
{
    char to_string_buffer[10];
    sprintf(to_string_buffer, "%d", numberToProcess);
    return ( strchr( to_string_buffer, '3' ) != NULL );
}


/**
 * If the fizz output is needed, add it to the buffer.
 *
 * Returns the following
 *  0   - if nothing is done
 *  -1  - the processing should halt
 *  +1  - added something, continue processing
 */
int add_fizz_if_required(int numberToProcess, char* result_buffer)
{
    if(divides_by_three(numberToProcess))
    {
        strcat(result_buffer, FIZZ);
        return 1;
    }

    return 0;
}

/**
 * If the buzz output is needed, add it to the buffer.
 *
 * Returns the following
 *  0   - if nothing is done
 *  -1  - the processing should halt
 *  +1  - added something, continue processing
 */
int add_buzz_if_required(int numberToProcess, char* result_buffer)
{
    if(divides_by_five(numberToProcess))
    {
        strcat(result_buffer, BUZZ);
        return 1;
    }

    return 0;
}

/**
 * If the luck output is needed, add it to the buffer.
 *
 * Returns the following
 *  0   - if nothing is done
 *  -1  - the processing should halt
 *  +1  - added something, continue processing
 */
int add_luck_if_required(int numberToProcess, char* result_buffer)
{
    if(contains_digit_three(numberToProcess))
    {
        strcat(result_buffer, LUCK);
        return -1;
    }

    return 0;
}

/**
 * If the digit output is needed, add it to the buffer.
 *
 * Returns the following
 *  0   - if nothing is done
 *  -1  - the processing should halt
 *  +1  - added something, continue processing
 */
int add_digit_if_required(int numberToProcess, char* result_buffer)
{
    if(strlen(result_buffer) == 0)
    {
        sprintf(result_buffer, "%d", numberToProcess);
        return -1;
    }
    return 0;
}

// This is really complicated syntax!  This is an array of pointers to functions
// that take (int, char*) as arguments and return int!  I wonder if there is a
// better way to write this so it's clearer
int (*functionList[])(int, char*) = {
    add_luck_if_required,
    add_fizz_if_required,
    add_buzz_if_required,
    add_digit_if_required
};

/*
 * Process a single integer number to return a textual result
 * based on the fizzbuzz rules.
 *
 * The return value of the function is number of characters
 * written to the buffer, or 0 on error.
 */
int process_one_number(int numberToProcess, char* result_buffer)
{
    result_buffer[0] = '\0';

    for(int i=0; i < sizeof(functionList)/sizeof(void (*)()) ; i++ )
    {
        int result = functionList[i](numberToProcess, result_buffer);
        if(result == -1) break;
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
