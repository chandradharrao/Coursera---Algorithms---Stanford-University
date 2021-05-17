#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

//struct to store elements
typedef struct vals{
    int length;
    double score;
}vals;

//helper functions
double scoreCalc(int w,int l){
    //l can be zero,hence make it numerator
    return (double)l/(double)w;
}

//return completion time of all the jobs
int solution(int W[],int L[],int n){
    map<int,vals> amap;

    //fill the score 
    for(int i = 0;i<n;i++){
        vals v;
        v.length = L[i];
        v.score = scoreCalc(W[i],L[i]);
        amap.insert(W[i],v);
    }

    //to sort amap based on keys we need to use multimap
    map<vals,int> mulmap;
    for(auto it:amap){
        mulmap.insert(make_pair)
    }
}

int main(){

    //input is the weight and length of the jobs
    int W[] = {3,1};
    int L[] = {5,2};
    int n = 2;

    cout << "Time Taken for completion of all the jobs is "<<solution(W,L,n);
}