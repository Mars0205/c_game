#include "manage.h"

int save_game(const char *filename) {
FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return 0;  // 打开文件失败
    }

    // 保存角色信息
    fwrite(&character_count, sizeof(int), 1, file);
    for (int i = 0; i < character_count; i++) {
        fwrite(&characters[i], sizeof(Character), 1, file);
    }

    // 保存消息链表
    MessageList *current_message = messages;
    while (current_message != NULL) {
        fwrite(current_message, sizeof(MessageList), 1, file);
        current_message = current_message->next;
    }

    fclose(file);
    return 1;  // 保存成功

}


int load_game(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return 0;  // 打开文件失败
    }

    // 读取角色信息
    fread(&character_count, sizeof(int), 1, file);
    for (int i = 0; i < character_count; i++) {
        fread(&characters[i], sizeof(Character), 1, file);
    }

    // 读取消息链表
    MessageList *last_message = NULL;
    messages = NULL;
    MessageList temp_message;
    while (fread(&temp_message, sizeof(MessageList), 1, file) == 1) {
        MessageList *new_message = (MessageList *)malloc(sizeof(MessageList));
        if (new_message == NULL) {
            fclose(file);
            return 0;  // 内存分配失败
        }

        *new_message = temp_message;
        new_message->next = NULL;

        if (messages == NULL) {
            messages = new_message;
        } else {
            last_message->next = new_message;
        }
        last_message = new_message;
    }

    fclose(file);
    return 1;  // 读取成功

}

void free_memory(void) {
// 释放角色的好友数组
    for (int i = 0; i < character_count; i++) {
        for (int j = 0; j < sizeof(characters[i].friends); j++) {
            // 假设这里释放的是指向角色的指针，如果角色是动态分配的
            // free(characters[i].friends[j]);
        }
    }

    // 释放消息链表
    MessageList *current_message = messages;
    while (current_message != NULL) {
        MessageList *temp = current_message;
        current_message = current_message->next;
        free(temp);  // 释放每个消息节点的内存
    }

    messages = NULL;  // 防止悬空指针

}
