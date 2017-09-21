#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

/*
 * Process a single integer number to return a textual result 
 * based on the fizzbuzz rules.
 * 
 * The return value of the function is number or characters 
 * written to the buffer, or 0 on error.
 */
int process_one_number(int numberToProcess, char* result_buffer);

/*
 * Process an array of numbers and populate the buffer with 
 * the textual result
 *
 * The return value of the function is number or characters 
 * written to the buffer, or 0 on error.
 */
int process_many_numbers(int numbersToProcess[], int sizeOfNumbersArray, char* result_buffer);

#endif


