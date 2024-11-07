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
    // step 1: create socket
    int sfd = socket(AF_INET, SOCK_STREAM, 0); // IPv4 + TCP
    if (sfd == -1) {
        sys_err("create socket error");
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERV_PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // step2: bind socket and addr
    if (bind(sfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        sys_err("bind error");
    }

    // step3: state CLOST => LISTEN
    if (listen(sfd, 256) == -1) {
        sys_err("listen error");
    }

    // step4: state LISTEN => SYN_RCVD => ESTABLISHED
    struct sockaddr_in addr_out;
    socklen_t client_addr_len = sizeof(addr_out); // 传入传出参数，先计算长度
    int cfd = accept(sfd, (struct sockaddr *)&addr_out, &client_addr_len);
    if (cfd == -1) {
        sys_err("accept error");
    }

    char client_ip[BUFSIZ];
    socklen_t client_ip_len;
    cout << "client ip = "
         << inet_ntop(AF_INET, &addr_out.sin_addr.s_addr, client_ip,
                      sizeof(client_ip))
         << ", port = " << ntohs(addr_out.sin_port) << endl;

    // step5: read and write
    char buf[BUFSIZ];
    while (true) {
        // blocking
        int ret = read(cfd, (void *)&buf, BUFSIZ);
        if (ret == 0) {
            break;
        }

        for (int i = 0; i < ret; i++) {
            buf[i] = toupper(buf[i]);
        }
        write(cfd, (void *)&buf, ret);
    }

    close(cfd);
    close(sfd); // state: CLOSE_WAIT => LAST_ACK => CLOSE

    return 0;
}
