#pragma once
#include <string>
#include <sstream>
#include <utility>
#include <functional>
#include <set>
#include <vector>
#include <chrono>
#include "useful.hxx"

	std::ifstream in_values;
	std::ofstream results;

uint64_t day1part1(bool testing) { 
	/* boilerplate */
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
	/* boilerplate end */

	auto time_start = std::chrono::high_resolution_clock::now();

    char buffer[8];
    int res = 0;

    while (!in_values.eof())
    {
        int current = 0;
        while (in_values.getline(buffer, sizeof(buffer)), in_values.gcount() > 1)
            current += atoi(buffer);
        res = (current > res)? current: res;
    }

	results << res; 

	uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
	
	in_values.close();
	results.close();
	return time_total;
}

uint64_t day1part2(bool testing) {
	/* boilerplate */
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
	/* boilerplate end */

	auto time_start = std::chrono::high_resolution_clock::now();

    char buffer[8];
    int top1 = 0;
    int top2 = 0;
    int top3 = 0;

    while (!in_values.eof())
    {
        int j = 0;
        while (in_values.getline(buffer, sizeof(buffer)), in_values.gcount() > 1)
        {
        	j += atoi(buffer);
        }

        if(j > top1)
    	{
    		top3 = top2;
    		top2 = top1; 
    		top1 = j;
    	} else
    	if (j > top2)
    	{
    		top3 = top2;
    		top2 = j;
    	} else
    	if (j > top3)
    	{
    		top3 = j; 
    	}
   	}

	results << top1 + top2 + top3; 

	uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
	
	in_values.close();
	results.close();
	return time_total;
	// return

}

std::function<uint64_t(bool)> d1p1obj = day1part1;
std::function<uint64_t(bool)> d1p2obj = day1part2;