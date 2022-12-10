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
        { in_values.open("./in/d10-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d10-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 10!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d10p1-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d10p1-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 10 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();
    std::string line;
    std::vector<std::string> temp;

    int score = 0;
    int cycle = 0;
    int reg_x = 1;
    int insn = 0;
    int amnt = 0;
    while(std::getline(in_values, line))
    {
        if(line.size() < 2) { break; }
        temp = split<std::string>(line, " ");
        insn = temp[0].c_str()[0];
        
        if(insn == 'a')
        {
            cycle++;
            if((cycle-20)%40 == 0) {  score += cycle * reg_x; }
            cycle++;
            if((cycle-20)%40 == 0) {  score += cycle * reg_x; }
            reg_x += std::atoi(temp[1].c_str());;
        } else
         if(insn == 'n') { 
            cycle++;
            if((cycle-20)%40 == 0) {  score += cycle * reg_x; }
            continue;
        }
    }
    fmt::fprintf(result, "%d", score);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

uint64_t day10part2(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d10-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d10-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 10!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d10p2-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d10p2-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 10 pt. 2!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();
    std::string line;
    std::vector<std::string> temp;

    int cycle = 1;
    int reg_x = 1;
    int insn = 0;
    int amnt = 0;
    while(std::getline(in_values, line))
    {
        if(line.size() < 2) { break; }
        temp = split<std::string>(line, " ");
        insn = temp[0].c_str()[0];
        
        if(insn == 'a')
        {
            cycle++;
            if(absl(cycle - reg_x) < 2){ fmt::printf("#"); } else { fmt::printf("."); }
            if(!(cycle%40)) { fmt::printf("\n"); }
            cycle++;
            if(absl(cycle - reg_x) < 2){ fmt::printf("#"); } else { fmt::printf("."); }
            if(!(cycle%40)) { fmt::printf("\n"); }
            reg_x += std::atoi(temp[1].c_str());;
        } else
         if(insn == 'n') { 
            cycle++;
            
            continue;
        }
    }
    fmt::fprintf(result, "%d", 0);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d10p1obj = day10part1;
std::function<uint64_t(bool)> d10p2obj = day10part2;