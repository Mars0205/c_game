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


//该函数用于查找Friendlist里面是否已经有待添加好友
int find_friend(const char *friend_name,struct FriendList *head0)//!!!!
{
    FriendList *suibian=head0;//!!!!
    while(suibian)
    {
        if(strcmp(suibian->name,friend_name)==0)return 0;//列表中已经有此好友
        suibian=suibian->next;
    }
    return 1;
}


int add_friend(const char *name, const char *friend_name) {
    //tail0为尾指针，用于链表
    FriendList *tail0 = NULL;
    Character *now_character;
    now_character = retrieve_character(name);
    FriendList *new_friend=(FriendList*)malloc(sizeof(FriendList));
    
    strcpy(new_friend->name,friend_name);
    new_friend->next = NULL;
        
    if(now_character->friends == NULL)
        {
            //tail0 = new_friend;
            now_character->friends = new_friend;
        }
    else
        {
            tail0 = new_friend;
            tail0 -> next = now_character->friends;
            now_character -> friends = tail0;
        }
        return 1;
}


void display_friends(const char *name) {
    

}

void free_friends(Character *character) {
    
}
