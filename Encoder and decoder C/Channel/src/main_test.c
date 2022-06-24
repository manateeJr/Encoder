#include <string.h>
#include "unity.h"
#include <Channel.h>
    

void setUp(void)
{
    // To do: optionally add the code to be executed before each unit test
}

void tearDown(void)
{
    // To do: optionally add the code to be executed after each unit test
}
//repair this
void Test_GetRandomNumber() {
    //ARRANGE
    int randomNumber;
    int expectedResult = 4;
    int testRange = 7;

    //ACT
    randomNumber = GetRandomNumber();

    //ASSERT
    TEST_ASSERT_INT_WITHIN(testRange, expectedResult, randomNumber);
}

void Test_RandomizeChar() {
    //ARRANGE
    char expectedResult = 'a';

    //ACT
    char randomizedChar = RandomizeChar(expectedResult, GetRandomNumber());

    //ASSERT
    TEST_ASSERT_NOT_EQUAL_CHAR(expectedResult, randomizedChar);
}

int main(void)
{
    UnityBegin(0);

    RUN_TEST(Test_GetRandomNumber, 0);

    RUN_TEST(Test_RandomizeChar, 1);

    return UnityEnd();
}
