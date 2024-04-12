#include <iostream>
#include <string>
#include "Achievement.cpp"
#include "Game.cpp"
#include "Platform.cpp"
using namespace std;

Platform platforms[5];
int platformCount = 0;

string addPlatformCmd = "addplatform";
string addGameCmd = "addgame";
string addAchievementCmd = "addachievement";
string listAllCmd = "listall";

void helpCmd() {
	cout << '\n';
	cout << addPlatformCmd << endl;
	cout << addGameCmd << endl;
	cout << addAchievementCmd << endl;
	cout << listAllCmd << endl;
}

void addPlatform() {
	if (platformCount >= 5) {
		cout << "Maximum platforms reached!" << endl;
		return;
	}

	platforms[platformCount++] = Platform::createNew();
}

Platform* findPlatform(string platformName) {
	for (int i = 0; i < platformCount; i++) {
		if (platformName == platforms[i].m_name) {
			return &platforms[i];
		}
	}

	cout << "Platform could not be found." << endl;
	return nullptr;
}

void addGame() {
	string str;
	cout << "Please specify a platform: " << endl;
	getline(cin, str);

	Platform* platPtr = findPlatform(str);
	if (platPtr == nullptr) {
		delete platPtr;
		return;
	}
	else if (platPtr->GameCount() >= 5) {
		cout << "Game could not be added.";
		delete platPtr;
		return;
	}

	platPtr->addGame(Game::createNew());
}

Game* findGame(string gameName) {
	for (int i = 0; i < platformCount; i++) {
		for (int j = 0; j < platforms[i].GameCount(); j++) {
			if (gameName == platforms[i].m_games[j].m_name) {
				return &platforms[i].m_games[j];
			}
		}
	}

	cout << "Game could not be found." << endl;
	return nullptr;
}

void addAchievement() {
	string str;
	cout << "Please specify a game: " << endl;
	getline(cin, str);

	Game* gPtr = findGame(str);

	if (gPtr == nullptr) {
		delete gPtr;
		return;
	}
	else if (gPtr->AchievementCount() >= 5) {
		cout << "Achievement could not be added." << endl;
		delete gPtr;
		return;
	}
	
	gPtr->addAchievement(Achievement::createNew());
}

void listAll() {
	cout << "\n\n";
	for (int i = 0; i < platformCount; i++)
		platforms[i].printSelf();

	cout << "\n\n";
}

int main() {

	cout << "Please create a platform to begin." << endl;
	addPlatform();

	string str;
	for (;;) {
		cout << "what would you like to do? (help for commands)" << endl;
		getline(cin, str);

		if (str == "help")
			helpCmd();
		else if (str == addPlatformCmd)
			addPlatform();
		else if (str == addGameCmd)
			addGame();
		else if (str == addAchievementCmd)
			addAchievement();
		else if (str == listAllCmd)
			listAll();
		else
			cout << "Please enter a valid command!" << endl;
	}
}