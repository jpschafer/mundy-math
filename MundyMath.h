#ifndef MUNDY_MATH_LIBRARY_H
#define MUNDY_MATH_LIBRARY_H

	class MundyMath {
	public:

		/**
		 * Adds two double operands
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Addition
		 */
		static double add(double a, double b);

		/**
		 * Subtracts two double operands
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Subtraction
		 */
		static double subtract(double a, double b);

		/**
		 * Multiplies two double operands.
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Multiplication
		 */
		static double multiply(double a, double b);

		/**
		 * Divides two double operands.
		 * @param a First Operand
		 * @param b Second Operand
		 * @return Result of Division
		 */
		static double divide(double a, double b);
	};

#endif //MUNDY_MATH_LIBRARY_H
