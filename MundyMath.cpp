#include "MundyMath.h"

double MundyMath::add(double a, double b) {
	return a + b;
}

double MundyMath::subtract(double a, double b) {
	return a - b;
}

double MundyMath::multiply(double a, double b) {
	return a * b;
}

double MundyMath::divide(double a, double b) {
	return a / b;
}

double MundyMath::squareRoot(double a) {
	
	if (a == 0 || a == 1) {
		return a;
	}
	
	int result = 1;
	for (int i = 0; result <= a; i++) {
		result=i*i;
	}
	return result;
}

double MundyMath::power(double a, double b) {
	int c = a;
	for (int i; i < b; i++) {
		c *= a
	}
	return c; 
}

