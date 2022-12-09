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
#include <utility>

#define FMT_HEADER_ONLY

#include "useful.hxx"
#include "fmt/core.h"
#include "fmt/printf.h"

inline int sign(int n)
{
    return (n < 0)? -1: 1; 
}

inline int abs(int n)
{
    return (n < 0)? -n: n;
}

inline bool adjacent(std::pair<int, int> a, std::pair<int, int> b)
{
    return ((abs(a.first - b.first) < 2) && (abs(a.second-b.second) < 2));
}

uint64_t day9part1(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d9-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d9-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 9!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d9p1-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d8p1-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 9 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();
    std::string line;
    std::array<std::array<int, 512>, 512> visited;
    std::pair<int, int> head, tail;

    std::cout<<"are we segfaulting\n"<<std::endl;

    while(std::getline(in_values, line))
    {
        int dir = line[0]; // 'U', 'D', 'L', 'R'
        int amt = std::atoi(line.substr(2, 3).c_str());

        if(dir == 'R'){ head.first  += amt; } else
        if(dir == 'L'){ head.first  -= amt; } else
        if(dir == 'U'){ head.second += amt; } else
        if(dir == 'D'){ head.second -= amt; }

        //if(adjacent(head, tail)) { continue; }

        if(
            (abs(head.first  - tail.first) <= 1) &&
            (abs(head.second - tail.second)<= 1)
        ){ continue; }

        // if(same first)

        if(head.first == tail.first)
        {
            tail.second += sign(head.second - tail.second);
        } else;

        // else if (same second)

        if(head.second == tail.second)
        {
            tail.first += sign(head.first - tail.first); 
        } else;

        if(abs(head.first - tail.first ) >1)
        {
            tail.first  += sign(head.first-tail.first);
        } else
        if(abs(head.second - tail.second)>1)
        {
            tail.second += sign(head.second-tail.second);
        }

        visited[tail.first][tail.second]++;

    }

    int score = 0;
    
    for(int i = 0; i < visited.size(); i++)
    {
        for(int j = 0; j < visited[0].size(); j++)
        {
            score += bool(visited[i][j]);
        }
    }

    fmt::printf ("%d", score);
    fmt::fprintf(result, "%d", score);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

uint64_t day9part2(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d9-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d9-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 9!\n";
        return -1;
    }

    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d9p2-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d9p2-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 9 pt. 2!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();

    int max = 0;

    fmt::fprintf(result, "%d", max);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d9p1obj = day9part1;
std::function<uint64_t(bool)> d9p2obj = day9part2;