
#include <stdio.h>

#include "fizzbuzz.h"
#include "testing.h"

const int FULL_TEST_DATA[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
const char* FULL_RESULT_FIZZBUZZ = "1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz 16 17 fizz 19 buzz";


BEGIN_TEST(divided_by_three_returns_fizz)
{
  char result_buffer[10];
  int result; // Doesn't matter about initializing, it'll be junk

  result = process_one_number(9, result_buffer);

  ASSERT_TRUE( result == 4, "Process one number results in 4" )
  ASSERT_STRINGS_EQUAL(result_buffer, "fizz", 10, "Compare strings")
}
END_TEST

BEGIN_TEST(divided_by_five_returns_buzz)
{
  char result_buffer[10];
  int result; // Doesn't matter about initializing, it'll be junk

  result = process_one_number(5, result_buffer);

  ASSERT_TRUE( result == 4, "Process one number results in 4" )
  ASSERT_STRINGS_EQUAL(result_buffer, "buzz", 10, "Compare strings")
}
END_TEST


BEGIN_TEST(divided_by_three_and_five_returns_fizzbuzz)
{
  char result_buffer[10];
  int result; // Doesn't matter about initializing, it'll be junk

  result = process_one_number(15, result_buffer);

  ASSERT_TRUE( result == 8, "Process one number results in 8" )
  ASSERT_STRINGS_EQUAL(result_buffer, "fizzbuzz", 10, "Compare strings")
}
END_TEST

BEGIN_TEST(a_number_that_doesnt_divide_returns_number)
{
  char result_buffer[10];
  int result; // Doesn't matter about initializing, it'll be junk

  result = process_one_number(7, result_buffer);

  ASSERT_TRUE( result == 1, "Process one number results in 1" )
  ASSERT_STRINGS_EQUAL(result_buffer, "7", 10, "Compare strings")
}
END_TEST

BEGIN_TEST(zero_doesnt_break_mod_operator_use)
{
  char result_buffer[10];
  int result; // Doesn't matter about initializing, it'll be junk

  result = process_one_number(0, result_buffer);

  ASSERT_TRUE( result == 1, "Process one number results in 1" )
  ASSERT_STRINGS_EQUAL(result_buffer, "0", 10, "Compare strings")
}
END_TEST

BEGIN_TEST(process_array_of_numbers)
{
  char result_buffer[1024]; // Paranoid, made the buffer huge
  int result; // Doesn't matter about initializing, it'll be junk

  result = process_many_numbers(FULL_TEST_DATA, sizeof(FULL_TEST_DATA)/sizeof(int), result_buffer);

  printf("Result: %d, result string: %s\n", result, result_buffer);

  ASSERT_TRUE( result == strlen(FULL_RESULT_FIZZBUZZ), "Process many numbers results in full string" )
  ASSERT_STRINGS_EQUAL(result_buffer, FULL_RESULT_FIZZBUZZ, 1024, "Compare strings")
}
END_TEST


int main(int argc, char* argv[]) 
{
  START_TESTING("FizzBuzz")

  RUN_TEST(&divided_by_three_returns_fizz, "Divide by three returns fizz");
  RUN_TEST(&divided_by_five_returns_buzz, "Divide by five returns buzz");
  RUN_TEST(&divided_by_three_and_five_returns_fizzbuzz, "Divide by three and five returns fizzbuzz");
  RUN_TEST(&a_number_that_doesnt_divide_returns_number, "Return number for something that doesn't divide");
  RUN_TEST(&zero_doesnt_break_mod_operator_use, "Zero shouldn't result in fizzbuzz");
  RUN_TEST(&process_array_of_numbers, "Test full fizzbuzz results");

  END_TESTING
}

