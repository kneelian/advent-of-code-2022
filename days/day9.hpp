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

static inline int sign(int x) { return x>0 ? 1 : x<0 ? -1 : 0; }

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
    else{ result = std::fopen("./out/d9p1-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 9 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();
    std::string line;
    std::vector<std::string> temp;
    std::array<std::array<int, 512>, 512> visited;
    std::array<int,2> xpos, ypos;

    for(int i = 0; i < xpos.size(); i++)
    {
        xpos[i] = ypos[i] = visited.size()/2;
    }

    for(int i = 0; i < visited.size(); i++)
    {
        for(int j = 0; j < visited.size(); j++)
        {
            visited[i][j] = 0;
        }
    }

    while(std::getline(in_values, line))
    {
        temp = split<std::string>(line, " ");
        char dir = temp[0][0]; // 'U', 'D', 'L', 'R'
        int amt  = std::atoi(temp[1].c_str());

        switch(dir)
        {
            case 'U': ypos[0]--; break;
            case 'D': ypos[0]++; break;
            case 'L': xpos[0]--; break;
            case 'R': xpos[0]++; break;
        }

        while(amt-- > 0)
        {
            int dx = 0, dy = 0;

            for (int i = 1; i < xpos.size(); i++) {
                dx = xpos[i-1] - xpos[i];
                dy = ypos[i-1] - ypos[i];

                if (abs(dx) <= 1 && abs(dy) <= 1)
                    break;

                xpos[i] += sign(dx);
                ypos[i] += sign(dy);
            }
        }
        visited[xpos[1]][ypos[1]] |= 1;
    }

    int score = 0;
    

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
    std::string line;
    std::vector<std::string> temp;
    std::array<std::array<int, 512>, 512> visited;
    std::array<int,2> xpos, ypos;

    std::cout<<"are we segfaulting\n"<<std::endl;

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d9p1obj = day9part1;
std::function<uint64_t(bool)> d9p2obj = day9part2;