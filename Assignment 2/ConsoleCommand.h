#pragma once

#include <memory>
#include <functional>
#include <vector>
#include <string>


namespace Commands {

	template<typename Result, typename... Arguments>
	class ConsoleCommand {
	public:

		inline void Init(const char name[], std::function<Result(Arguments...)> process) {
			m_name = name;
			m_process = process;
		}

		inline Result Parse(const std::string& input, std::function<Result(std::string)> converter) {
			std::vector<std::string> args;
			std::vector<Result> finalArgs;

			char separator = ' ';
			size_t pos = 0;
			while ((pos = input.find(separator)) != std::string::npos) {
				args.push_back(input.substr(0, pos));
				input.erase(0, pos + 1);
			}

			for (auto s : args) {
				finalArgs.push_back(converter(s));
			}
			return Run(finalArgs[finalArgs.size()]...);
		}
		inline Result Run(Arguments ...args) const {
			return m_process(args...);
		}

		inline std::string GetName() const {
			return m_name;
		}
		
	private:
		std::function<Result(Arguments...)> m_process;
		std::string m_name;	
	};
}