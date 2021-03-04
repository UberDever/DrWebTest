#pragma once

#include <string>
#include <algorithm>

// They said, inheriting from std::string is bad idea... but that works
class MyString : public std::string
{
public:
	// All common constructors for convenience
	MyString() : std::string() {}
	MyString(const char* str) : std::string(str) {}
	MyString(const char* str, size_t n) : std::string(str, n) {}
	MyString(size_t n, char c) : std::string(n, c) {}

	void swap(std::string right)
	{
		const std::string censor = "dr.web";
		auto it = std::search(
			right.begin(), right.end(),
			censor.begin(), censor.end(),
			[](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); }
		);

		if (it != right.end())
			throw std::invalid_argument("Substring \"dr.web\" in any case if forbidden");

		static_cast<std::string*>(this)->swap(right);
	};
};