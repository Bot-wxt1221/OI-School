#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
	int i=0;
    while(!ans.eof()){
    	++i;
        int x = ouf.readInt();
        int y = ouf.readInt();
        int n = ans.readInt();
//        cerr<<x<<' '<<y<<' '<<n<<'\n';
//        ans.readEoln();
        while(n--)
        {
        	int t=ans.readInt();
//        	cerr<<t<<'\n';
        	if(t==x)	continue;
        	if(t==y)	continue;
        	quitf(_wa, "The answer is wrong: on line %d , expected %d , found %d %d",i,t,x,y);
		}
//        ans.readEoln();
    }
    quitf(_ok, "The answer is correct.");
    return 0;

}
