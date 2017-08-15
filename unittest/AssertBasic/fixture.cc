#include "gtest/gtest.h"
#include "pila.h"

class TestStack : public ::testing::Test {
public:
	Pila<int> mystack;
	void SetUp() {
		mystack.push(10);
		mystack.push(20);
	}
	void TearDown() {

	}
};

TEST_F(TestStack, pushTest) {
	mystack.push(30);
	mystack.push(40);
	EXPECT_EQ(mystack.size(), 4);
}

TEST_F(TestStack, popTest) {
	mystack.pop();
	mystack.pop();
	EXPECT_EQ(mystack.size(), 0);
}
