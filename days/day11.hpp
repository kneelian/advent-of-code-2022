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

struct Monkey
{
    std::vector<uint64_t> items;

    int op; // 0 add 1 mul2 sqr
    int arg2; // 0 is old

    int divtest;
    int true_dest;
    int false_dest;
};

#define ADD 0
#define MUL 1
#define SQR 2

uint64_t day11part1(bool testing)
{
    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d11p1-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d11p1-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 11 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();

    std::vector<Monkey> monkies; 
    monkies.resize(8);
    
    monkies[0] = {{98, 70, 75, 80, 84, 89, 55, 98}, MUL, 2,  11, 1, 4};
    monkies[1] = {{59},                             SQR, 1,  19, 7, 3};
    monkies[2] = {{77, 95, 54, 65, 89},             ADD, 6,  7 , 0, 5};
    monkies[3] = {{71, 64, 75},                     ADD, 2,  17, 6, 2};
    monkies[4] = {{74, 55, 87, 98},                 MUL, 11, 3 , 1, 7};
    monkies[5] = {{90, 98, 85, 52, 91, 60},         ADD, 7,  5 , 0, 4};
    monkies[6] = {{99, 51},                         ADD, 1,  13, 5, 2};
    monkies[7] = {{98, 94, 59, 76, 51, 65, 75},     ADD, 5,  2 , 3, 6};
    

    /*monkies[0] = {{79, 98}, MUL, 19,  23, 2, 3};
    monkies[1] = {{54, 65, 75, 74}, ADD, 6,  19, 2, 0};
    monkies[2] = {{79, 60, 97}, SQR, 1,  13 , 1, 3};
    monkies[3] = {{74}, ADD, 3,  17, 0, 1};*/

    std::array<uint64_t, 8> monky_toss = {0, 0, 0, 0, 0, 0, 0, 0};

    for(int j = 0; j < 20; j++)
    {
        /*fmt::printf("After round: #%d, monkeys:\n", j);
        for(int k = 0; k < monkies.size(); k++)
        {
            fmt::printf("\tmonkie #%d contains: ", k);
            for(int l = 0; l < monkies[k].items.size(); l++)
                { fmt::printf("%d ", monkies[k].items[l]); }
            fmt::printf("\n");
        }
        fmt::printf("\n");*/

        for(int i = 0; i < monkies.size(); i++)
        {
            while(!monkies[i].items.empty())
            {
                if(monkies[i].op == ADD)
                { monkies[i].items.front() += monkies[i].arg2;} 
                else
                if(monkies[i].op == MUL)
                { monkies[i].items.back() *= monkies[i].arg2;}
                else // sqr
                { monkies[i].items.back() *= monkies[i].items.back(); }
                monkies[i].items.back() /= 3;

                if(!(monkies[i].items.front() % monkies[i].divtest))
                { monkies[monkies[i].true_dest ].items.push_back(monkies[i].items.back()); } 
                else
                { monkies[monkies[i].false_dest].items.push_back(monkies[i].items.back()); } 
                monkies[i].items.pop_back(); 
                monky_toss[i] += 1;
            }
        }
    }

    /*fmt::printf("After round: #%d, monkeys:\n", 20);
    for(int k = 0; k < monkies.size(); k++)
    {
        fmt::printf("\tmonkie #%d contains: ", k);
        for(int l = 0; l < monkies[k].items.size(); l++)
            { fmt::printf("%d ", monkies[k].items[l]); }
        fmt::printf("\n");
    }
    fmt::printf("\n");*/

    uint64_t first_monky  = 0, 
             second_monky = 0;
    for(int i = 0; i < monky_toss.size(); i++)
    {
        if(monky_toss[i] > first_monky)
        {
            second_monky = first_monky;
            first_monky  = monky_toss[i]; 
        } else
        if(monky_toss[i] > second_monky)
        { second_monky = monky_toss[i]; }
    }

    fmt::fprintf(result, "%d * %d == %d\n", int(first_monky), int(second_monky), int(first_monky) * int(second_monky));

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
}

