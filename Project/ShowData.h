#include"ExcelDriver\ExcelDriver.hpp"
#include"ExcelDriver\stdafx.h"
#include"ExcelDriver\BitsAndPieces\StringConversions.hpp"
#include"ExcelDriver\ExcelMechanisms.hpp"
#include"ExcelDriver\VectorsAndMatrices\NumericMatrix.cpp"
#include"ExcelDriver\ExceptionClasses\DatasimException.hpp"
#include"Category.h"
using namespace std;

#ifndef ShowData
#define ShowData

void Menu(const Category& Beat,const Category& Meet,const Category& Miss,const vector<vector<vector<double>>>& ReturnMatrix);
void ShowStockInfo(const Category& Beat,const Category& Meet,const Category& Miss);
void ShowStat(const vector<vector<vector<double>>>& ReturnMatrix);
void ShowPic(const vector<vector<vector<double>>>& ReturnMatrix);

#endif 

