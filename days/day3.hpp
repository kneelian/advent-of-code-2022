#pragma once
#include <string>
#include <sstream>
#include <utility>
#include <functional>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

#define FMT_HEADER_ONLY

#include "useful.hxx"
#include "fmt/core.h"
#include "fmt/printf.h"

uint64_t day3part1(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d3-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d3-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 3!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d3p1-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d3p1-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 3 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */
    /*
        if(n >= 'a') { n -= 'b'; }
        else { n -= 0x26; }
    */

    auto time_start = std::chrono::high_resolution_clock::now();

    int score = 0;
    std::string line;
    std::set<int> half_a, half_b, intersect;

    while(std::getline(in_values, line))
    {
        intersect.clear();
        half_a.clear(); 
        half_b.clear();

        int half = line.size() / 2;

        for(int i = 0; i < half; i++)
        {
            half_a.insert(line[i]);
        }
        for(int i = half; i < half * 2; i++)
        {
            half_b.insert(line[i]);
        }

        std::set_intersection(
            half_a.begin(),
            half_a.end(), 
            half_b.begin(), 
            half_b.end(),
            std::inserter(intersect, intersect.begin())
        );

        for(int i : intersect)
        {
            score += (i < 'a')? (i - 'A' + 27): (i - '`');
        }
    }

    fmt::fprintf(result, "%d", score);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

uint64_t day3part2(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d3-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d3-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 3!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d3p2-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d3p2-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 3 pt. 2!\n";
        return -1;
    }
    /* boilerplate end */
    /*
        if(n >= 'a') { n -= 'b'; }
        else { n -= 0x26; }
    */

    auto time_start = std::chrono::high_resolution_clock::now();

    int score = 0;
    std::string line;
    std::set<int> elf_a, elf_b, elf_c, temp;

    do
    {
        temp.clear();
        elf_a.clear();
        elf_b.clear();
        elf_c.clear();
        
        std::getline(in_values, line);
        for(int i = 0; i < line.size(); i++)
        { elf_a.insert(line[i]); }
        
        std::getline(in_values, line);
        for(int i = 0; i < line.size(); i++)
        { elf_b.insert(line[i]); }

        std::getline(in_values, line);
        for(int i = 0; i < line.size(); i++)
        { elf_c.insert(line[i]); }

        std::set_intersection(
            elf_a.begin(),
            elf_a.end(), 
            elf_b.begin(), 
            elf_b.end(),
            std::inserter(temp, temp.begin())
        );

        elf_a.clear();

        std::set_intersection(
            temp.begin(),
            temp.end(), 
            elf_c.begin(), 
            elf_c.end(),
            std::inserter(elf_a, elf_a.begin())
        );

        int i = *elf_a.begin();
        if(!i) break;

        //std::cout << "i = " << i << "(" << char(i) << ") \t score: " << score << " -> ";

        score += (i < 'a')? (i - 'A' + 27): (i - '`');

        // std::cout << score << std::endl;
    } while(line.size() > 2);

    fmt::fprintf(result, "%d", score);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d3p1obj = day3part1;
std::function<uint64_t(bool)> d3p2obj = day3part2;