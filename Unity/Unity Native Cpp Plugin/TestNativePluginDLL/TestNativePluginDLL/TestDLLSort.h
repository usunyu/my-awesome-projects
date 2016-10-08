#define TESTDLLSORT_API __declspec(dllexport) 

extern "C" {
	TESTDLLSORT_API void TestSort(int a[], int length);
}