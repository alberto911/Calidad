#include "gtest/gtest.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::UnitTest;
using ::testing::TestEventListeners;
using ::testing::TestPartResult;
using ::testing::TestCase;
using ::testing::TestInfo;

class EventListener : public EmptyTestEventListener {
	ofstream myfile;
public:
	EventListener() {
		myfile.open("output.txt");
	}

	~EventListener() {
		myfile.close();
	}

	virtual void OnTestProgramStart(const UnitTest& unit_test) {
		myfile << "Iniciando test\n";
	}

	virtual void OnTestCaseStart(const TestCase& test_case) {
		myfile << "Test case: " << test_case.name() << endl;
	}

	virtual void OnTestStart(const TestInfo& test_info) {
		myfile << "Test name: " << test_info.name() << endl;
	}

	virtual void OnTestEnd(const TestInfo& test_info) {
		myfile << "El tiempo de ejecución de " << test_info.name() << " fue: " << test_info.result()->elapsed_time() << endl;
	}

	virtual void OnTestCaseEnd(const TestCase& test_case) {
		myfile << "El tiempo de ejecución de " << test_case.name() << " fue: " << test_case.elapsed_time() << endl;
	}

	virtual void OnTestProgramEnd(const UnitTest& unit_test) {
		myfile << "El número de tests ejecutado fue: " << unit_test.total_test_count() << endl;
		myfile << unit_test.successful_test_count() << " correctos\n";
		myfile << unit_test.failed_test_count() << " incorrectos\n";
	}

	virtual void OnTestPartResult(const TestPartResult& tpr) {
		if (tpr.failed()) {
			myfile << "Falla. Los detalles son los siguientes:\n";
			myfile << "\tLínea del error: " << tpr.line_number() << endl;
			string s (tpr.summary());
			size_t pos1 = s.find_first_of(":");
			size_t pos2 = s.find_first_of("\n");
			myfile << "\tValor actual" << s.substr(pos1, pos2-pos1) << endl;
			pos1 = s.find_last_of(":");
			myfile << "\tValor esperado" << s.substr(pos1) << endl;
		}
	}
};

TEST(TestCaseUno, Test1) {
	ASSERT_EQ(8,9);
}

TEST(TestCaseUno, Test2) {
	ASSERT_EQ(9,9);
}

int main(int argc, char** argv) {
	InitGoogleTest(&argc, argv);
	
	TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
	delete listeners.Release(listeners.default_result_printer());
	listeners.Append(new EventListener);

	return RUN_ALL_TESTS();
}
