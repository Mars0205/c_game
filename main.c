#include "data.h"
#include "character.h"
#include "tasks.h"
#include "social.h"
#include "manage.h"
#include <windows.h> //防乱码

// 全局数据库模拟
Character characters[20]; //角色数据库最多只能存储20条角色纪录，利用数组模拟
MessageList *messages = NULL; //利用链表模拟消息数据库
int character_count = 0;

void display_menu() {
    printf("\n==== 角色模拟游戏 ====\n");
    printf("1. 创建角色\n");
    printf("2. 完成任务\n");
    printf("3. 添加好友\n");
    printf("4. 发送消息\n");
    printf("5. 接收消息\n");
    printf("6. 加载游戏\n");
    printf("7. 保存游戏\n");
    printf("8. 退出游戏\n");
    printf("=======================\n");
    printf("请选择一个操作：");
}

void handle_create_character() {
    char name[20];
    printf("请输入角色名称：");
    scanf("%s", name);
    if (!retrieve_character(name)) {
        if (create_character(name)) {
            printf("角色 %s 创建成功！", name);
        } else {
            printf("角色创建失败，可能已达到角色数量上限。\n");
        }
    } else {
        printf("角色已存在!\n");
    }
}

void handle_complete_task() {
    char name[20];
    int input,reward;
    TaskType selectedTask;

    printf("请输入角色名称：");
    scanf("%s", name);

    printf("请输入任务类型（0—学习，1—社交，2—体育，3—社会实践，4—恋爱）及奖励：");
    scanf("%d %d", &input, &reward);
    if (input >= 0 && input < 5) {
        selectedTask = (TaskType)input;
        if (complete_task(name, selectedTask, reward)) {
            update_character_status(name);
        } else {
            printf("课程参加失败，请检查输入是否正确。\n");
        }
    }
    else{
        printf("输入任务类型错误。\n");
    }
}

void handle_add_friend() {
    char name[20], friend_name[20];
    Character *current;
    while(1){
        printf("请输入您的角色名称：");
        scanf("%s", name);
        current = retrieve_character(name);
        if(current){
            break;
        }
        else printf("角色名不存在，请重新输入\n");
    }
    while(1){
        printf("请输入好友名称：");
        scanf("%s", friend_name);
        if(retrieve_character(friend_name)){
            if(find_friend(friend_name, current -> friends)){
                if(name == friend_name){
                    printf("无法和自己成为好友！\n");
                    break;
                }
                if (add_friend(name, friend_name)) {
                    printf("%s 已添加 %s 为好友！\n", name, friend_name);
                }
                else {
                    printf("添加好友失败。\n");
                }
                break;
            }
            else {
                printf("好友已存在！\n");//需要修改
            }
        }
        else printf("角色名不存在，请重新输入\n");
    }
    
}

void handle_send_message() {
    char from_name[20], to_name[20], message[100];
    Character *current;
    while(1){
        printf("请输入您的角色名称：");
        scanf("%s", from_name);
        current = retrieve_character(from_name);
        if(current){
            break;
        }
        else printf("角色名不存在，请重新输入\n");
    }
    while(1){
        printf("请输入好友名称：");
        scanf("%s", to_name);
        if(!find_friend(to_name, current -> friends)){
            break;
        }
        else printf("无法和不是好友的对象通信，请重新输入\n");
    }
    printf("请输入消息内容：");
    getchar(); // 清除输入缓冲区
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0'; // 去除换行符
    if (send_message(from_name, to_name, message)) {
        printf("消息已发送！\n");
    } else {
        printf("发送消息失败。\n");
    }
}

void handle_receive_messages() {
    char name[20];
    printf("请输入您的角色名称：");
    scanf("%s", name);
    MessageList *msgs = receive_messages(name);
    printf("=== %s 收到的消息列表 ===\n", name);
    while (msgs) {
        printf("来自 %s: %s\n", msgs->from_name, msgs->message);
        msgs = msgs->next;
    }
}

void handle_save_game() {
    char name[20]="game_save.log";
    //printf("请输入角色名称以保存：");
    //scanf("%s", name);
    if (save_game(name)) {
        printf("游戏进度已保存！\n");
    } else {
        printf("保存失败，请检查角色名称是否正确。\n");
    }
}

void handle_load_game() {
    char name[20]="game_save.log";
    //printf("请输入角色名称以加载：");
    //scanf("%s", name);
    if (load_game(name)) {
        printf("游戏进度已加载！\n");
    } else {
        printf("加载失败！\n");
    }
}



int main() {
    SetConsoleOutputCP(65001);
    char input[10];
    do {
        display_menu();
        scanf("%s",input);
        char choice = input[0];
        switch (choice) {
            case '1':
                handle_create_character();
                break;
            case '2':
                handle_complete_task();
                break;
            case '3':
                handle_add_friend();
                break;
            case '4':
                handle_send_message();
                break;
            case '5':
                handle_receive_messages();
                break;
            case '6':
                handle_load_game();
                break;
            case '7':
                handle_save_game();
                break;
            case '8':
                free_memory();//释放动态分配的内存
                printf("退出游戏，感谢您的游玩！\n");
                break;
            default:
                printf("无效的选项，请重试。\n");
        }
    } while (input[0] != '8');
    return 0;
}
