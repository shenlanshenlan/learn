// 相关函数 

#ifndef _SER_H
#define _SER_H

#include "main.h"
 


//***********配置文件相关**********
void getcfg(char *path, char *p[]);
// 获取路径文件 返回键值对二维指针
void move_space(char *str);
//c 去除字符串中的空格;
void getkeyandvalue(char *str, char *key, char *value);
//返回字符串中的键值对
void read_line(int filefd, char *str);
//读取一行，存入参数2
void init_cfg(struct  _ser * _ser); 
//初始化配置结构

/*  命令解析 */
char ** analysis(char *buf);
 //解析读入字符 将字符串处理为一个二维数组 version one bug
char ** create_command(char *buf,int *len); 
//分解字符串 为单词 version two
char **  read_command(int * cm_len);
  //读取命令
void movespaceofhard(char * buf); 
//去除字符串头的空格
#include "ser.c"
#endif