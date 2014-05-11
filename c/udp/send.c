#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
  int sock;
  struct sockaddr_storage ss;
  struct sockaddr_in *to = (struct sockaddr_in *)&ss;
  int n;

  /* ソケットの作成 */
  sock = socket(AF_INET, SOCK_DGRAM, 0);

  /* 接続先指定用構造体の準備 */
  to->sin_family = AF_INET;
  to->sin_port = htons(11111);
  /* 127.0.0.1はlocalhost */
  n = inet_pton(AF_INET, "127.0.0.1", &(to->sin_addr));
  if(n < 1){
    perror("inet_pton");
    return 1;
  }

  /* データを送信 */
  n = sendto(sock, "TEST", 5, 0, (struct sockaddr *)to, sizeof(struct sockaddr_in));
  if(n < 1){
    perror("sendto");
    return 1;
  }

  /* socketの終了 */
  close(sock);

  return 0;
}
