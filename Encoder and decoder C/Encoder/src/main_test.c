#include <string.h>
#include "unity.h"
#include "Encode.h"

    

void setUp(void)
{
    // To do: optionally add the code to be executed before each unit test
}

void tearDown(void)
{
    // To do: optionally add the code to be executed after each unit test
}

void test_EncodeNibble() {
    //ARRANGE
    char testNibble = 0b0110;
    char expectedNibble = 0b0110010;

    //ACT
    testNibble = EncodeNibble(testNibble);

    //ASSERT
    TEST_ASSERT_EQUAL_CHAR(expectedNibble, testNibble);
}

void test_ExtractLowNibble() {
    char testByte = 0b10011110;
    char expectedNibble = 0b1110;

    //ACT
    testByte = ExtractLowNibble(testByte);

    //ASSERT
    TEST_ASSERT_EQUAL_CHAR(testByte, expectedNibble);
}

void test_ExtractHighNibble() {
    //ARRANGE
    char testByte = 0b11010010;
    char expectedNibble = 0b1101;

    //ACT
    testByte = ExtractHighNibble(testByte);

    //ASSERT
    TEST_ASSERT_EQUAL_CHAR(testByte, expectedNibble);
}

void test_ConstructByte() {
    // ARRANGE
    char b0 = 0b0;
    char b1 = 0b1;
    char b2 = 0b0;
    char b3 = 0b0;
    char b4 = 0b0;
    char b5 = 0b1;
    char b6 = 0b1;

    char testByte;
    char expectedByte = 0b1100010;

    //ACT
    testByte = ConstructByte(b0, b1, b2, b3, b4, b5, b6);

    //ASSERT
    TEST_ASSERT_EQUAL_CHAR(testByte, expectedByte);
}

int main(void)
{
    UnityBegin(0);

    // TEST ENCODE NIBBLE
    RUN_TEST(test_EncodeNibble, 1);

    // TEST EXTRACTING LOW NIBBLE
    RUN_TEST(test_ExtractLowNibble, 2);

    // TEST EXTRACTING HIGH NIBBLE
    RUN_TEST(test_ExtractLowNibble, 3);

    // TEST CONSTRUCT BYTE
    RUN_TEST(test_ConstructByte, 4);
    return UnityEnd();
}
