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

/*
    std::string s = "string_split_example";
    std::string half = s.substr(0, s.length()/2);
    std::string otherHalf = s.substr(s.length()/2);
*/


uint64_t day7part1(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d7-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d7-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 7!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d7p1-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d7p1-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 7 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();
    std::string line;
    std::vector<std::string> split_line;
    std::unordered_map<std::string, uint64_t> directories;
    std::deque<std::string> dir_stack;
    uint64_t score = 0;

    directories["/"] = 0;
    dir_stack.push_front("/");

    while(std::getline(in_values,line))
    {
        split_line = split<std::string>(line, " ");
        if(
            (split_line[1] == "ls" ) or
            (split_line[0] == "dir") or
            (split_line[2] == "/")
        ) { continue; } 
        else if ((split_line[1] == "cd") and (split_line[2] == ".."))
        { dir_stack.pop_front();  continue; } 
        else if (split_line[1] == "cd")
        { 
            dir_stack.push_front(split_line[2] + dir_stack.front());
            directories[dir_stack.front()] = 0;
            continue;
        } 
        else
        {
            for(int i = 0; i < dir_stack.size(); i++)
            { directories[dir_stack[i]] += atoi(split_line[0].c_str()); }
            continue;
        }
    }
    for(auto i = directories.begin(); i != directories.end(); i++)
    { if(i->second <= 100000) { score += i->second; } }

    //fmt::printf("%d\n",score);
    fmt::fprintf(result, "%d", score);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

uint64_t day7part2(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d7-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d7-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 7!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d7p2-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d7p2-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 7 pt. 2!\n";
        return -1;
    }
    /* boilerplate end */
    
    auto time_start = std::chrono::high_resolution_clock::now();
    std::string line;
    std::vector<std::string> split_line;

    std::unordered_map<std::string, uint64_t> directories;
    std::deque<std::string> dir_stack;

    directories["/"] = 0;
    dir_stack.push_front("/");

    while(std::getline(in_values,line))
    {
        split_line = split<std::string>(line, " ");
        if(
            (split_line[1] == "ls" ) or
            (split_line[0] == "dir") or
            (split_line[2] == "/")
        ) { continue; } 

        else if ((split_line[1] == "cd") and (split_line[2] == ".."))
        { dir_stack.pop_front();  continue; } 

        else if (split_line[1] == "cd")
        { 
            dir_stack.push_front(split_line[2] + dir_stack.front());
            directories[dir_stack.front()] = 0;
            continue;
        } 

        else
        {
            for(int i = 0; i < dir_stack.size(); i++)
            { directories[dir_stack[i]] += atoi(split_line[0].c_str()); }
            continue;
        }
    }

    uint64_t max_size = directories["/"];
    uint64_t score = max_size;

    for(auto i = directories.begin(); i != directories.end(); i++)
    {
        int a = i->second;
        if((a < score) and ((max_size - a) < 40000000)) { score = a; }
    }

    //fmt::printf("%d\n",score);
    fmt::fprintf(result, "%d", score);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d7p1obj = day7part1;
std::function<uint64_t(bool)> d7p2obj = day7part2;