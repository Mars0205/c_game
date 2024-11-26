#include "data.h"

/*int store_character(Character* character)
{
    if (character_count >= 20) {
        return 0; // 失败返回0
    }
    characters[character_count++] = *character;
    return 1; // 成功返回1
}*/

Character* retrieve_character(const char* name)
{
    for (int i = 0; i < character_count; ++i) {
        if (strcmp(characters[i].name, name) == 0) {
            return &characters[i]; // 找到则返回指针
        }
    }
    return NULL; // 未找到则返回NULL
}

/*int store_message(MessageList* msg)
{
    if (message_count >= 100) {
        return 0; // 失败返回0
    }
    messages[message_count++] = *msg;
    return 1; // 成功返回1
}*/


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


