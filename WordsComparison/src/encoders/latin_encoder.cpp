#include "latin_encoder.h"
#include <cwctype>
#include <algorithm>

std::wstring LatinEncoder::encode(const std::wstring& string)
{
	if (checkCompatibility(string) == false)
	{
		return L"";
	}

	std::wstring str = string;
	std::transform(str.begin(), str.end(), str.begin(), ::towupper);

	std::wstring code;
	for (int i = 0; i < str.length(); i++) 
	{
		if (i == 0)
		{
			code += str[i];
		}
		if (i > 0 && iswalpha(str[i]) != 0)
		{
			code += parseCharacter(str[i]);
		}
	}

	for (int j = 0; j < code.length(); j++) 
	{
		if (j > 0 && code[j] == code[j - 1]) 
		{
			code.erase(j, 1);
		}
		else if (code[j] == L'0') 
		{
			code.erase(j, 1); 
		}
	}

	if (code.length() < CODE_LENGTH)
	{
		int zeros = CODE_LENGTH - code.length();
		for (int k = 0; k < zeros; k++) 
		{
			code += '0';  
		}
	}
	else if (code.length() > CODE_LENGTH) 
	{
		code = code.substr(0, CODE_LENGTH); 
	}
	return code;
}

bool LatinEncoder::checkCompatibility(const std::wstring& str)
{
	bool result = true;

	for (size_t i = 0; i < str.size(); i++)
	{
		wchar_t currentChar = str[i];
		if ((currentChar < 65 || currentChar > 90) && 
			(currentChar < 97 || currentChar > 122))
		{
			result = false;
			break;
		}
	}
	return result;
}

wchar_t LatinEncoder::parseCharacter(wchar_t c)
{
	if (c == L'A' || c == L'E' || c == L'I' || c == L'O' ||
		c == L'U' || c == L'H' || c == L'W' || c == L'Y') 
	{
		return L'0';
	}
	else if (c == L'B' || c == L'F' || c == L'P' || c == L'V') 
	{
		return L'1';
	}
	else if (c == L'C' || c == L'G' || c == L'J' || c == L'K' ||
		c == L'Q' || c == L'S' || c == L'X' || c == L'Z') 
	{
		return L'2';
	}
	else if (c == L'D' || c == L'T') 
	{
		return L'3';
	}
	else if (c == L'M' || c == L'N') 
	{
		return L'4';
	}
	else if (c == L'L')
	{
		return L'5';
	}
	else 
	{
		return L'6';
	}
}
