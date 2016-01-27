/*
 * Implementation of Karatsuba multiplication algorithm.
 */

/* 
 * File:   main.cpp
 * Author: ademi
 *
 * Created on January 26, 2016, 9:51 AM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

long long multiply(long long x, long long y){
    if(x<100 || y<100)return x*y;
    int i_x,i_y;
    for(i_x=1;;i_x++)if((x/pow(10,i_x))<1)break;
    for(i_y=1;;i_y++)if((y/pow(10,i_y))<1)break;
    int max = (int)fmax(i_x,i_y);
    int multiplier = ceil(max/2);
    
    long long a = floor(x/pow(10,multiplier));
    long long b = fmod(x,pow(10,multiplier));
    long long c = floor(y/pow(10,multiplier));
    long long d = fmod(y,pow(10,multiplier));

    long long z1 =multiply(a,c);
    long long z2 =multiply(b,d);
    long long z3 =multiply((a+b),(c+d));
    
    return (z1*pow(10,multiplier*2)+(z3-z1-z2)*pow(10,multiplier)+z2);
    }
int main(int argc, char** argv) {
    long long x,y;
    cin >>x;
    cin >>y;
    cout << multiply(x,y);
    return 0;
}

