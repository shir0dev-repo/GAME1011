#pragma once

#include <ostream>
#include <tuple>
#include <string>
#include "PropertyImpl.h"

struct Dialog
{
	Dialog();
	Dialog(std::string, std::string);

	std::string m_Speaker;
	std::string m_Text;

	inline friend std::ostream& operator<<(std::ostream& os, const Dialog& d)
	{
		os << d.m_Speaker << ':' << std::endl;
		os << d.m_Text << std::endl;

		return os;
	}

	inline bool operator==(const Dialog& other) const {
		return m_Speaker == other.m_Speaker && m_Text == other.m_Text;
	}

	constexpr static auto properties = std::make_tuple(
		property(&Dialog::m_Speaker, "m_Speaker"),
		property(&Dialog::m_Text, "m_Text")
	);
};

