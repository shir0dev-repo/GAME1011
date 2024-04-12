//#pragma once
//
//#include <iostream>
//#include <map>
//#include <string>
//#include <functional>
//
//#include "Commands.h"
//#include "ConsoleCommand.h"
//
//namespace Commands {
//
//	static inline bool Execute(const vectargs_T& params) {
//		if (commandMap.empty())
//			throw;
//		else if (params.empty())
//			return false;
//			
//		
//
//		ICommand* command = nullptr;
//
//		for (std::pair<const std::string, ICommand> cmd : commandMap) {
//			if (cmd.second.Parse(params)) {
//				command = &cmd.second;
//				break;
//			}
//		}
//
//		if (command == nullptr) {
//			std::cout << "Could not parse command: " << params[0] << ". Please try again." << std::endl;
//			return false;
//		}
//
//		bool success = dynamic_cast<ConsoleCommand&>(*command).Run(params);
//		delete command;
//		
//		return success;
//	}
//}