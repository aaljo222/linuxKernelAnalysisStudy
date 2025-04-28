// network_layer.h
#ifndef NETWORK_LAYER_H
#define NETWORK_LAYER_H

#include "skbuff.h"

// 네트워크 레이어 수신 함수
void network_layer_receive(struct sk_buff *skb);

#endif // NETWORK_LAYER_H