uint64_t day11part2(bool testing)
{
    std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d11p2-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d11p2-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 11 pt. 2!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();

    std::vector<Monkey> monkies; 
    monkies.resize(8);
    
    monkies[0] = {{98, 70, 75, 80, 84, 89, 55, 98}, MUL, 2,  11, 1, 4};
    monkies[1] = {{59},                             SQR, 1,  19, 7, 3};
    monkies[2] = {{77, 95, 54, 65, 89},             ADD, 6,  7 , 0, 5};
    monkies[3] = {{71, 64, 75},                     ADD, 2,  17, 6, 2};
    monkies[4] = {{74, 55, 87, 98},                 MUL, 11, 3 , 1, 7};
    monkies[5] = {{90, 98, 85, 52, 91, 60},         ADD, 7,  5 , 0, 4};
    monkies[6] = {{99, 51},                         ADD, 1,  13, 5, 2};
    monkies[7] = {{98, 94, 59, 76, 51, 65, 75},     ADD, 5,  2 , 3, 6};
    

    /*monkies[0] = {{79, 98}, MUL, 19,  23, 2, 3};
    monkies[1] = {{54, 65, 75, 74}, ADD, 6,  19, 2, 0};
    monkies[2] = {{79, 60, 97}, SQR, 1,  13 , 1, 3};
    monkies[3] = {{74}, ADD, 3,  17, 0, 1};*/

    std::array<uint64_t, 8> monky_toss = {0, 0, 0, 0, 0, 0, 0, 0};

    for(int j = 0; j < 10000; j++)
    {
        /*fmt::printf("After round: #%d, monkeys:\n", j);
        for(int k = 0; k < monkies.size(); k++)
        {
            fmt::printf("\tmonkie #%d contains: ", k);
            for(int l = 0; l < monkies[k].items.size(); l++)
                { fmt::printf("%d ", monkies[k].items[l]); }
            fmt::printf("\n");
        }
        fmt::printf("\n");*/

        for(int i = 0; i < monkies.size(); i++)
        {
            while(!monkies[i].items.empty())
            {
                if(monkies[i].op == ADD)
                { monkies[i].items.back() += monkies[i].arg2;} 
                else
                if(monkies[i].op == MUL)
                { monkies[i].items.back() *= monkies[i].arg2;}
                else // sqr
                { monkies[i].items.front() *= monkies[i].items.back(); }
                monkies[i].items.back() %= 9699690;

                if(!(monkies[i].items.back() % monkies[i].divtest))
                { monkies[monkies[i].true_dest ].items.push_back(monkies[i].items.back()); } 
                else
                { monkies[monkies[i].false_dest].items.push_back(monkies[i].items.back()); } 
                monkies[i].items.pop_back(); 
                monky_toss[i] += 1;
            }
        }
    }

    /*fmt::printf("After round: #%d, monkeys:\n", 20);
    for(int k = 0; k < monkies.size(); k++)
    {
        fmt::printf("\tmonkie #%d contains: ", k);
        for(int l = 0; l < monkies[k].items.size(); l++)
            { fmt::printf("%d ", monkies[k].items[l]); }
        fmt::printf("\n");
    }
    fmt::printf("\n");*/

    uint64_t first_monky  = 0, 
             second_monky = 0;
    for(int i = 0; i < monky_toss.size(); i++)
    {
        if(monky_toss[i] > first_monky)
        {
            second_monky = first_monky;
            first_monky  = monky_toss[i]; 
        } else
        if(monky_toss[i] > second_monky)
        { second_monky = monky_toss[i]; }
    }

    fmt::fprintf(result, "%llu * %llu == %llu\n", first_monky, second_monky, first_monky * second_monky);

    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
}

std::function<uint64_t(bool)> d11p1obj = day11part1;
std::function<uint64_t(bool)> d11p2obj = day11part2;