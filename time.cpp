#include <iostream>
using namespace std;
#include <string>
#include <time.h>


int main()
{
	char szResult[32] = {0};
	time_t lTime;
	struct tm *pstTmTime;
	time(&lTime);
	pstTmTime = localtime(&lTime);
	strftime(szResult, 32, "%Y-%m-%d ", pstTmTime);
	cout<<szResult<<endl;
	cout<<lTime<<endl;

// 	time_t lWeekTime = lTime-24*3600*7;
// 	cout<<endl<<"一周前的时间"<<endl;
// 	cout<<lWeekTime<<endl;
// 	pstTmTime = localtime(&lWeekTime);
// 	memset(szResult, 0, 32);
// 	strftime(szResult, 32, "%Y-%m-%d ", pstTmTime);
// 	cout<<szResult<<endl;

//	cout<<endl<<"一个月前的时间"<<endl;
	
	cout<<pstTmTime->tm_mday<<endl;
	cout<<pstTmTime->tm_mon<<endl;
	cout<<pstTmTime->tm_year<<endl;
	cout<<pstTmTime->tm_wday<<endl;
	cout<<pstTmTime->tm_yday<<endl;
 	
	cout<<endl<<"==========="<<endl;
	pstTmTime->tm_mon -= 1;
	cout<<pstTmTime->tm_mday<<endl;
	cout<<pstTmTime->tm_mon<<endl;
	cout<<pstTmTime->tm_year<<endl;
	cout<<pstTmTime->tm_wday<<endl;
	cout<<pstTmTime->tm_yday<<endl;

	strftime(szResult, 32, "%Y-%m-%d ", pstTmTime);
	cout<<szResult<<endl;

	return 0;
}