#include "TestDLLSort.h"
#include <algorithm>

extern "C" {
	void TestSort(int a[], int length) {
		std::sort(a, a + length);
	}
}