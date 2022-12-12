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

uint64_t day10part1(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d12-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d12-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 12!\n";
        return -1;
    }

    /**/std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d12p1-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d12p1-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 12 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();
    std::string line;

    while(std::getline(in_values, line))
    {
    }
    
    int score = 0;

    std::fprintf(result, "%d", score);
    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
}

uint64_t day12part2(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d12-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d12-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 12!\n";
        return -1;
    }

    /**/std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d12p2-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d12p2-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 12 pt. 2!\n";
        return -1;
    }
    /* boilerplate end */

    int score = 0;

    std::fprintf(result, "%d", score);
    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d12p1obj = day12part1;
std::function<uint64_t(bool)> d12p2obj = day12part2;