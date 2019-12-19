#include <iostream>

#include "../lib/data.h"

void input(const std::string&, int&);

void Data::fill()
{
    input("write heads number: ", N);
    input("write tails number: ", M);
    input("write steps number: ", K);
    input("write which position flip over: ", S);
    input("wtite heads number after proceed: ", L);
    
    H = 1; // cause we start count from Head
    T = 0;
    A = N + M;
    B = N - L;
}

void input(const std::string& msg, int& box) {
    std::cout << msg;
    std::cin >> box;
}
