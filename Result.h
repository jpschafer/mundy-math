#include <string>
#include <type_traits>

template <typename T>

class Result {
public:
	T originalResult;
	int base; // For string types specifically
	
	Result() {   cout<<"Constructor Called"<<endl;   }
	
	T getResult() {
		return originalResult;
	};
	
	string toBinary() {
		T num = originalResult
		
		if (isStringBased) {
			num = std::stoi (originalResult, nullptr, 0);
		}
		
		int remainder; 
		long octal = 0, i = 1;
   
    while(n != 0) {
        remainder = n%8;
        n = n/8;
        octal = octal + (remainder*i);
        i = i*10;
    }
    return octal;
		
	};
	
	string toOctal();
	
	int toInteger() {
		if (isStringBased) {
		
		} else {
		
		}
	};
	
	double toDouble() {
		if (isStringBased) {
		
		} else {
		
		}
	};
	
	bool isStringBased() {
		return std::is_same<T, string>::value
	}
  
};
