#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
struct msgtype{
  long mytype;
  char buffer[127];
};
int main(){
  int msgid = msgget((key_t)1111,IPC_CREAT);
  if(msgid == -1){
    perror("msgget");
    return -1;
  }
  struct msgtype msg;
  memset(&msg, 0, sizeof(msg));
 
  msgrcv(msgid, &msg, sizeof(msg.buffer),1,0);
  
  printf("Recieve %s\n",msg.buffer);
  msg.mytype = 2;
//  memset(&msg, 0, sizeof(msg.buffer));
  strncpy(msg.buffer,"???????????",126);
  msgsnd(msgid, &msg, sizeof(msg.buffer),0); 
  return 0;
}
