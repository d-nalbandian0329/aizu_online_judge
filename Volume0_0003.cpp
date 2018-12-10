#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


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


void inputData(vector<string>& data_set) {
	string buffer;

	getline(cin, buffer);
	int n = convertStringToNumber<int>(buffer);

	for(int i = 0; i < n; ++i) {
		getline(cin, buffer);
		data_set.push_back(buffer);
	}
}

bool isRightTriangle(const vector<int>& edge_set) {
	int max_index = 0;

	if(edge_set[max_index] < edge_set[(max_index+1)%3])
		max_index = (max_index+1)%3; 
	if(edge_set[max_index] < edge_set[(max_index+2)%3])
		max_index = (max_index+2)%3; 

	return ((edge_set[max_index] * edge_set[max_index]) ==
				(edge_set[(max_index+1)%3] * edge_set[(max_index+1)%3]
				+ edge_set[(max_index+2)%3] * edge_set[(max_index+2)%3]));
}


vector<bool> evaluateTriangle(const vector<string>& data_str) {
	vector<bool> ret(data_str.size());

	for(int i = 0; i < data_str.size(); ++i) {
		auto temp = splitString(data_str[i]);
		vector<int> buff { convertStringToNumber<int>(temp[0]),
							convertStringToNumber<int>(temp[1]),
							convertStringToNumber<int>(temp[2])};

		ret[i] = isRightTriangle(buff);
	}

	return ret;
}


void doAllProcess() {
	vector<string> buffer;

	inputData(buffer);

	vector<bool> ret = evaluateTriangle(buffer);

	for(int i = 0; i < ret.size(); ++i)
		std::cout << (ret[i] ? "YES" : "NO") << std::endl;
}



int main() {
	doAllProcess();

	return 0;
}
