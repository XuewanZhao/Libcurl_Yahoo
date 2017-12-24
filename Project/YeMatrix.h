

#ifndef YeMatrix_h
#define YeMatrix_h
#include <vector>
#include"Category.h"
using namespace std;

typedef vector<double> Vector_d;

//Vector_d+Vector_d
Vector_d operator+(const Vector_d& W,const Vector_d& V);


Vector_d operator-(const Vector_d& W,const Vector_d& V);


Vector_d operator/(const Vector_d& W, const int& a);

//Computing cumulative sum
Vector_d Cumsum(const Vector_d& W);

vector<vector<vector<double>>> SetMatrix(Vector_d  BeatAAR, Vector_d  BeatCAAR, Vector_d  MeetAAR, Vector_d  MeetCAAR, Vector_d  MissAAR, Vector_d  MissCAAR);
vector<vector<string>> Settitle();
#endif /* Matrix_h */
