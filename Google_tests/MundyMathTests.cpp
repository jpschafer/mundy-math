//
// Created by jason on 9/20/2021.
//

#include "gtest/gtest.h"
#include "../MundyMath.h"

TEST(testMathSuite, additionTest) {
	EXPECT_EQ(31, MundyMath::add(30.5, 0.5));
	EXPECT_EQ(100, MundyMath::add(25, 75));
	EXPECT_EQ(100, MundyMath::add(75, 25));
	EXPECT_EQ(1000, MundyMath::add(500, 500));
}

TEST(testMathSuite, subtractionTest) {
	EXPECT_EQ(0, MundyMath::subtract(50, 50));
	EXPECT_EQ(50, MundyMath::subtract(75, 25));
	EXPECT_EQ(100, MundyMath::subtract(100.5, 0.5));
	EXPECT_EQ(99.5, MundyMath::subtract(100, 0.5));
}

TEST(testMathSuite, multiplicationTest) {
	EXPECT_EQ(2500, MundyMath::multiply(50, 50));
	EXPECT_EQ(1875, MundyMath::multiply(75, 25));
	EXPECT_EQ(50.25, MundyMath::multiply(100.5, 0.5));
}

TEST(testMathSuite, divisionTest) {
	EXPECT_EQ(1, MundyMath::divide(50, 50));
	EXPECT_EQ(3, MundyMath::divide(75, 25));
	EXPECT_EQ(201, MundyMath::divide(100.5, 0.5));
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
	EXPECT_EQ(2147483647, MundyMath::power(2, 31));
}

