
 

#ifndef _MAIN_H
#define _MAIN_H

 

#include  "k.h"
#include <netinet/if_ether.h>
#include <pcap.h>
#define NULL ((void *)0)
//#define CMD "udp and ser host %s and dest port %d"
#define CMD "icmp and des host 192.168.1.101"

 
struct  sockaddr     *dest,*local;     
struct  sockaddr_in   locallookup;
socklen_t destlen,locallen; 
pcap_t  *pd;  

int rawfd  ;  
int verbose ;
int snaplen = 200;
int datalink;
char *device;

 
#endif