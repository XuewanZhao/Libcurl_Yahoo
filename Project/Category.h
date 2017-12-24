#ifndef Category_h
#define Category_h
#include"Stock.h"
#include<map>
#define SampleNum 40
using namespace std;


class Category
{
public:
	map<string, Stock> Content;
	vector<string> Ticker;
	vector<double> AAR;
	vector<double> CAAR;

	void GenAbnormalReturn(vector<string> SPYDate, vector<double> SPYPrice);
	void GenAAR();
	void GenCAAR();
};

void RandSelect(Category& StockPool, Category& Sample);


#endif // !Category_h
