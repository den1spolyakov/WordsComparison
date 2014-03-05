#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <string>
#include <vector>
#include <memory>
#include "encoders/encoder.h"
#include "distance.h"

class Comparator
{
public:
	Comparator() {}
	~Comparator() {}

	float similarityCoefficient(const std::wstring& str1, 
		const std::wstring& str2);
	void addEncoder(std::shared_ptr<Encoder> encoder);
private:
	std::vector<std::shared_ptr<Encoder>> encoders;
};

#endif