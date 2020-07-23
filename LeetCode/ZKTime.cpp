#include "ZKTime.h"
#include<iostream>
#include <ctime>
#include <fstream>
#include<stdio.h>
#include<windows.h>
#pragma comment( lib,"winmm.lib" )
DWORD t1, t2;
void ZKTime::ReStart()
{
	t1 = GetTickCount();
}
void ZKTime::Print(const char * str)
{
	std::cout << str << "--->" << (t2 - t1)*1.0 << "ms" << std::endl;
}