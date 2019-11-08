#include <iostream>
#include <cmath>
using namespace std;
int canh, n;
int A[100];

bool bac1(int dinh)
{   int bac;
    bool bac2;
    bac2 = true;
    bac = 0;
    for (int i = 0; i < 2*n+1; i++)
    {
        if (A[i] == dinh) 
        {
            bac = bac + 1;
            if (bac > 1) 
            {
                bac2 = false;
				break;     
            }
        }
        if (i == 2*n+1)
        	{
        		bac2 = false;
        		break;
    		}
    }
    return (bac2);
}
void prufer()
    {	int dinh;
        while (canh > 1)
        {
            for (int dinh=1; dinh<=n; dinh++)
            {
                if (bac1(dinh) == true ) 
                {
                    for (int j= 0; j < 2*n; j++)
                    if (A[j] == dinh) 
                    {
                        if ( j%2 == 0 )
                        {
                            A[j] = 0;
                            cout << A[j+1];
                            A[j+1] = 0;
                        }
                        if ( j%2 == 1 )
                        {
                            A[j] = 0 ;
                            cout << A[j-1];
                         	A[j-1] = 0;
                        }
                    cout << " ";
                    canh = canh -1;
                    exit;
                    }
            	}
            }
        prufer();
        }
    }

int main() 
 {  int i,a,b;
    cin >> canh;
    n = canh;
     for ( i = 0; i < canh ; i++)
        {
            cin >> A[i*2] >> A[i*2+1];
        } // Nhap du lieu**//
    prufer();
}
