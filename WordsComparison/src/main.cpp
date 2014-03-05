#include "comparator.h"
#include "encoders/latin_encoder.h"
#include "encoders/cyrillic_encoder.h"
#include <iostream>
#include <iomanip>

const int outputPrecision = 4;

void log(const std::wstring& str1, const std::wstring& str2, 
	Comparator& comparator);

int main()
{
	setlocale(LC_ALL, "");
	
	Comparator comparator;
	comparator.addEncoder(std::shared_ptr<Encoder>(new LatinEncoder()));
	comparator.addEncoder(std::shared_ptr<Encoder>(new CyrillicEncoder()));

	
	log(L"����", L"����", comparator);
	log(L"����", L"����", comparator);
	log(L"����", L"����", comparator);
	log(L"����", L"����", comparator);
	log(L"����", L"����", comparator);
	log(L"elephant", L"Elefant", comparator);

	std::cin.get();
	return 0;
}

void log(const std::wstring& str1, const std::wstring& str2,
	Comparator& comparator)
{
	std::wcout << std::setprecision(outputPrecision) 
		<< comparator.similarityCoefficient(str1, str2) << std::endl;
}