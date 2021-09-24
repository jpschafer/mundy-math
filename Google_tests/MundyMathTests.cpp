//
// Created by jason on 9/20/2021.
//

#include "gtest/gtest.h"
#include "../MundyMath.h"
#include "../Result.h"

TEST(testMathSuite, additionTest) {
	// Same Operand Tests
	EXPECT_EQ(31, MundyMath::add(30.5, 0.5).getResult());
	EXPECT_EQ(100, MundyMath::add(25, 75).getResult());
	EXPECT_EQ(100, MundyMath::add(75, 25).getResult());
	EXPECT_EQ(1000, MundyMath::add(500, 500).getResult());

	// Alternating Double / Integer
	EXPECT_EQ(1000, MundyMath::add(500.0, 500).getResult());
	EXPECT_EQ(1000, MundyMath::add(500, 500.0).getResult());

	// Octal Tests
	EXPECT_EQ( 20, MundyMath::add("012", "012").getResult());
	EXPECT_EQ( 20, MundyMath::add("012", 10).getResult());
	EXPECT_EQ( 20, MundyMath::add(10, "012").getResult());

	// Hexadecimal Tests
	EXPECT_EQ( 20, MundyMath::add("0xA", "0xA").getResult());
	EXPECT_EQ( 20, MundyMath::add("0xA", 10).getResult());
	EXPECT_EQ( 20, MundyMath::add(10, "0xA").getResult());

	// Binary Tests
	EXPECT_EQ( 40, MundyMath::add("0b00010100", "0b00010100").getResult());
	EXPECT_EQ( 40, MundyMath::add("0b00010100", 20).getResult());
	EXPECT_EQ( 40, MundyMath::add(20, "0b00010100").getResult());
}

TEST(testMathSuite, subtractionTest) {
	EXPECT_EQ(0, MundyMath::subtract(50, 50).getResult());
	EXPECT_EQ(50, MundyMath::subtract(75, 25).getResult());
	EXPECT_EQ(100, MundyMath::subtract(100.5, 0.5).getResult());
	EXPECT_EQ(99.5, MundyMath::subtract(100, 0.5).getResult());
}

TEST(testMathSuite, multiplicationTest) {
	EXPECT_EQ(2500, MundyMath::multiply(50, 50).getResult());
	EXPECT_EQ(1875, MundyMath::multiply(75, 25).getResult());
	EXPECT_EQ(50.25, MundyMath::multiply(100.5, 0.5).getResult());
}

TEST(testMathSuite, divisionTest) {
	EXPECT_EQ(1, MundyMath::divide(50, 50).getResult());
	EXPECT_EQ(3, MundyMath::divide(75, 25).getResult());
	EXPECT_EQ(201, MundyMath::divide(100.5, 0.5).getResult());
	EXPECT_EQ(50.025, MundyMath::divide(25.0125, 0.5).getResult());
}

TEST(testMathSuite, squareRootTest) {
	EXPECT_EQ(3, MundyMath::squareRoot(9));
	EXPECT_EQ(7, MundyMath::squareRoot(49));
	EXPECT_EQ(7, MundyMath::squareRoot(49.5));
	EXPECT_EQ(7, MundyMath::squareRoot(50));
	EXPECT_EQ(574, MundyMath::squareRoot(329476));
	EXPECT_EQ(10000, MundyMath::squareRoot(100000000));	
}

TEST(testMathSuite, powerTest) {
	EXPECT_EQ(3, MundyMath::power(3, 1));
	EXPECT_EQ(9, MundyMath::power(3, 2));
	EXPECT_EQ(27, MundyMath::power(3, 3));
	EXPECT_EQ(1073741824, MundyMath::power(2, 30));
	EXPECT_EQ(1073741824, MundyMath::power(2.0, 30));
	EXPECT_EQ(244.140625, MundyMath::power(2.5, 6));
	EXPECT_EQ(0.5, MundyMath::power(2.0, -1));
	EXPECT_EQ(1, MundyMath::power(2, -1));
	EXPECT_EQ(0.0625, MundyMath::power(2.0, -4));
	EXPECT_EQ(0, MundyMath::power(2, -4));
}

