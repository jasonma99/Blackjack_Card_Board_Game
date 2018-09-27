#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stddef.h>

using namespace std;

int count=52;
int remainingCards(int * cards);
int deal(int * cards);
int* shuffle(int * cards);
void stand(int threshold, int* cards);

void HiLo(int curr, int next);
int runningCount=0;
void BlackJack(int * cards);
int bet(int runningCount);
int main(){
	srand((unsigned int)time(NULL));
	int cards[52];	
	for(int i=0; i<4;i++){
		for( int j=1; j<11;j++){
			cards[10*i+j-1]=j;
		}
	}
	for (int j=40;j <52;j++){
		cards[j]=10;
	}
	/*for(int i=0;i<52; i++){
		cout<< cards[i]<<" ";
	}
	shuffle(cards);
	cout<<"\n";
	for(int i=0;i<52; i++){
		cout<< cards[i]<<" ";
	}	
	cout<<"\n";
	cout<<remainingCards(cards);
	deal(cards);
	cout<<remainingCards(cards);
	*/
	cout<<"Question 4:"<<endl;
	for( int i=10; i<=20;i++){
		stand(i, cards);
	}
	BlackJack(cards);
}

int remainingCards(int* cards){
	return count;
}
int deal(int* cards){
	count--;
	return cards[count];
}
int* shuffle(int* cards){
	int j,temp;
	for (int max=51;max>=0;max--){
		j=rand()/(RAND_MAX/(max+1)+1);
		temp=cards[max];
		cards[max]=cards[j];
		cards[j]=temp;
	}
	count =52;
	runningCount=0;
	return cards;
}

void stand(int threshold, int * cards){
	shuffle(cards);
	int curr=0, reach=0;
	float percent=0, bust=0;
	int x=0;
	for (int i=0;i<100000;){
		shuffle(cards);
		while (curr<threshold){	
			x=deal(cards);
			if (x==1){
				if (11+curr<=21)
					curr=curr+11;
				else
					curr++;
			}
			else
				curr=curr+x;
			if (count==0){
				shuffle(cards);
			}
		}	
		if (curr>=threshold&&curr<=21){
			reach++;
			++i;
			curr=0;
		}
		else if (curr>21){
			++bust;
			++i;
			curr=0;
		}
	}
	percent=bust/100000;
	cout<< threshold<< " "<< percent<< endl;
}


void HiLo(int runningCount, int next){
	if (next==10||next==1)
		runningCount--;
	if (next>=2&&next<=6)
		runningCount++;
}
int bet(int runningCount){
	if (runningCount<=-2)
		return -1;
	if (runningCount>=2)
		return 1;
}
void BlackJack(int * cards){
	shuffle(cards);
	float percent=0, correct=0;
	for (int i=0; i<10000;i++){
		int dealer=0, player[4]={0}, x=0,win=0;
		shuffle(cards);
		x=deal(cards);
		if (x==1)
			dealer=dealer+11;
		else
			dealer=dealer+x;
		HiLo(runningCount,x);
		for(int k=0;k<2;k++){
			for (int j=0; j<4; j++){
				x=deal(cards);
				if (x==1){
					if (11+player[j]<=21)
						player[j]=player[j]+11;
					else
						player[j]++;
				}
				else
					player[j]=player[j]+x;
				HiLo(runningCount,x);
			}
		}
		while(player[3]<18){
			if (count==0)
				shuffle(cards);
		
			x=deal(cards);
			if (x==1){
				if (11+player[3]<=21)
					player[3]=player[3]+11;
				else
					player[3]++;
			}
			else
				player[3]=player[3]+x;
			HiLo(runningCount,x);
		}
		while(dealer<=16){
			if (count==0)
				shuffle(cards);
		
			x=deal(cards);
			if (x==1){
				if (11+dealer<=21)
					dealer=dealer+11;
				else
					dealer++;
			}
			else
				dealer=dealer+x;
			HiLo(runningCount,x);
			bet(runningCount);
		}
		if (player[3]==21||dealer>21||(dealer<player[3]))
			win=1;
		else if (player[3]>21||(dealer>player[3]))
			win=-1;
				
		if (win==bet(runningCount))
			correct++;
		if (count==0)
			shuffle(cards);
	}
	percent=correct/10000;
	cout<<"Question 5:"<<endl;
	cout<<percent<<endl;
	
}