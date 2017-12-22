/* csapp-11.2
 * 十六进制转点分十进制
 * 使用了 htonl() inet_ntop()
 * 此例中 argv[0] is ./hex2dd ; argv[1] is 0x8002c2f2 ;
 */

#include "csapp.h"

int main(int argc, char **argv) {   // argc统计参数个数，argv是字符串数组
    struct in_addr inaddr;  // 网络字节序列
    uint32_t addr;          // 主机字节序列
    char buf[MAXBUF];       // 存储点分十进制字符串

    printf("%d\n", argc);
    if (argc != 2) {
        fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
        exit(0); 
    }                               

    sscanf(argv[1], "%x", &addr);   // 取十六进制数
    inaddr.s_addr = htonl(addr);    // 主机序转为网络序

    if (!inet_ntop(AF_INET, &inaddr, buf, MAXBUF)) {  // 网络地址转为点分十进制表示
        printf("unix_error : inet_ntop\n");
        exit(0);
    }
    
    printf("%s\n", buf);  

    exit(0);
}