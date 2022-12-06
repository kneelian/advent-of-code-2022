#pragma once
#include <string>
#include <sstream>
#include <utility>
#include <functional>
#include <vector>

#define FMT_HEADER_ONLY

#include "useful.hxx"
#include "fmt/core.h"
#include "fmt/printf.h"

uint64_t day2part1(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d2-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d2-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 1!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d2p1-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d2p1-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 2 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();

    int score = 0;
    std::string line;

    while(std::getline(in_values, line))
    {
        score += (line[2] - 87) + (((line[2] - 88) - (line[0] - 61))%3)*3;
    }

    fmt::fprintf(result, "%d", score);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    return time_total;
} 

uint64_t day2part2(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d2-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d2-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 1!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d2p2-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d2p2-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 2 pt. 2!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();

    int score = 0;
    std::string line;

    while(std::getline(in_values, line))
    {
        score += 1 + ((line[2] - 88) * 3) + (((line[2] - 88) + (line[0] - 65) + 2)%3);
    }
    fmt::fprintf(result, "%d", score);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    return time_total;
} 

std::function<uint64_t(bool)> d2p1obj = day2part1;
std::function<uint64_t(bool)> d2p2obj = day2part2;