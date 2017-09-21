
#include <stdio.h>

#include "fizzbuzz.h"
#include "testing.h"


BEGIN_TEST(dummy_test)
{
  char* wibble = "Hello";
 
  printf("DUMMY TEST\n");
  ASSERT_TRUE( 1==1, "One is one" )
  ASSERT_STRINGS_EQUAL("hello", wibble, "Compare strings")
}
END_TEST


int main(int argc, char* argv[]) 
{
  START_TESTING("FizzBuzz")

  RUN_TEST(&dummy_test, "Dummy test 1");
  RUN_TEST(&dummy_test, "Dummy test 2");

  END_TESTING
}

