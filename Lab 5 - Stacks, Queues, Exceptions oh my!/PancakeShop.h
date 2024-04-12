#pragma once

#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <iomanip>

class PancakeShop
{
public:
	const float&& _PANCAKE_COST = 2.50f;

	PancakeShop(size_t);
	
	void DisplayStats();
	void DisplayFinalStats();
	void Close();

	inline size_t GetPancakeCount() const { return m_pancakeStack.size(); }
	inline size_t GetCustomerCount() const { return m_customerQueue.size(); }
	inline void ClearScreen() {
		std::cout.clear();
		std::cout << "\033[2J\033[1;1H";
	}

	void BakePancakes();
	void TakeOrder();
	bool SellPancakes(int&) throw();

private:
	
	std::string DisplayBakingProgress();

	std::string FormatPrecision(float);

	std::stack<int> m_pancakeStack;
	std::queue<int> m_customerQueue;

	float m_profit;
	float m_bakingProgress;

	int m_currentCustomerID;
};

