//
// Created by Donghui Zheng on 2020/12/22 15:05.
//

#include <iostream>
#include "Action.h"
using namespace std;

int main() {
    action::welcomeScreen();//���û�ӭ����.
    system("pause");
    system("cls");
    while (true) {//��ѭ��.
        int choice;//�û������ѡ��.
        int flag = 1;//�����ж��Ƿ��˳�����.
        action::directorySelectionScreen();//����Ŀ¼ѡ�����.
        cin >> choice;
        fflush(stdin);//�������.
        while (choice > 3 || choice < 1) {
            cout << "���������������������룡\n" << endl;
            action::directorySelectionScreen();//����Ŀ¼ѡ�����.
            cin >> choice;
            fflush(stdin);//�������.
        }
        int continueKey;
        switch (choice) {
            case 1://���漰�ļ��Ĵ���������.
                while (flag) {//�������.
                    action::operationWithoutFile();//����operationWithoutFile����.
                    cout << "\n�������㣿��ѡ��1����/0���񣩣�";
                    fflush(stdin);//�������.
                    cin >> continueKey;
                    flag = continueKey;
                    system("cls");
                }
                break;
            case 2://�漰�ļ��Ĵ���������.
                while (flag) {//�������.
                    action::operationWithFile();//����operationWithFile����.
                    cout << "\n�������㣿��ѡ��1����/0���񣩣�";
                    fflush(stdin);//�������.
                    cin >> continueKey;
                    flag = continueKey;
                    system("cls");
                }
                break;
            default:
                action::exitSystem();
                break;
        }
    }
    return 0;
}
