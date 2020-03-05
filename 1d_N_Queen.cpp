#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	int ans=1;
	int n=8;
	int q[n]={0};
	int c=0; 			//no need r, cause q[c] = r
	q[0]= 0;
	
	//NEXT COLUMN
	NC: c++;
	if (c==n)
		goto PRINT;
	
	q[c] = -1;
	
	//NEXT ROW
	NR: q[c]++;
	if (q[c]==n)
		goto BACKTRACK;
		
	//Row test, Up+Down Diagonal Test
	for (int i=0; i<c; i++)
		if (q[c]==q[i] || (c-i)== abs(q[c]-q[i]))
			goto NR;
	
	goto NC;
	
	//BACKTRACK
	BACKTRACK: c--;
	if (c==-1)
		return 0;
	goto NR;
	
	//PRINT
	PRINT:
		cout << "Solution " << ans << ":" << endl;
		for (int row=0; row<n ;row++)
		{
			for (int col=0; col<n; col++)
			{
				if(q[col]==row)
					cout << "1" << " ";
				else
					cout << "0" << " ";
			}
			cout << endl;
		}
		cout << endl;
		ans++;
		goto BACKTRACK;
		
	return 0;
}
