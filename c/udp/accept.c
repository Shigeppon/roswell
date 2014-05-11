#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
  int sock;
  struct sockaddr_storage ss;
  struct sockaddr_in *binaddr = (struct sockaddr_in *)&ss;

  struct sockaddr_storage senderinfo;
  socklen_t addrlen;
  char buf[2048];
  int n;

  /* ソケットの作成 */
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if(sock < 0){
    perror("socket");
    return 1;
  }

  /* 接続先指定用構造体の準備 */
  binaddr->sin_family = AF_INET;
  binaddr->sin_port = htons(11111);
  binaddr->sin_addr.s_addr = INADDR_ANY;

  if(bind(sock, (struct sockaddr *)binaddr, sizeof(struct sockaddr_in)) != 0){
    perror("bind");
    return 1;
  }

  /* データを受信 */
  addrlen = sizeof(senderinfo);
  n = recvfrom(sock, buf, sizeof(buf) - 1, 0, (struct sockaddr *)&senderinfo, &addrlen);

  write(fileno(stdout), buf, n);

  /* socketの終了 */
  close(sock);

  return 0;
}
