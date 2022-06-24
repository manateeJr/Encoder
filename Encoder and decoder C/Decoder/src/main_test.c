#include <string.h>
#include "unity.h"
#include "Decoder.h"

    

void setUp(void)
{
    // To do: optionally add the code to be executed before each unit test
}

void tearDown(void)
{
    // To do: optionally add the code to be executed after each unit test
}

void test_ConstructNibble() {
    //ARRANGE
    char d0 = 0b1;
    char d1 = 0b1;
    char d2 = 0b1;
    char d3 = 0b1;

    char testNibble;
    char expectedNibble = 0xF;

    //ACT
    ConstructNibble(d0, d1, d2, d3, &testNibble);

    //ASSERT
    TEST_ASSERT_EQUAL_CHAR(expectedNibble, testNibble);
}

void test_DecodeNibble() {
    //ARRANGE
    char testNibble = 0b01101001;
    char expectedNibble = 0b1101;
    
    //ACT
    testNibble = DecodeNibble(testNibble);

    //ASSERT
    TEST_ASSERT_EQUAL_CHAR(expectedNibble, testNibble);
}

int main(void)
{
    UnityBegin(0);
    //Construct nibble test
    RUN_TEST(test_ConstructNibble, 0);
    //Decode nibble test
    RUN_TEST(test_DecodeNibble, 1);
    
    return UnityEnd();
}
