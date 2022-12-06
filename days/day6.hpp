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

    if(testing)
        { results.open("./out/d6p1-t-out.txt", std::ifstream::in); }
    else{ results.open("./out/d6p1-out.txt",   std::ifstream::in); }

    if(!results.is_open()) {
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

    results << score;

    in_values.close();
    results.close();

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
        std::cerr << "Can't open input file for day 5!\n";
        return -1;
    }

    if(testing)
        { results.open("./out/d6p2-t-out.txt", std::ifstream::in); }
    else{ results.open("./out/d6p2-out.txt",   std::ifstream::in); }

    if(!results.is_open()) {
        std::cerr << "Can't open output file for day 6 pt. 1!\n";
        return -1;
    }
    /* boilerplate end */
    
    auto time_start = std::chrono::high_resolution_clock::now();
    int score = 0;
    std::string line;
    std::getline(in_values,line);

    std::string    message_marker;
    std::set<char> overlap_check ;

    for(int i = 0; i < 14; i++)
    { message_marker.push_back(line[i]); }

    for(int i = 13; i <= line.size(); i++)
    {
        overlap_check.clear();
        for(int j = 0; j < 14; j++)
        {
            overlap_check.insert(message_marker[j]);
        }
        if( overlap_check.size() == 14 ) { score = i; break; }
        
        message_marker.erase(0,1);
        message_marker.push_back(line[i]);
    }

    std::cout << score <<std::endl;

    for(int i = 0; i < message_marker.size(); i++)
    {
        std::cout << message_marker[i];
    } std::cout << std::endl;

    results << score;

    in_values.close();
    results.close();

    uint64_t time_total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
    
    return time_total;
} 

std::function<uint64_t(bool)> d6p1obj = day6part1;
std::function<uint64_t(bool)> d6p2obj = day6part2;