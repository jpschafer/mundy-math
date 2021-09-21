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
}