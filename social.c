#include "social.h"

int send_message(const char *from_name, const char *to_name, char *message) {
    int send_message(const char *from_name, const char *to_name, const char *message) {
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

MessageList* receive_messages(const char *to_name) {
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
    // 假设角色管理模块通过某种方式提供了访问角色信息的接口，以下为伪代码示例：
    Character *current_character = get_character_by_name(name);  // 获取当前角色

    // 这里假设角色可以有最多100个好友
    if (current_character->friend_count < 100) {
        // 在角色的好友列表中添加好友
        current_character->friends[current_character->friend_count] = get_character_by_name(friend_name);
        current_character->friend_count++;
        return 1;  // 好友添加成功
    }

    return 0;  // 好友数量已满

}


void display_friends(const char *name) {
    // 获取角色
    Character *current_character = get_character_by_name(name);
    
    // 输出该角色的所有好友
    printf("%s的好友列表:\n", name);
    for (int i = 0; i < current_character->friend_count; i++) {
        printf("%s\n", current_character->friends[i]->name);
    }

}

void free_friends(Character *character) {
    // 释放好友列表中的每个好友内存
    for (int i = 0; i < character->friend_count; i++) {
        // 假设释放角色好友的内存（根据实际情况调整）
        free(character->friends[i]);
    }

    // 重置好友数量
    character->friend_count = 0;

}
