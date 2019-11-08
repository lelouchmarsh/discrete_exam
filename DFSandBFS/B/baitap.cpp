#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include <queue>
using namespace std;
char  SBS[5757][6];
int check[5757];
int A[5757];
int dem, num_tplt, co_string1, co_string2,q, co_string3;
string string1, string2, string3;
queue<int> myqueue;
bool lienthong( char string1[5], char string2[5])
{   bool lienthong1;
    lienthong1= true;
    int check_list[5];
    for (int j=0; j<=5; j++) check_list[j] = j+1;
    for (int i=1;i<=4;i++)
		{for (int j=0; j<=5; j++)
			{
				if ((string1[i] == string2 [j]) && (check_list[j] !=0))
					{
						check_list[j] = 0;
						break;
					}
				if (j==5)
				{
					lienthong1=false;
					return(lienthong1);
					exit;
				}
            }
        }           
    return (lienthong1);
}
bool lienthongmanh(char string1[5], char string2[5])
{
	if (lienthong(string1,string2) && lienthong(string2,string1)) 
		{
			return(true);
		}
	else return(false);
}
// Kiem tra thoa man tinh chat //
void open()
 { 
   fstream infile; 
   infile.open("F://discrete//DFSandBFS//A//sandtext.txt", ios::in);
   dem =0;
   cout << "\n===========================\n" ;
   cout << "Doc du lieu co trong file!" << endl; 
   while (infile.eof()!=true)
   {
   infile >> SBS[dem];
   check[dem] = 0;
   dem = dem+1;
    }

   infile.close(); 
} // Doc du lieu
void dfs(int dinh)
{   if (check[dinh]==0)
    {   check[dinh] = 1;
   	cout << SBS[dinh] << "   ";   
        for (int j=0; j<=dem; j++)
        if ((lienthongmanh(SBS[dinh] , SBS[j])) && (check[j] == 0))
        {
            dfs(j);
             }
    }
}
void B1()
{ open();
   num_tplt = 0;
   int j=1;
   for (int i=0; i<=dem; i++) 
   if (check[i] == 0)
    {
    num_tplt= num_tplt+1;
    dfs(i);
    cout << endl;
    cout << endl;
    cout << endl;
   }
	num_tplt = num_tplt-1;
   cout << "so thanh phan lien thong manh"<<endl;
   cout << num_tplt;
 }
void bfs(int dinh)
{
    myqueue.push(dinh); // day dinh vao queue
    check[dinh] = 1;   // check dinh
    while (!myqueue.empty())
    {
        int u = myqueue.front(); // gan u = phan tu dau ( O day la dinh)
        myqueue.pop();
		A[q] = u;
		q = q+1;  // loai bo phan tu dau 
        for (int j=0; j<=dem; j++)
           { if ((lienthongmanh(SBS[u] , SBS[j])) && (check[j] == 0)) // lien thong va chua duoc check
            {	
                myqueue.push(j);
                check[j] = check[u] +1;
                if (j == co_string2) 
				{
				exit;
            }
           }
    }
}
}
void B3()	
{   open();
	cout << "Nhap tu thu nhat";
	cin >> string1;
	cout << "Nhap tu thu hai";
	cin >> string2;
	for (int i=0; i<=dem; i++)
		{
			if (SBS[i] == string1)
				{ co_string1 = i;
				break;
					}
		}
	for (int i=0; i<=dem; i++)
		{
			if (SBS[i] == string2)
				{
					co_string2 = i;
					break;
				}
		}
	// Toa do cua cac tu nhap vao
	 bfs(co_string1);
	 A[q] = co_string2;
	 while (q>0)
	 	{for (int i=q-1; i>=0; i--)
            if ((lienthongmanh(SBS[A[q]] , SBS[A[i]])) && ( check[A[q]] != check[A[i]]))
            {
            cout << SBS [A[q]] << " <--" ;
            q = i;
            }
		 }
	 cout << string1;
}
void B2()
{
	open();
 	cout << "nhap u" << endl;
 	cin >> string3;
 		for (int i=0; i<=dem; i++)
		{
			if (SBS[i] == string3)
				{ co_string3 = i;
				break;
					}
	}
	cout << co_string3;
	dfs(co_string3);
}
int main()
{	cout << "Cau B1";
	B1();
	cout << "===============================================================================" << endl;
	cout << "Cau B2";
	cout << "===============================================================================" << endl;
	B2();
	cout << "Cau B3";
	B3();
}

 	
