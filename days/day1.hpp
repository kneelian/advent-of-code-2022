#pragma once
#include <string>
#include <utility>
#include <functional>
#include <vector>
#include <chrono>

	std::ifstream in_values;
	std::ofstream results;

uint64_t day1part1(bool testing) { 
	if(testing)
		{ in_values.open("./in/d1-t-in.txt", std::ifstream::in); }
	else{ in_values.open("./in/d1-in.txt",   std::ifstream::in); }
	
	if(!in_values.is_open()) { 
		std::cerr << "Can't open input file for day 1!\n";
		return -1;
	}

	if(testing)
		{ results.open("./out/d1p1-t-out.txt", std::ifstream::in); }
	else{ results.open("./out/d1p1-out.txt",   std::ifstream::in); }

	if(!results.is_open()) {
	 	std::cerr << "Can't open output file for day 1 pt. 1!\n";
		return -1;
	}

	std::string temporary;
	std::vector<std::string> input;

    while (getline(in_values, temporary))
    	{ input.push_back(temporary); }
    in_values.close();

	std::vector<int> input_parsed;
	int temp = 0;

	for(int i = 0; i < input.size(); i++)
	{ input_parsed.push_back(std::stoi(input[i],0,10)); }

	auto time_start = std::chrono::high_resolution_clock::now();

		for(int i = 1; i < input_parsed.size(); i++)
		{ if(input_parsed[i] > input_parsed[i-1]) temp++; }

	uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
	results << temp;
	return time_total;
}

uint64_t day1part2(bool testing) {
		if(testing)
		{ in_values.open("./in/d1-t-in.txt", std::ifstream::in); }
	else{ in_values.open("./in/d1-in.txt",   std::ifstream::in); }

	if(!in_values.is_open()) { 
		std::cerr << "Can't open input file for day 1!\n";
		return -1;
	}

	if(testing)
		{ results.open("./out/d1p2-t-out.txt", std::ifstream::in); }
	else{ results.open("./out/d1p2-out.txt",   std::ifstream::in); }
	
	if(!results.is_open()) {
	 	std::cerr << "Can't open output file for day 1 pt. 2!\n";
		return -1;
	}

	std::string temporary;
	std::vector<std::string> input;

    while (getline(in_values, temporary))
    	{ input.push_back(temporary); }
    in_values.close();

	std::vector<int> input_parsed;

	for(int i = 0; i < input.size(); i++)
	{ input_parsed.push_back(std::stoi(input[i],0,10)); }

	auto time_start = std::chrono::high_resolution_clock::now();
		uint64_t prev_window    = -1;
		uint64_t current_window =  0;
		int temp;

		for(int i = 2; i < input_parsed.size(); i++)
		{
			if (current_window > prev_window) { temp++; }
			prev_window = current_window;
			current_window = input_parsed[i] + input_parsed[i-1] + input_parsed[i-2];
		}

	uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
	results << temp;
	return time_total;

}

std::function<uint64_t(bool)> d1p1obj = day1part1;
std::function<uint64_t(bool)> d1p2obj = day1part2;