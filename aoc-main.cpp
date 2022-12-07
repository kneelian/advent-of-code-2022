
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <array>
#include <fstream>
#include <cmath>
#include <Windows.h>

#include "aoc-days.hpp"

bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

int main(int argc, char* argv[])
{

	if(argc < 2) { std::cerr << "Too few arguments!\n"; return 1; }

	if(cmdOptionExists(argv, argv+argc, "-h"))
	{
		std::cout << "Advent of Code 2021 runner.\n"
				  << "List of commands:\n"
				  << "\t aoc -h ...      -- shows this help log and exits (regardless of number of args)\n"
				  << "\t aoc X# Y#       -- runs AOC day X part Y and shows the time it took in microseconds\n"
				  << "\t aoc t Z# X# Y#  -- gives average runtime of day X part Y over Z runs\n"
				  << "\t aoc b           -- runs all available days and parts, gives individual and overall time\n"
				  << "\t aoc t X# b      -- gives average runtime for all days and parts over X runs\n"
				  << "\t aoc ... s       -- runs the sample input instead of the real input"
				  << std::endl;
		return 0;
	}

	bool opt_batch  = false;
	bool opt_sample = false;
	bool opt_timed  = false;

	if(cmdOptionExists(argv, argv+argc, "b")) { opt_batch  = true; }
	if(cmdOptionExists(argv, argv+argc, "s")) { opt_sample = true; }
	if(cmdOptionExists(argv, argv+argc, "t")) { opt_timed  = true; }

	int day   = 0; 
	int part  = 0; 
	int times = 1;

	if(opt_timed)
	{
		times = std::stoi(argv[2]);
		if(!opt_batch)
		{
			day  = std::stoi(argv[3]);
			part = std::stoi(argv[4]);
		}
	}
	else
	{
		if(!opt_batch)
		{
			day  = std::stoi(argv[1]);
			part = std::stoi(argv[2]);
		}
	}

	// std::cout << day << " " << part << std::endl;
	/*
	std::vector<std::string> options;
	for(int a = 1; a < argc; a++)
	{
		options.push_back(argv[a]);
	}*/
	

	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	std::function<uint64_t(bool)> part1_array[]
	= {
		{ nullptr },
		{ d1p1obj },
		{ d2p1obj },
		{ d3p1obj },
		{ d4p1obj },
		{ d5p1obj },
		{ d6p1obj },
		{ d7p1obj },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr }
	};
	std::function<uint64_t(bool)> part2_array[]
	= {
		{ nullptr },
		{ d1p2obj },
		{ d2p2obj },
		{ d3p2obj },
		{ d4p2obj },
		{ d5p2obj },
		{ d6p2obj },
		{ d7p2obj },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr },
		{ nullptr }
	};

	uint64_t overall_time_ns = 0;

	uint64_t total_time_ns = 0;
	std::cout << '\n';
	if(!opt_batch)
	{
		for(int i = times; i != 0; i--)
		{
			if(part == 2)
			{
				total_time_ns += part2_array[day](opt_sample);
			}
			else if(part == 1)
			{
				total_time_ns += part1_array[day](opt_sample);
			}
		}

		std::cout << std::fixed << std::showpoint << std::setprecision(1);
		std::cout << "d" << day << "p" << part 
			  << " Σt ≈ " << double(total_time_ns)/1000 << "μs" 
			  << std::setprecision(3) <<  " (avg: " << double(total_time_ns)/(times*1000) << "μs)"
			  << std::endl;
	}
	else
	{
		for(int i = 0; i < 26; i++)
		{
			overall_time_ns += total_time_ns;
			total_time_ns = 0;
			if(part1_array[i] != 0)
			{
				for(int j = times; j != 0; j--)
				{
					total_time_ns += part1_array[i](false);
				}
				std::cout << std::fixed << std::showpoint << std::setprecision(1);
				std::cout << "d" << i << "p1"
						  << " Σt ≈ " << double(total_time_ns)/1000 << "μs" 
						  << std::setprecision(3) <<  "\t(avg: " << double(total_time_ns)/(times*1000) << "μs, " <<double(total_time_ns)/(times*1000*1000) << "ms)"
						  << std::endl;
			}
			total_time_ns = 0;
			if(part2_array[i] != 0)
			{
				for(int j = times; j != 0; j--)
				{
					total_time_ns += part2_array[i](false);
				}
				std::cout << std::fixed << std::showpoint << std::setprecision(1);
				std::cout << "d" << i << "p2"
						  << " Σt ≈ " << double(total_time_ns)/1000 << "μs" 
						  << std::setprecision(3) <<  "\t(avg: " << double(total_time_ns)/(times*1000) << "μs, " <<double(total_time_ns)/(times*1000*1000) << "ms)"
						  << std::endl;
			}
		}
		std::cout << "------------------------\nOverall time taken Στ ≈ " << std::setprecision(1) <<  double(overall_time_ns)/1000 << "μs (appx. ~" << std::setprecision(3)<< double(overall_time_ns)/(1000*1000) << "ms)\n" << std::endl;
	}

	return 0;
}