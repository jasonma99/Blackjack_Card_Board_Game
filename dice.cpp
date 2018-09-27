#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stddef.h>
using namespace std;
void rollDie(int num){
	int a;
	float* bucket=0;
	bucket=new float[7];
	float percent=0;
	for (int j=0; j<num;j++){
		a = 1+ rand()/(RAND_MAX/6+1);
		bucket[a]++;
	}
	for (int i=1;i<7;i++){
		if (bucket[i]==0)
			percent=0;
		else 
			percent=(bucket[i]/num);
		cout << i<<": "<< percent<<endl;
	}
	delete [] bucket;
}
void equalDie(int num){
	int a;
	float* bucket=0;
	bucket=new float[7];
	float percent=0, equal=0;
	float high=0, low=0;
	for (int j=0; j<num;j++){
		high=0;
		low=0;
		for(int k=0;k<100;k++){
		a = 1+ rand()/(RAND_MAX/6+1);
		if (a<=3)
			low++;
		else if (a>3)
			high++;
		}
		if (high==low)
			equal++;
	}
	percent=equal/num;
	cout<< percent <<endl;
	/*if (high>=low){
		percent=((low*2)/num)*100;
		cout<< percent << "% of times the number of high rolls is equal to the number of low rolls"<<endl;
	}
	else if (high<low){
		percent=((high*2)/num) *100;
		cout<< percent << "% of times the number of high rolls is equal to the number of low rolls"<<endl;
	}*/
	delete [] bucket;
}
void twoDice(int num){
	int a,b;
	float* bucket=0;
	bucket=new float[13];
	float percent=0;
	for (int j=0; j<num;j++){
		a = 1+ rand()/(RAND_MAX/6+1);
		b = 1+ rand()/(RAND_MAX/6+1);
		bucket[a+b]++;
	}
	for (int i=2;i<13;i++){
		if (bucket[i]!=0)
			percent=(bucket[i]/num);
		else 
			percent=0;
		cout << i<<": "<< percent<<endl;
	}
	delete [] bucket;
	
}
int main (){
	srand((unsigned int)time(NULL));
	cout<<"Question 1:"<<endl;
	cout<<"10 times"<<endl;
	rollDie(10);
	cout<<"1000 times"<<endl;
	rollDie(1000);
	cout<<"100000 times"<<endl;
	rollDie(100000);
	cout<<"Question 2:"<<endl;
	equalDie(10000);
	cout<<"Question 3:"<<endl;
	twoDice(10000);	
}