#include "MundyMath.h"
#include "Result.h"

Result<int> MundyMath::add(int a, int b) {
	int r = a + b;
	Result<int> result(r);
	return result;
}

Result<double> MundyMath::add(int a, double b) {
	int r = a + b;
	Result<double> result(r);
	return result;
}

Result<int> MundyMath::add(int a, string b) {
	int n = convertToInteger(b);
	return add(a, n);
}

Result<double> MundyMath::add(double a, double b) {
	int r = a + b;
	Result<double> result(r);
	return result;
}

Result<double> MundyMath::add(double a, int b) {
	return add(b, a);
}

Result<double> MundyMath::add(double a, string b) {
	int n = convertToInteger(b);
	return add(a, n);
}

Result<int> MundyMath::add(string a, string b) {
	int na = convertToInteger(a);
	int nb = convertToInteger(b);
	return add(na, nb);
}

Result<int> MundyMath::add(string a, int b) {
	return add(b, a);
}

Result<double> MundyMath::add(string a, double b) {
	return add(b, a);
}

int MundyMath::convertToInteger(string a) {
	if (a[0] == '0' && a[1] == 'b') {
		a.erase(0, 2);
		a.erase(0, min(a.find_first_not_of('0'), a.size()-1));
		cout << a << "suh";

		return std::stoi(a, 0, 2);
	} else {
		return std::stoi(a, nullptr, 0);
	}
}
//double MundyMath::squareRoot(double a) {
//
//	if (a == 0 || a == 1) {
//		return a;
//	}
//
//	int result = 1;
//	int lastAcceptedResult = 1;
//	for (int i = 0; result <= a; i++) {
//		result=i*i;
//
//		// Handle where a may go over for partial Square Roots, we are just going to floor.
//		if (result <= a) {
//			lastAcceptedResult = result;
//		}
//	}
//	return result;
//}
//
//double MundyMath::power(double a, double b) {
//	int c = a;
//	for (int i; i < b; i++) {
//		c *= a;
//	}
//	return c;
//}

