#include "sort.h"
#include "gtest/gtest.h"
#include <iostream>
#include <cstdlib>

#define N 100

template <typename T>
class Fixture : public ::testing::Test {
public:
	void SetUp() {
		sortingMethod = new T;
		for (int i = 0; i < N; ++i) {
			a[i] = N - i; // Orden inverso
			sorted[i] = i + 1; // Ordenado
		}
	}
	void TearDown() {
		delete sortingMethod;
	}

	T* sortingMethod;
	int a[N];
	int sorted[N];
};

typedef ::testing::Types<BubbleSort, InsertionSort, SelectionSort> methods;
TYPED_TEST_CASE(Fixture, methods);

TYPED_TEST(Fixture, testSort) {
	this->sortingMethod->sort(this->a, N); // Ordenar arreglo
	for (int i = 0; i < N; ++i)
		ASSERT_EQ(this->a[i], this->sorted[i]); // Comparar que todos los elementos correspondan
}
