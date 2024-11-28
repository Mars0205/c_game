#ifndef SOCIAL_H_INCLUDED
#define SOCIAL_H_INCLUDED

#include "character.h"

//发送信息，成功返回1
int send_message(const char *from_name, const char *to_name, char *message);

//接收信息，返回接受的消息链表
MessageList* receive_messages(const char *to_name);

// 输出链表中的所有消息（新功能）
void printMessages(MessageList* head);

// 释放消息链表内存
void freeMessages(MessageList* head);

//
//添加好友，成功返回1
int add_friend(const char *name, const char *friend_name);

//展示好友列表
void display_friends(const char *name);

//清空全部角色的好友
void free_friends(Character *character);

#endif // SOCIAL_H_INCLUDED
