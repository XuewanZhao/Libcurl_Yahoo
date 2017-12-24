#include <fstream>
#include <sstream>  
#include"GetData.h"
#include"YeMatrix.h"
#include"ShowData.h"
#include<thread>
using namespace std;
int main()
{
	string fileList[3] = { "Beat.txt","Meet.txt","Miss.txt" };
	Category Beat, Meet, Miss;
	Vector_d BeatAAR(61), BeatCAAR(61), MeetAAR(61), MeetCAAR(61), MissAAR(61), MissCAAR(61);
	//get SPY
	Stock SPY("SPY", "2017-05-25", "2017-11-09", "0", "0");
	//Get Whole Pool.
	GetWholePool(Beat, Meet, Miss, fileList);
	curl_global_init(CURL_GLOBAL_ALL);
	thread t1{ GetStockPrice, ref(Beat) };
	thread t2{ GetStockPrice, ref(Meet) };
	thread t3{ GetStockPrice, ref(Miss) };
	thread t4{ GetSPYPrice, ref(SPY) };
	t1.join(); t2.join(); t3.join(); t4.join();
	for (int i = 0; i < 100; i++)
	{
	Category Beat_sample, Meet_sample, Miss_sample;
	//Select the sample and get price for stocks in sample.
	RandSelect(Beat, Beat_sample);
	RandSelect(Meet, Meet_sample);
	RandSelect(Miss, Miss_sample);
	//Computing Abnormal Return for each stock
    Beat_sample.GenAbnormalReturn(SPY.Date, SPY.Price);
	Meet_sample.GenAbnormalReturn(SPY.Date, SPY.Price);
	Miss_sample.GenAbnormalReturn(SPY.Date, SPY.Price);
	//Computing AAR and CAAR
	Beat_sample.GenAAR();
	Beat_sample.GenCAAR();
	Meet_sample.GenAAR();
	Meet_sample.GenCAAR();
	Miss_sample.GenAAR();
	Miss_sample.GenCAAR();
	BeatAAR = BeatAAR + Beat_sample.AAR;
	BeatCAAR = BeatCAAR + Beat_sample.CAAR;
	MeetAAR = MeetAAR + Meet_sample.AAR;
	MeetCAAR = MeetCAAR + Meet_sample.CAAR;
	MissAAR = MissAAR + Miss_sample.AAR;
	MissCAAR = MissCAAR + Miss_sample.CAAR;
    }
	vector<vector<vector<double>>> ReturnMatrix;
	ReturnMatrix = SetMatrix(BeatAAR, BeatCAAR, MeetAAR, MeetCAAR, MissAAR, MissCAAR);
	Menu(Beat, Meet, Miss, ReturnMatrix);
	getchar();
	return 0;
}
