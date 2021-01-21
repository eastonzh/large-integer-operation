//
// Created by Donghui Zheng on 2020/12/22 15:02.
//

#include "BigInteger.h"

string bigInteger::translateToString(linkList &list) {
    node *back;
    int length = list.linkListSize();
    string result(length, 0);//��������Ϊl,��ʼ��Ϊ0���ַ���.
    back = list.returnHeadPoint()->prev;
    for (int i = length - 1; i >= 0; i--) {//ѭ���������������뵽�ַ�����.
        result[i] = back->data + '0';
        back = back->prev;
    }
    if (list.linkListFlag() == -1) {
        result = "-" + result;
    }
    return result;
}
void bigInteger::writeFile(const string& data, const string& url) {
    ofstream fileStream;//�ļ�������.
    fileStream.open(url, ios::out | ios::app);
    //�ļ�������.
    if (!fileStream.is_open()) {
        fileStream.close();
        return;
    }
    fileStream << data << endl;
    fileStream.close();
}
int bigInteger::comparisonOfSize(linkList &list1, linkList &list2) {
    int length1 = list1.returnLinkListLength();
    int length2 = list2.returnLinkListLength();
    int flag = 0;
    if (length1 > length2) {//list1���ȴ���list2����.
        flag = 1;
    } else if (length1 == length2) {//�������.
        node *point1 = list1.returnHeadPoint()->next;
        node *point2 = list2.returnHeadPoint()->next;
        for (int i = 0; i < length1; i++) {//�Ӹ�λ��ʼ�Ƚϴ�С.
            if (point1->data > point2->data) {
                flag = 1;
                break;
            } else if (point1->data < point2->data) {
                flag = -1;
                break;
            }
            point1 = point1->next;
            point2 = point2->next;
        }
    } else {//list1����С��list2����.
        flag = -1;
    }
    return flag;
}
bool bigInteger::compareListLength(linkList &list1, linkList &list2) {
    int listLength1 = list1.linkListSize();
    int listLength2 = list2.linkListSize();
    return listLength1 > listLength2;
}
void bigInteger::inputListWithoutFile(linkList &object1, linkList &object2) {
    int length;
    node *back;
    int flag;//���ű��.
    //��һ�������������뼰�洢.
    cout << "�������һ����������";
    string string1;
    cin >> string1;
    flag = 1;
    if (string1[0] == '-') {
        string1 = string1.substr(1);
        flag = -1;
    }
    length = string1.length();
    object1.createLinkListWithoutForValue(length);//��������Ϊlength1��˫��ѭ������,��ֵ��object1.
    back = object1.returnHeadPoint()->prev;
    object1.returnLinkListFlag() = flag;
    //���������洢��������.
    for (int i = length - 1; i >= 0; --i) {
        back->data = string1[i] - '0';
        back = back->prev;
    }
    //�ڶ��������������뼰�洢.
    cout << "������ڶ�����������";
    string string2;
    cin >> string2;
    flag = 1;
    if (string2[0] == '-') {
        string2 = string2.substr(1);
        flag = -1;
    }
    length = string2.length();
    object2.createLinkListWithoutForValue(length);//��������Ϊlength1��˫��ѭ������,��ֵ��object2.
    back = object2.returnHeadPoint()->prev;
    object2.returnLinkListFlag() = flag;
    //���������洢��������.
    for (int i = length - 1; i >= 0; --i) {
        back->data = string2[i] - '0';
        back = back->prev;
    }
}
void bigInteger::listOperateWithFile_decimalSystem(linkList &object1, linkList &object2, char choice) {
    int flag;//���ű��.
    ifstream fileStream;//�ļ�������.
    fileStream.open(R"(C:\Users\15590\Desktop\Operation of large integers\file\file_decimalSystem.txt)", ios::in);//���ļ�.
    //�ļ�������.
    if (!fileStream.is_open()) {
        fileStream.close();
        return;
    }
    //�ļ�����,��Ϊ���ļ�.
    char testData;
    fileStream >> testData;
    if (fileStream.eof()) {
        cout << "�ļ�Ϊ�գ�\n";
        fileStream.close();
        return;
    }
    //���ļ����ڣ��������ݴ���.
    string string1, string2;
    int length;
    node *back;
    while (fileStream >> string1 >> string2) {
        flag = 1;
        if (string1[0] == '-') {
            string1 = string1.substr(1);
            flag = -1;
        }
        length = string1.length();
        object1.createLinkListWithoutForValue(length);//��������Ϊlength1��˫��ѭ������,��ֵ��object1.
        back = object1.returnHeadPoint()->prev;
        object1.returnLinkListFlag() = flag;
        //���������洢��������.
        for (int i = length - 1; i >= 0; --i) {
            back->data = string1[i] - '0';
            back = back->prev;
        }
        flag = 1;
        if (string2[0] == '-') {
            string2 = string1.substr(1);
            flag = -1;
        }
        length = string2.length();
        object2.createLinkListWithoutForValue(length);//��������Ϊlength1��˫��ѭ������,��ֵ��object2.
        back = object2.returnHeadPoint()->prev;
        object2.returnLinkListFlag() = flag;
        //���������洢��������.
        for (int i = length - 1; i >= 0; --i) {
            back->data = string2[i] - '0';
            back = back->prev;
        }
        cout << "list1:" << object1 << endl;
        cout << "list2:" << object2 << endl;
        switch (choice) {
            case '+': {
                cout << "�ӷ� ��>>> (list1 + list2) = ";
                addition_bigInteger(object1, object2, 10);
                break;
            }
            case '-': {
                cout << "���� ��>>> (list1 - list2) = ";
                subtraction_bigInteger(object1, object2, 10);
                break;
            }
            case '*': {
                cout << "�˷� ��>>> (list1 * list2) = ";
                multiplication_bigInteger(object1, object2, 10);
                break;
            }
            case '/': {
                cout << "���� ��>>> (list1 / list2) = ";
                division_bigInteger(object1, object2, 10);
                break;
            }
            default: {
                cout << "ָ������ ��>>> (list1 ^ list2) = ";
                exponentialCalculation_bigInteger(object1, object2, 10);
                break;
            }
        }
    }
    fileStream.close();
}
void bigInteger::listOperateWithFile_binarySystem(linkList &object1, linkList &object2, char choice) {
    int flag;//���ű��.
    ifstream fileStream;//�ļ�������.
    fileStream.open(R"(C:\Users\15590\Desktop\Operation of large integers\file\file_binarySystem.txt)", ios::in);//���ļ�.
    //�ļ�������.
    if (!fileStream.is_open()) {
        fileStream.close();
        return;
    }
    //�ļ�����,��Ϊ���ļ�.
    char testData;
    fileStream >> testData;
    if (fileStream.eof()) {
        cout << "�ļ�Ϊ�գ�\n";
        fileStream.close();
        return;
    }
    //���ļ����ڣ��������ݴ���.
    string string1, string2;
    int length;
    node *back;
    while (fileStream >> string1 >> string2) {
        flag = 1;
        if (string1[0] == '-') {
            string1 = string1.substr(1);
            flag = -1;
        }
        length = string1.length();
        object1.createLinkListWithoutForValue(length);//��������Ϊlength��˫��ѭ������,��ֵ��object1.
        back = object1.returnHeadPoint()->prev;
        object1.returnLinkListFlag() = flag;
        //���������洢��������.
        for (int i = length - 1; i >= 0; --i) {
            back->data = string1[i] - '0';
            back = back->prev;
        }
        flag = 1;
        if (string2[0] == '-') {
            string2 = string1.substr(1);
            flag = -1;
        }
        length = string2.length();
        object2.createLinkListWithoutForValue(length);//��������Ϊlength��˫��ѭ������,��ֵ��object2.
        back = object2.returnHeadPoint()->prev;
        object2.returnLinkListFlag() = flag;
        //���������洢��������.
        for (int i = length - 1; i >= 0; --i) {
            back->data = string2[i] - '0';
            back = back->prev;
        }
        cout << "list1:" << object1 << endl;
        cout << "list2:" << object2 << endl;
        switch (choice) {
            case '+': {
                cout << "�ӷ� ��>>> (list1 + list2) = ";
                addition_bigInteger_binarySystem(object1, object2);
                break;
            }
            case '-': {
                cout << "���� ��>>> (list1 - list2) = ";
                subtraction_bigInteger_binarySystem(object1, object2);
                break;
            }
            case '*': {
                cout << "�˷� ��>>> (list1 * list2) = ";
                multiplication_bigInteger_binarySystem(object1, object2);
                break;
            }
            case '/': {
                cout << "���� ��>>> (list1 / list2) = ";
                division_bigInteger_binarySystem(object1, object2);
                break;
            }
            default: {
                cout << "ָ������ ��>>> (list1 ^ list2) = ";
                exponentialCalculation_bigInteger(object1, object2, 2);
                break;
            }
        }
    }
    fileStream.close();
}
linkList bigInteger::additionAuxiliaryFunction(linkList &object1, linkList &object2, int base) {
    linkList result;
    bool lengthJudge = compareListLength(object1, object2);//�жϴ���������������ĳ��ȴ�С.
    if (lengthJudge) {//object1�ĳ��� > object2�ĳ���.
        int objectLength1 = object1.linkListSize();
        int objectLength2 = object2.linkListSize();
        int quotientRecord = 0;//quotient��¼��λ.
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
        result.createLinkListWithoutForValue(objectLength1);//�������������Ϊobject1��object2�г��Ƚϴ���.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
        for (int i = 0; i < objectLength2; ++i) {//��object1��object2�г��Ƚ�С�ߵĳ��ȴ�ѭ��.
            int sum = tempPoint1->data + tempPoint2->data + quotientRecord;//sum��¼ÿλ�ĺ�.
            int valueForBit = sum % base;//valueForBitΪÿλӦ����¼�ĵĽ��.
            quotientRecord = sum / base;//quotient��¼��λ.
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = valueForBit;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength2; i < objectLength1; ++i) {//�����ȴ�ѭ��.
            int sum = tempPoint1->data + quotientRecord;
            int valueForBit = sum % base;//valueForBitΪÿλӦ����¼�ĵĽ��.
            quotientRecord = sum / base;//quotient��¼��λ.
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = valueForBit;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        if (quotientRecord == 1) {
            result.insert(1, 0);
        }
    } else {//object1�ĳ��� <= object2�ĳ���.
        int objectLength1 = object1.linkListSize();
        int objectLength2 = object2.linkListSize();
        int quotientRecord = 0;//quotient��¼��λ.
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
        result.createLinkListWithoutForValue(objectLength2);//�������������Ϊobject1��object2�г��Ƚϴ���.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
        for (int i = 0; i < objectLength1; ++i) {//��object1��object2�г��Ƚ�С�ߵĳ��ȴ�ѭ��.
            int sum = tempPoint1->data + tempPoint2->data + quotientRecord;//sum��¼ÿλ�ĺ�.
            int valueForBit = sum % base;//valueForBitΪÿλӦ����¼�ĵĽ��.
            quotientRecord = sum / base;//quotient��¼��λ.
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = valueForBit;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength1; i < objectLength2; ++i) {//�����ȴ�ѭ��.
            int sum = tempPoint2->data + quotientRecord;
            int valueForBit = sum % base;//valueForBitΪÿλӦ����¼�ĵĽ��.
            quotientRecord = sum / base;//quotient��¼��λ.
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = valueForBit;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        if (quotientRecord == 1) {
            result.insert(1, 0);
        }
    }
    return result;
}
linkList bigInteger::subtractionAuxiliaryFunction(linkList &object1, linkList &object2, int base) {
    linkList result;
    int objectLength1 = object1.linkListSize();
    int objectLength2 = object2.linkListSize();
    if (objectLength1 > objectLength2) {//object1�ĳ��� > object2�ĳ���.
        int subRecord = 0;//subRecord��¼��λ.
        int sum = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
        result.createLinkListWithoutForValue(objectLength1);//�������������Ϊobject1��object2�г��Ƚϴ���.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
        for (int i = 0; i < objectLength2; ++i) {//��object1��object2�г��Ƚ�С�ߵĳ��ȴ�ѭ��.
            if ((tempPoint1->data - subRecord) < tempPoint2->data) {//��Ҫ��λ.
                sum = tempPoint1->data + base - tempPoint2->data - subRecord;//sum��¼ÿλ�Ĳ�.
                subRecord = 1;//subRecord��¼��λ.
            } else {//����Ҫ��λ.
                sum = tempPoint1->data - tempPoint2->data - subRecord;//sum��¼ÿλ�Ĳ�.
                subRecord = 0;//subRecord��¼��λ.
            }
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength2; i < objectLength1; ++i) {//�����ȴ�ѭ��.
            if (tempPoint1->data < subRecord) {//����λΪ0.
                sum = tempPoint1->data - subRecord + base;//��ǰһλ��1,sum��¼ÿλ����Ĳ�.
                subRecord = 1;//sub��¼��λ.
            } else {//����λ��ΪΪ0.
                sum = tempPoint1->data - subRecord;
                subRecord = 0;//sub��¼��λ.
            }
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = sum;
            resultTempPoint=resultTempPoint->prev;
        }
        if (sum == 0) {
            result.erase(1);
        }
    } else if (objectLength1 < objectLength2) {//object1�ĳ��� < object2�ĳ���.
        int subRecord = 0;//subRecord��¼��λ.
        int sum = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
        result.createLinkListWithoutForValue(objectLength2);//�������������Ϊobject1��object2�г��Ƚϴ���.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
        for (int i = 0; i < objectLength1; ++i) {//��object1��object2�г��Ƚ�С�ߵĳ��ȴ�ѭ��.
            if ((tempPoint2->data - subRecord) < tempPoint1->data) {//��Ҫ��λ.
                sum = tempPoint2->data + base - tempPoint1->data - subRecord;//sum��¼ÿλ�Ĳ�.
                subRecord = 1;//subRecord��¼��λ.
            } else {//����Ҫ��λ.
                sum = tempPoint2->data - tempPoint1->data - subRecord;//sum��¼ÿλ�Ĳ�.
                subRecord = 0;//subRecord��¼��λ.
            }
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength1; i < objectLength2; ++i) {//�����ȴ�ѭ��.
            if (tempPoint2->data < subRecord) {//����λΪ0.
                sum = tempPoint2->data - subRecord + base;//��ǰһλ��1,sum��¼ÿλ����Ĳ�.
                subRecord = 1;//sub��¼��λ.
            } else {//����λ��ΪΪ0.
                sum = tempPoint2->data - subRecord;
                subRecord = 0;//sub��¼��λ.
            }
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;
            resultTempPoint=resultTempPoint->prev;
        }
        if (sum == 0) {
            result.erase(1);
        }
    } else {//object1�ĳ��� = object2�ĳ���.
        int sizeMark = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
        node *markPoint1 = object1.returnHeadPoint()->next;//tempPoint1ָ��object1��һ���ڵ�.
        node *markPoint2 = object2.returnHeadPoint()->next;//tempPoint2ָ��object2��һ���ڵ�.
        //ѭ�����ڱȽ�������������С.
        for (int i = 0; i < objectLength1; ++i) {
            if (markPoint1->data > markPoint2->data) {
                sizeMark = 1;//��һ����������,m��ֵΪ1.
                break;
            } else if (markPoint1->data < markPoint2->data) {
                sizeMark = 2;//�ڶ�����������,m��ֵΪ2.
                break;
            }
            markPoint1 = markPoint1->next;
            markPoint2 = markPoint2->next;
        }
        if (sizeMark == 0) {//�������������.
            result.createLinkListWithoutForValue(1);
            result.returnHeadPoint()->next->data = 0;//��������Ϊ0.
        }
        if (sizeMark == 1) {//��һ����������.
            result.createLinkListWithoutForValue(objectLength1);//������Ϊ����֮�����ⳤ��.
            node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
            int subRecord = 0;//subRecord��¼��λ.
            int sum = 0;
            for (int i = 0; i < objectLength1; i++) {//ѭ��λ����.
                if ((tempPoint1->data - subRecord) < tempPoint2->data) {
                    sum = tempPoint1->data + base - tempPoint2->data - subRecord;//��ǰһλ��1,sum��¼ÿλ����Ĳ�.
                    subRecord = 1;//subRecord��¼��λ.
                } else {
                    sum = tempPoint1->data - tempPoint2->data - subRecord;//ֱ�����.
                    subRecord = 0;//sub��¼��λ.
                }
                tempPoint1 = tempPoint1->prev;
                tempPoint2 = tempPoint2->prev;
                resultTempPoint->data = sum;//�������������.
                resultTempPoint = resultTempPoint->prev;
            }
            if (sum == 0) {//�������λΪ0.
                result.erase(1);//����һ���ڵ�,������0ɾ��.
            }
            node *temp1 = result.returnHeadPoint()->next;
            node *temp2 = temp1->next;
            node *temp3 = result.returnHeadPoint();
            while (temp1->data == 0) {//����0001�����,ѭ������ɾ������0.
                delete temp1;//ɾ���ýڵ�.
                temp1 = temp2;
                temp2 = temp2->next;
                result.returnLinkListLength() = result.returnLinkListLength() - 1;//�����ȼ�1.
            }
            temp3->next = temp1;//ɾ���ڵ�֮������Ӳ���.
            temp1->prev = temp3;
        } else if (sizeMark == 2) {//�ڶ�����������
            result.createLinkListWithoutForValue(objectLength1);//������Ϊ����֮�����ⳤ��.
            node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
            int subRecord = 0;//subRecord��¼��λ.
            int sum = 0;
            for (int i = 0; i < objectLength1; i++) {//ѭ��λ����.
                if ((tempPoint2->data - subRecord) < tempPoint1->data) {
                    sum = tempPoint2->data + base - tempPoint1->data - subRecord;//��ǰһλ��1,sum��¼ÿλ����Ĳ�.
                    subRecord = 1;//sub��¼��λ.
                } else {
                    sum = tempPoint2->data - tempPoint1->data - subRecord;//ֱ�����.
                    subRecord = 0;//sub��¼��λ.
                }
                tempPoint1 = tempPoint1->prev;
                tempPoint2 = tempPoint2->prev;
                resultTempPoint->data = sum;//�������������.
                resultTempPoint = resultTempPoint->prev;
            }
            if (sum == 0) {//�������λΪ0.
                result.erase(1);//����һ���ڵ�,������0ɾ��.
            }
            node *temp1 = result.returnHeadPoint()->next;
            node *temp2 = temp1->next;
            node *temp3 = result.returnHeadPoint();
            while (temp1->data == 0) {//����0001�����,ѭ������ɾ������0.
                delete temp1;//ɾ���ýڵ�.
                temp1 = temp2;
                temp2 = temp2->next;
                result.returnLinkListLength() = result.returnLinkListLength() - 1;//�����ȼ�1.
            }
            temp3->next = temp1;//ɾ���ڵ�֮������Ӳ���.
            temp1->prev = temp3;
        }
    }
    return result;
}
linkList bigInteger::multiplicationAuxiliaryFunction(linkList &object1, linkList &object2, int base) {
    linkList result;
    int objectLength1 = object1.linkListSize();
    int objectLength2 = object2.linkListSize();
    //judgePoint1��judgePoint2�����ж����������Ƿ�Ϊ0����.
    node *judgePoint1 = object1.returnHeadPoint()->next;
    node *judgePoint2 = object2.returnHeadPoint()->next;
    node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
    //����������������һ��Ϊ0.
    if (judgePoint1->data == 0 || judgePoint2->data == 0) {
        result.insert(0,0);//��˽��Ϊ0.
    } else {
        result.createLinkListWithForValue(objectLength1 + objectLength2);//��������Ϊ����������֮��,��ȫ����ʼ��.
        //markPoint�����ÿ����˵Ľ����������,tempPoint��ǰ��λ.
        node *tempPoint = result.returnHeadPoint()->prev;
        node *markPoint = tempPoint;
        for (int i = 0; i < objectLength2; ++i) {
            if (tempPoint2->data == 0) {
                tempPoint2 = tempPoint2->prev;
                tempPoint = tempPoint->prev;
                markPoint = tempPoint;
                continue;
            }
            int temp = 0;
            node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
            for (int j = 0; j < objectLength1; ++j) {
                //ÿ����Ҫ�������������.
                temp = temp + (tempPoint2->data) * (tempPoint1->data) + markPoint->data;
                markPoint->data = temp % base;//���.
                temp = temp / base;//��λ.
                tempPoint1 = tempPoint1->prev;
                markPoint = markPoint->prev;
            }
            markPoint->data = markPoint->data + temp;//��λ��Ľ����������.
            tempPoint2 = tempPoint2->prev;
            tempPoint = tempPoint->prev;
            markPoint = tempPoint;
        }
        if (result.returnHeadPoint()->next->data == 0)//�����λΪ0.
            result.erase(1);//ɾ��0.
    }
    return result;
}
linkList bigInteger::divisionFunction(linkList &operator1, linkList &operator2, int base) {
    int l1=operator1.linkListSize();
    int l2=operator2.linkListSize();
    node*ptr1=operator1.returnHeadPoint()->prev;//ָ������β
    node*ptr2=operator2.returnHeadPoint()->prev;//ָ������β
    linkList d;
    d.createLinkListWithoutForValue(l1);//�ϳ��ߵĳ���
    node*ptr3=d.returnHeadPoint()->prev;
    int sum,sub=0;
    for(int i=0;i<l2;i++)
    {
        if((ptr1->data-sub)<ptr2->data)
        {
            sum=ptr1->data+10-ptr2->data-sub;//��λ�����
            sub=1;//��¼��λ
        }
        else
        {
            sum=ptr1->data-ptr2->data-sub;//ֱ�����
            sub=0;//��¼��λ
        }
        ptr1=ptr1->prev;
        ptr2=ptr2->prev;
        ptr3->data=sum;//���������������
        ptr3=ptr3->prev;
    }
    for(int k=l2;k<l1;k++)//��λ��ѭ��
    {
        if(ptr1->data<sub)//С��0
        {
            sum=ptr1->data-sub+10;//��λ���
            sub=1;//��¼��λ
        }
        else
        {
            sum=ptr1->data-sub;//ֱ�����
            sub=0;//��λ
        }
        ptr1=ptr1->prev;
        ptr3->data=sum;//���������������
        ptr3=ptr3->prev;
    }
    node*ptr4=d.returnHeadPoint()->next;
    node*ptr5=ptr4->next;
    node*ptr6=d.returnHeadPoint();
    while(ptr4->data==0&&d.linkListSize()>1)//����0001���,ѭ������ɾ������0
    {
        delete ptr4;//ɾ������0
        ptr4=ptr5;
        ptr5=ptr5->next;
        d.returnLinkListLength()=d.returnLinkListLength()-1;//�����ȼ�1
    }
    ptr6->next=ptr4;//ɾ���ڵ�֮������Ӳ���
    ptr4->prev=ptr6;
    return d;
}
linkList bigInteger::divisionAuxiliaryFunction(linkList &object1, linkList &object2, int base) {
    linkList result;
    if (comparisonOfSize(object1, object2) == -1) {//�����ȱ�����������.
        result.insert(0, 0);
    } else {//�����ͱ�������Ȼ򱻳����ȳ���������.
        if (object2.returnHeadPoint()->next->data == 0) {//����Ϊ0�����.
            cout << "Divide by 0, no result!" << endl;
        } else if (object1.returnHeadPoint()->next->data == 0) {//������Ϊ0�����.
            result.insert(0, 0);
        } else {//�������.
            linkList tempList;
            int objectLength1 = object1.linkListSize();
            int objectLength2 = object2.linkListSize();
            if ((objectLength2 - 1) != 0) {
                tempList.createLinkListWithoutForValue(objectLength2 - 1);
                node *tempListPtr = tempList.returnHeadPoint()->next;
                node *ptr = object1.returnHeadPoint()->next;
                for (int i = 0; i < objectLength2 - 1; ++i) {//ѭ����ֵ.
                    tempListPtr->data = ptr->data;
                    tempListPtr = tempListPtr->next;
                    ptr = ptr->next;
                }
            }
            node *markPtr = object1.returnHeadPoint()->next;
            for (int i = 0; i < objectLength2 - 1; ++i) {//Ѱ��object2���λλ��object1��λ��.
                markPtr = markPtr->next;
            }
            node *erasePoint;
            for (int i = objectLength2 - 1; i < objectLength1; ++i) {
                int count = 0;//count��¼�������.
                erasePoint = tempList.returnHeadPoint()->next;
                if (erasePoint->data == 0) {//���֮���Ϊ0,��0���������0.
                    node *change = tempList.returnHeadPoint()->next;
                    change->data = markPtr->data;
                } else {//����������һλ��.
                    tempList.insert(markPtr->data, tempList.linkListSize());
                }
                while ((comparisonOfSize(tempList, object2)) >= 0) {//�Ƚ��������Ĵ�С.
                    tempList = subtractionAuxiliaryFunction(tempList, object2, base);//����������.
                    count++;//��¼��������.
                }
                markPtr = markPtr->next;
                result.insert(count, result.linkListSize());//��ÿ�������Ĵ������뵽result��.
            }
            if (result.returnHeadPoint()->next->data == 0) {//�������Ϊ0.
                result.erase(1);
            }
        }
    }
    return result;
}
void bigInteger::addition_bigInteger(linkList &operation1, linkList &operation2, int base) {
    linkList result;
    time_t timeStart, timeEnd;//ʱ�����.
    time(&timeStart);//������ʼʱ��.
    if (operation1.linkListFlag() == -1) {//��һ������Ϊ����.
        if (operation2.linkListFlag() == 1) {//�ڶ�������Ϊ����.
            if (comparisonOfSize(operation1, operation2) == 1) {//��һ�����ľ���ֵ���ڵڶ�����.
                result = subtractionAuxiliaryFunction(operation1, operation2, base);
                result.returnLinkListFlag() = -1;
                cout << result;
                cout << endl;
            } else {//��һ�����ľ���ֵС�ڵ��ڵڶ�����.
                result = subtractionAuxiliaryFunction(operation2, operation1, base);
                cout << result;
                cout << endl;
            }
        } else {//�ڶ�������Ϊ������0.
            result = additionAuxiliaryFunction(operation1, operation2, base);
            result.returnLinkListFlag() = -1;
            cout << result;
            cout << endl;
        }
    } else {//��һ������Ϊ������0.
        if (operation2.linkListFlag() == -1) {//�ڶ�������Ϊ����.
            if (comparisonOfSize(operation1, operation2) == -1) {//��һ�����ľ���ֵС�ڵڶ�����.
                result = subtractionAuxiliaryFunction(operation2, operation1,base);
                result.returnLinkListFlag() = -1;
                cout << result;
                cout << endl;
            } else {//��һ�����ľ���ֵ���ڵ��ڵڶ�����.
                result = subtractionAuxiliaryFunction(operation1, operation2, base);
                cout << result;
                cout << endl;
            }
        } else {//�ڶ�������Ϊ������0.
            result = additionAuxiliaryFunction(operation1, operation2, base);
            cout << result;
            cout << endl;
        }
    }
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_decimalSystem.txt)");
    }
}
void bigInteger::addition_bigInteger_binarySystem(linkList &object1, linkList &object2) {
    time_t timeStart, timeEnd;//ʱ�����.
    linkList result;
    time(&timeStart);//������ʼʱ��.
    bool lengthJudge = compareListLength(object1, object2);//�жϴ���������������ĳ��ȴ�С.
    if (lengthJudge) {//object1�ĳ��� > object2�ĳ���.
        int objectLength1 = object1.linkListSize();
        int objectLength2 = object2.linkListSize();
        int quotientRecord = 0;//quotient��¼��λ.
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
        result.createLinkListWithoutForValue(objectLength1);//�������������Ϊobject1��object2�г��Ƚϴ���.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
        for (int i = 0; i < objectLength2; ++i) {//��object1��object2�г��Ƚ�С�ߵĳ��ȴ�ѭ��.
            int sum = tempPoint1->data + tempPoint2->data + quotientRecord;//sum��¼ÿλ�ĺ�.
            int valueForBit = sum % 2;//valueForBitΪÿλӦ����¼�ĵĽ��.
            quotientRecord = sum / 2;//quotient��¼��λ.
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = valueForBit;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength2; i < objectLength1; ++i) {//�����ȴ�ѭ��.
            int sum = tempPoint1->data + quotientRecord;
            int valueForBit = sum % 2;//valueForBitΪÿλӦ����¼�ĵĽ��.
            quotientRecord = sum / 2;//quotient��¼��λ.
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = valueForBit;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        if (quotientRecord == 1) {
            result.insert(1, 0);
        }
    } else {//object1�ĳ��� <= object2�ĳ���.
        int objectLength1 = object1.linkListSize();
        int objectLength2 = object2.linkListSize();
        int quotientRecord = 0;//quotient��¼��λ.
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
        result.createLinkListWithoutForValue(objectLength2);//�������������Ϊobject1��object2�г��Ƚϴ���.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
        for (int i = 0; i < objectLength1; ++i) {//��object1��object2�г��Ƚ�С�ߵĳ��ȴ�ѭ��.
            int sum = tempPoint1->data + tempPoint2->data + quotientRecord;//sum��¼ÿλ�ĺ�.
            int valueForBit = sum % 2;//valueForBitΪÿλӦ����¼�ĵĽ��.
            quotientRecord = sum / 2;//quotient��¼��λ.
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = valueForBit;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength1; i < objectLength2; ++i) {//�����ȴ�ѭ��.
            int sum = tempPoint2->data + quotientRecord;
            int valueForBit = sum % 2;//valueForBitΪÿλӦ����¼�ĵĽ��.
            quotientRecord = sum / 2;//quotient��¼��λ.
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = valueForBit;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        if (quotientRecord == 1) {
            result.insert(1, 0);
        }
    }
    cout << result << endl;
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_binarySystem.txt)");
    }
}
void bigInteger::subtraction_bigInteger(linkList &operation1, linkList &operation2, int base) {
    linkList result;
    time_t timeStart, timeEnd;//ʱ�����.
    time(&timeStart);//������ʼʱ��.
    if (operation2.linkListFlag() == 0) {//�ڶ���������Ϊ0.
        result = operation1;
    } else if (operation2.linkListFlag() == 1) {//�ڶ���������Ϊ����.
        if (operation1.linkListFlag() == 1) {//��һ��������Ϊ����.
            if (comparisonOfSize(operation1, operation2) == -1) {//��һ�������ľ���ֵС�ڵڶ�������.
                result = subtractionAuxiliaryFunction(operation2, operation1, base);
                result.returnLinkListFlag() = -1;
                cout << result;
                cout << endl;
            } else {//��һ�������ľ���ֵ���ڵ��ڵڶ�������.
                result = subtractionAuxiliaryFunction(operation1, operation2, base);
                cout << result;
                cout << endl;
            }
        } else {//��һ��������Ϊ������0.
            result = additionAuxiliaryFunction(operation1, operation2, base);
            result.returnLinkListFlag() = -1;
            cout << result;
            cout << endl;
        }
    } else {//�ڶ���������Ϊ����.
        if (operation1.linkListFlag() == -1) {//��һ��������Ϊ����.
            if (comparisonOfSize(operation1, operation2) == 1) {
                result = subtractionAuxiliaryFunction(operation1, operation2, base);
                result.returnLinkListFlag() = -1;
                cout << result;
                cout << endl;
            } else {//��һ�������ľ���ֵС�ڵ��ڵڶ�������.
                result = subtractionAuxiliaryFunction(operation2, operation1, base);
                cout << result;
                cout << endl;
            }
        } else {//��һ��������Ϊ������0.
            result = additionAuxiliaryFunction(operation1, operation2, base);
            cout << result;
            cout << endl;
        }
    }
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_decimalSystem.txt)");
    }
}
void bigInteger::subtraction_bigInteger_binarySystem(linkList &object1, linkList &object2) {
    time_t timeStart, timeEnd;//ʱ�����.
    linkList result;
    int objectLength1 = object1.linkListSize();
    int objectLength2 = object2.linkListSize();
    time(&timeStart);//������ʼʱ��.
    if (objectLength1 > objectLength2) {//object1�ĳ��� > object2�ĳ���.
        int subRecord = 0;//subRecord��¼��λ.
        int sum = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
        result.createLinkListWithoutForValue(objectLength1);//�������������Ϊobject1��object2�г��Ƚϴ���.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
        for (int i = 0; i < objectLength2; ++i) {//��object1��object2�г��Ƚ�С�ߵĳ��ȴ�ѭ��.
            if ((tempPoint1->data - subRecord) < tempPoint2->data) {//��Ҫ��λ.
                sum = tempPoint1->data + 2 - tempPoint2->data - subRecord;//sum��¼ÿλ�Ĳ�.
                subRecord = 1;//subRecord��¼��λ.
            } else {//����Ҫ��λ.
                sum = tempPoint1->data - tempPoint2->data - subRecord;//sum��¼ÿλ�Ĳ�.
                subRecord = 0;//subRecord��¼��λ.
            }
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength2; i < objectLength1; ++i) {//�����ȴ�ѭ��.
            if (tempPoint1->data < subRecord) {//����λΪ0.
                sum = tempPoint1->data - subRecord + 2;//��ǰһλ��1,sum��¼ÿλ����Ĳ�.
                subRecord = 1;//sub��¼��λ.
            } else {//����λ��ΪΪ0.
                sum = tempPoint1->data - subRecord;
                subRecord = 0;//sub��¼��λ.
            }
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = sum;
            resultTempPoint=resultTempPoint->prev;
        }
        if (sum == 0) {
            result.erase(1);
        }
    } else if (objectLength1 < objectLength2) {//object1�ĳ��� < object2�ĳ���.
        int subRecord = 0;//subRecord��¼��λ.
        int sum = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
        result.createLinkListWithoutForValue(objectLength2);//�������������Ϊobject1��object2�г��Ƚϴ���.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
        for (int i = 0; i < objectLength1; ++i) {//��object1��object2�г��Ƚ�С�ߵĳ��ȴ�ѭ��.
            if ((tempPoint2->data - subRecord) < tempPoint1->data) {//��Ҫ��λ.
                sum = tempPoint2->data + 2 - tempPoint1->data - subRecord;//sum��¼ÿλ�Ĳ�.
                subRecord = 1;//subRecord��¼��λ.
            } else {//����Ҫ��λ.
                sum = tempPoint2->data - tempPoint1->data - subRecord;//sum��¼ÿλ�Ĳ�.
                subRecord = 0;//subRecord��¼��λ.
            }
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;//����������������.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength1; i < objectLength2; ++i) {//�����ȴ�ѭ��.
            if (tempPoint2->data < subRecord) {//����λΪ0.
                sum = tempPoint2->data - subRecord + 2;//��ǰһλ��1,sum��¼ÿλ����Ĳ�.
                subRecord = 1;//sub��¼��λ.
            } else {//����λ��ΪΪ0.
                sum = tempPoint2->data - subRecord;
                subRecord = 0;//sub��¼��λ.
            }
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;
            resultTempPoint=resultTempPoint->prev;
        }
        if (sum == 0) {
            result.erase(1);
        }
    } else {//object1�ĳ��� = object2�ĳ���.
        int sizeMark = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
        node *markPoint1 = object1.returnHeadPoint()->next;//tempPoint1ָ��object1��һ���ڵ�.
        node *markPoint2 = object2.returnHeadPoint()->next;//tempPoint2ָ��object2��һ���ڵ�.
        //ѭ�����ڱȽ�������������С.
        for (int i = 0; i < objectLength1; ++i) {
            if (markPoint1->data > markPoint2->data) {
                sizeMark = 1;//��һ����������,m��ֵΪ1.
                break;
            } else if (markPoint1->data < markPoint2->data) {
                sizeMark = 2;//�ڶ�����������,m��ֵΪ2.
                break;
            }
            markPoint1 = markPoint1->next;
            markPoint2 = markPoint2->next;
        }
        if (sizeMark == 0) {//�������������.
            result.createLinkListWithoutForValue(1);
            result.returnHeadPoint()->next->data = 0;//��������Ϊ0.
        }
        if (sizeMark == 1) {//��һ����������.
            result.createLinkListWithoutForValue(objectLength1);//������Ϊ����֮�����ⳤ��.
            node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
            int subRecord = 0;//subRecord��¼��λ.
            int sum = 0;
            for (int i = 0; i < objectLength1; i++) {//ѭ��λ����.
                if ((tempPoint1->data - subRecord) < tempPoint2->data) {
                    sum = tempPoint1->data + 2 - tempPoint2->data - subRecord;//��ǰһλ��1,sum��¼ÿλ����Ĳ�.
                    subRecord = 1;//subRecord��¼��λ.
                } else {
                    sum = tempPoint1->data - tempPoint2->data - subRecord;//ֱ�����.
                    subRecord = 0;//sub��¼��λ.
                }
                tempPoint1 = tempPoint1->prev;
                tempPoint2 = tempPoint2->prev;
                resultTempPoint->data = sum;//�������������.
                resultTempPoint = resultTempPoint->prev;
            }
            if (sum == 0) {//�������λΪ0.
                result.erase(1);//����һ���ڵ�,������0ɾ��.
            }
            node *temp1 = result.returnHeadPoint()->next;
            node *temp2 = temp1->next;
            node *temp3 = result.returnHeadPoint();
            while (temp1->data == 0) {//����0001�����,ѭ������ɾ������0.
                delete temp1;//ɾ���ýڵ�.
                temp1 = temp2;
                temp2 = temp2->next;
                result.returnLinkListLength() = result.returnLinkListLength() - 1;//�����ȼ�1.
            }
            temp3->next = temp1;//ɾ���ڵ�֮������Ӳ���.
            temp1->prev = temp3;
        } else if (sizeMark == 2) {//�ڶ�����������
            result.createLinkListWithoutForValue(objectLength1);//������Ϊ����֮�����ⳤ��.
            node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPointָ��result��β�ڵ�.
            int subRecord = 0;//subRecord��¼��λ.
            int sum = 0;
            for (int i = 0; i < objectLength1; i++) {//ѭ��λ����.
                if ((tempPoint2->data - subRecord) < tempPoint1->data) {
                    sum = tempPoint2->data + 2 - tempPoint1->data - subRecord;//��ǰһλ��1,sum��¼ÿλ����Ĳ�.
                    subRecord = 1;//sub��¼��λ.
                } else {
                    sum = tempPoint2->data - tempPoint1->data - subRecord;//ֱ�����.
                    subRecord = 0;//sub��¼��λ.
                }
                tempPoint1 = tempPoint1->prev;
                tempPoint2 = tempPoint2->prev;
                resultTempPoint->data = sum;//�������������.
                resultTempPoint = resultTempPoint->prev;
            }
            if (sum == 0) {//�������λΪ0.
                result.erase(1);//����һ���ڵ�,������0ɾ��.
            }
            node *temp1 = result.returnHeadPoint()->next;
            node *temp2 = temp1->next;
            node *temp3 = result.returnHeadPoint();
            while (temp1->data == 0) {//����0001�����,ѭ������ɾ������0.
                delete temp1;//ɾ���ýڵ�.
                temp1 = temp2;
                temp2 = temp2->next;
                result.returnLinkListLength() = result.returnLinkListLength() - 1;//�����ȼ�1.
            }
            temp3->next = temp1;//ɾ���ڵ�֮������Ӳ���.
            temp1->prev = temp3;
        }
    }
    cout << result << endl;
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_binarySystem.txt)");
    }
}
void bigInteger::multiplication_bigInteger(linkList &operation1, linkList &operation2, int base) {
    linkList result;
    time_t timeStart, timeEnd;//ʱ�����.
    time(&timeStart);//������ʼʱ��.
    if (operation1.linkListFlag() == operation2.linkListFlag()) {
        result = multiplicationAuxiliaryFunction(operation1, operation2, base);
        cout << result;
        cout << endl;
    } else {
        result = multiplicationAuxiliaryFunction(operation1, operation2, base);
        result.returnLinkListFlag() = -1;
        cout << result;
        cout << endl;
    }
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_decimalSystem.txt)");
    }
}
void bigInteger::multiplication_bigInteger_binarySystem(linkList &object1, linkList &object2) {
    time_t timeStart, timeEnd;//ʱ�����.
    linkList result;
    int objectLength1 = object1.linkListSize();
    int objectLength2 = object2.linkListSize();
    time(&timeStart);//������ʼʱ��.
    //judgePoint1��judgePoint2�����ж����������Ƿ�Ϊ0����.
    node *judgePoint1 = object1.returnHeadPoint()->next;
    node *judgePoint2 = object2.returnHeadPoint()->next;
    node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2ָ��object2��β�ڵ�.
    //����������������һ��Ϊ0.
    if (judgePoint1->data == 0 || judgePoint2->data == 0) {
        result.insert(0,0);//��˽��Ϊ0.
    } else {
        result.createLinkListWithForValue(objectLength1 + objectLength2);//��������Ϊ����������֮��,��ȫ����ʼ��.
        //markPoint�����ÿ����˵Ľ����������,tempPoint��ǰ��λ.
        node *tempPoint = result.returnHeadPoint()->prev;
        node *markPoint = tempPoint;
        for (int i = 0; i < objectLength2; ++i) {
            if (tempPoint2->data == 0) {
                tempPoint2 = tempPoint2->prev;
                tempPoint = tempPoint->prev;
                markPoint = tempPoint;
                continue;
            }
            int temp = 0;
            node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1ָ��object1��β�ڵ�.
            for (int j = 0; j < objectLength1; ++j) {
                //ÿ����Ҫ�������������.
                temp = temp + (tempPoint2->data) * (tempPoint1->data) + markPoint->data;
                markPoint->data = temp % 2;//���.
                temp = temp / 2;//��λ.
                tempPoint1 = tempPoint1->prev;
                markPoint = markPoint->prev;
            }
            markPoint->data = markPoint->data + temp;//��λ��Ľ����������.
            tempPoint2 = tempPoint2->prev;
            tempPoint = tempPoint->prev;
            markPoint = tempPoint;
        }
        if (result.returnHeadPoint()->next->data == 0)//�����λΪ0.
            result.erase(1);//ɾ��0.
    }
    cout << result << endl;
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_binarySystem.txt)");
    }
}
void bigInteger::division_bigInteger(linkList &operation1, linkList &operation2, int base) {
    linkList result;
    time_t timeStart, timeEnd;//ʱ�����.
    time(&timeStart);//������ʼʱ��.
    if (operation1.linkListFlag() == operation2.linkListFlag()) {
        result = divisionAuxiliaryFunction(operation1, operation2, base);
        cout << result;
        cout << endl;
    } else {
        result = divisionAuxiliaryFunction(operation1, operation2, base);
        result.returnLinkListFlag() = -1;
        cout << result;
        cout << endl;
    }
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_decimalSystem.txt)");
    }
}
void bigInteger::division_bigInteger_binarySystem(linkList &object1, linkList &object2) {
    linkList result;
    time_t timeStart, timeEnd;//ʱ�����.
    time(&timeStart);//������ʼʱ��.
    if (comparisonOfSize(object1, object2) == -1) {//�����ȱ�����������.
        result.insert(0, 0);
    } else {//�����ͱ�������Ȼ򱻳����ȳ���������.
        if (object2.returnHeadPoint()->next->data == 0) {//����Ϊ0�����.
            cout << "Divide by 0, no result!" << endl;
        } else if (object1.returnHeadPoint()->next->data == 0) {//������Ϊ0�����.
            result.insert(0, 0);
        } else {//�������.
            linkList tempList;
            int objectLength1 = object1.linkListSize();
            int objectLength2 = object2.linkListSize();
            if ((objectLength2 - 1) != 0) {
                tempList.createLinkListWithoutForValue(objectLength2 - 1);
                node *tempListPtr = tempList.returnHeadPoint()->next;
                node *ptr = object1.returnHeadPoint()->next;
                for (int i = 0; i < objectLength2 - 1; ++i) {//ѭ����ֵ.
                    tempListPtr->data = ptr->data;
                    tempListPtr = tempListPtr->next;
                    ptr = ptr->next;
                }
            }
            node *markPtr = object1.returnHeadPoint()->next;
            for (int i = 0; i < objectLength2 - 1; ++i) {//Ѱ��object2���λλ��object��λ��.
                markPtr = markPtr->next;
            }
            node *erasePoint;
            for (int i = objectLength2 - 1; i < objectLength1; ++i) {
                int count = 0;//count��¼�������.
                erasePoint = tempList.returnHeadPoint()->next;
                if (erasePoint->data == 0) {//���֮���Ϊ0,��0���������0.
                    node *change = tempList.returnHeadPoint()->next;
                    change->data = markPtr->data;
                } else {//����������һλ��.
                    tempList.insert(markPtr->data, tempList.linkListSize());
                }
                while ((comparisonOfSize(tempList, object2)) >= 0) {//�Ƚ��������Ĵ�С.
                    tempList = subtractionAuxiliaryFunction(tempList, object2, 2);//����������.
                    count++;//��¼��������.
                }
                markPtr = markPtr->next;
                result.insert(count, result.linkListSize());//��ÿ�������Ĵ������뵽result��.
            }
            if (result.returnHeadPoint()->next->data == 0) {//�������Ϊ0.
                result.erase(1);
            }
        }
    }
    cout << result << endl;
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_binarySystem.txt)");
    }
}
void bigInteger::exponentialCalculation_bigInteger(linkList &operation1, linkList &operation2, int base) {
    linkList result;
    time_t timeStart, timeEnd;//ʱ�����.
    time(&timeStart);//������ʼʱ��.
    if (operation2.linkListSize() == 1 && operation2.returnHeadPoint()->next->data == 0) {//ָ����0�����.
        result.insert(1, 0);
    } else if (operation2.linkListSize() == 1 && operation2.returnHeadPoint()->next->data == 1) {//ָ����1�����.
        result = operation1;
    } else {
        linkList tempList;
        tempList.insert(1, 0);
        result = multiplicationAuxiliaryFunction(operation1, operation1, base);//��һ�γ˷�,ƽ��.
        operation2 = divisionFunction(operation2, tempList, base);//ѭ��������1.
        while ((comparisonOfSize(operation2, tempList)) == 1) {
            result = multiplicationAuxiliaryFunction(result, operation1, base);//����.
            operation2 = subtractionAuxiliaryFunction(operation2, tempList, 10);//ѭ��������1.
        }
    }
    cout << result << endl;
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string url;
        if (base == 10) {
            url = R"(C:\Users\15590\Desktop\Operation of large integers\file\result_decimalSystem.txt)";
        } else {
            url = R"(C:\Users\15590\Desktop\Operation of large integers\file\result_binarySystem.txt)";
        }
        string str = translateToString(result);
        writeFile(str, url);
    }
}