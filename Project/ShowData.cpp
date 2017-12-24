#include"ShowData.h"
#include"YeMatrix.h"
using namespace std;
void Menu(const Category& Beat,const Category& Meet,const Category& Miss,const vector<vector<vector<double>>>& ReturnMatrix)
{
	int c = 0;

	while (c != 4)
	{
		cout << "*******************************************************************" << endl;
		cout << "**Please enter the number in front of the option you want to do. **" << endl;
		cout << "**1.Pull information for one stock from one group.               **" << endl;
		cout << "**2.Show ARR or CAAR for one group.                              **" << endl;
		cout << "**3.Show the Excel graph with CAAR for all 3 groups.             **" << endl;
		cout << "**4.Quit.                                                        **" << endl;
		cout << "*******************************************************************" << endl;
		cout << endl;
		cout << "The number you choose is:"; cin >> c;
		if (c == 1)
			ShowStockInfo(Beat, Meet, Miss);
		else if (c == 2)
			ShowStat(ReturnMatrix);
		else if (c == 3)
			ShowPic(ReturnMatrix);
		else if (c == 4)
			cout <<"Quit." << endl;
		else
			cout << "Please enter a valid number." << endl;
		cout << endl; cout << endl; cout << endl;
	}
}
void ShowStockInfo(const Category& Beat,const Category& Meet,const Category& Miss)
{
	cout << "You choose 1." << endl;
	string sticker;
	cout << "Enter the ticker: "; cin >> sticker;;
	
	map<string, Stock>::const_iterator itr1 = Beat.Content.find(sticker);
	if (itr1 != Beat.Content.end())
		itr1->second.printInfo();
		
	map<string, Stock>::const_iterator itr2 = Meet.Content.find(sticker);
	if (itr2 != Meet.Content.end())
		itr2->second.printInfo();
	map<string, Stock>::const_iterator itr3 = Miss.Content.find(sticker);
	if (itr3 != Miss.Content.end())
		itr3->second.printInfo();
}
void ShowStat(const vector<vector<vector<double>>>& ReturnMatrix)
{
	cout << "You choose 2." << endl;
	int indicator1, indicator2, a, b;
	cout << "1.Show AAR."<<endl; 
	cout << "2.Show CAAR." << endl;
	cin >> indicator2;
	if (indicator2 != 1 && indicator2 != 2)
		cout << "Enter a valid number please." << endl;
	cout << "1.Show group Beat." << endl;
	cout << "2.Show group Meet." << endl;
	cout << "3.Show group Miss." << endl;
	cin >> indicator1;
	if (indicator1 != 1 && indicator1 != 2 && indicator1 != 3)
		cout << "Enter a valid number please." << endl;
	NumericMatrix<double, long> Data(1, 61);
	b = indicator1 - 1;
	a = indicator2 - 1;
	for (long i = 1; i <= 61; i++)
		Data(1, i) = ReturnMatrix[b][a][i - 1];
	Vector<double, long> xarr(1);
	Vector<double, long> yarr(61);
	xarr[1] = 1;
	yarr[yarr.MinIndex()] = 1;
	for (long i = yarr.MinIndex() + 1; i <= yarr.MaxIndex(); i++)
		yarr[i] = yarr[i - 1] + 1;
	vector<vector<string>>title;
	title = Settitle();
	printMatrixInExcel(Data, xarr, yarr, title[a][b]);
}

void ShowPic(const vector<vector<vector<double>>>& ReturnMatrix)
{
	cout << "You choose 3." << endl;
	Vector<double, long> CAARx1(61);
	Vector<double, long>CAARx2(61);
	Vector<double, long>CAARx3(61);
	Vector<double, long>CAARy1(61);
	Vector<double, long>CAARy2(61);
	Vector<double, long>CAARy3(61);
	CAARx1[CAARx1.MinIndex()] = -30.0;
	CAARx2[CAARx2.MinIndex()] = -30.0;
	CAARx3[CAARx3.MinIndex()] = -30.0;
	for (long i = CAARx1.MinIndex() + 1; i <= CAARx1.MaxIndex(); i++)
	{
		CAARx1[i] = CAARx1[i - 1] + 1;
		CAARx2[i] = CAARx2[i - 1] + 1;
		CAARx3[i] = CAARx3[i - 1] + 1;
	}

	for (long i = CAARy1.MinIndex(); i <= CAARy1.MaxIndex(); i++)
	{
		CAARy1[i] = ReturnMatrix[0][1][i - 1];
		CAARy2[i] = ReturnMatrix[1][1][i - 1];
		CAARy3[i] = ReturnMatrix[2][1][i - 1];
	}

	list<std::string> labels;// Names of each vector
	list<Vector<double, long> > yyy;
	labels.push_back("Beat");
	labels.push_back("Meet");
	labels.push_back("Miss");

	yyy.push_back(CAARy1);
	yyy.push_back(CAARy2);
	yyy.push_back(CAARy3);

	printInExcel(CAARx1, labels, yyy, "CAAR", "T/days", "return");
	
}