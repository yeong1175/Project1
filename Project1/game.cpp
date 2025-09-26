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
        printf("���ڸ� �Է��ϼ���. �ٽ� �Է�: ");
    }
    
}


void Game::intro() {
    printf("����� ������ ���谡�Դϴ�. ��������� ���ƴٳ�� ������ ���̾� ������ ��� �ӹ����ֽ��ϴ�.\n");
    printf("����� ���̾� ������ �Խ��ǵ��� ���ƴٴϸ� �ǷڰŸ����� ã���ֽ��ϴ�\n\n");

    printf("\"Ȥ�� ���谡���̽Ű���?\"\n");
    printf("\"�� �׷�����\"\n");
    printf("\"���谡 ���̽ö�� ���� �� �����ֽǼ��ֳ���?\"\n");
    printf("\"���� ���̽Ű���?\"\n\n");

    printf("\"���� ��ó �ۼ������� �̹�ī��� �մϴ�.\n");
    printf("���� ������ ��κ� ��翡 �����ϰ� �ִµ�, ������� �˰� ����� �۹����� �װ��ֽ��ϴ�.\n");
    printf("������ ������ �� ����� ����ϰ� �ְ�, �ձ����� ���� ������ ���� �����ϴ�.\n");
    printf("������ �ذ��� �ֽ� �� �������? �Ƿں�� �ε��� �帮�ڽ��ϴ�.\"\n\n");

    printf("\"�׷���\"\n\n");
    printf("����� �̹�ī�� �ۼ������� ���մϴ�...\n");
    printf("�ۼ������� �����߽��ϴ�.\n");
    printf("\"�������� ��������\"\n\n");

    printf("����� �̹�ī�� �������� ���մϴ�.\n");
    printf("���� �տ� �Ǵ� ������ ���Դϴ�.\n\n");
}


void Game::firstChoice() {
    printf("1. �״�� �����Ѵ�.\n");
    printf("2. �Ǵ��� ���� ���ư���.\n\n");

    printf("����(1/2): ");
    int choice = readInt();
    while (choice != 1 && choice != 2) {
        printf("�߸��� �Է��Դϴ�. ����(1/2): ");
        choice = readInt();
    }

    if (choice == 1) {
        
        printf("\n\"����, ���� ���������� ����� 30�޷��� �����Ѵٰ�\"\n");
        printf("\"���� �����? �Ϲݱ濡 �׷� �� ������ϱ�?\"\n");
        printf("\"��� �ֱ� ���� ����\"\n");
        printf("\"�׷� �޾ư� ���ô���\"\n\n");
        battleScene();
    }
    else {
    
        player.addHp(-1);
        printf("\n����� �Ǵ޵��� ���� �ָ� ���� �������� ���մϴ�.\n");
        printf("ü���� 1 �����߽��ϴ�! (���� ü��: %d, ��: %d)\n\n", player.hp, player.str);
    }
}

void Game::battleScene() {
    printf("== ���� �߻�! �ֻ����� �������� (3 �Է�) ==\n");

    int cmd = -1;
    do {
        printf("�Է�: ");
        cmd = readInt();
        if (cmd != 3) printf("3�� �Է� �����մϴ�. �ٽ�.\n");
    } while (cmd != 3);

 
    uniform_int_distribution<int> myDice(12, 20);
    uniform_int_distribution<int> thugDice(12, 13);

    int myRoll = myDice(rng);
    int thugRoll = thugDice(rng);

    int myPower = player.str + myRoll;
    int thugPower = thugRoll+thug.str;

    printf("\n%s �ֻ���: %d + ��(%d) = %d\n", player.name.c_str(), myRoll, player.str, myPower);
    printf("%s �ֻ���: %d + ��(%d)= %d\n", thug.name.c_str(), thugRoll, thug.str, thugPower);

    if (myPower >= thugPower) {
        player.addStr(1);
        printf("\n����� %s��(��) �����߽��ϴ�! �Ǵ��� ��Ŭ�� ȹ���߽��ϴ�.\n", thug.name.c_str());
        printf("���� 1 �����߽��ϴ�! (���� ��: %d, ü��: %d)\n\n", player.str, player.hp);
    }
    else {
        player.addHp(-1);
        printf("\n%s�� ����� �����߽��ϴ�...\n", thug.name.c_str());
        printf("ü���� 1 �����߽��ϴ�! (���� ü��: %d, ��: %d)\n\n", player.hp, player.str);
    }
}

