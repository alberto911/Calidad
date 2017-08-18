#include <iostream>
using namespace std;

class Sort {
public:
	virtual void sort(int a[], int n) = 0;
};

class BubbleSort : public Sort {
public:
	void sort(int a[], int n) {
		bool swapped = true;
		int j = 0;

		while (swapped) {
			swapped = false;
			j++;
			for (int i = 0; i < n - j; ++i) {
				if (a[i] > a[i + 1]) {
					swap(a[i], a[i + 1]);
					swapped = true;
				}
			}
		}
	}
};

class InsertionSort : public Sort {
public:
	void sort(int a[], int n) {
		for (int i = 1; i < n; ++i) {
			for (int j = i; j > 0 && a[j - 1] > a[j]; --j)
				swap(a[j], a[j - 1]);
		}
	}
};

class SelectionSort : public Sort {
public:
	void sort(int a[], int n) {
		for (int i = 0; i < n-1; ++i) {
			int min = i;
			for (int j = i+1; j < n; ++j) {
				if (a[j] < a[min])
					min = j;
			}
		
			if (min != i)
				swap(a[i], a[min]);
		}
	}
};
