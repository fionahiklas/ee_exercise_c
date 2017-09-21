
#include <stdio.h>

#include "fizzbuzz.h"
#include "testing.h"


BEGIN_TEST(divided_by_three_returns_fizz)
{
  char result_buffer[10];
  int result;

  result = process_one_number(3, result_buffer);

  ASSERT_TRUE( result==0, "Process one number results in 0" )
  ASSERT_STRINGS_EQUAL(result_buffer, "fizz", 10, "Compare strings")
}
END_TEST


int main(int argc, char* argv[]) 
{
  START_TESTING("FizzBuzz")

  RUN_TEST(&divided_by_three_returns_fizz, "Divide by three returns fizz");

  END_TESTING
}

