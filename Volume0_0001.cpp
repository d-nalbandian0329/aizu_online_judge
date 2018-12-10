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

template <class T>
T convertStringToNumber(const string& str) {
	stringstream ss;
	T ret;

	ss << str;
	ss >> ret;

	return ret;
}


void doAllProcess() {
	vector<string> buffer;
	vector<int> data_set;

	inputData(buffer);

	data_set.resize(buffer.size());
	for(int i = 0; i < buffer.size(); ++i)
		data_set[i] = convertStringToNumber<int>(buffer[i]);

	sort(data_set.begin(), data_set.end(), [](int n1, int n2){ return n1>=n2; });

	std::cout << data_set[0] << std::endl;
	std::cout << data_set[1] << std::endl;
	std::cout << data_set[2] << std::endl;
}


int main() {
	doAllProcess();

	return 0;
}
