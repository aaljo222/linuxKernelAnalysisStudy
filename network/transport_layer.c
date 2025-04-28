// transport_layer.c
#include "transport_layer.h"
#include "socket_layer.h"
#include "skb_utils.h"
#include <stdio.h>

// TCP 상태 머신 정의
typedef enum {
    TCP_STATE_CLOSED,
    TCP_STATE_LISTEN,
    TCP_STATE_SYN_SENT,
    TCP_STATE_SYN_RECEIVED,
    TCP_STATE_ESTABLISHED,
    TCP_STATE_FIN_WAIT_1,
    TCP_STATE_FIN_WAIT_2,
    TCP_STATE_TIME_WAIT
} tcp_state_t;

// 현재 TCP 연결 상태
static tcp_state_t tcp_state = TCP_STATE_CLOSED;
// 재전송 횟수 카운터
static int retransmission_count = 0;

// SYN 패킷 재전송 처리 함수
void tcp_retransmit() {
    printf("[TCP] Retransmitting SYN packet (attempt %d)\n", retransmission_count);
    retransmission_count++;
    if (retransmission_count > 3) {
        printf("[TCP] Retransmission failed, closing connection\n");
        tcp_state = TCP_STATE_CLOSED;
    }
}

// TCP 패킷 수신 처리 함수
void transport_layer_tcp_receive(struct sk_buff *skb) {
    printf("[Transport Layer] TCP packet received\n");
    skb_pull(skb, 20); // TCP 헤더 제거

    // TCP 상태에 따라 처리 분기
    if (tcp_state == TCP_STATE_CLOSED) {
        printf("[TCP] Received SYN, sending SYN-ACK\n");
        tcp_state = TCP_STATE_SYN_RECEIVED;
        skb_push(skb, 20);
        retransmission_count = 0;
    } else if (tcp_state == TCP_STATE_SYN_RECEIVED) {
        printf("[TCP] Received ACK, connection ESTABLISHED\n");
        tcp_state = TCP_STATE_ESTABLISHED;
    } else if (tcp_state == TCP_STATE_ESTABLISHED) {
        printf("[TCP] Data packet in ESTABLISHED state\n");
        socket_layer_receive(skb);
        printf("[TCP] Sending FIN, moving to FIN_WAIT_1\n");
        tcp_state = TCP_STATE_FIN_WAIT_1;
    } else if (tcp_state == TCP_STATE_FIN_WAIT_1) {
        printf("[TCP] Received FIN-ACK, moving to FIN_WAIT_2\n");
        tcp_state = TCP_STATE_FIN_WAIT_2;
    } else if (tcp_state == TCP_STATE_FIN_WAIT_2) {
        printf("[TCP] Received final ACK, moving to TIME_WAIT\n");
        tcp_state = TCP_STATE_TIME_WAIT;
    } else if (tcp_state == TCP_STATE_TIME_WAIT) {
        printf("[TCP] Connection closed after TIME_WAIT\n");
        tcp_state = TCP_STATE_CLOSED;
    }
}

// UDP 패킷 수신 처리 함수
void transport_layer_udp_receive(struct sk_buff *skb) {
    printf("[Transport Layer] UDP packet received\n");
    skb_pull(skb, 8); // UDP 헤더 제거
    socket_layer_receive(skb);
}
