#pragma once
#include <string>
#include <sstream>
#include <utility>
#include <functional>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

#include "useful.hxx"


/*
    std::string s = "string_split_example";
    std::string half = s.substr(0, s.length()/2);
    std::string otherHalf = s.substr(s.length()/2);
*/


uint64_t day4part1(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d4-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d4-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 4!\n";
        return -1;
    }

    if(testing)
        { results.open("./out/d4p1-t-out.txt", std::ifstream::in); }
    else{ results.open("./out/d4p1-out.txt",   std::ifstream::in); }

    if(!results.is_open()) {
        std::cerr << "Can't open output file for day 4 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();

    int score = 0;
    int e1s, e1e, e2s, e2e;
    std::string line;
    std::vector<std::string> line_split, half;

    //int i = -1;

    while(std::getline(in_values, line))
    {
        //i++;
        line_split = split<std::string>(line, ",");
        half = split<std::string>(line_split[0], "-");
            e1s = atoi(half[0].c_str());
            e1e = atoi(half[1].c_str());
        half = split<std::string>(line_split[1], "-");
            e2s = atoi(half[0].c_str());
            e2e = atoi(half[1].c_str());
        if(
            ((e1s >= e2s) && (e1e <= e2e)) ||
            ((e2s >= e1s) && (e2e <= e1e)) 
        ){ score++; }
 
    }
    results << score;

    in_values.close();
    results.close();

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

uint64_t day4part2(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d4-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d4-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 4!\n";
        return -1;
    }

    if(testing)
        { results.open("./out/d4p2-t-out.txt", std::ifstream::in); }
    else{ results.open("./out/d4p2-out.txt",   std::ifstream::in); }

    if(!results.is_open()) {
        std::cerr << "Can't open output file for day 4 pt. 2!\n";
        return -1;
    }
    /* boilerplate end */
    auto time_start = std::chrono::high_resolution_clock::now();

    int score = 0;
    int e1s, e1e, e2s, e2e;
    std::string line;
    std::vector<std::string> line_split, half;

    //int i = -1;

    while(std::getline(in_values, line))
    {
        //i++;
        line_split = split<std::string>(line, ",");
        half = split<std::string>(line_split[0], "-");
            e1s = atoi(half[0].c_str());
            e1e = atoi(half[1].c_str());
        half = split<std::string>(line_split[1], "-");
            e2s = atoi(half[0].c_str());
            e2e = atoi(half[1].c_str());
        if(
            (e1s >= e2s && e1s <= e2e) || 
            (e2s >= e1s && e2s <= e1e)
        ){score++;}
    }
    results << score;

    in_values.close();
    results.close();

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d4p1obj = day4part1;
std::function<uint64_t(bool)> d4p2obj = day4part2;