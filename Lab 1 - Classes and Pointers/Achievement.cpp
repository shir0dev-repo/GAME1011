#pragma once

#include <iostream>
#include <string>

using namespace std;

class Achievement {
private:
	void initialize(string title, string description, int scoreValue) {
		m_title = title;
		m_description = description;
		m_scoreValue = scoreValue;
	}

public:
	string m_title;
	string m_description;
	int m_scoreValue = 0;

	void printSelf() {
		cout << "        " << "Title: " << m_title << endl;
		cout << "          " << "Description: " << m_description << endl;
		cout << "          " << "Score value: " << m_scoreValue << endl;
	}

	static Achievement createNew() {
		cout << "Creating achievement..." << endl;

		Achievement a;
		string name;
		string desc;
		int scoreValue = 0;

		cout << "Achievement name: " << endl; 
		getline(cin, name);

		cout << "Achievement description: " << endl;
		getline(cin, desc);

		string valueIn;
		do {
			cout << "Score value: " << endl;
			getline(cin, valueIn);

			scoreValue = atoi(valueIn.c_str());
			if (scoreValue == 0) {
				cout << "Invalid value. Try again." << endl;
			}
		} while (scoreValue == 0);

		a.initialize(name, desc, scoreValue);
		cout << "Achievement created." << endl;
		return a;
	}
};