#include "data.h"

Character* retrieve_character(const char* name)
{
    for (int i = 0; i < character_count; ++i) {
        if (strcmp(characters[i].name, name) == 0) {
            return &characters[i];
        }
    }
    return NULL;
}

Character* find_friend(const char *friend_name,struct FriendList *head0)//!!!!
{
    FriendList *suibian=head0;//!!!!
    while(suibian)
    {
        if(strcmp(suibian->name,friend_name)==0){
            return retrieve_character(friend_name);//列表中有此好友
        }
        suibian=suibian->next;
    }
    return NULL;
}

int store_message(MessageList* msg)
{
    
    if(messages == NULL){
        messages = msg;
    }
    else {
        MessageList* current = messages;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = msg;
    }
    
    return 1;
}


/*MessageList* retrieve_messages(const char* name)// 检索消息链表messages以获取角色接收到的消息列表
{
    static MessageList list;
    memset(&list, 0, sizeof(list)); // 清空列表

    for (int i = 0; i < message_count; ++i) {
        if (strcmp(messages[i].sender, name) == 0) {
            // 将匹配的消息添加到列表中
            // 具体的添加逻辑需要根据MessageList的实现而定
        }
    }

    return &list; // 返回消息列表指针
}*/


