#ifndef ENCODER_H
#define ENCODER_H

#include <string>

class Encoder
{
public:
	virtual std::wstring encode(const std::wstring& str) = 0;
	virtual bool checkCompatibility(const std::wstring& str) = 0;
};

#endif