#ifndef RESULT_H
#define RESULT_H

#include <string>
#include <sstream>
#include <type_traits>
#include <iostream>

using namespace std;

template <typename T>
class Result {
public:
	T originalResult;

	Result(T originalResult) {
		this->originalResult = originalResult;
	}

	Result(string stringNum) {
		this->originalResult = convertToInteger(stringNum);
	}

	T getResult() {
		return originalResult;
	};
	
	string toBinary() {
		int n = originalResult;
		
		int remainder; 
		long binary = 0, i = 1;
   
		while(n != 0) {
			remainder = n%2;
			n = n/2;
			binary = binary + (remainder*i);
			i = i*10;
		}
		return addSuffix(to_string(binary), "0b");
	};
	
	string toOctal() {
		int n = originalResult;

		int remainder;
		long octal = 0, i = 1;

		while(n != 0) {
			remainder = n%8;
			n = n/8;
			octal = octal + (remainder*i);
			i = i*10;
		}
		return addSuffix(to_string(octal), "0");
	};
	
	string toHexadecimal() {
		// Convert to int first!
		int a = originalResult;

		stringstream stream;
		if (a < 0) {
			stream << "-0x" << std::hex << -a;
		} else {
			stream << "0x" << std::hex << a;
		}

  		return stream.str();
	};

	
	int toInteger() {
		return originalResult;
	};
	
	double toDouble() {
		return originalResult;
	};

	int convertToInteger(string a) {
		if (a[0] == '0' && a[1] == 'b') {
			a.erase(0, 2);
			a.erase(0, min(a.find_first_not_of('0'), a.size() - 1));

			return std::stoi(a, 0, 2);
		} else if (a[0] == '-' && a[1] == '0' && a[2] == 'b') {
			a.erase(1, 2);
			a.erase(1, min(a.find_first_not_of('0'), a.size() - 1));

			return std::stoi(a, 0, 2);
		} else {
				return std::stoi(a, nullptr, 0);
		}
	}

	bool isStringBased() {
		return std::is_same<T, string>::value;
	}

	string addSuffix(string num, string suffix) {
		if (num[0] == '-') {
			num.erase(0, 1);
			return "-" + suffix + num;
		} else {
			return suffix + num;
		}
	}
  
};

#endif //RESULT_H
