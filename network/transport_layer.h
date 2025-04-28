// transport_layer.h
#ifndef TRANSPORT_LAYER_H
#define TRANSPORT_LAYER_H

#include "skbuff.h"

// TCP 수신 처리 함수
void transport_layer_tcp_receive(struct sk_buff *skb);

// UDP 수신 처리 함수
void transport_layer_udp_receive(struct sk_buff *skb);

// TCP 재전송 함수
void tcp_retransmit();

#endif // TRANSPORT_LAYER_H
