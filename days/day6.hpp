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

#define FMT_HEADER_ONLY

#include "useful.hxx"
#include "fmt/core.h"
#include "fmt/printf.h"

/*
    std::string s = "string_split_example";
    std::string half = s.substr(0, s.length()/2);
    std::string otherHalf = s.substr(s.length()/2);
*/


uint64_t day6part1(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d6-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d6-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 6!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d6p1-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d6p1-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 6 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();
    int score = 0;
    std::string line;
    std::getline(in_values,line);

    char a = line[0], 
         b = line[1], 
         c = line[2], 
         d = line[3];

    for(int i = 4; i <= line.size(); i++)
    {
        if
        (
            a != b && a != c && a != d &&
            b != c && b != d &&
            c != d
        )
        { score = i; break; }
        a = b;
        b = c;
        c = d;
        d = line[i];
    }

    fmt::fprintf(result, "%d", score);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

uint64_t day6part2(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d6-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d6-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 6!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d6p2-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d6p2-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 6 pt. 2!\n";
        return -1;
    }
    /* boilerplate end */
    
    auto time_start = std::chrono::high_resolution_clock::now();
    int score = 0;
    std::string line;
    std::getline(in_values,line);

    std::array<char,14> chars;

    /*for(int i = 18; i <= line.size(); i+=14)
    {
        std::copy(line.begin()+i, line.begin()+i+14, chars.begin());
        /*fmt::printf("%s\n",chars.data());
        fmt::printf("%d\n",i)
        int j, k;
        for(j = 0; j < 14; j++)
        {
            for(k = j+1; k < 14; k++)
            {
                //fmt::printf("\tcomparing %c vs. %c\n", chars[j], chars[k]);
                if(chars[j] == chars[k])
                {
                    goto turbo_continue;
                }
            }
        }
        score += i + 14;*/
    for(int i = 0; i <= line.size(); i++)
    {
        for(int e = 0; e < 14; e++)
        {
            chars[e] = line[i+e];
        }
//        std::copy(line.begin()+i, line.begin()+i+14, chars.begin());
        int j, k;
        for(j = 0; j < 14; j++)
        {
            for(k = j+1; k < 14; k++)
            {
                if(chars[j] == chars[k])
                {
                    goto turbo_continue;
                }
            }
        }
        score = i+14;
        break;

        turbo_continue:
        void(0);
    }
//    fmt::printf("%d\n",score);/**/
    fmt::fprintf(result, "%d", score);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d6p1obj = day6part1;
std::function<uint64_t(bool)> d6p2obj = day6part2;