void Game::afterDetour() {
   
    player.addHp(-1);
    printf("\n����� �Ǵ޵��� ���� �ָ� ���� �������� ���մϴ�.\n");
    printf("ü���� 1 �����߽��ϴ�! (���� ü��: %d, ��: %d)\n\n", player.hp, player.str);
}

void Game::farmScene() {
    printf("���忡 �����߽��ϴ�.\n");
    printf("������ �Ӱ� ����� �ְ� ������ ���� �۹����� ���Դϴ�.\n\n");

    printf("����� ���� �۹���� �ٰ����ϴ�.\n");
    printf("�۹����� �Ѹ��� ���� ȫ������ ������� ������ ���� ������ ���Դϴ�.\n\n");

    printf("\"�� ���� ������.....\"\n");
    printf("\"(����� ���� ���Դϴ�)........\"\n\n");
    printf("\"�̹�ī��, ��ó���� ������ �� ���� ������� �渶���� ��� ���Դϴ�.\"\n");
    printf("\"�渶���̿�?\"\n");
    printf("\"���� ���� ���� ������ ������ ������� �渶���� ���� �� ����� �������Դϴ�.\n");
    printf("���� ����(����) ������߰ڽ��ϴ�.\"\n\n");
}

void Game::lookfoward() {
    while (true) {
        printf("����� ���� �����մϴ�.\n");
        printf("���� ��� �����Ͻðڽ��ϱ�?\n");
        printf("1. �ֹ��� �ܿ��.\n");
        printf("2. ������ ���� �Ǵ�.\n");
        printf("3. �ֺ� ������ �����.\n\n");

        printf("����(1/2/3): ");
        int choice2 = readInt();
        while (choice2 < 1 || choice2 > 3) {
            printf("�߸��� �Է��Դϴ�. ����(1/2/3): ");
            choice2 = readInt();
        }

        if (choice2 == 1) {
            printf("\n����� \"���!\" ������ �����ߴ�.\n");
            if (player.intel >= 11) {
                printf("���� ����! ���� ���� ������ �巯����.\n");
                break;
            }
            else {
                player.addHp(-1);
                printf("���� ����! ������ ���� ������ �����߽��ϴ�!\n");
                printf("hp-1 , ���� hp = %d\n\n", player.hp);
                continue;
            }
        }
        else if (choice2 == 3) {
            printf("\n����� ���� ���� ���� �ɾ���.\n");
            if (player.wis >= 10) {
                printf("����! ���� ���� �˰� ���ϱ� ������ ��ġ�� �˷��ش�.\n");
                break;
            }
            else {
                player.addHp(-1);
                printf("���С� ���� ���� �������� ���ߴ�.\n");
                printf("hp-1 , ���� hp = %d\n\n", player.hp);
                continue;
            }
        }
        else {
            printf("����\n");
            printf("\n����� ������ ������ ���� �ı� �����ߴ١� \n");
            printf("���� �̾��� ���� �ٱ�� ���� �Ա��� �߰�!\n\n");
            printf("\n�̹�ī�� ������ʹ� ������ �� ������ �� ȥ�� ���ڽ��ϴ�\n");
            printf("\n�� �˰ڽ��ϴ�\n");
            break;
        }
    }
}

void Game::enterCave() {
    printf("����� ������ ���Խ��ϴ�.\n");
}