#ifndef __CLI_WORK__
#define __CLI_WORK__

enum {
  COMMAND_CD,
  COMMAND_LS,
  COMMAND_PWD,
  COMMAND_MKDIR,
  COMMAND_RMDIR,
  COMMAND_RM,
  COMMAND_GETFILE,
  COMMAND_PUTFILE,
  COMMAND_QUIT,
  COMMAND_REGISTER,
  COMMAND_LOGIN,
};

typedef struct user_s{
    char name[64];
    char passwd[960];
}user_t;

typedef struct cmd_s{
    char cmd[256];
    char args[1024];
}cmd_t;
//客户端业务
//传入socketfd
void client_work(const int sockfd);
int cmd_analyse(const char *cmd);
int cmd_separa(const char* cmd, char* tokens[], int* tokenNum);
int cmd_valid(const int cmd_type,const int argc);
void user_login(cmd_t *cmd,const int sockfd);
#endif

