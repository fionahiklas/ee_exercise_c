#ifndef TESTING_H
#define TESTING_H

#include <stdio.h>


#define BEGIN_TEST(function_name) \
  int (function_name)() { \

#define END_TEST \
  return 0; \
  } 

#define ASSERT_TRUE(condition, description) \
  if (!(condition)) \
  { \
    sprintf(stderr, "%s", (description)); \
    return 1; \
  }


#define START_TESTING(description) \
  { \
    int pass_count = 0; \
    int fail_count = 0; \
    fprintf(stderr,"Starting tests: %s\n\n", (description)); 
 	
#define RUN_TEST(function, description) \
{ \
  int test_result = (*function)(); \
  fprintf(stderr, "%s ...", (description)); \
  if (test_result) \
  { \
    fail_count++; \
    fprintf(stderr, " FAIL\n"); \
  } \
  else \
  { \
    pass_count++; \
    fprintf(stderr, " PASS\n"); \
  } \
}

#define END_TESTING \
  fprintf(stderr, "\n\nFinished testing\n Passed: %d\n Failed: %d\n\n", pass_count, fail_count); \
}


#endif


