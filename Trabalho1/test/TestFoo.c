#include "foo.h"
#include "unity.h"
#include "unity_fixture.h"
#include "stdlib.h"
#include "string.h"

#include "float.h"

TEST_GROUP(Foo);

TEST_SETUP(Foo)
{
}

TEST_TEAR_DOWN(Foo)
{
}


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int compare(const void * a, const void * b ) {
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;

    return strcmp(pa,pb);
}


TEST(Foo, TestFoo1)
{
  // All of these should pass
  
  int source_vet[4][5] = {{2, 3, 1, 4, 5}, {1, 2, 3, 4, 5}, {0, 0, 0, 0, 0}, {10, -9, -2147483648, 3, 2147483647}};
  int target_vet[4][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {0, 0, 0, 0, 0}, {-2147483648,-9, 3, 10, 2147483647}};
  
  const char *source_vet_char[] = {"f", "", "d", "jj"};
  const char *target_vet_char[] = {"", "d", "f", "jj"};
  
  float source_vet_float[5] = {2.5, FLT_MAX, 2.3, FLT_MIN, 5};
  float target_vet_float[5] = {FLT_MIN, 2.3, 2.5, 5, FLT_MAX};
  
    printf("\n");
	printf("The maximum value of float = %.10e\n", FLT_MAX);
	printf("The minimum value of float = %.10e\n", FLT_MIN);
  
  
  int i, j;
  int stringLen = sizeof(source_vet_char) / sizeof(char *);
  
  
  qsort(source_vet_float, 5, sizeof(float), cmpfunc);
	  printf("\n");
	  for(j=0; j<5; j++)
	  {
		  printf("%.38f \n", source_vet_float[j]);
	  }
	  TEST_ASSERT_EQUAL_FLOAT_ARRAY(target_vet_float, source_vet_float, 5);
  
  
  
  
  
  qsort(source_vet_char, stringLen, sizeof(char *), compare);
    printf("\n");
    for (i=0; i<stringLen; ++i)
    {
        printf("%s\n",  source_vet_char[i]);
    }
  TEST_ASSERT_EQUAL_STRING_ARRAY(target_vet_char, source_vet_char, stringLen);
  
  
  
  
  
  for(i=0; i<4; i++)
  {
	  qsort(source_vet[i], 5, sizeof(int), cmpfunc);
	  printf("\n");
	  for(j=0; j<5; j++)
	  {
		  printf("%d ", source_vet[i][j]);
	  }
	  TEST_ASSERT_EQUAL_INT_ARRAY(target_vet[i], source_vet[i], 5);
  };
  
}

TEST(Foo, TestFoo2)
{
  // This test will fail
  //TEST_ASSERT_EQUAL(1, foo2(1,2));
}

