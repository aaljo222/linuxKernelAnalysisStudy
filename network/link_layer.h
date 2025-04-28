// link_layer.h
#ifndef LINK_LAYER_H
#define LINK_LAYER_H

#include "skbuff.h"

// 링크 레이어 수신 함수
void link_layer_receive(struct sk_buff *skb);

#endif // LINK_LAYER_H
