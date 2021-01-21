//
// Created by Donghui Zheng on 2021/1/2 22:49.
//

#include "Action.h"
/**
 * @details ��ӭ����.
 * @param void.
 * @return void.
 */
void action::welcomeScreen() {
    cout << "***�������������***\n";
    cout << "!�ó��������Ļ��ʾѡ����Ҫ���еĲ���\n\n";
    cout << "���ߣ�֣����\n";
    cout << "�༶�������ݹ���Ӧ��1901��\n";
    cout << "ѧ�ţ�201906062631\n";
    cout << "\n";
}
/**
 * @details Ŀ¼ѡ��������.
 * @param void.
 * @return void.
 */
void action::directorySelectionScreen() {
    cout << "��ѡ��\n";
    cout << "1.���漰�ļ��Ĵ���������\n";
    cout << "2.�漰�ļ��Ĵ���������\n";
    cout << "3.�˳�����\n";
    cout << "���ѡ��";
}
/**
 * @details ѡ���������.
 * @param void.
 * @return void.
 */
void action::baseSelection() {
    cout << "��ѡ��:\n";
    cout << "1.ʮ����\n";
    cout << "2.������\n";
    cout << "���ѡ��";
}
/**
 * @details �˳�����.
 * @param void.
 * @return void.
 */
void action::exitSystem() {
    cout << "\n��ӭ�´�ʹ�ã�\n\n";
    system("pause");
    exit(0);
}
/**
 * @details ���㷽��.
 * @param void.
 * @return void.
 */
void action::selectionDirectory() {
    cout << "����1��2��3��4��5ѡ�������\n";
    cout << "1���ӷ�\n";
    cout << "2������\n";
    cout << "3���˷�\n";
    cout << "4������\n";
    cout << "5��ָ��\n";
    cout << "6���˳�\n";
    cout << "���ѡ��";
}
/**
 * @details ���漰�ļ��Ĵ���������.
 * @param void.
 * @return void.
 */
void action::operationWithoutFile() {
    int choice;
    baseSelection();//���ý���ѡ����.
    cin >> choice;
    fflush(stdin);//�������.
    while (choice > 2 || choice < 1) {
        cout << "���������������������룡\n" << endl;
        baseSelection();//���ý���ѡ����.
        cin >> choice;
        fflush(stdin);//�������.
    }
    if (choice == 1) {//ʮ����.
        int flag = 1;
        while (flag) {
            int operatorSelection;
            selectionDirectory();//�������㷽������.
            cin >> operatorSelection;
            fflush(stdin);//�������.
            while (operatorSelection > 6 || operatorSelection < 1) {
                cout << "���������������������룡\n" << endl;
                selectionDirectory();//�������㷽������.
                cin >> operatorSelection;
                fflush(stdin);//�������.
            }
            linkList list1, list2;
            switch (operatorSelection) {
                case 1: {//�ӷ�.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "�ӷ� ��>>> (list1 + list2) = ";
                    bigInteger::addition_bigInteger(list1, list2, 10);
                    break;
                }
                case 2: {//����.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "���� ��>>> (list1 - list2) = ";
                    bigInteger::subtraction_bigInteger(list1, list2, 10);
                    break;
                }
                case 3: {//�˷�.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "�˷� ��>>> (list1 * list2) = ";
                    bigInteger::multiplication_bigInteger(list1, list2, 10);
                    break;
                }
                case 4: {//����.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "���� ��>>> (list1 / list2) = ";
                    bigInteger::division_bigInteger(list1, list2, 10);
                    break;
                }
                case 5: {//ָ������.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "ָ������ ��>>> (list1 ^ list2) = ";
                    bigInteger::exponentialCalculation_bigInteger(list1, list2, 10);
                    break;
                }
                default: {
                    break;
                }
            }
            if (operatorSelection == 6) {
                cout << "Exit?(0.Yes/1.No):";
                cin >> choice;
                flag = choice;
            }
        }
    } else {//������.
        int flag = 1;
        while (flag) {
            int operatorSelection;
            selectionDirectory();//�������㷽������.
            cin >> operatorSelection;
            fflush(stdin);//�������.
            while (operatorSelection > 6 || operatorSelection < 1) {
                cout << "���������������������룡\n" << endl;
                selectionDirectory();//�������㷽������.
                cin >> operatorSelection;
                fflush(stdin);//�������.
            }
            linkList list1, list2;
            switch (operatorSelection) {
                case 1: {//�ӷ�.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "�ӷ� ��>>> (list1 + list2) = ";
                    bigInteger::addition_bigInteger_binarySystem(list1, list2);
                    break;
                }
                case 2: {//����.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "���� ��>>> (list1 - list2) = ";
                    bigInteger::subtraction_bigInteger_binarySystem(list1, list2);
                    break;
                }
                case 3: {//�˷�.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "�˷� ��>>> (list1 * list2) = ";
                    bigInteger::multiplication_bigInteger_binarySystem(list1, list2);
                    break;
                }
                case 4: {//����.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "���� ��>>> (list1 / list2) = ";
                    bigInteger::division_bigInteger_binarySystem(list1, list2);
                    break;
                }
                case 5: {//ָ������.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "ָ������ ��>>> (list1 ^ list2) = ";
                    bigInteger::exponentialCalculation_bigInteger(list1, list2, 2);
                    break;
                }
                default: {
                    break;
                }
            }
            if (operatorSelection == 6) {
                cout << "Exit?(0.Yes/1.No):";
                cin >> choice;
                flag = choice;
            }
        }
    }
}
/**
 * @details �漰�ļ��Ĵ���������.
 * @param void.
 * @return void.
 */
