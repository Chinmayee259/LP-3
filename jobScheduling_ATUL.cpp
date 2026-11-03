#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class jobschedule
{
    public:
    void solve()
    {
        vector<char>job = {'a','b','c','d','e'};
        vector<int>deadline = {2,1,2,1,3};
        vector<int>profit = {100,19,27,25,15};
    

    // sort the jobs
        for(int i = 0 ; i < 5 ;i++)
        {
            for(int j = 1+i ; j < 5; j++)
                {
                    if(profit[i]<profit[j])
                       {
                        swap(profit[i],profit[j]);
                        swap(job[i],job[j]);
                        swap(deadline[i],deadline[j]);
                       }
                }
        }

// find max deadline
        int maxdeadline = 0;
        for(int i = 0 ; i < 5 ; i++)
            {
                 if(deadline[i]>maxdeadline)
                     {
                         maxdeadline = deadline[i];
                     }
            }

            vector<char>slot(maxdeadline,'-');
            
            int maxprofit = 0 ;
            
            for(int i = 0 ; i < 5 ; i++)
                {
                    for(int j = deadline[i]-1;j >= 0; j--)
                        {
                            if(slot[j] == '-')
                            {
                                slot[j] = job[i];
                                maxprofit += profit[i];
                                break;
                            }
                        }
                }

                cout<<maxprofit<<endl;
        
                for(int i  = 0 ; i < maxdeadline; i++)
                    {  
                        if(slot[i] != '-')
                        {
                            cout<<slot[i];
                        }
                    }
        }
};
int main()
{   jobschedule obj;
    obj.solve();
    return 0;
}  
