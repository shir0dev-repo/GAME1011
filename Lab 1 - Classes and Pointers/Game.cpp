#pragma once

#include <iostream>
#include <string>
#include "Achievement.cpp"
using namespace std;

class Game {
private:
	int m_achievementCount = 0;

	void initialize(string name, string publisher, string developer) {
		m_name = name;
		m_publisher = publisher;
		m_developer = developer;
		m_achievementCount = 0;
	}

public:
	string m_name;
	string m_publisher;
	string m_developer;
	Achievement m_achievements[5];

	int AchievementCount() { return m_achievementCount; }

	void addAchievement(Achievement achievement) {
		if (m_achievementCount >= 5) {
			cout << "Max achievements reached.";
			return;
		}

		m_achievements[m_achievementCount++] = achievement;
	}

	void printSelf() {
		cout << "    " << "Name: " << m_name << endl;
		cout << "      " << "Publisher: " << m_publisher << endl;
		cout << "      " << "Developer: " << m_developer << endl;
		if (m_achievementCount <= 0) return;

		cout << "      Achievements:" << endl;
		for (int i = 0; i < m_achievementCount; i++) {
			m_achievements[i].printSelf();
		}
	}

	static Game createNew() {
		cout << "Creating game..." << endl;

		Game g;
		string name;
		string pub;
		string dev;

		cout << "Game name: " << endl;
		getline(cin, name);

		cout << "Game publisher: " << endl;
		getline(cin, pub);

		cout << "Game developer: " << endl;
		getline(cin, dev);

		g.initialize(name, pub, dev);
		cout << "Game created." << endl;
		return g;
	}
};