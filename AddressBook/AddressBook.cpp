#include <iostream>
#include <string>
using namespace std;
#define MAX 1000        //宏定义


//设计联系人结构体
struct Person {
	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计通讯录结构体
struct Addressbooks {
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前保存联系人个数
	int m_Size;
};

//添加联系人
void addPerson(Addressbooks * abs) {
	//判断通讯录是否已满
	if (abs->m_Size == MAX) {
		std::cout << "通讯录已满，无法添加!" << endl;
		return;
	}
	else {
		//添加联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true)
		{
			cout << "请输入性别：" << endl;
			int sex = 0;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "您输入的有误，请重新输入！" << endl;
			}
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭住址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//更新通讯录人数
		abs->m_Size++;

		system("pause");  //按任意键继续
		system("cls");    //清屏
	}
};

//显示联系人
void showPerson(Addressbooks * abs) {
	if (abs->m_Size == 0) {
		cout << "当前通讯录为空" << endl;
		return;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {

			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "住址： " << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

//查找联系人是否存在,存在返回下标，不存在返回-1
int isExist(Addressbooks * abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;  //如果遍历结束都没有找到，返回 -1
}

//删除联系人
void deletePerson(Addressbooks * abs) {
	cout << "请输入删除联系人姓名： ";
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;   //更新通讯录中的人数
		cout << "删除成功" << endl;
	}
	else {
		cout << "找到此人" << endl;
	}

	system("pause");
	system("cls");
};

//查找联系人
void findPerson(Addressbooks * abs) {
	cout << "请输入要查找的联系人： ";
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		Person person = abs->personArray[ret];
		cout << "姓名： " << person.m_Name << "\t";
		cout << "性别： " << person.m_Sex << "\t";
		cout << "年龄： " << person.m_Age << "\t";
		cout << "电话： " << person.m_Phone << "\t";
		cout << "住址： " << person.m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks * abs) {
	cout << "请输入您要修改的联系人： " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {
		Person * person = &abs->personArray[ret];
		//姓名
		cout << "请输入姓名： " << endl;
		string name;
		cin >> name;
		person->m_Name = name;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				person->m_Sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入！" << endl;
			}
		}

		//年龄
		cout << "亲输入年龄： " << endl;
		int age;
		cin >> age;
		person->m_Age = age;

		//联系电话
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		person->m_Phone = phone;

		//家庭住址
		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		person->m_Addr = address;
	}
	else {
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(Addressbooks * abs) {
	cout << "确定要清空通讯录吗？y/n" << endl;
	char flag;
	cin >> flag;
	if (flag == 'y') {
		abs->m_Size = 0;
		cout << "通讯录已清空" << endl;
	}
	else {
	}

	system("pause");
	system("cls");
}

//显示主菜单
void showMenu() {
	cout << "***********************************" << endl;
	cout << "********** 1.添加联系人 ***********" << endl;
	cout << "********** 2.显示联系人 ***********" << endl;
	cout << "********** 3.删除联系人 ***********" << endl;
	cout << "********** 4.查找联系人 ***********" << endl;
	cout << "********** 5.修改联系人 ***********" << endl;
	cout << "********** 6.清空联系人 ***********" << endl;
	cout << "********** 0.退出通讯录 ***********" << endl;
	cout << "***********************************" << endl;
}

int main() {

	int select = 0; //创建用户选择输入的变量

	//创建通讯录结构体变量
	struct Addressbooks abs;
	//初始化通讯录当前人员个数
	abs.m_Size = 0;

	while (true)
	{
		//菜单调用
		showMenu();
		cin >> select;

		switch (select) {
		case 1:    //添加联系人
			addPerson(&abs);
			break;
		case 2:    //显示联系人
			showPerson(&abs);
			break;
		case 3:    //删除联系人
			deletePerson(&abs);
			break;
		case 4:    //查找联系人
			findPerson(&abs);
			break;
		case 5:    //修改联系人
			modifyPerson(&abs);
			break;
		case 6:    //清空联系人
			cleanPerson(&abs);
			break;
		case 0:    //退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	system("cls");
	return 0;
}