void action::operationWithFile() {
    int choice;
    baseSelection();//���ý���ѡ����.
    cin >> choice;
    fflush(stdin);//�������.
    while (choice > 2 || choice < 1) {
        cout << "���������������������룡\n" << endl;
        baseSelection();//���ý���ѡ����.
        cin >> choice;
        fflush(stdin);//�������.
    }
    if (choice == 1) {//ʮ����.
        int flag = 1;
        while (flag) {
            int operatorSelection;
            selectionDirectory();//�������㷽������.
            cin >> operatorSelection;
            fflush(stdin);//�������.
            while (operatorSelection > 6 || operatorSelection < 1) {
                cout << "���������������������룡\n" << endl;
                selectionDirectory();//�������㷽������.
                cin >> operatorSelection;
                fflush(stdin);//�������.
            }
            linkList list1, list2;
            switch (operatorSelection) {
                case 1: {//�ӷ�.
                    bigInteger::listOperateWithFile_decimalSystem(list1, list2, '+');
                    break;
                }
                case 2: {//����.
                    bigInteger::listOperateWithFile_decimalSystem(list1, list2, '-');
                    break;
                }
                case 3: {//�˷�.
                    bigInteger::listOperateWithFile_decimalSystem(list1, list2, '*');
                    break;
                }
                case 4: {//����.
                    bigInteger::listOperateWithFile_decimalSystem(list1, list2, '/');
                    break;
                }
                case 5: {//ָ������.
                    bigInteger::listOperateWithFile_decimalSystem(list1, list2, '^');
                    break;
                }
                default: {
                    break;
                }
            }
            if (operatorSelection == 6) {
                cout << "Exit?(0.Yes/1.No):";
                cin >> choice;
                flag = choice;
            }
        }
    } else {//������.
        int flag = 1;
        while (flag) {
            int operatorSelection;
            selectionDirectory();//�������㷽������.
            cin >> operatorSelection;
            fflush(stdin);//�������.
            while (operatorSelection > 6 || operatorSelection < 1) {
                cout << "���������������������룡\n" << endl;
                selectionDirectory();//�������㷽������.
                cin >> operatorSelection;
                fflush(stdin);//�������.
            }
            linkList list1, list2;
            switch (operatorSelection) {
                case 1: {//�ӷ�.
                    bigInteger::listOperateWithFile_binarySystem(list1, list2, '+');
                    break;
                }
                case 2: {//����.
                    bigInteger::listOperateWithFile_binarySystem(list1, list2, '-');
                    break;
                }
                case 3: {//�˷�.
                    bigInteger::listOperateWithFile_binarySystem(list1, list2, '*');
                    break;
                }
                case 4: {//����.
                    bigInteger::listOperateWithFile_binarySystem(list1, list2, '/');
                    break;
                }
                case 5: {//ָ������.
                    bigInteger::listOperateWithFile_binarySystem(list1, list2, '^');
                    break;
                }
                default: {
                    break;
                }
            }
            if (operatorSelection == 6) {
                cout << "Exit?(0.Yes/1.No):";
                cin >> choice;
                flag = choice;
            }
        }
    }
}
