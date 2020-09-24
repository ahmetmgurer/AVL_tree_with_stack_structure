/**
* @file Utils.cpp
* @description büyük olan veriyi döndüren kaynak dosyası.
* @course 1/A
* @assignment 2. Ödev
* @date 26.08.2020
* @author Ahmet Mücahit Gürer
*/
#include "Utils.h"

using namespace std;

 int  Utils::max(int a, int b)
{
	int max = 0;
	(a > b) ? max = a : max = b;
	return max;
}


