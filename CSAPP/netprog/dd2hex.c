/* csapp-11.3
 * 点分十进制转十六进制
 * 使用了 inet_pton() ntohl()
 * 此例中 argv[0] is ./dd2hex ; argv[1] is 128.2.194.242 ;
 */

#include "csapp.h"

int main(int argc, char **argv) {   // argc统计参数个数，argv是字符串数组
    struct in_addr inaddr;  // 网络字节序列
    int rc;                 // 接收返回值

    printf("%d\n", argc);
    if (argc != 2) { 
        fprintf(stderr, "usage: %s <dotted-decimal>\n", argv[0]);
        exit(0); 
    }                           
    
    rc = inet_pton(AF_INET, argv[1], &inaddr);              // 点分十进制表示转网络地址
    if (rc == 0)
        printf("app_error : inet_pton error : invalid dotted-decimal address\n");
    else if (rc < 0)
        printf("unix_error : inet_pton\n");
        
    printf("network order : 0x%x\n", inaddr.s_addr);        // 查看网络序(大端)
    printf("host order : 0x%x\n", ntohl(inaddr.s_addr));    // 网络序转主机序

    exit(0);
}
