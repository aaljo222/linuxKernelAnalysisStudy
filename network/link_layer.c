// link_layer.c
#include "link_layer.h"
#include "network_layer.h"
#include "skb_utils.h"
#include <stdio.h>

// 링크 레이어 수신 함수
void link_layer_receive(struct sk_buff *skb) {
    printf("[Link Layer] Received packet, protocol: %04x\n", skb->protocol);

    // Ethernet 헤더 제거 (14 bytes)
    skb_pull(skb, 14);

    // 프로토콜 타입에 따라 상위 레이어로 전달
    if (skb->protocol == ETH_P_IP) {
        network_layer_receive(skb);
    } else {
        // 기타 프로토콜 처리 (예: ARP)
    }
}
