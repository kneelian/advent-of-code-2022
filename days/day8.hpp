#pragma once
#include <string>
#include <sstream>
#include <utility>
#include <functional>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
#include <array>
#include <cstdio>
#include <unordered_map>

#define FMT_HEADER_ONLY

#include "useful.hxx"
#include "fmt/core.h"
#include "fmt/printf.h"

uint64_t day8part1(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d8-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d8-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 8!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d8p1-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d8p1-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 8 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();
    std::string line;
    std::array<std::array<int, 99>, 99> grid_2d;

    for(int i = 0; i < 99; i++)
    {
    	std::getline(in_values, line);
    	for(int j = 0; j < 99; j++)
    	{
    		grid_2d[i][j] = (line[j] - '0');
    	}
    }

    /*
    for(int i = 0; i < 99; i++)
    {
    	for(int j = 0; j < 99; j++)
    	{
    		fmt::printf("%d", grid_2d[i][j]);
    	}
    	fmt::printf("\n");
    }*/

    int score = 197;
    int tree_height = 0;

    for(int i = 1; i <= 98; ++i)
    {
    	for(int j = 1; j <= 98; ++j)
    	{
    		tree_height = grid_2d[i][j];

    		for (int x = i-1; x >= 0; --x)
    		{ if(tree_height <= grid_2d[x][j]) { goto check2; } }
    		score++; continue;

    		check2:;
			for (int x = i+1; x < 99; ++x)
    		{ if(tree_height <= grid_2d[x][j]) { goto check3; } }
			score++; continue;

			check3:;
			for (int y = j-1; y >= 0; --y)
    		{ if(tree_height <= grid_2d[i][y]) { goto check4; } }
			score++; continue;

			check4:;
			for (int y = j+1; y < 99; ++y)
    		{ if(tree_height <= grid_2d[i][y]) { goto turbo_break; } }
			score++; continue;

			turbo_break:;
    	}
    }

    fmt::fprintf(result, "%d", score);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

uint64_t day8part2(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d8-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d8-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 8!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d8p2-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d8p2-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 8 pt. 2!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();
    std::string line;
    std::array<std::array<int, 99>, 99> grid_2d;

    for(int i = 0; i < 99; i++)
    {
    	std::getline(in_values, line);
    	for(int j = 0; j < 99; j++)
    	{
    		grid_2d[i][j] = (line[j] - '0');
    	}
    }
    int tree_height = 0;
    int max = 0;

    for(int i = 1; i <= 98; ++i)
    {
    	for(int j = 1; j <= 98; ++j)
    	{
    		int up    = 0,
		    	down  = 0,
		    	left  = 0,
		    	right = 0;
    		tree_height = grid_2d[i][j];

    		for (int x = i-1; x >= 0; --x)
    		{ up++;   if(tree_height <= grid_2d[x][j]) { break; } }

			for (int x = i+1; x < 99; ++x)
    		{ down++; if(tree_height <= grid_2d[x][j]) { break; } }

			for (int y = j-1; y >= 0; --y)
    		{ left++; if(tree_height <= grid_2d[i][y]) { break; } }

			for (int y = j+1; y < 99; ++y)
    		{ right++;if(tree_height <= grid_2d[i][y]) { break; } }
			
    		max = (max < (up * down * left * right))? (up * down * left * right): max;
    	}
    }
	//fmt::printf("%d", max);
    fmt::fprintf(result, "%d", max);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d8p1obj = day8part1;
std::function<uint64_t(bool)> d8p2obj = day8part2;