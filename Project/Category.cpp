#include"Category.h"
#include"YeMatrix.h"
#include<algorithm>
#include<numeric>
#include<time.h>
using namespace std;

void RandSelect(Category& StockPool, Category& Sample)
{
	vector<int> index_(StockPool.Ticker.size());
	iota(index_.begin(), index_.end(), 0);
	srand(time(NULL));
	random_shuffle(index_.begin(), index_.end());
	for (unsigned int i = 0; i < SampleNum; i++)
	{
	
		map<string, Stock>::iterator itr = StockPool.Content.find(StockPool.Ticker[index_[i]]);
		if (itr != StockPool.Content.end())
			Sample.Content.insert(pair<string, Stock>(StockPool.Ticker[i], itr->second));
	}
}

void Category::GenAAR()
{
	Vector_d W(DayNum, 0);
	map<string, Stock>::iterator it;
	for (it = Content.begin(); it != Content.end(); it++)
		W = W + it->second.AbnormalReturn;
	W = W / SampleNum;
	AAR = W;
}

void Category::GenCAAR()
{
	CAAR = Cumsum(AAR);
}


void Category::GenAbnormalReturn(vector<string> SPYDate, vector<double> SPYPrice)
{
	for (map<string, Stock>::iterator itr = Content.begin(); itr != Content.end(); )
	{
		itr->second.GenDailyReturn();
		itr->second.GenAbnormalReturn(SPYDate, SPYPrice);
		itr++;
	}

}