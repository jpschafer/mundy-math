#ifndef MUNDY_MATH_LIBRARY_H
#define MUNDY_MATH_LIBRARY_H
#include "Result.h"
#include <string>
#include <iostream>


// NOTICE: ALL OCTAL AND BINARY TYPES ARE ASSUMED TO BE INTEGER EQUIVALENTS IN THEIR BASE!
using namespace std;

const static string BINARY_PREFIX = "0b";

	class MundyMath {
	public:
		// Trying to be clever on input types doesn't work out great when
		// you need your return type to be "fluid". It's easier for me to just permutate
		// these and then treat the return type more generically for conversion purposes.
		/**
		 * Adds two double operands
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Addition
		 */
		static Result<int> add(int a, int b);
		static Result<double> add(int a, double b);
		static Result<int> add(int a, string b);
		static Result<double> add(double a, double b);
		static Result<double> add(double a, int b);
		static Result<double> add(double a, string b);
		static Result<int> add(string a, string b);
		static Result<int> add(string a, int b);
		static Result<double> add(string a, double b);

		/**
		 * Subtracts two double operands
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Subtraction
		 */
		static Result<int> subtract(int a, int b);
		static Result<double> subtract(int a, double b);
		static Result<int> subtract(int a, string b);
		static Result<double> subtract(double a, double b);
		static Result<double> subtract(double a, int b);
		static Result<double> subtract(double a, string b);
		static Result<int> subtract(string a, string b);
		static Result<int> subtract(string a, int b);
		static Result<double> subtract(string a, double b);


		/**
		 * Multiplies two double operands.
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Multiplication
		 */
		static Result<int> multiply(int a, int b);
		static Result<double> multiply(int a, double b);
		static Result<int> multiply(int a, string b);
		static Result<double> multiply(double a, double b);
		static Result<double> multiply(double a, int b);
		static Result<double> multiply(double a, string b);
		static Result<int> multiply(string a, string b);
		static Result<int> multiply(string a, int b);
		static Result<double> multiply(string a, double b);


		/**
		 * Divides two double operands.
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Division
		 */
		static Result<int> divide(int a, int b);
		static Result<double> divide(int a, double b);
		static Result<int> divide(int a, string b);
		static Result<double> divide(double a, double b);
		static Result<double> divide(double a, int b);
		static Result<double> divide(double a, string b);
		static Result<int> divide(string a, string b);
		static Result<int> divide(string a, int b);
		static Result<double> divide(string a, double b);

		static int convertToInteger(string a);
		/**
		 * Calculates Square Root of operand
		 * @param Operand
		 * @return Result of Square Root
		 */
		static Result<int> squareRoot(int a);
		static Result<double> squareRoot(double a);
		static Result<int> squareRoot(string a);

		/**
		 * Exponentiates the given Operand with the given Power
		 * Only supports positive and negative integer powers
		 * @param a Operand
		 * @param b Power to Exponentiate
		 * @return Result of Square Root
		 */
		static Result<int> power(int a, int b);
		static Result<double> power(double a, int b);
		static Result<int> power(string a, int b);
		
	};

#endif //MUNDY_MATH_LIBRARY_H
