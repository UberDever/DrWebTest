#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include <execution>

// Running time of original, given original string: 967 ms
// Running time of optimized version, given same string: 275 ms

// 1. Saved ranges as constexpr
// 2. Used C++17 execution policy for containers, therefore lambda is performed in parallel
// 3. Used some arithmetics for avoiding multiple if / else
// 4. Used references for avoiding copying (This differs from original signature, but this faster)


std::wstring& get_ceasar_string(std::wstring& str) {

	constexpr wchar_t shift = 3;
	constexpr wchar_t alphabetRange = (L'z' - L'a' + 1);
	constexpr wchar_t caseRange = L'a' - L'A';

	std::for_each(
		std::execution::par_unseq,
		str.begin(),
		str.end(),
		[&](auto&& letter)
		{
			wchar_t c = letter - L'A';
			if (c < 0)
				return;
			wchar_t letterCase = (wchar_t)c / (wchar_t)caseRange;
			wchar_t letterShift = c % caseRange;
			if (letterCase > 1 || letterShift >= alphabetRange)
				return;
			c = (letterShift + shift) % alphabetRange;
			letter = c + L'A' + ((bool)letterCase) * caseRange;
		});

	return str;
}
