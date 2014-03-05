#ifndef LATIN_ENCODER_H
#define LATIN_ENCODER_H

#include "encoder.h"

class LatinEncoder : public Encoder
{
public:
	virtual std::wstring encode(const std::wstring& str);
	virtual bool checkCompatibility(const std::wstring& str);
private:
	static const int CODE_LENGTH = 4;

	wchar_t parseCharacter(wchar_t c);
};

#endif