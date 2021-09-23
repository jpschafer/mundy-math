#ifndef MUNDY_MATH_LIBRARY_H
#define MUNDY_MATH_LIBRARY_H
#include "Result.h"

using namespace std;

	class MundyMath {
	public:

		/**
		 * Adds two double operands
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Addition
		 */
		template <class T, class T2, class T3>
		static Result<T3> add(T a, T2 b) {
			T num1 = a;
			T2 num2 = b;

			if (std::is_same<T, string>::value) {
				num1 = std::stoi(a, nullptr, 0);
			}

			if (std::is_same<T2, string>::value) {
				num2 = num1 = std::stoi(a, nullptr, 0);
			}

			string numResult = a + b;

			Result result = new Result<T3>(numResult);
			return result;
		}

		/**
		 * Subtracts two double operands
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Subtraction
		 */
		template <class T, class T2, class T3>
		static Result<T3> subtract(T a, T2 b) {
			T num1 = a;
			T2 num2 = b;

			if (std::is_same<T, string>::value) {
				num1 = std::stoi(a, nullptr, 0);
			}

			if (std::is_same<T2, string>::value) {
				num2 = num1 = std::stoi(a, nullptr, 0);
			}

			Result result = new Result<T3>(a - b);
			return result;
		}

		/**
		 * Multiplies two double operands.
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Multiplication
		 */
		template <class T, class T2, class T3>
		static Result<T3> multiply(T a, T2 b) {
			T num1 = a;
			T2 num2 = b;

			if (std::is_same<T, string>::value) {
				num1 = std::stoi(a, nullptr, 0);
			}

			if (std::is_same<T2, string>::value) {
				num2 = num1 = std::stoi(a, nullptr, 0);
			}

			Result result = new Result<T3>(a * b);
			return result;
		}

		/**
		 * Divides two double operands.
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Division
		 */
		template <class T, class T2, class T3>
		static Result<T3> divide(T a, T2 b) {
			T num1 = a;
			T2 num2 = b;

			if (std::is_same<T, string>::value) {
				num1 = std::stoi(a, nullptr, 0);
			}

			if (std::is_same<T2, string>::value) {
				num2 = num1 = std::stoi(a, nullptr, 0);
			}

			Result result = new Result<T3>(a / b);
			return result;
		}
		
//		/**
//		 * Calculates Square Root of operand
//		 * @param Operand
//		 * @return Result of Square Root
//		 */
//		template <class T, class T2, class T3>
//		static double squareRoot(T a);
//
//		/**
//		 * Exponentiates the given Operand with the given Power
//		 * @param a Operand
//		 * @param b Power to Exponentiate
//		 * @return Result of Square Root
//		 */
//		template <class T, class T2, class T3>
//		static double power(T a, int b);
		
	};

#endif //MUNDY_MATH_LIBRARY_H
