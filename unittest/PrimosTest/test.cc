#include "gtest/gtest.h"
#include "circular.h"

TEST(TestCaseName, TestPrimes) {
	ASSERT_FALSE(isPrime(0));
	ASSERT_FALSE(isPrime(1));
	ASSERT_FALSE(isPrime(-2));
	ASSERT_FALSE(isPrime(9));
	ASSERT_TRUE(isPrime(2));
	ASSERT_TRUE(isPrime(7));
	ASSERT_TRUE(isPrime(997));
}

TEST(TestCaseName, TestCircularPrimes) {
	ASSERT_FALSE(isCircularPrime("0"));
	ASSERT_FALSE(isCircularPrime("1"));
	ASSERT_FALSE(isCircularPrime("-2"));
	ASSERT_FALSE(isCircularPrime("53"));

	char const* circularPrimes[19] = {"2", "3", "5", "7", "11", "13", "17", "37", "79", "113", "197", "199", "337", "1193", "3779", "11939", "19937", "193939", "199933"};
	for (int i = 0; i < 19; ++i)
		ASSERT_TRUE(isCircularPrime(circularPrimes[i]));
}
