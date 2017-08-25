#include "gtest/gtest.h"
#include "scanner.h"
#include <iostream>

using namespace std;

using ::testing::InitGoogleTest;
using ::testing::EmptyTestEventListener;
using ::testing::UnitTest;
using ::testing::TestEventListeners;
using ::testing::ValuesIn;

class EventListener : public EmptyTestEventListener {
public:
	// Probar que al final se haya liberado la memoria
	virtual void OnTestProgramEnd(const UnitTest& unit_test) {
		ASSERT_EQ(Scanner::count, 0);
		if (Scanner::count == 0)
			cout << "Memoria liberada correctamente." << endl;
	}
};

class TestScanner : public ::testing::TestWithParam<int> {
public:
	Scanner* s;
	void SetUp() {
		s = new Scanner();
	}
	void TearDown() {
		delete s;
	}
};

int ports[] = {3306, 53, 80, 443, 53, 68, 13283, 34026}; // Puertos abiertos
INSTANTIATE_TEST_CASE_P(puertos, TestScanner, ValuesIn(ports));

TEST_P(TestScanner, testPort) {
	ASSERT_TRUE(s->testPort(GetParam()));
}

int main(int argc, char** argv) {
	InitGoogleTest(&argc, argv);

	TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
	listeners.Append(new EventListener);

	return RUN_ALL_TESTS();
}
