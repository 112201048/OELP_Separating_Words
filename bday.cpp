#include <bits/stdc++.h>
using namespace std;
#define DAYS 365
#define SEED DAYS
#define REPS 6000

int main()
{
    srand(time(0));
    int days = DAYS;
    int bdays [DAYS];

    for(int N = 1; N < days; N++)
    {
        int count = 0;
        for(int reps = 0; reps < REPS; reps++){
            for(int i = 0; i < days; i++)
                bdays[i] = 0;

            for (int j  = 0 ; j < N; j++){
                bdays[rand()%DAYS] ++  ;
            }

            for(int k = 0; k < days; k++)
                if(bdays[k] > 1){
                    count++;
                    break;
                }   
        }
        std::cout << N <<", " << ((float)count)/REPS << endl;
    }
    return 0;
}