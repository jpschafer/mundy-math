class Result {
public:
	T originalResult;
	Result() {   cout<<"Constructor Called"<<endl;   }
	
	T getResult();
	string toBinary();
	string toOctal();
	int toInteger();
	double toDouble();
  
};
