#include <bits/stdc++.h>
#define SIZE 1000001
using namespace std;


class Timer
{
    using clk = std::chrono::steady_clock;
    using microseconds = std::chrono::microseconds;

    clk::time_point tsb;
    clk::time_point tse;

public:

    void clear() { tsb = tse = clk::now(); }
    void start() { tsb = clk::now(); }
    void stop() { tse = clk::now(); }

    friend std::ostream& operator<<(std::ostream& o, const Timer& timer)
    {
        return o << timer.secs();
    }

    // return time difference in seconds
    double secs() const
    {
        if(tse <= tsb)
            return 0.0;
        auto d = std::chrono::duration_cast<microseconds>(tse - tsb);
        return d.count() / 1000000.0;
    }
};

unsigned sum = 0;

    Timer timer;
    
    
long long S[SIZE],n;
long cost(int k)
{
	long cs=0;
	timer.start();
	for(int i=0;i<n;i++)
	{
		cs+=min(S[i]%k,k-S[i]%k);
	}
	timer.stop();
	cout<<"Took "<<timer<<"s"<<endl;
	//cout<<cs <<"returned for "<<k<<endl;
	return cs;
}
int main()
{
	 ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin>>n;
	long long a,s=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		s+=a;
		S[i]=s;
	}
	if(s==1)
		cout<<-1<<endl;
	else
	{
		int t=n;
		long c=LONG_MAX,p=2;
		while (p * p <= s) {
			if (s % p == 0) {
				c = min(c, cost(p));
				while (s % p == 0)
					s /= p;
			}
			++p;
		}
		if(s>1)
			c=min(c,cost(s));
		cout<<c<<endl;
	}
	return 0;
}
