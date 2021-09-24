#include "MundyMath.h"
#include "Result.h"

Result<int> MundyMath::add(int a, int b) {
	int r = a + b;
	Result<int> result(r);
	return result;
}

Result<double> MundyMath::add(int a, double b) {
	double r = a + b;
	Result<double> result(r);
	return result;
}

Result<int> MundyMath::add(int a, string b) {
	int n = convertToInteger(b);
	return add(a, n);
}

Result<double> MundyMath::add(double a, double b) {
	double r = a + b;
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

//Subtract
Result<int> MundyMath::subtract(int a, int b) {
	int r = a - b;
	Result<int> result(r);
	return result;
}

Result<double> MundyMath::subtract(int a, double b) {
	double r = a - b;
	Result<double> result(r);
	return result;
}

Result<int> MundyMath::subtract(int a, string b) {
	int n = convertToInteger(b);
	return subtract(a, n);
}

Result<double> MundyMath::subtract(double a, double b) {
	double r = a - b;
	Result<double> result(r);
	return result;
}

Result<double> MundyMath::subtract(double a, int b) {
	return subtract(b, a);
}

Result<double> MundyMath::subtract(double a, string b) {
	int n = convertToInteger(b);
	return subtract(a, n);
}

Result<int> MundyMath::subtract(string a, string b) {
	int na = convertToInteger(a);
	int nb = convertToInteger(b);
	return subtract(na, nb);
}

Result<int> MundyMath::subtract(string a, int b) {
	return subtract(b, a);
}

Result<double> MundyMath::subtract(string a, double b) {
	return subtract(b, a);
}

// Multiply
Result<int> MundyMath::multiply(int a, int b) {
	int r = a * b;
	Result<int> result(r);
	return result;
}

Result<double> MundyMath::multiply(int a, double b) {
	double r = a * b;
	Result<double> result(r);
	return result;
}

Result<int> MundyMath::multiply(int a, string b) {
	int n = convertToInteger(b);
	return multiply(a, n);
}

Result<double> MundyMath::multiply(double a, double b) {
	double r = a * b;
	Result<double> result(r);
	return result;
}

Result<double> MundyMath::multiply(double a, int b) {
	return multiply(b, a);
}

Result<double> MundyMath::multiply(double a, string b) {
	double n = convertToInteger(b);
	return multiply(a, n);
}

Result<int> MundyMath::multiply(string a, string b) {
	int na = convertToInteger(a);
	int nb = convertToInteger(b);
	return multiply(na, nb);
}

Result<int> MundyMath::multiply(string a, int b) {
	return multiply(b, a);
}

Result<double> MundyMath::multiply(string a, double b) {
	return multiply(b, a);
}

// Divide
Result<int> MundyMath::divide(int a, int b) {
	int r = a / b;
	Result<int> result(r);
	return result;
}

Result<double> MundyMath::divide(int a, double b) {
	double r = a / b;
	Result<double> result(r);
	return result;
}

Result<int> MundyMath::divide(int a, string b) {
	int n = convertToInteger(b);
	return divide(a, n);
}

Result<double> MundyMath::divide(double a, double b) {
	double r = a / b;
	Result<double> result(r);
	return result;
}

Result<double> MundyMath::divide(double a, int b) {
	return divide(b, a);
}

Result<double> MundyMath::divide(double a, string b) {
	int n = convertToInteger(b);
	return divide(a, n);
}

Result<int> MundyMath::divide(string a, string b) {
	int na = convertToInteger(a);
	int nb = convertToInteger(b);
	return divide(na, nb);
}

Result<int> MundyMath::divide(string a, int b) {
	return divide(b, a);
}

Result<double> MundyMath::divide(string a, double b) {
	return divide(b, a);
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
double MundyMath::squareRoot(double a) {

	if (a == 0 || a == 1) {
		return a;
	}

	int result = 1;
	int lastAcceptedResult = 1;
	for (int i = 0; result <= a; i++) {
		result=i*i;

		// Handle where a may go over for partial Square Roots, we are just going to floor.
		if (result <= a) {
			lastAcceptedResult = i;
		}
	}
	return lastAcceptedResult;
}

double MundyMath::power(double a, int b) {
	double c = a;
	for (int i = 1; i < abs(b); i++) {
		c *= a;
	}

	if (b < 0) {
		return 1/c;
	} else {
		return c;
	}
}

int MundyMath::squareRoot(int a) {

	if (a == 0 || a == 1) {
		return a;
	}

	int result = 1;
	int lastAcceptedResult = 1;
	for (int i = 0; result <= a; i++) {
		result=i*i;

		// Handle where a may go over for partial Square Roots, we are just going to floor.
		if (result <= a) {
			lastAcceptedResult = i;
		}
	}
	return lastAcceptedResult;
}

int MundyMath::power(int a, int b) {
	int c = a;

	for (int i = 1; i < abs(b); i++) {
		c *= a;
	}

	if (b < 0) {
		std::cout << c;
		return 1/c;
	} else {
		return c;
	}
}

