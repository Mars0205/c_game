#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROGRESS_THRESHOLD 100

/* 数据结构定义 */


// 任务类型枚举
typedef enum {
    LEARNING,    // 学习任务
    SOCIAL,      // 社交任务
    SPORTS,      // 体育任务
    VOLUNTEER,   // 社会实践任务
    ROMANCE      // 恋爱任务
} TaskType;

//好友列表
typedef struct FriendList {
    char name[20];  // 名称
    struct FriendList *next;  // 指针
} FriendList;

//角色
typedef struct {
    char name[20];  // 名称
    int level;  // 等级
    int energy; // 能量
    FriendList *friends;  // 好友链表
    int skills[5]; //技能，skill[i]表示第i类任务的累积技能
} Character;

//消息列表
typedef struct MessageList {
    char from_name[20];  // 发送者名称
    char to_name[20];  // 接收者名称
    char message[100];  // 消息
    struct MessageList *next;  // 指针
} MessageList;



/* 全局数据库模拟 */

//全局变量前置声明
extern Character characters[20]; //角色数据库最多只能存储20条角色纪录，利用数组模拟
extern MessageList *messages; //利用链表模拟消息数据库
extern int character_count; //已建立角色数量



/* 数据库模拟函数 */

//往角色数据库中添加纪录
//添加成功返回0，失败（数据库已满）返回1
int store_character(Character *character);

//在角色数据库中检索，成功返回被检索信息，失败返回空指针
Character* retrieve_character(const char *name);

//往消息数据库中添加纪录，成功返回1
int store_message(MessageList *msg);

//在消息数据库中检索，查找发送给指定角色的全部消息，返回被检索信息链表
MessageList* retrieve_messages(const char *name);

#endif // DATA_H_INCLUDED
