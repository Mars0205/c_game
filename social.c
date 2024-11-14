#include "social.h"

MessageList *message_head = NULL;
int send_message(const char *from_name, const char *to_name, char *message) {
    MessageList *new_message = (MessageList *)malloc(sizeof(MessageList));
    if (new_message == NULL) {
        return 0;  // 内存分配失败
    }

    // 初始化消息
    strcpy(new_message->from_name, from_name);
    strcpy(new_message->to_name, to_name);
    strcpy(new_message->message, message);
    new_message->next = NULL;

    // 将消息添加到链表
    if (message_head == NULL) {
        message_head = new_message;
    } else {
        MessageList *current = message_head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_message;
    }

    return 1;  // 消息发送成功

}

MessageList* receive_messages(const char *name) {
    MessageList *current = message_head;
    MessageList *received_messages = NULL, *last = NULL;

    // 遍历消息链表，筛选出符合条件的消息
    while (current != NULL) {
        if (strcmp(current->to_name, name) == 0) {
            MessageList *new_message = (MessageList *)malloc(sizeof(MessageList));
            if (new_message == NULL) {
                return NULL;  // 内存分配失败
            }
            // 复制消息
            strcpy(new_message->from_name, current->from_name);
            strcpy(new_message->to_name, current->to_name);
            strcpy(new_message->message, current->message);
            new_message->next = NULL;

            // 添加到接收到的消息列表
            if (received_messages == NULL) {
                received_messages = new_message;
            } else {
                last->next = new_message;
            }
            last = new_message;
        }
        current = current->next;
    }

    return received_messages;  // 返回接收到的消息列表

}


int add_friend(const char *name, const char *friend_name) {
    
}


void display_friends(const char *name) {
    

}

void free_friends(Character *character) {
    
}
