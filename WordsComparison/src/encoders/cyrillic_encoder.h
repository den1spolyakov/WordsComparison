#ifndef CYRILLIC_ENCODER_H
#define CYRILLIC_ENCODER_H

#include "encoder.h"

class CyrillicEncoder : public Encoder
{
public:
	virtual std::wstring encode(const std::wstring& str);
	virtual bool checkCompatibility(const std::wstring& str);

	static void replaceLastSonant(std::wstring& stream);
	static std::wstring normalize(const std::wstring& str);
private:
	static const std::wstring alphabet;
	static const std::wstring sonants;
	static const std::wstring breathConsonants;
	static const std::wstring sonantsToBreathConsonants;
	static const std::wstring vowelPattern;
	static const std::wstring vowelReplace;
};

#endif