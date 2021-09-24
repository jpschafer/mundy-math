#ifndef RESULT_H
#define RESULT_H

#include <string>
#include <sstream>
#include <type_traits>

using namespace std;

template <typename T>
class Result {
public:
	T originalResult;
	int base; // For string types specifically

	Result(T originalResult) {
		this->originalResult = originalResult;
	}
	
	T getResult() {
		return originalResult;
	};
	
	string toBinary() {
		T n = originalResult;
		
		if (isStringBased()) {
			n = std::stoi (originalResult, nullptr, 0);
		}
		
		int remainder; 
		long binary = 0, i = 1;
   
		while(n != 0) {
			remainder = n%2;
			n = n/2;
			binary = binary + (remainder*i);
			i = i*10;
		}
		return "0b" + to_string(binary);
	};
	
	string toOctal() {
		T n = originalResult;

		if (isStringBased()) {
			n = std::stoi (originalResult, nullptr, 0);
		}

		int remainder;
		long octal = 0, i = 1;

		while(n != 0) {
			remainder = n%8;
			n = n/8;
			octal = octal + (remainder*i);
			i = i*10;
		}
		return "0" + to_string(octal);
	};
	
	string toHexadecimal() {
		// Convert to int first!
		int a = originalResult
		std::stringstream stream;
		stream << "0x" 
		//<< std::setfill ('0') << std::setw(sizeof(T)*2) 
		<< std::hex << a;
  		return stream.str();
	};
	
	int toInteger() {
		if (isStringBased()) {
			return std::stoi (originalResult, nullptr, 0);
		} else {
			return originalResult;
		}
	};
	
	double toDouble() {
		if (isStringBased()) {
			return std::stoi (originalResult, nullptr, 0);
		} else {
			return originalResult;
		}
	};
	
	bool isStringBased() {
		return std::is_same<T, string>::value;
	}
  
};

#endif //RESULT_H
