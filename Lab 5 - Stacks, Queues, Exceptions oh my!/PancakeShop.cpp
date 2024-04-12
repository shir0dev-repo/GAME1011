#include <iostream>
#include <Windows.h>

#include "PancakeShop.h"
#include "OutOfPancakeException.h"

PancakeShop::PancakeShop(size_t customerLineup) {
	for (int i = 1; i <= customerLineup; i++) {
		m_customerQueue.push(i);
	}	
	
	m_profit = 0.0f;
	m_bakingProgress = 0.0f;
	m_currentCustomerID = 0;

	std::cout << "Open for business!" << std::endl;
}

void PancakeShop::Close() {
	ClearScreen();
	DisplayFinalStats();
}

void PancakeShop::DisplayStats() {
	std::cout << "Open for business!" << std::endl << std::endl;

	std::cout << "Available pancakes: " << m_pancakeStack.size() << std::endl;
	std::cout << "Total profit: $" << FormatPrecision(m_profit) << std::endl;
	std::cout << "Customers remaining: " << m_customerQueue.size() << std::endl;
}

void PancakeShop::DisplayFinalStats() {
	std::cout << "Closed for the day!" << std::endl << std::endl;

	std::cout << "Customers served: " << m_currentCustomerID << std::endl;
	std::cout << "Pancakes sold: " << int(m_profit / _PANCAKE_COST) << " pancakes" << std::endl;
	std::cout << "Total profit: $" << FormatPrecision(m_profit) << std::endl;
}

void PancakeShop::BakePancakes() {
	std::cout << "Started baking pancakes..." << std::endl;
	while (m_bakingProgress <= 1.1f) {
		std::cout << DisplayBakingProgress() << '\r';
		m_bakingProgress += 0.1f;
		Sleep(100);
		std::cout.flush();
	}

	std::cout << std::endl;

	m_bakingProgress = 0;
	for (int i = 0; i < 5; i++)
		m_pancakeStack.push(1);
	
	std::cout << "Baked 5 pancakes! Total in stack: " << m_pancakeStack.size() << std::endl << std::endl;
}

void PancakeShop::TakeOrder() {
	m_currentCustomerID = m_customerQueue.front();
	std::cout << "Customer " << m_customerQueue.front() << ": " << "lemme get uhh";
	int p = 0;
	while (p < 3) {
		std::cout << '.';	
		Sleep(500);
		p++;
	}

	int orderSize = rand() % 3 + 1;
	std::cout << ' ' << orderSize << " pancakes please!" << std::endl << std::endl;
	Sleep(500);

	try {
		SellPancakes(orderSize);
	}
	catch (OutOfPancakeException e) {
		std::cout << e.what() << std::endl;
		BakePancakes();
		SellPancakes(orderSize);
	}

	m_customerQueue.pop();
}

bool PancakeShop::SellPancakes(int& orderSize) throw() {
	if (orderSize > m_pancakeStack.size()) {
		throw OutOfPancakeException();
	}
	else {
		for (int i = 0; i < orderSize; i++) {
			m_pancakeStack.pop();
		}
		std::cout << "You made $" << FormatPrecision(_PANCAKE_COST * orderSize) << '!' << std::endl;
		m_profit += _PANCAKE_COST * orderSize;
		return true;
	}
}


std::string PancakeShop::DisplayBakingProgress() {	
	const int BAR_WIDTH = 70;
	std::string prgStr = "";
	
	prgStr.push_back('[');

	int pos = BAR_WIDTH * m_bakingProgress;

	for (int i = 0; i < BAR_WIDTH; i++) {
		if (i < pos) prgStr.push_back('=');
		else prgStr.push_back('-');
	}
	prgStr.push_back(']');
	float value = m_bakingProgress * 100.0;
	prgStr.append(" Baking Progress: " + FormatPrecision(value));
	if (value > 99)
		prgStr.append("% - Done!   ");
	else
		prgStr.append("% - Baking...");


	return prgStr;
}

std::string PancakeShop::FormatPrecision(float value) {
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << value;
	return ss.str();
}