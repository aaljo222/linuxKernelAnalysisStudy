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
