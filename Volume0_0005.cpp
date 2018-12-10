#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void inputData(vector<string>& data_set) {
	string buffer;
	while(getline(std::cin,buffer))
		data_set.push_back(buffer);
}

vector<string> splitString(const string& str, const string& separator = " ") {
	vector<string> ret;

	std::size_t bp, ep;
	bp = ep = 0;
	while((ep = str.find_first_of(separator, bp)) != string::npos){
		if(bp != ep){
			ret.push_back(string(str.begin() + bp, str.begin() + ep));
		}
		bp = ep + 1;
	}

	if(bp <= str.size() - 1){
		ret.push_back(string(str.begin() + bp, str.end()));
	}

	return ret;
}

template <class T>
T convertStringToNumber(const string& str) {
	stringstream ss;
	T ret;

	ss << str;
	ss >> ret;

	return ret;
}



vector<int> parseStringData(const string& data_str) {
	auto buff = splitString(data_str);

	vector<int> ret(buff.size());
	for(int i = 0; i < buff.size(); ++i){
		auto temp = convertStringToNumber<int>(buff[i]);
		ret[i] = temp;
	}

	return ret;
}


int calcGCD(int a, int b) {
	return (a % b == 0) ? b : calcGCD(b, a%b);
}


void displayAnswer(int a, int b) {
	int gcd = calcGCD(a, b);
	int lcm = gcd * (a/gcd) * (b/gcd);
	std::cout << gcd << " " << lcm << std::endl;
}


void doAllProcess() {
	vector<string> buffer;
	inputData(buffer);

	for(int i = 0; i < buffer.size(); ++i){
		auto data_set = parseStringData(buffer[i]);

		int a, b;
		if(data_set[0] > data_set[1]) {
			a = data_set[0];
			b = data_set[1];
		}
		else {
			a = data_set[1];
			b = data_set[0];
		}

		displayAnswer(a, b);
	}
}


int main() {
	doAllProcess();

	return 0;
}
