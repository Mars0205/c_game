#include "social.h"

MessageList* createMessage(const char* sender, const char* receiver, const char* content) {
    MessageList* newMessage = (MessageList*)malloc(sizeof(MessageList));
    strncpy(newMessage->from_name, sender, 20 - 1);
    strncpy(newMessage->to_name, receiver, 20 - 1);
    strncpy(newMessage->message, content, 100 - 1);
    
    newMessage->next = NULL;
    return newMessage;
}

int send_message(const char *from_name, const char *to_name, char *message) {
    
    printf("请输入消息内容：");
    getchar(); // 清除输入缓冲区
    fgets(message, 100, stdin);
    // 确保字符串以空字符结尾
    message[strcspn(message, "\n")] = '\0'; // 去除换行符

    MessageList *new_message = createMessage(from_name, to_name, message);

    // 将消息添加到链表
    store_message(new_message);

    return 1;  // 消息发送成功

}


MessageList* receive_messages(const char *name) {
    
    MessageList *current = messages;
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
    Character *now_character;
    now_character = retrieve_character(name);
    FriendList *current = now_character->friends;
    if(current == NULL){
        printf("<暂无好友>\n");
    }
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }

}


void free_friends(Character *character) {
    for(int i=0;i<20;i++){
        FriendList *current = characters[i].friends;
        FriendList *next;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
    }
}


void printMessages(MessageList* head) {
    MessageList* current = head;
    while (current != NULL) {
        printf("Sender: %s\n", current->from_name);
        printf("Receiver: %s\n", current->to_name);
        printf("Content: %s\n", current->message);
        printf("----------------------\n");
        current = current->next;
    }
}


void freeMessages(MessageList* head) {
    MessageList* current = head;
    MessageList* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}