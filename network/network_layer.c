// network_layer.c
#include "network_layer.h"
#include "transport_layer.h"
#include "skb_utils.h"
#include <stdio.h>

// 네트워크 레이어 수신 함수
void network_layer_receive(struct sk_buff *skb) {
    printf("[Network Layer] Processing IP packet\n");

    // IP 헤더 제거 (20 bytes)
    skb_pull(skb, 20);

    // IP 프로토콜 번호에 따라 TCP 또는 UDP로 전달
    if (skb->ip_proto == IPPROTO_TCP) {
        transport_layer_tcp_receive(skb);
    } else if (skb->ip_proto == IPPROTO_UDP) {
        transport_layer_udp_receive(skb);
    } else {
        // 기타 프로토콜 처리
    }
}
