#include "gtest/gtest.h"
#include <exception>

using namespace std;

class myexception: public exception {
	virtual const char* what() const throw() {
		return "My exception happened";
	}
} myex;

TEST(TestCaseName, TestOne) {
	EXPECT_TRUE(true);
	EXPECT_FALSE(false);
	SUCCEED();
	ADD_FAILURE();
	FAIL();
}

TEST(TestCaseName, TestTwo) {
	ASSERT_EQ(2,2);
	ASSERT_NE(2,3);
	ASSERT_LT(4,9);
	ASSERT_LE(4,4);
	ASSERT_GT(9,4);
	ASSERT_GE(9,5);
}

TEST(TestCaseName, TestThree) {
	ASSERT_STREQ("hola", "hola");
	ASSERT_STRNE("hola", "hello");
	ASSERT_STRCASEEQ("hola", "HOLA");
	ASSERT_STRCASENE("hola", "HELLO");
}

TEST(TestCaseName, TestFour) {
	ASSERT_THROW(throw myex, myexception);
	ASSERT_ANY_THROW(throw 1);
	ASSERT_NO_THROW(1 + 2);
}

TEST(TestCaseName, TestFive) {
	ASSERT_FLOAT_EQ(1.0f, 1.0f);
	ASSERT_DOUBLE_EQ(2.5, 2.5);
	ASSERT_NEAR(1.95, 2.0, 0.1);
}

