#include <arpa/inet.h>
#include <bits/stdc++.h>
#include <cerrno>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERV_PORT 6666

using namespace std;

void sys_err(const char *str) {
    perror(str);
    exit(1);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in serv_addr; // 服务器地址结构
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, "127.0.0.1", (void *)&serv_addr.sin_addr.s_addr);

    int cfd = socket(AF_INET, SOCK_STREAM, 0); // IPv4 + TCP
    if (cfd == -1) {
        sys_err("create socket error");
    }

    // state: CLOSED => SYN_SEND => ESTABLISHED
    int ret = connect(cfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        sys_err("connect error");
    }

    char buf[BUFSIZ];
    int cnt = 10;
    while (cnt--) {
        write(cfd, "hello\n", 6);
        int ret = read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, ret);
    }

    close(cfd); // state: FIN_WAIT_1 => FIN_WAIT_2 => TIME_WAIT => CLOSE
    return 0;
}
