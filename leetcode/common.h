#pragma once

#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <random>
#include <limits>
#include <cassert>
#include <chrono>
#include <unordered_map>
#include <iostream>

using namespace std;

class ElapseTimeHelper
{
public:
	ElapseTimeHelper()
	{
		_start = std::chrono::high_resolution_clock::now();
	}
	double GetElapseMilliSeconds()
	{
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - _start);
		return duration.count();
	}
private:
	std::chrono::high_resolution_clock::time_point _start;
};