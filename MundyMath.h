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

		static Result<int> subtract(int a, int b);
		static Result<double> subtract(int a, double b);
		static Result<int> subtract(int a, string b);
		static Result<double> subtract(double a, double b);
		static Result<double> subtract(double a, int b);
		static Result<double> subtract(double a, string b);
		static Result<int> subtract(string a, string b);
		static Result<int> subtract(string a, int b);
		static Result<double> subtract(string a, double b);

		static Result<int> multiply(int a, int b);
		static Result<double> multiply(int a, double b);
		static Result<int> multiply(int a, string b);
		static Result<double> multiply(double a, double b);
		static Result<double> multiply(double a, int b);
		static Result<double> multiply(double a, string b);
		static Result<int> multiply(string a, string b);
		static Result<int> multiply(string a, int b);
		static Result<double> multiply(string a, double b);

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

//		/**
//		 * Subtracts two double operands
//		 * @param a First Operand
//		 * @param b Second Operand
//		 * @return Result of Subtraction
//		 */
//		template <class T, class T2, class T3>
//		static Result<T3> subtract(T a, T2 b) {
//			T num1 = a;
//			T2 num2 = b;
//
//			if (std::is_same<T, string>::value) {
//				num1 = std::stoi(a, nullptr, 0);
//			}
//
//			if (std::is_same<T2, string>::value) {
//				num2 = num1 = std::stoi(a, nullptr, 0);
//			}
//
//			Result result = new Result<T3>(a - b);
//			return result;
//		}
//
//		/**
//		 * Multiplies two double operands.
//		 * @param a First Operand
//		 * @param b Second Operand
//		 * @return Result of Multiplication
//		 */
//		template <class T, class T2, class T3>
//		static Result<T3> multiply(T a, T2 b) {
//			T num1 = a;
//			T2 num2 = b;
//
//			if (std::is_same<T, string>::value) {
//				num1 = std::stoi(a, nullptr, 0);
//			}
//
//			if (std::is_same<T2, string>::value) {
//				num2 = num1 = std::stoi(a, nullptr, 0);
//			}
//
//			Result result = new Result<T3>(a * b);
//			return result;
//		}
//
//		/**
//		 * Divides two double operands.
//		 * @param a First Operand
//		 * @param b Second Operand
//		 * @return Result of Division
//		 */
//		template <class T, class T2, class T3>
//		static Result<T3> divide(T a, T2 b) {
//			T num1 = a;
//			T2 num2 = b;
//
//			if (std::is_same<T, string>::value) {
//				num1 = std::stoi(a, nullptr, 0);
//			}
//
//			if (std::is_same<T2, string>::value) {
//				num2 = num1 = std::stoi(a, nullptr, 0);
//			}
//
//			Result result = new Result<T3>(a / b);
//			return result;
//		}
//
////		/**
////		 * Calculates Square Root of operand
////		 * @param Operand
////		 * @return Result of Square Root
////		 */
////		template <class T, class T2, class T3>
////		static double squareRoot(T a);
////
////		/**
//		 * Exponentiates the given Operand with the given Power
//		 * @param a Operand
//		 * @param b Power to Exponentiate
//		 * @return Result of Square Root
//		 */
//		template <class T, class T2, class T3>
//		static double power(T a, int b);
		
	};

#endif //MUNDY_MATH_LIBRARY_H
