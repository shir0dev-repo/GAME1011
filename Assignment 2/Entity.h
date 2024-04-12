#pragma once

#include <string>

class Entity
{
public:
	inline Entity() { m_name = ""; m_damage = 1; }
	Entity(std::string);

	std::string m_name;
	int m_damage;	
};

