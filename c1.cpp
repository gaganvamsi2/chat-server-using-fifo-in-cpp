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

int fd=open("/tmp/server",O_WRONLY);



void * readfunc(void *arg){

int sz;
char buff[len];
  int fser=open("/tmp/1",O_RDONLY);
while(1){
  if((sz=read(fser,buff,len))>0){
    string s(buff);
    cout<<s<<endl;
    memset(buff, '\0', 1024);
  }
}

}
void * writefunc(void *arg){
char buff[len];
  while(1){
  string s="";
  getline(cin,s);
  if(s.length()>0){
  s=to_string(id) +":"+s;

   char *buff=&s[0];
   write(fd,buff,s.length());
 }

}
}




int clients=3;
int main(){
  int t,pid,wpid,status=0;
  cout<<"started"<<endl;
  fflush(stdin);

// if((pid=fork())==0){
//
//
//
//     int fser=open("/tmp/1",O_RDONLY);
//   while(1){
//     if((sz=read(fser,buff,len))>0){
//       string s(buff);
//       cout<<s<<endl;
//       memset(buff, '\0', 1024);
//     }
//   }
// }
// else{
//
//   while(1){
//   string s="";
//   getline(cin,s);
//   if(s.length()>0){
//   s=to_string(id) +":"+s;
//
//    char *buff=&s[0];
//    write(fd,buff,s.length());
//    sleep(2);
//  }
//  }
int arg1;
pthread_t t1,t2;
pthread_create(&t1,NULL,writefunc,( void *)&arg1);
pthread_create(&t2,NULL,readfunc,( void *)&arg1);
pthread_join(t1,NULL);
pthread_join(t2,NULL);





return 0;
}
