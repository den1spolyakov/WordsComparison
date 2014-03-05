#include "cyrillic_encoder.h"
#include <cwctype>

const std::wstring CyrillicEncoder::alphabet
= L"�������������������������������";
const std::wstring CyrillicEncoder::sonants
= L"�����";
const std::wstring CyrillicEncoder::breathConsonants
= L"�����";
const std::wstring CyrillicEncoder::sonantsToBreathConsonants
= L"����������������";
const std::wstring CyrillicEncoder::vowelPattern
= L"����ߨ�";
const std::wstring CyrillicEncoder::vowelReplace
= L"�������";

std::wstring CyrillicEncoder::encode(const std::wstring& str)
{
	if (str.size() == 0 || checkCompatibility(str) == false)
	{
		return L"";
	}

	std::wstring temp = normalize(str);
	replaceLastSonant(temp);

	std::wstring result;

	wchar_t oldCh = 0;
	for (size_t i = 0; i < temp.size(); i++)
	{
		wchar_t ch = temp[i];

		int vowelIndex = std::find(vowelPattern.begin(), vowelPattern.end(),
			ch) - vowelPattern.begin();

		if (vowelIndex != vowelPattern.size())
		{
			if ((oldCh == L'�' || oldCh == L'�') && (ch == L'�' || ch == L'�'))
			{
				result[result.size() - 1] = L'�';
			}
			else
			{
				result += vowelReplace[vowelIndex];
			}
		}
		else
		{
			if ((std::find(sonantsToBreathConsonants.begin(), sonantsToBreathConsonants.end(),
				ch) - sonantsToBreathConsonants.begin()) != sonantsToBreathConsonants.size())
			{
				int sonantIndex = std::find(sonants.begin(), sonants.end(), oldCh)
					- sonants.begin();
				if (sonantIndex != sonants.size())
				{
					oldCh = breathConsonants[sonantIndex];
					result[result.size() - 1] = oldCh;
				}
			}

			if (oldCh == L'�' && ch == L'�')
			{
				result[result.size() - 1] = L'�';
			}
			else if (ch != oldCh)
			{
				result += ch;
			}
		}
		oldCh = ch;
	}
	return result;
}

bool CyrillicEncoder::checkCompatibility(const std::wstring& str)
{
	bool result = true;
	
	for (auto c = str.begin(); c != str.end(); c++)
	{
		if (*c < 1040 || *c > 1103)
		{
			result = false;
			break;
		}
	}
	return result;
}

void CyrillicEncoder::replaceLastSonant(std::wstring& str)
{
	if (str.size() > 0)
	{
		int lastSonantIndex = std::find(sonants.begin(), sonants.end(),
			str[str.size() - 1])
			- sonants.begin();

		if (lastSonantIndex != sonants.size())
		{
			str[str.size() - 1] = breathConsonants[lastSonantIndex];
		}
	}
}

std::wstring CyrillicEncoder::normalize(const std::wstring& str)
{
	std::wstring newStr;

	wchar_t oldCh = 0;
	for (int i = 0; i < str.size(); i++)
	{
		wchar_t ch = std::towupper(str[i]);
		if (ch != oldCh)
		{
			if ((std::find(alphabet.begin(), alphabet.end(), ch) - alphabet.begin())
				!= alphabet.size())
			{
				newStr += ch;
			}
		}
		oldCh = ch;
	}
	return newStr;
}

