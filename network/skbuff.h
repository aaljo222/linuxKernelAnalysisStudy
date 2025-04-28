// skbuff.h
#ifndef SKBUFF_H
#define SKBUFF_H

// Ethernet 프로토콜 타입 정의 (IPv4)
#define ETH_P_IP 0x0800

// IP 프로토콜 번호 정의 (TCP)
#define IPPROTO_TCP 6

// IP 프로토콜 번호 정의 (UDP)
#define IPPROTO_UDP 17

// 네트워크 패킷을 나타내는 sk_buff 구조체
struct sk_buff {
    unsigned short protocol; // Ethernet 프로토콜 타입
    unsigned char ip_proto;  // IP 프로토콜 번호
    void *data;              // 데이터 시작 포인터
    unsigned int len;        // 데이터 길이
};

#endif // SKBUFF_H
