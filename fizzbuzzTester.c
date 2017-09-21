
#include <stdio.h>

#include "fizzbuzz.h"
#include "testing.h"


BEGIN_TEST(divided_by_three_returns_fizz)
{
  char result_buffer[10];
  int result; // Doesn't matter about initializing, it'll be junk

  result = process_one_number(3, result_buffer);

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




int main(int argc, char* argv[]) 
{
  START_TESTING("FizzBuzz")

  RUN_TEST(&divided_by_three_returns_fizz, "Divide by three returns fizz");
  RUN_TEST(&divided_by_five_returns_buzz, "Divide by five returns buzz");
  RUN_TEST(&divided_by_three_and_five_returns_fizzbuzz, "Divide by three and five returns fizzbuzz");
  RUN_TEST(&a_number_that_doesnt_divide_returns_number, "Return number for something that doesn't divide");

  END_TESTING
}

