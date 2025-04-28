// socket_layer.c
#include "socket_layer.h"
#include <stdio.h>

// 소켓 레이어 수신 함수
void socket_layer_receive(struct sk_buff *skb) {
    printf("[Socket Layer] Payload received, length: %u bytes\n", skb->len);
}
