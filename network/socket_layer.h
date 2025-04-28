// socket_layer.h
#ifndef SOCKET_LAYER_H
#define SOCKET_LAYER_H

#include "skbuff.h"

// 소켓 레이어 수신 함수
void socket_layer_receive(struct sk_buff *skb);

#endif // SOCKET_LAYER_H
