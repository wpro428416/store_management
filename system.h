#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

class Data
{
private:
public:
    int number;//±àºÅ
    string brand_name;
    int amount;
    Data(int number,string brand_name);
};

class Map
{
private:
    Data * computer[20];
    int tag;
    int temp_number;
    int temp_amount;
    string temp_brand_name;
public:
    Map();
    bool check();
    void print_mainMap();
    void print_ini();
    void print_deposit();
    void print_getOut();
    void print_addBrand();
    void print_skim();
    void print_clear();
    bool change(int number,int amount);
    bool add(int number,string brand_name);
    void record();
};


#endif // SYSTEM_H_INCLUDED
