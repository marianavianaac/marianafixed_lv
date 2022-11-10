#include "flv.h"
#include <iostream>

int main()
{
	using namespace data_structures;
	auto flv = FLV<int>{ 7 };
	flv[5] = 3;
	auto flv2 = flv;
	flv2 = flv;
	flv[5] = 5;

	std::cout << flv[5] << "\n";
	flv = flv;

	std::cout << flv[5] << "\n";
	auto flv_m = FLV < std::string>{ 7 };
	flv_m[5] = "abc";
	std::cout << flv_m[5] << "\n";

	flv_m = flv_m;
	std::cout << flv_m[5] << "\n";
	auto flv_m2 = std::move(flv_m);
	
}
