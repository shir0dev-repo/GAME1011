#pragma once

#include <iostream>
#include <string>
#include "Game.cpp"
using namespace std;

class Platform {
private:
	int m_gamesCount = 0;

	void initialize(string name, string manufacturer) {
		m_name = name;
		m_manufacturer = manufacturer;
		m_gamesCount = 0;
	}

public:
	string m_name;
	string m_manufacturer;
	Game m_games[5];

	int GameCount() { return m_gamesCount; }

	void addGame(Game game) {
		if (m_gamesCount >= 5) {
			cout << "Max games reached." << endl;
			return;
		}

		m_games[m_gamesCount++] = game;
	}

	void printSelf() {
		cout << "Name: " << m_name << endl;
		cout << "  Manufacturer: " << m_manufacturer << endl;
		if (m_gamesCount <= 0) return;

		cout << "  Games:" << endl;
		for (int i = 0; i < m_gamesCount; i++) {
			m_games[i].printSelf();
		}
	}

	static Platform createNew() {
		cout << "Creating platform..." << endl;

		Platform p;
		string name, manufacturer;

		cout << "Platform name: " << endl;
		getline(cin, name);

		cout << "Platform manufacturer: " << endl;
		getline(cin, manufacturer);

		p.initialize(name, manufacturer);

		cout << "Platform created." << endl;
		return p;
	}
};