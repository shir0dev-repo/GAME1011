#pragma once

#include <iostream>
#include <fstream>
#include "Jsonify.h"

template<class C>
bool Save(const char directory[], C& object) {
	std::ofstream file(directory, std::ios::out | std::ios::binary);

	file.write((char*)&object, sizeof(object));
	file.close();

	return file.good();
}

bool SaveRaw(const char directory[], std::string content) {
	std::ofstream file(directory, std::ios::out);

	file.write(content.c_str(), content.size());
	file.close();

	return file.good();
}

template<class C>
C Load(const char directory[]) {
	std::ifstream file(directory, std::ios::out | std::ios::binary);
	
	C object;
	file.read((char*)&object, sizeof(C));
	file.close();

	return object;
}