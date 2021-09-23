#include <string>

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
		if (isStringBased) {
		
		} else {
		
		}
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
		if (isStringBased) {
		
		} else {
		
		}
	}
  
};
