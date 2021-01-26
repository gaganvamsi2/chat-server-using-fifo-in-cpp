#include<bits/stdc++.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;
int len=1024;

int clients=3;
int main(){
  int t,fd,sz;
  char buff[len];
  t=mkfifo("/tmp/server",0777);
 for(int i=1;i<=clients;i++){
    string s="/tmp/"+to_string(i);
  const char * c = s.c_str();
  t=mkfifo(c,0777);
  }

  fd=open("/tmp/server",O_RDONLY);
  while(1){
    if((sz=read(fd,buff,len))>0){
      string s(buff);
      cout<<s<<"  message recieved"<<endl;

      int pos = s.find(":");
      string in=s.substr(0,pos);
      int f=stoi(in);
     cout<<"sent by "<<f<<"th   client "<<endl;
      for(int i=1;i<=clients;i++){
        string fi="/tmp/"+to_string(i);
        if(i!=f){
          const char * ci = fi.c_str();
          int fdi=open(ci,O_WRONLY);
          const char * c = &s[0];
          write(fdi,c,s.length());
          close(fdi);
        }
       }
       memset(buff, '\0', 1024);
    }


  }


}
