#include "Game.h"
using namespace std;

Game::Game()
    : rng(static_cast<unsigned>(time(nullptr))) {
}




int Game::readInt() {
    int v;
    while (!(cin >> v)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        printf("숫자만 입력하세요. 다시 입력: ");
    }
    
}


void Game::intro() {
    printf("당신은 떠돌이 모험가입니다. 세계곳곳을 돌아다녔고 지금은 샤이어 마을에 잠시 머물고있습니다.\n");
    printf("당신은 샤이어 마을의 게시판들을 돌아다니며 의뢰거리들을 찾고있습니다\n\n");

    printf("\"혹시 모험가님이신가요?\"\n");
    printf("\"네 그런데요\"\n");
    printf("\"모험가 님이시라면 저를 좀 도와주실수있나요?\"\n");
    printf("\"무슨 일이신가요?\"\n\n");

    printf("\"저는 근처 작센마을의 이방카라고 합니다.\n");
    printf("저의 마을은 대부분 농사에 종사하고 있는데, 농장들이 검게 물들고 작물들이 죽고있습니다.\n");
    printf("마을의 이장은 이 사실을 방관하고 있고, 왕국으로 보낸 서신은 답이 없습니다.\n");
    printf("용사님이 해결해 주실 수 있을까요? 의뢰비는 두둑히 드리겠습니다.\"\n\n");

    printf("\"그러죠\"\n\n");
    printf("당신은 이방카와 작센마을로 향합니다...\n");
    printf("작센마을에 도착했습니다.\n");
    printf("\"농장으로 가보시죠\"\n\n");

    printf("당신은 이방카와 농장으로 향합니다.\n");
    printf("농장 앞에 건달 무리가 보입니다.\n\n");
}


void Game::firstChoice() {
    printf("1. 그대로 직진한다.\n");
    printf("2. 건달을 피해 돌아간다.\n\n");

    printf("선택(1/2): ");
    int choice = readInt();
    while (choice != 1 && choice != 2) {
        printf("잘못된 입력입니다. 선택(1/2): ");
        choice = readInt();
    }

    if (choice == 1) {
        
        printf("\n\"어이, 여길 지나가려면 통행료 30달러를 내야한다고\"\n");
        printf("\"무슨 통행료? 일반길에 그런 게 어딨습니까?\"\n");
        printf("\"어디 있긴 여기 있지\"\n");
        printf("\"그럼 받아가 보시던가\"\n\n");
        battleScene();
    }
    else {
    
        player.addHp(-1);
        printf("\n당신은 건달들을 피해 멀리 돌아 농장으로 향합니다.\n");
        printf("체력이 1 감소했습니다! (현재 체력: %d, 힘: %d)\n\n", player.hp, player.str);
    }
}

void Game::battleScene() {
    printf("== 전투 발생! 주사위를 굴리세요 (3 입력) ==\n");

    int cmd = -1;
    do {
        printf("입력: ");
        cmd = readInt();
        if (cmd != 3) printf("3만 입력 가능합니다. 다시.\n");
    } while (cmd != 3);

 
    uniform_int_distribution<int> myDice(12, 20);
    uniform_int_distribution<int> thugDice(12, 13);

    int myRoll = myDice(rng);
    int thugRoll = thugDice(rng);

    int myPower = player.str + myRoll;
    int thugPower = thugRoll+thug.str;

    printf("\n%s 주사위: %d + 힘(%d) = %d\n", player.name.c_str(), myRoll, player.str, myPower);
    printf("%s 주사위: %d + 힘(%d)= %d\n", thug.name.c_str(), thugRoll, thug.str, thugPower);

    if (myPower >= thugPower) {
        player.addStr(1);
        printf("\n당신이 %s을(를) 제압했습니다! 건달의 너클을 획득했습니다.\n", thug.name.c_str());
        printf("힘이 1 증가했습니다! (현재 힘: %d, 체력: %d)\n\n", player.str, player.hp);
    }
    else {
        player.addHp(-1);
        printf("\n%s가 당신을 제압했습니다...\n", thug.name.c_str());
        printf("체력이 1 감소했습니다! (현재 체력: %d, 힘: %d)\n\n", player.hp, player.str);
    }
}

void Game::afterDetour() {
   
    player.addHp(-1);
    printf("\n당신은 건달들을 피해 멀리 돌아 농장으로 향합니다.\n");
    printf("체력이 1 감소했습니다! (현재 체력: %d, 힘: %d)\n\n", player.hp, player.str);
}

void Game::farmScene() {
    printf("농장에 도착했습니다.\n");
    printf("농장은 붉게 물들어 있고 곳곳에 죽은 작물들이 보입니다.\n\n");

    printf("당신은 죽은 작물들로 다가갑니다.\n");
    printf("작물들의 뿌리는 진한 홍색으로 물들었고 곳곳에 검은 점들이 보입니다.\n\n");

    printf("\"이 검은 점들은.....\"\n");
    printf("\"(당신은 생각 중입니다)........\"\n\n");
    printf("\"이방카님, 근처에서 누군가 이 땅을 양분으로 흑마법을 사용 중입니다.\"\n");
    printf("\"흑마법이요?\"\n");
    printf("\"붉은 땅과 검은 점들은 생명을 양분으로 흑마법을 썼을 때 생기는 흔적들입니다.\n");
    printf("먼저 뺑을(땅을) 살펴봐야겠습니다.\"\n\n");
}

void Game::lookfoward() {
    while (true) {
        printf("당신은 땅을 조사합니다.\n");
        printf("땅을 어떻게 조사하시겠습니까?\n");
        printf("1. 주문을 외운다.\n");
        printf("2. 손으로 땅을 판다.\n");
        printf("3. 주변 새에게 물어본다.\n\n");

        printf("선택(1/2/3): ");
        int choice2 = readInt();
        while (choice2 < 1 || choice2 > 3) {
            printf("잘못된 입력입니다. 선택(1/2/3): ");
            choice2 = readInt();
        }

        if (choice2 == 1) {
            printf("\n당신은 \"루모스!\" 마법을 시전했다.\n");
            if (player.intel >= 11) {
                printf("마법 성공! 오염 시작 지점이 드러났다.\n");
                break;
            }
            else {
                player.addHp(-1);
                printf("마법 실패! 지능이 낮아 마법에 실패했습니다!\n");
                printf("hp-1 , 현재 hp = %d\n\n", player.hp);
                continue;
            }
        }
        else if (choice2 == 3) {
            printf("\n당신은 새의 언어로 말을 걸었다.\n");
            if (player.wis >= 10) {
                printf("성공! 새가 땅이 검게 변하기 시작한 위치를 알려준다.\n");
                break;
            }
            else {
                player.addHp(-1);
                printf("실패… 새의 말을 이해하지 못했다.\n");
                printf("hp-1 , 현재 hp = %d\n\n", player.hp);
                continue;
            }
        }
        else {
            printf("성공\n");
            printf("\n당신은 무작정 손으로 땅을 파기 시작했다… \n");
            printf("땅과 이어진 검은 줄기와 동굴 입구를 발견!\n\n");
            printf("\n이방카님 여기부터는 위험할 수 있으니 저 혼자 들어가겠습니다\n");
            printf("\n네 알겠습니다\n");
            break;
        }
    }
}

void Game::enterCave() {
    printf("당신은 동굴에 들어왔습니다.\n");
}