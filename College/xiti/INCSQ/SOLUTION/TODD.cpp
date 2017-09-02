//increasing.cpp
//increasing sequence problem
//pgmr: T Feil

#include <iostream.h>
#include <string.h>


char S[81];
int first, n, TheBest[81], Best[81], Mark[81];


//copy S[n..n+k-1] to T[]
void SubstringCopy(char S[81], char T[81], int n, int k) {
  int i;
  for(i=n;i<n+k;i++)
    T[i-n]=S[i];
  T[k]='\0';
}

//true is S>T (as numbers)
int Bigger(char S[81], char T[81]){
  int n, m, i, j;
  if(T[0]=='\0') return 1;
  n=strlen(S);
  m=strlen(T);
  i=0;
  while(S[i]=='0') i++;
  n=n-i;
  j=0;
  while(T[j]=='0') j++;
  m=m-j;
  if(n>m) return 1;
  if(n<m) return 0;
  while(S[i]!='\0' && S[i]==T[j]){
    i++; j++;
  }
  if(S[i]=='\0') return 0;
  if(S[i]>T[j]) return 1;
  return 0;
}
 
void Copy(int A[81], int B[81],int n){
  int i;
  for(i=0;i<=n;i++) A[i]=B[i];
}
 
void PrintSeq(){
  int i, first=1;
  for(i=0;i<n;i++){
    cout<<S[i];
    if(TheBest[i]) 
      cout<<',';
  }
  cout<<endl;
}

int FirstWord(int start, int finish, char* prev, int last){
  char F[81],T[81],Last[81];
  int newfinish,length=n-last;

  while(finish>=start &&finish<last){
    SubstringCopy(S,F,start,finish-start+1);
    SubstringCopy(S,Last,last,n-last);
    if(Bigger(F,prev) && Bigger(Last,F)){
      if(finish==last-1){ //got a solution
        Best[finish]=1;
        return 1;
      }
      else{
        SubstringCopy(S,T,start,finish-start+1);
        if(FirstWord(finish+1,last-1,T,last)){
          Best[finish]=1;
          return 1;
        }
      }
    }
    finish--;
  }
  return 0;
}

int BiggerSeq(int A[], int B[]){
  int i, Afirst = -1, Bfirst=-1, Alast, Blast;
  char Anum[81], Bnum[81];

/*
cout<<"In BiggerSeq "<<endl;
for (i=0;i<n;i++) cout<<A[i]; cout<<endl;
for (i=0;i<n;i++) cout<<B[i]; cout<<endl<<endl;;
*/
Alast=Blast=0;
  while(Alast<n && Blast <n)  {
    Alast = Afirst+1;
    Blast = Bfirst+ 1;
    while(Alast<n && A[Alast]==0)
      Alast++;
    while(Blast<n && B[Blast]==0) Blast++;
    SubstringCopy(S,Anum, Afirst+1,Alast-Afirst);
    SubstringCopy(S,Bnum, Bfirst+1,Blast-Bfirst);
//cout<<Anum<<' '<<Bnum<<endl;
    if(Bigger(Anum,Bnum))
      return 1;
    if(Bigger(Bnum,Anum))
      return 0;
    Afirst=Alast;
    Bfirst=Blast;
  }
  return 0;
}


void UpDate(){
  int i;
//cout<<"UpDate"<<endl;
//for(i=0;i<n;i++) cout<<Best[i]; cout<<endl;
  if(first){
    first=0;
    for(i=0;i<n;i++)
      TheBest[i]=Best[i];
  }
  else
    if(BiggerSeq(Best,TheBest))
     for(i=0;i<n;i++)
      TheBest[i]=Best[i];
}

void main(){

  int i,last,newlast,found,finish;

  cin>>S;
  n=strlen(S);
  while(n!=1 || S[0]!='0'){
    for(i=0;i<n;i++){ TheBest[i]=0; Mark[i]=0;}

    last=n-1;
    found =0;
    first=1;
    while(last>-1 && !found){
     newlast=last;
     while(newlast>0 && S[newlast-1]=='0') newlast--;
     if(newlast==0) found=1;
     else{
       while(newlast<=last){
         for(i=0;i<n;i++) Best[i]=0;
         finish=n-newlast-1;
         if(finish>=newlast) finish=newlast-1;

         if(FirstWord(0,finish,"0",newlast)){
           found=1;
           UpDate();
         }
           finish++;
           newlast++;
       }
      }
      last--;
    }
    PrintSeq(); 

    cin>>S;
    n=strlen(S);
  } 
}

