#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

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

vector<int> addDigits(const vector<string>& str_set) {
	vector<int> data_set(str_set.size());

	auto countDigits = [](const int num) -> int {
		int n = num, i;
		for(i = 0; n > 0; n/=10,++i);
		return i;
	};

	for(int i = 0; i < str_set.size(); ++i) {
		vector<string> temp = splitString(str_set[i], " ");
		data_set[i] = countDigits(convertStringToNumber<int>(temp[0])
									+ convertStringToNumber<int>(temp[1]));
	}

	return data_set;
}


void doAllProcess() {
	vector<string> buffer;

	inputData(buffer);

	auto ret = addDigits(buffer);

	for(auto&& e : ret)
		std::cout << e << std::endl;
}



int main() {
	doAllProcess();


	return 0;
}
