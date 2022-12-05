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

#include "useful.hxx"


/*
    std::string s = "string_split_example";
    std::string half = s.substr(0, s.length()/2);
    std::string otherHalf = s.substr(s.length()/2);
*/


uint64_t day5part1(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d5-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d5-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 5!\n";
        return -1;
    }

    if(testing)
        { results.open("./out/d5p1-t-out.txt", std::ifstream::in); }
    else{ results.open("./out/d5p1-out.txt",   std::ifstream::in); }

    if(!results.is_open()) {
        std::cerr << "Can't open output file for day 5 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();
    //int score = 0;
    std::string line;
    std::array<std::deque<char>,9> stacks;

    do
    {
        std::getline(in_values, line);
        if(line.size() < 3) { break; }

        for(int i = 0; i < 9; i++)
        {
            if(line[1 + (4*i)] == '0') { continue; }
            stacks[i].push_back(line[1+(4*i)]);
        }

    } while(1);

    int num =0, source =0, dest =0;
    std::vector<std::string> temp;

    while(std::getline(in_values, line))
    {
        if(line == "\n") { break; }
        temp   = split<std::string>(line, " ");
        num    = atoi(temp[1].c_str());
        source = atoi(temp[3].c_str()) - 1;
        dest   = atoi(temp[5].c_str()) - 1;

        for(int i = 0; i < num; i++)
        {
            stacks[dest].push_front(stacks[source].front());
            stacks[source].pop_front();
        }
    }

    line.clear();

    for(int i = 0; i < 9; i++)
    {
        line += stacks[i].front();
    }

    results << line;

    in_values.close();
    results.close();

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

uint64_t day5part2(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d5-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d5-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 5!\n";
        return -1;
    }

    if(testing)
        { results.open("./out/d5p1-t-out.txt", std::ifstream::in); }
    else{ results.open("./out/d5p1-out.txt",   std::ifstream::in); }

    if(!results.is_open()) {
        std::cerr << "Can't open output file for day 5 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */
    
    auto time_start = std::chrono::high_resolution_clock::now();
    //int score = 0;
    std::string line;
    std::array<std::deque<char>,10> stacks;

    do
    {
        std::getline(in_values, line);
        if(line.size() < 3) { break; }
        for(int i = 0; i < 9; i++)
        {
            if(line[1 + (4*i)] == '0') { continue; }
            stacks[i].push_back(line[1+(4*i)]);
        }

    } while(1);

    int num =0, source =0, dest =0;
    std::vector<std::string> temp;

    while(std::getline(in_values, line))
    {
        if(line == "\n") { break; }
        temp   = split<std::string>(line, " ");
        num    = atoi(temp[1].c_str());
        source = atoi(temp[3].c_str()) - 1;
        dest   = atoi(temp[5].c_str()) - 1;

        /*
            for(int i = num; i > 0; i--)
            {
                stacks[dest].push_front(stacks[source][i]);
                stacks[source].pop_front();
            }
            for(int i = 0; i < num; i++)
            {
                stacks[source].pop_front();
            }
        */

        for(int i = 0; i < num; i++)
        {
            stacks[9].push_front(stacks[source].front());
            stacks[source].pop_front();
        }
        for(int i = 0; i < num; i++)
        {
            stacks[dest].push_front(stacks[9].front());
            stacks[9].pop_front();
        }
    }

    line.clear();

    for(int i = 0; i < 9; i++)
    {
        line += stacks[i].front();
    }
    results << line;

    in_values.close();
    results.close();

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d5p1obj = day5part1;
std::function<uint64_t(bool)> d5p2obj = day5part2;