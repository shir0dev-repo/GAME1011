#pragma once 

#include <map>
#include <string>
#include <iostream>
#include <type_traits>
#include "PropertyImpl.h"

/*

Partially acquired from https://stackoverflow.com/questions/17549906/c-json-serialization
by user Guillaume Racicot

*/

namespace Json {
	struct Value;

	struct ValueData {
		std::map<std::string, Value> subObject;
		std::string jsonString;
		int number = 0;
	};

	struct Value {
		ValueData data;

		Value& operator[](std::string name) {
			return data.subObject[std::move(name)];
		}

		const Value& operator[](std::string name) const {
			auto it = data.subObject.find(std::move(name));

			if (it != data.subObject.end()) {
				return it->second;
			}

			throw;
		}

		Value& operator=(std::string value) {
			data.jsonString = value;
			return *this;
		}

		Value& operator=(double value) {
			data.number = (int)value;
			return *this;
		}
	};

	template<typename T> T& asAny(Value&);
	template<typename T> const T& asAny(const Value&);

	template<>
	const int& asAny<int>(const Value& value) {
		return value.data.number;
	}

	template<>
	const std::string& asAny<std::string>(const Value& value) {
		return value.data.jsonString;
	}

	template<>
	std::string& asAny<std::string>(Value& value) {
		return value.data.jsonString;
	}
}

template<typename T>
T fromJson(const Json::Value& data) {
	T object;

	constexpr auto nbProperties = std::tuple_size<decltype(T::properties)>::value;

	for_sequence(std::make_index_sequence<nbProperties>{}, [&](auto i) {
		constexpr auto property = std::get<i>(T::properties);

		using Type = typename decltype(property)::Type;

		object.*(property.member) = Json::asAny<Type>(data[property.name]);
	});

	return object;
}

template<typename T>
std::string quote(T element) {
	std::string str = '"' + element + '"';
	return '"' + element + '"';
}

template<>
std::string quote<int>(int element) {
	return std::to_string(element);
}

template<typename T>
Json::Value toJson(const T& object) {
	Json::Value data;

	std::string dataStr = "{\n";
	std::string separator = " : ";

	constexpr auto nbProperties = std::tuple_size<decltype(T::properties)>::value;

	auto len = std::make_index_sequence<nbProperties>{};
	for_sequence(len, [&](auto i) {
		
		constexpr auto property = std::get<i>(T::properties);
		using Type = typename decltype(property)::Type;

		// assign json object data
		data[property.name] = object.*(property.member);
		
		// convert and append data to json string (pretty-printed, of course)
		dataStr.append("\t{ ");
		dataStr += quote(std::string(property.name)) + separator + quote(object.*(property.member)) + " }";
		if (i.value < len.size() - 1)
			dataStr += ',';
		dataStr += '\n';
	});
	dataStr.push_back('}');

	data = dataStr;
	return data;
}

// couldn't figure out for the life of me how to deserialize, so this is just here because im proud i could make it work
//template<typename T, size_t N>
//Json::Value toJson(const T(&arr)[N]) {
//	Json::Value data;
//
//	std::string dataStr = "{\n";
//	std::string separator = " : ";
//
//	int size = std::size(arr);
//	constexpr auto nbProperties = std::tuple_size<decltype(T::properties)>::value;
//	auto len = std::make_index_sequence<nbProperties>{};
//
//	// array
//	for (int i = 0; i < size; i++) {
//		dataStr.append("\t{\n");
//		
//		// array element
//		for_sequence(len, [&](auto j) {
//			constexpr auto property = std::get<j>(T::properties);
//			using Type = typename decltype(property)::Type;
//
//			// assign json object data
//			data[property.name] = arr[i].*(property.member);
//
//			// convert and append data to json string (pretty-printed, of course)
//			dataStr.append("\t\t{");
//			dataStr += quote(std::string(property.name)) + separator + quote(arr[i].*(property.member)) + " }";
//			if (j.value < len.size() - 1)
//				dataStr += ',';
//
//			dataStr.push_back('\n');
//		});
//
//		dataStr.append("\t}");
//		if (i < size - 1)
//			dataStr.push_back(',');
//		dataStr.push_back('\n');
//	}
//
//	dataStr.push_back('}');
//	data = dataStr;
//	return data;
//}