#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <utility>


using namespace std;


class Dice {
public:
	enum {
		FRONT = 0u, LEFT, TOP
	};
	
	Dice(uint8_t front = 2u, uint8_t left = 3u, uint8_t top = 1u) {
		value_[FRONT] = front;
		value_[LEFT]  = left;
		value_[TOP]   = top;
	}

	std::size_t getValue(const std::string& direction) const {
		if(direction == "Front")
			return value_[FRONT];
		else if(direction == "Left")
			return value_[LEFT];
		else if(direction == "Top")
			return value_[TOP];
	}

	void rollDice(const std::string& direction) {
		uint8_t top, front, left;

		if(direction == "North") {
			top = value_[FRONT];
			front = 7 - value_[TOP];
			value_[TOP] = top;
			value_[FRONT] = front;
		}
		else if(direction == "South"){
			top = 7 - value_[FRONT];
			front = value_[TOP];
			value_[TOP] = top;
			value_[FRONT] = front;
		}

		else if(direction == "East") {
			top = 7 - value_[LEFT];
			left = value_[TOP];
			value_[TOP] = top;
			value_[LEFT] = left;
		}
		else if(direction == "West") {
			top = value_[LEFT];
			left = 7 - value_[TOP];
			value_[TOP] = top;
			value_[LEFT] = left;
		}
		else if(direction == "Right") {
			front = value_[LEFT];
			left = 7 - value_[FRONT];
			value_[FRONT] = front;
			value_[LEFT] = left;
		}

		else if(direction == "Left") {
			front = 7 - value_[LEFT];
			left = value_[FRONT];
			value_[FRONT] = front;
			value_[LEFT] = left;
		}
	}

private:
	uint8_t value_[3];
};


template <class T>
T convertStringToNumber(const string& str) {
	stringstream ss;
	T ret;

	ss << str;
	ss >> ret;

	return ret;
}


vector<vector<string>> inputData() {
	vector<vector<string>> data_set;

	string buffer;

	while(true){
		getline(cin, buffer);
		int n = convertStringToNumber<int>(buffer);

		if(!n)
			break;

		vector<string> temp;
		for(int i = 0; i < n; ++i) {
			getline(cin, buffer);
			temp.push_back(buffer);
		}

		data_set.push_back(temp);
	}

	return data_set;
}



void doAllProcess() {
	auto data_set = inputData();

	for(int i = 0; i < data_set.size(); ++i) {
		Dice dice;
		std::size_t score = 1u;

		for(int j = 0; j < data_set[i].size(); ++j) {
			dice.rollDice(data_set[i][j]);
			score += dice.getValue("Top");;
		}

		cout << score << endl;
	}
}


int main() {
	doAllProcess();

	return 0;
}

