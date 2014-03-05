#include "distance.h"
#include <vector>
#include <cwctype>
#include <algorithm>

float getDistance(const std::wstring& str1, const std::wstring& str2)
{
	const size_t firstSize = str1.size(),
		secondSize = str2.size();
	std::vector<float> column(secondSize + 1),
		previousColumn(secondSize + 1);

	for (size_t i = 0; i < previousColumn.size(); i++)
	{
		previousColumn[i] = i;
	}

	for (size_t i = 0; i < firstSize; i++)
	{
		column[0] = i + 1;
		for (size_t j = 0; j < secondSize; j++)
		{
			if (str1[i] == str2[j])
			{
				column[j + 1] = previousColumn[j];
			}
			else
			{
				column[j + 1] = std::min(std::min(previousColumn[j + 1] + 1, column[j] + 1),
					previousColumn[j] + 1);
				if (std::towlower(str1[i]) == std::towlower(str2[j]))
				{
					column[j + 1] -= 0.5;
				}
			}
		}
		column.swap(previousColumn);
	}
	return previousColumn[secondSize];
}

float getPercentage(const std::wstring& str1, const std::wstring& str2)
{
	float d = getDistance(str1, str2);
	int max = std::max(str1.size(), str2.size());
	return (max - d) / max;
}
