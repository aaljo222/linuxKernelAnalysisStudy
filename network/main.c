// main.c
#include "link_layer.h"
#include "skbuff.h"
#include <stdio.h>
#include <string.h>

int main() {
    // 가짜 패킷 데이터 버퍼 준비
    char buffer[1500];
    memset(buffer, 0, sizeof(buffer));

    // sk_buff 구조체 초기화
    struct sk_buff skb;
    skb.protocol = ETH_P_IP;     // Ethernet 프로토콜을 IP로 설정
    skb.ip_proto = IPPROTO_TCP;  // IP 프로토콜을 TCP로 설정
    skb.data = buffer;           // 데이터 포인터 설정
    skb.len = sizeof(buffer);    // 데이터 길이 설정

    // 테스트 시작 메시지 출력
    printf("== Packet Test Start ==\n");

    // 링크 레이어 수신 함수 호출 (네트워크 패킷 처리 시작)
    link_layer_receive(&skb);

    // 테스트 완료 메시지 출력
    printf("== Test Complete ==\n");

    return 0;
}

// skb_utils.h
#ifndef SKB_UTILS_H
#define SKB_UTILS_H

#include "skbuff.h"

// skb_pull: 데이터 시작 지점을 앞으로 이동시켜 헤더를 제거하는 함수
static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data = (char *)skb->data + len; // 데이터 포인터를 앞으로 이동
    skb->len -= len;                     // 총 데이터 길이를 줄임
}

// skb_push: 데이터 시작 지점을 뒤로 이동시켜 헤더를 추가하는 함수
static inline void skb_push(struct sk_buff *skb, unsigned int len) {
    skb->data = (char *)skb->data - len; // 데이터 포인터를 뒤로 이동
    skb->len += len;                    // 총 데이터 길이를 늘림
}

#endif // SKB_UTILS_H
