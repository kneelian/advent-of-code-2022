#pragma once
#include <string>
#include <sstream>
#include <utility>
#include <functional>
#include <vector>

#include "useful.hxx"

uint64_t day2part1(bool testing)
{
    if(testing)
        { in_values.open("./in/d2-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d2-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 2!\n";
        return -1;
    }

    if(testing)
        { results.open("./out/d2p1-t-out.txt", std::ifstream::in); }
    else{ results.open("./out/d2p1-out.txt",   std::ifstream::in); }

    if(!results.is_open()) {
        std::cerr << "Can't open output file for day 2 pt. 1!\n";
        return -1;
    }

    std::string temporary;
    std::vector<std::string> input;

    while (getline(in_values, temporary))
        { input.push_back(temporary); }
    in_values.close();

    // transform input into usable form (string to pair of values)
    auto time_start = std::chrono::high_resolution_clock::now();

    // functionality

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();

    results << 0;
    return time_total;
} // somethings not working right, fix tomorrow

uint64_t day2part2(bool testing)
{
    return 1;
}

std::function<uint64_t(bool)> d2p1obj = day2part1;
std::function<uint64_t(bool)> d2p2obj = day2part2;