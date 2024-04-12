#include <iostream>
#include <string>
#include <map>
#include <tuple>

#include "Jsonify.h"
#include "Dialog.h"
#include "SaveLoad.h"
#include "Entity.h"
#include "ConsoleCommand.h"

int main()
{
	Commands::ConsoleCommand<int, int, int> addcmd;
	std::function<int(int, int)> addF([&](int i, int j) -> int { return i + j; });
	addcmd.Init("add", addF);

	Commands::ConsoleCommand<std::string, std::string, char> appendcmd;
	std::function<std::string(std::string, char)> appendF([&](std::string s, char c) -> std::string { s.push_back(c); return s; });
	appendcmd.Init("append", appendF);

	std::string input;
	std::getline(std::cin, input);

	if (input == "add") {
		std::cin >> input;
		int i = std::stoi(input);
		std::cin >> input;
		int i2 = std::stoi(input);

		std::cout << addcmd.Run(i, i2);
	}

	std::string s = "Robert JSON Oppenheimer";	
	std::string t = "now I am become JSON, parser of text.";

	Dialog d(s, t);
	Json::Value dialogJSON = toJson(d);
	std::string dir = "entity.bin";
	Entity e("mynama");
	Save(dir.c_str(), e);
	SaveRaw("dialog.json", dialogJSON.data.jsonString.c_str());
	auto e2 = Load<Entity>(dir.c_str());
}