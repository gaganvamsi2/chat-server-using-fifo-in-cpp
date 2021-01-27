#include<bits/stdc++.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/wait.h>
#include<string.h>
using namespace std;
int len=1024;
int id=1;

int clients=3;
int main(){
  int t,fd,sz,pid;
  cout<<"started"<<endl;
  fflush(stdin);
  fd= open("/tmp/server",O_WRONLY);
  char buff[]="2:error2";
  write(fd,buff,sizeof(buff));
  int f1=open("/tmp/1",O_RDONLY);
    int f3=open("/tmp/3",O_RDONLY);
  if((sz=read(f1,buff,len))>0){
    string s(buff);
    cout<<s<<endl;
  }
  if((sz=read(f3,buff,len))>0){
    string s(buff);
    cout<<s<<endl;
  }

/*
if((pid=fork())==0){
  while(1){
    int fser=open("/tmp/1",O_RDONLY);
    if((sz=read(fser,buff,len))>0){
      string s(buff);
      cout<<s;
    }
  }
}
else{
  while(1){
    string s;
  cin>>s;
  s=to_string(id) +":"+s;
  cout<<s<<" is the message sent to server"<<endl;
   char *buff=&s[0];
   sleep(2);
  // write(fd,buff,sizeof(buff));
 }
}
*/
return 0;
}
