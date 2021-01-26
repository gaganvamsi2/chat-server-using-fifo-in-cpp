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
int id=3;

int clients=3;
int main(){
  int t,fd,sz,pid,wpid,status=0;
  char buff[len];
  cout<<"started"<<endl;
  fflush(stdin);
 fd=open("/tmp/server",O_WRONLY);
if((pid=fork())==0){
    int fser=open("/tmp/3",O_RDONLY);
  while(1){
    if((sz=read(fser,buff,len))>0){
      string s(buff);
      cout<<s<<endl;
      memset(buff, '\0', 1024);
    }
  }
}
else{
  while(1){
  string s="";
  getline(cin,s);
  if(s.length()>0){
  cout<<"your message:"<<s<<endl;
  s=to_string(id) +":"+s;

   char *buff=&s[0];
   write(fd,buff,s.length());
   sleep(2);
 }
 }

}
while ((wpid = wait(&status)) > 0);





return 0;
}
