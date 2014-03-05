#include "comparator.h"

float Comparator::similarityCoefficient(const std::wstring& str1,
	const std::wstring& str2)
{
	float similarity = getPercentage(str1, str2);
	
	for (auto encoder = encoders.begin(); encoder != encoders.end();
		encoder++)
	{
		std::wstring encodedStr1 = (*encoder)->encode(str1);
		std::wstring encodedStr2 = (*encoder)->encode(str2);
		if (!encodedStr1.empty() && !encodedStr2.empty() &&
			encodedStr1 == encodedStr2)
		{
			similarity = (similarity + 1) / 2;
			break;
		}

	}

	return similarity;
}

void Comparator::addEncoder(std::shared_ptr<Encoder> encoder)
{
	encoders.push_back(encoder);
}
