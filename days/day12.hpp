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
#include <unordered_set>

#define FMT_HEADER_ONLY

#include "useful.hxx"
#include "fmt/core.h"
#include "fmt/printf.h"

uint64_t day12part1(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d12-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d12-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 12!\n";
        return -1;
    }

    /**/std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d12p1-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d12p1-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 12 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */

    auto time_start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> map;
    std::string line;

    int start_column = 0, start_row = 0, end_column = 0, end_row = 0;
    int found = 0;
    int temp = 0;

    while(std::getline(in_values, line))
    {
        if(!(found == 2))
        {
            for(int i = 0; i < line.size(); i++)
            {
                if(line[i] == 'S')
                {
                    start_column = i; start_row = temp;
                    line[i] = 'a';
                    found++;
                } else
                if(line[i] == 'E')
                {
                    end_column = i; end_row = temp;
                    line[i] = 'z';
                    found++;
                }
            }
        }
        map.push_back(line);
        temp++;
    }

    std::vector<std::array<int, 144>> visited_map; visited_map.resize(43);
    std::deque<std::array<int,3>> values_deque;

    fmt::printf("start: %d,%d = %c; end: %d,%d = %c\n", start_row, start_column, map[start_row][start_column], end_row, end_column, map[end_row][end_column]);

    for(int i = 0; i < map.size(); i++)
    {
        fmt::printf("%s\n",map[i].c_str());
    }

    fmt::printf("map is %dx%d rows and columns\n", map[0].size(), map.size());

    values_deque.push_front({ start_row, start_column, 0 });

    // map holds rows, map[i] holds chars in rows

    int curr_row = 0, curr_column = 0;
    int currval = 0;

    int score = 0;

    while(!values_deque.empty())
    {
        curr_row     = values_deque.front()[0]; // row
        curr_column  = values_deque.front()[1]; // column
        currval      = values_deque.front()[2]; // value

        values_deque.pop_front();

        if(curr_row == end_row and curr_column == end_column) 
        { 
            score = currval; 
            fmt::printf("reached_the_end\n"); break; 
        } else
        if(visited_map[curr_row][curr_column]) 
        {
            //fmt::printf("dupe found\n"); 
            continue; 
        } else
        visited_map[curr_row][curr_column]++;

        for(int r = curr_row-1; r <= curr_row+1; r++)
        {
            for(int c = curr_column-1; c <= curr_column+1; c++)
            {
                if
                (
                    (c == curr_column or r == curr_row) and (c != curr_column and r != curr_row)
                    and (c > 0) and (r > 0) and (c < map[0].size()) and (r < map.size())
                )
                {
                    if(map[r][c] <= map[curr_row][curr_column]+1)
                    {
                        values_deque.push_back({r, c, currval+1});
                    }
                }
            }
        }
    }

/*
q=deque([(start[0],start[1],0)])
visited=set()

while q:
    a,b,c=q.popleft()
    if (a,b) == end:
        print(c)
        break
    if (a,b)in visited:
        continue
    visited.add((a,b))
    for i in range(a-1,a+2):
        for r in range(b-1,b+2):
            if len(x) >i>0 and len(x[0])>r>0 and (i==a or r==b):
                if ord(x[i][r]) <= ord(x[a][b])+1:
                    q.append((i,r,c+1))


    values_deque.push_front({ start_x, start_y, 0 });

    int curr_x = 0, curr_y = 0;
    int currval = 0;

    int score = 0;

    while(!values_deque.empty())
    {
        curr_x  = values_deque.front()[0]; // column
        curr_y  = values_deque.front()[1]; // row
        currval = values_deque.front()[2]; // value

        values_deque.pop_front();

        //fmt::printf("curr_x, curr_y, currval: %d %d %d\n", curr_x, curr_y, currval);

        if(curr_x == end_x and curr_y == end_y) 
        { 
            score = currval; 
            fmt::printf("reached_the_end\n"); break; 
        } else
        if(visited_map[curr_y][curr_x]) 
        {
            //fmt::printf("dupe found\n"); 
            continue; 
        }
        visited_map[curr_y][curr_x]++;

        for(int i = curr_x-1; i <= curr_x+1; i++)
        {
            for(int j = curr_y-1; j <= curr_y+1; j++)
            {
                if
                (
                    (j == curr_x or i == curr_y) and
                    (i >= 0) and (j >= 0) and (i < 41) and (j < 142)
                )
                {
                    if((map[curr_x][curr_y]+1 >= map[i][j]))
                        //fmt::printf("(%d, %d: %c) vs (%d, %d: %c)\n", curr_x, curr_y, map[curr_y][curr_x], i, j, map[i][j]);
                        values_deque.push_front({i, j, currval+1});/
                }
            }
        }
    } **/

    for(int i = 0; i < visited_map.size(); i++)
    {
        for(int j = 0; j < visited_map[0].size(); j++){
        fmt::printf("%d", visited_map[i][j]);}fmt::printf(" <- %d\n", i);
    }

    fmt::printf("%d\n", score);
    fmt::fprintf(result, "%d", score);
    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
}

uint64_t day12part2(bool testing)
{
    /* boilerplate */
    if(testing)
        { in_values.open("./in/d12-t-in.txt", std::ifstream::in); }
    else{ in_values.open("./in/d12-in.txt",   std::ifstream::in); }
    
    if(!in_values.is_open()) { 
        std::cerr << "Can't open input file for day 12!\n";
        return -1;
    }

    /**/std::FILE* result;

    if(testing)
        { result = std::fopen("./out/d12p2-t-out.txt", "r+"); }
    else{ result = std::fopen("./out/d12p2-out.txt"  , "r+"); }

    if(!result) {
        std::cerr << "Can't open output file for day 12 pt. 2!\n";
        return -1;
    }
    /* boilerplate end */
    auto time_start = std::chrono::high_resolution_clock::now();

    int score = 0;

    std::fprintf(result, "%d", score);
    in_values.close();
    std::fclose(result);

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d12p1obj = day12part1;
std::function<uint64_t(bool)> d12p2obj = day12part2;