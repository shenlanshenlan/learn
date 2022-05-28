//
#ifndef _FUN_C
#define _FUN_C

#include "main.h"

void open_pcap()
{
    int err = 0;
    uint32_t localnet, netmask;
    char cmd[MAXLINE], errbuf[PCAP_ERRBUF_SIZE],
        str1[200], str2[200];
    struct bpf_program fcode;

    if (device == NULL)
    {
        if ((device = pcap_lookupdev(errbuf)) == NULL)
        { //返回网络设备名称
            printf("pcap lookup:%s", errbuf);
            exit(0);
        }
    }

    printf("device = %s\n", device);

    // 输出网卡设备
    if ((pd = pcap_open_live(device, snaplen, 0, 500, errbuf)) < 0)
        printf("pcap_open_live:%s\n", errbuf);
    //打开设备返回 ？？描述符？

    if (pcap_lookupnet(device, &localnet, &netmask, errbuf) < 0)
        printf("pcap_lookupnet :%s\n", errbuf);
    //返回主机网络地址和掩码

      inet_ntop(AF_INET, &localnet, str1,  sizeof(str1)); 
         
      inet_ntop(AF_INET, &netmask,  str2,  sizeof(str2));  
         
    printf("localnet = %s, mask = %s\n",
           str1,
           str2);
   
    


   
        //输出网络地址和子网掩码
         snprintf(cmd, sizeof(cmd), CMD 
                  ); 

    cout(cmd);

    if (verbose)
        printf("cmd = %s", cmd);

    if (pcap_compile(pd, &fcode, cmd, 0, netmask) < 0)
       printf("pcap_compile error\n" ); //构造过滤1描述符号2

    //编译过滤码
    if (pcap_setfilter(pd, &fcode) < 0)
       printf("pcap_setfilter error\n" ); 
    // 设置过滤码

    if ((datalink = pcap_datalink(pd)) < 0)
    printf("datalink error\n" );
    //返回数据链路类型

    if (verbose)
        printf("datalink = %s\n", datalink);
    //打印数据链路类型

    
}

void get_pcap()
{
    char *ptr; 
    in_addr_t  ss;
    struct pcap_pkthdr pkthdr;

    for ( ; ; )
    {
        ptr = (char *)pcap_next(pd, &pkthdr);
        if(ptr == NULL)
        continue;
        else 
       { 
        //16个字节
      struct   sockaddr * sp  ;
        sp =   (SA *)(ptr+12+14) ;
        struct sockaddr_in *ss;
        ss = (struct sockaddr_in *)sp;
        //ss->sin_addr.s_addr=ntohl(ss->sin_addr.s_addr);
       cout( k_ntop(sp));
      
      /*str 为完整的数据链路层分组
        包含 以太网首部
             IP 首部及数据
      
        可以对其进行分析操作  */
                       

     // ntohs

        printf("Packet length: %d\n", pkthdr.len);  
        printf("Number of bytes: %d\n", pkthdr.caplen);  
        printf("Recieved time: %s", ctime((const time_t *)&pkthdr.ts.tv_sec)); 
       }
    }
}
数据
#endif