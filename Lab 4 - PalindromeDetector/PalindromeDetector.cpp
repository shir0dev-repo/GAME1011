#include <vector>
#include <string>
#include <iostream>

static std::string ReverseString(std::string input)
{
	std::string reversed;
	const char separator = ' ';
	for (int i = input.size() - 1; i > -1; i--)
	{
		reversed.push_back(input[i]);
	}

	return reversed;
}

static bool CheckForPalindrome(std::string input, std::string reversed)
{
	const char separator = ' ';
	reversed.erase(remove(reversed.begin(), reversed.end(), separator), reversed.end());
	input.erase(remove(input.begin(), input.end(), separator), input.end());

	return (reversed == input);
}

static bool CheckForExit(std::string input)
{
	for (char c : input)
	{
		if (std::isdigit(c))
			return true;
	}

	return false;
}

int main()
{
	std::string input;
	std::string reversed;

	std::cout << "Enter any number to exit the program." << std::endl;
	std::cout << "Please enter a string to check: " << std::endl;

	while (std::getline(std::cin, input))
	{
		if (CheckForExit(input))
			break;

		reversed = ReverseString(input);
		std::cout << input << " reversed is: " << reversed << std::endl;
		if (CheckForPalindrome(input, reversed))
		{
			std::cout << "That means " << input << " is a palindrome!" << std::endl;
		}
		else
		{
			std::cout << input << " is not a palindrome." << std::endl;
		}

		input.clear();
		reversed.clear();

		std::cout << std::endl << "Please enter a string to check: " << std::endl;
	}

	std::cout << "Thanks for playing!" << std::endl;

	return 0;
}