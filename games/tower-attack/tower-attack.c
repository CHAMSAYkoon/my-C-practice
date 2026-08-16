#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



struct Pirson {
    char name [20];         //1
    int hpMAX;              //2
    int hp;                 //3
    int strength;           //4
    int hpItem;             //5
    char skillName [3][50]; //7 공격 => 방어 => 회복 순서로
};

struct Pirson player = {"플레이어", 100, 100, 10, 10, {"배어내기", "막기", "회복 포션 사용"}};

struct Pirson kaine = {"케인", 150, 150, 10, 0, {"안 죄송해!!", "춘잣!!", " "}};

struct Pirson kiminzik = {"감스트", 220, 220, 15, 0, {"너 개새끼 열매 먹었어?", "이래도 지랄 저래도 지랄", " "}};

struct Pirson kimjoonpyo = {"김준표", 150, 150, 15, 3, {"웃음소리", "아름다운 마술입니다", "썰 풀기"}};

bool fight (struct Pirson *player, struct Pirson *enemy) {
    int choices = 0;
    int attack = 0;
    int block = 0;
    while (true) {
        if ((*player).hp < 1) { //플레이어의 턴
            return false;
        }
        printf("\n적의 HP: %d/%d\n적의 공격력: %d\n", (*enemy).hp, (*enemy).hpMAX, (*enemy).strength);
        printf("\n나의 HP: %d/%d\n나의 공격력: %d\n", (*player).hp, (*player).hpMAX, (*player).strength);
        printf("\n남은 회복 포션: %d", (*player).hpItem);
        printf("\n플레이어의 턴\n1 - %s\n2 - %s\n번호 입력: ", (*player).skillName, (*player).skillName + 2);
        scanf("%d", &choices);
        if (choices == 1) {
            srand(time(NULL));
            attack = (*player).strength * ((rand() % 3) + 1);
            printf("\n플레이어가 %d 의 위력으로 [%s] 공격\n", attack, (*player).skillName);
            srand(time(NULL));
            block = (*enemy).strength; + ((rand() % 10) + 1);
            if (attack > block) {
                (*enemy).hp -= attack - block;
                printf("\n%s이(가) [%s](으)로 %d만큼을 방어\n%s에게 %d만큼의 피해\n",(*enemy).name,(*enemy).skillName + 1, block, (*enemy).name, attack - block);
            } else if (attack <= block) {
                printf("\n%s이(가) [%s]으로 공격을 완전히 방어\n",(*enemy).name, (*enemy).skillName + 1);
            }
        } else if (choices == 2) {
            if ((*player).hp == (*player).hpMAX) {
                printf("\n포션을 복용했으나 아무 일도 일어나지 않았다.\n");
            } else if ((*player).hp < (*player).hpMAX) {
                if ((*player).hpItem > 0){
                    (*player).hp = (*player).hpMAX;
                    (*player).hpItem--;
                    printf("\n체력이 완전히 회복되었다.\n");
                }
                
            }
        }

        if ((*enemy).hp < 1) { //적의 턴
            return true;
        }
        srand(time(NULL));
        attack = (*enemy).strength * ((rand() % 2) + 1);
        printf("\n%s이(가) %d의 위력으로[%s] 공격\n",(*enemy).name, attack, (*enemy).skillName);
        srand(time(NULL));
        block = (*player).strength * ((rand() %3) + 1);
        if (attack > block) {
            (*player).hp -= attack - block;
            printf("\n%s이(가) [%s](으)로 %d만큼을 방어\n%s에게 %d만큼의 피해\n",(*player).name,(*player).skillName + 1, block, (*player).name, attack - block);
        } else if (attack <= block) {
            printf("\n%s이(가) [%s]으로 공격을 완전히 방어\n",(*player).name, (*player).skillName + 1);
        }
        srand(time(NULL));
        if ((*enemy).hpItem > 0 && ((rand() % 3) + 1) == 1 && (*enemy).hp < (*enemy).hpMAX) {
            (*enemy).hp = (*enemy).hpMAX;
            (*enemy).hpItem--;
            printf("\n%s이(가) [%s](으)로 체력을 완전히 회복\n", (*enemy).name, (*enemy).skillName + 2);
        }
        
        
    }
}

int main(void) {
    printf("당신은 어느날 결심했습니다. \"그래, 나는 모험가가 되어 탑과 던전들을 공략하며 살 테야.\"\n몇년에 걸쳐 이런 저런 준비를 마친 당신은 동내 뒷산에 있던 3층 탑에 도전하게 됩니다.\n\n첫번째 적, [%s]\n", kaine.name);
    printf("\n\"자~ 오랜만에 이 탑에 도전자가 왔어요~ 내 실력을 알까?\"\n첫번째 적이 당신을 반깁니다.\n");
    
    if (fight(&player, &kaine)) {
        printf("\n\"아이고난!\"\n적이 쓰러지고 다음 층으로 가는 계단이 열립니다.\n");
    } else {
        printf("\n\n[Game Over]");
        return 0;
    }

    printf("\n\"지금 이 탑의 문제가 뭘까요? 바로 당신입니다.\"\n적이 당신에게 달려듭니다.\n");

    if (fight(&player, &kiminzik)) {
        printf("\n\"이게 뭐야! 이게 뭐야! 이게 뭐야!\"\n적이 쓰러지고 다음 층으로 가는 계단이 열립니다.\n");
    } else {
        printf("\n\n[Game Over]");
        return 0;
    }

    printf("\n드디어 이 탑의 마지막 적을 만날 시간입니다.\n어둠 속에서 호탕한 웃음소리가 울려퍼지며 마지막 스테이지가 시작됩니다.\n");

    if (fight(&player, &kimjoonpyo)) {
        printf("\n드디어 마지막 이 탑의 적을 물리친 당신은 그들의 전리품을 챙겨 탑을 내려왔습니다.\n이것으로 당신의 모험의 첫 발걸음을 땠다고 할 수 있겠군요.\n앞의로의 당신의 인생에 축복을 빌며 이 게임은 끝납니다.\n\n[The - End]\n");
    } else {
        printf("\n\n[Game Over]");
        return 0;
    }
}