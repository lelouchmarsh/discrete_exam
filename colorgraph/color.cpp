#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include<cmath>
using namespace std;
int so_dinh, so_canh , dinh_max, bac_max;
int list_canh[100][100];
int color[100];
void open()
 { 	int a,b;
	fstream infile; 
    infile.open("F://discrete//colorgraph//dothi.txt", ios::in);
    cout << "\n===========================\n" ;
    cout << "Doc du lieu co trong file!" << endl; 
    infile >> so_dinh >> so_canh;
    while (infile.eof()!=true) 
   {
       infile >> a >> b;
       list_canh[a][b] = 1;
       list_canh[b][a] = 1;
   }
   infile.close(); 
 } // Doc du lieu
int bac(int dinh)
{
    int bac1=0;
    for (int i=1; i<=so_dinh; i++)
        {  
            if (list_canh[dinh][i] == 1) 
            {
                bac1 = bac1+1;
            }
        }
    return (bac1);
} // tinh so bac cua dinh
void tim_dinh_max()
{   
    bac_max = 0;
    for (int i=1; i<=so_dinh; i++)
         if (bac(i) >= bac_max)
         {
             bac_max = bac(i);
             dinh_max = i;
         }
}
  // Tim dinh co bac max
void xoa_dinh(int dinh)
{
    for (int i=1; i<=so_dinh; i++)
       { list_canh[dinh][i] = 0;
        list_canh[i][dinh] = 0;
        }
}

 // xoa dinh ra khoi list
void quet(int dinh)
{
	for (int i=1; i<=so_dinh; i++)
		if ((list_canh[dinh][i] == 0) && (color[i] ==0))
		{
            color[i] = color [dinh];
		}
    xoa_dinh(dinh);
}
int main()
{   int j=0;
    open();
    tim_dinh_max();
    while( bac_max>0) 
        {   
            tim_dinh_max();
            color[dinh_max] = j;
            quet(dinh_max);
            j=j+1;
        }
    // gan mau
    cout << "So mau can dung la  " << j-1 <<endl;
    for (int i=1; i<=so_dinh; i++)
    	{
    		cout << "Dinh " << i << " to mau  " << color[i] << endl;
    	}
}
