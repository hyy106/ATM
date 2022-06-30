#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"time.h"
#include"cstdio"
#include"windows.h"
#include"conio.h"


//函数声明
void main1();
void InitTraData();
void SignUp(); 
void SignIn();   
void Menu(); 
void SaveMoney(); 
void SaveMoney1();
void WithdrawMoney();  
void WithdrawMoney1(); 
void TransferMoney();   
void TransferMoney1();  
void Inquire();   
void InquireBalance(); 
void InqInformation();  
void InqRecord(); 
void ChangeInformation();  
void ChangeUserName();   
void ChangePhone();   
void ChangePassword(); 
void getPassword(char a[], int b);  
void SysTime();       
void SaveUserData();    
void SaveTransactionData();     
void IniUser_Data();     
void SetPassword();           
void SetPhoneNum();          
void SaveTransaction();      
void WithdrawTransaction();    
void TransferTransaction();      
void HandTransaction();        
void PrintTransaction();   
float HandMoney; 
int QK = 0, CK = 0, ZZ = 0;


struct Account
{
	char name[100];
	char AccountNum[50];
	char PhoneNum[12];
	char password[10];
	float balance;

	struct Account* next;
};

struct Trade
{
	char TAccountNum[50];
	char Time[100];
	char Operation[100];
	float Money;

	struct Trade* Tnext;
};

typedef struct Account Account;
typedef struct Trade Trade;
Account* Pset = (Account*)malloc(sizeof(Account));
Account* head = NULL;
Account* tail = NULL;
Account* curAccount;
Account* curAccountO;
Account ZX;

Trade* THead = NULL;
Trade* TTail = NULL;
Trade* TCurAccount;
Trade TA;


int FindACC(Account IV1)//登录时查找当前账户
{
	Account* curP = head;
	Trade* TcurP = THead;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV1.AccountNum) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindPassword(Account IV1)//登录时查找当前账户密码
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV1.AccountNum) == 0 && strcmp(curP->password, IV1.password) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindACC2(Account IV)//查找是否被已有账户
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV.AccountNum) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindACC3(Account TT)//查找转账账户
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curAccount->AccountNum, TT.AccountNum) == 0)
		{
			int a, b = 0;
			printf("\n错误！\n");
			while (b < 3)
			{
				printf("\n\n1.重新输入对方账户号码");
				printf("\n\n2.返回主菜单");
				printf("\n\n0.退出系统\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					TransferMoney();
					b = 3;
					break;
				case 2:
					system("cls");
					Menu();
					b = 3;
					break;
				case 0:
					b = 3;
					SaveUserData();
					exit(0);
				default:
					b++;
					break;
				}
			}
		}
		else if (strcmp(curP->AccountNum, TT.AccountNum) == 0)
		{
			curAccountO = curP;//当前转账对象账户
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}


int main()
{
	SysTime();
	IniUser_Data();
	InitTraData();
	main1();
	SaveUserData();
	SaveTransactionData();
	return 0;
}

void main1()
{
	printf("\n键入对应选项数字，按回车键确认。\n\t\n");
	int a, b = 0;
	while (b != 1)
	{
		printf("\n\t1.用户登录");
		printf("\t2.用户注册\n");
		printf("\t0.退出\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			SignIn();
			break;
		case 2:
			SignUp();
			break;
		case 0:
			exit(0);
		default:
			b = 1;
			system("cls");
			printf("\n输入有误，请按照提示再次输入!");
			break;
		}
	}
}

void SignIn()//登录
{
	system("cls");
	int m = 0, n = 0;
	while (m < 3)//3次输入错账号将退出系统
	{
		Account IV1;//账户中间变量1
		printf("\n\t输入账号\n");
		scanf("%s", IV1.AccountNum);
		system("cls");
		if (FindACC(IV1))
		{
			while (n < 3)//3次输入错密码将退出系统
			{
				printf("\n\t输入密码\n");
				char storePassword[10] = { '\0' };    //存储用户输入的密码
				getPassword(storePassword, 10);
				strcpy(IV1.password, storePassword);
				system("cls");
				if (FindPassword(IV1))
				{
					m = 3;
					n = 3;
					Menu();
					break;
				}
				else
				{
					m++;
					n++;
					if (n == 3)
					{
						printf("\n\t该账号已被冻结\n");
						strcpy(curAccount->password, "abc");;
						break;
					}
					else
					{
						printf("\n\t密码错误\n");
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\t没有查找到该用户!请重新输入\n");
			if (m == 3)
			{
				printf("\n\t错误，已退出系统\n");
				SaveUserData();
				exit(0);
			}
		}
	}
}

void Menu()//主菜单
{
	int a, b = 1;
	while (b)
	{
		b = 0;
		printf("\n1.存款");
		printf("\t2.取款\n");
		printf("\n3.转帐");
		printf("\t4.查询\n");
		printf("\n5.修改资料");
		printf("\t0.退出系统\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			SaveMoney();
			break;
		case 2:
			system("cls");
			WithdrawMoney();
			break;
		case 3:
			system("cls");
			TransferMoney();
			break;
		case 4:
			system("cls");
			Inquire();
			break;
		case 5:
			system("cls");
			ChangeInformation();
			break;
		case 0:
			system("cls");
			SaveUserData();
			exit(0);
			break;
		default:
			system("cls");
			printf("\n输入错误！\n");
			b = 1;
			break;
		}
	}
}

void SaveTransaction()//存款记录
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "存款");
		TP->Money = TA.Money;

		SaveTransactionData();
	}
}

void WithdrawTransaction()//取款记录
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "取款");
		TP->Money = TA.Money;
		SaveTransactionData();
	}
}

void TransferTransaction()//转账记录
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "转账");
		TP->Money = TA.Money;
		SaveTransactionData();
	}
	Trade* TPi = (Trade*)malloc(sizeof(Trade));
	TPi->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TPi;
		TTail = TPi;
	}
	else
	{
		TTail->Tnext = TPi;
		TTail = TPi;
		strcpy(TPi->TAccountNum, curAccountO->AccountNum);
		strcpy(TPi->Time, TA.Time);
		strcpy(TPi->Operation, "转账");
		TPi->Money = -TA.Money;
		SaveTransactionData();
	}
}

void HandTransaction()//手续费记录
{
	Trade* HP = (Trade*)malloc(sizeof(Trade));
	HP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = HP;
		TTail = HP;
	}
	else
	{
		TTail->Tnext = HP;
		TTail = HP;
		strcpy(HP->TAccountNum, curAccount->AccountNum);
		strcpy(HP->Time, TA.Time);
		strcpy(HP->Operation, "手续费");
		HP->Money = -HandMoney;
		SaveTransactionData();
	}
}

void PrintTransaction()//打印流水
{
	int a;
	Trade* HcurP = THead;
	while (HcurP != NULL)//交易记录
	{
		if (strcmp(curAccount->AccountNum, HcurP->TAccountNum) == 0)
		{
			a++;
			TCurAccount = HcurP;
			printf("\n\t时间：%s\t种类：%s\t金额：%.2f\n", TCurAccount->Time, TCurAccount->Operation, TCurAccount->Money);
		}
		HcurP = HcurP->Tnext;
	}
	if (a == 0)
	{
		printf("\n\t无交易记录\n\n");
	}
}

void SaveMoney()//存款
{
	int a;
	QK = 0;
	printf("\t温馨提示：单笔存款不得超过10000。\n");
	printf("\n\n\t请输入你要存入的金额：\n");
	scanf("%d", &a);
	if (a > 10000)
	{
		system("cls");
		printf("\n\t单笔存款不得超过10000。\n");
		SaveMoney1();
	}
	else
	{
		SysTime();
		TA.Money = a * 1.00;
		curAccount->balance = curAccount->balance + TA.Money;
		system("cls");
		SaveUserData();
		SaveTransaction();
		printf("\n\t成功存入%.2f!!!!\n", TA.Money);
		CK = 1;
		SaveMoney1();
	}
}

void SaveMoney1()//存款选项
{
	int k = 0, b;
	while (k < 3)
	{
		if (CK)
			printf("\n1.再次存款");
		else
			printf("\n1.重新输入金额");
		printf("\t2.返回主菜单\n");
		printf("\n0.退出系统\n");
		
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			SaveMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void WithdrawMoney()//取款
{
	int a;
	CK = 0;
	printf("\t温馨提示：单笔取款不得超过10000。\n");
	printf("\n\n请输入你要取出的金额：");
	scanf("%d", &a);
	if (a > 10000)
	{
		system("cls");
		printf("\n\t单笔取款不得超过10000。\n");
		WithdrawMoney1();
	}
	else
	{
		SysTime();
		TA.Money = a * -1.00;
		if (curAccount->balance + TA.Money < 0)
		{
			system("cls");
			printf("\n\t余额不足!!!!\n");
		}
		else
		{
			curAccount->balance = curAccount->balance + TA.Money;
			system("cls");
			SaveUserData();
			WithdrawTransaction();
			printf("\n\t取款成功!!!!\n");
			QK = 1;
		}
		WithdrawMoney1();
	}
}

void WithdrawMoney1()//取款选项
{
	int k = 0, b;
	while (k < 3)
	{
		if (QK)
			printf("\n\n1.再次取款");
		else
			printf("\n\n1.重新输入金额");
		printf("\t2.返回主菜单");
		printf("\n\n0.退出系统");
		
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			WithdrawMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void TransferMoney()//转账
{
	int a;
	ZZ = 0;
	printf("\t温馨提示：1.单笔取款不得超过10000。\n");
	printf("\t        2.转账将收取2%%的手续费。\n\t\n");
	printf("\n\n请输入你要转出到的账户：");
	Account TT;
	scanf("%s", &TT.AccountNum);
	if (FindACC3(TT))
	{
		system("cls");
		printf("\n请输入你要转出的金额：");
		scanf("%d", &a);
		if (a > 10000)
		{
			printf("\n\t单笔转账不得超过10000。\n");
			TransferMoney1();
		}
		else
		{
			SysTime();
			TA.Money = a * -1.00;
			HandMoney = 0.02 * a;
			if (curAccount->balance + TA.Money - HandMoney < 0)
			{
				system("cls");
				printf("\n\t余额不足!!!!\n");
			}
			else
			{
				system("cls");
				curAccount->balance = curAccount->balance + TA.Money - HandMoney;
				curAccountO->balance = curAccountO->balance - TA.Money;
				TransferTransaction();
				HandTransaction();
				SaveUserData();
				printf("\n\t转账成功!!!!\n");
				ZZ = 1;
			}
			TransferMoney1();
		}
	}
	else
	{
		system("cls");
		printf("\n\t对方账户不存在！！！！");
		TransferMoney1();
	}

}

void TransferMoney1()//转账选项
{
	int k = 0, b;
	while (k < 3)
	{
		if (ZZ)
			printf("\n\n1.再次转账");
		else
			printf("\n\n1.重新转账");
		printf("\t2.返回主菜单");
		printf("\n\n0.退出系统\n");
		
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			TransferMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void Inquire()//查询页
{

	int a, b = 0;
	while (b < 3)
	{
		printf("\n1.查询余额");
		printf("\t2.查询交易记录\n");
		printf("\n3.查询个人信息");
		printf("\t4.返回主菜单\n");
		printf("\n0.退出系统\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			InquireBalance();
			b = 3;
			break;
		case 2:
			system("cls");
			InqInformation();
			b = 3;
			break;
		case 3:
			system("cls");
			InqRecord();
			b = 3;
			break;
		case 4:
			system("cls");
			Menu();
			b = 3;
			break;
		case 0:
			system("cls");
			b = 3;
			SaveUserData();
			exit(0);
		default:
			b++;
			break;
		}
	}
}

void InquireBalance()//查询账户
{
	SysTime();
	printf("\n\t您的余额为\n%.2f\n", curAccount->balance);
	int a, b = 0;
	while (b < 3)
	{
		printf("\n1.返回上一页");
		printf("\t2.返回主菜单\n");
		printf("\n0.退出系统\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();
			b = 3;
			break;
		case 2:
			system("cls");
			Menu();
			b = 3;
			break;
		case 0:
			b = 3;
			SaveUserData();
			exit(0);
		default:
			b++;
			break;
		}
	}
}

void InqInformation()//查询个人信息
{
	printf("\n\t姓名：\n%s\n", curAccount->name);
	printf("\n\t账号：\n%s\n", curAccount->AccountNum);
	printf("\n\t预留手机号：\n%s\n", curAccount->PhoneNum);
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\t1.返回上一页");
		printf("\t2.返回主菜单\n");
		printf("\n\t0.退出系统\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void InqRecord()//查询交易记录
{
	PrintTransaction();
	int a, k = 0;
	while (k < 3)
	{
		printf("\n1.返回上一页");
		printf("\t2.返回主菜单\n");
		printf("\n0.退出系统\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void ChangeInformation()//修改信息菜单
{
	system("cls");
	int a, b = 1;
	while (b)
	{
		printf("\n1.修改用户");
		printf("\t2.修改电话\n");
		printf("\n3.修改密码");
		printf("\t4.返回上一页\n");
		printf("\n0.退出系统\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			ChangeUserName();
			b = 0;
			break;
		case 2:
			ChangePhone();
			b = 0;
			break;
		case 3:
			ChangePassword();
			b = 0;
			break;
		case 4:
			Menu();
			b = 0;
			break;
		case 0:
			SaveUserData();
			exit(0);
		default:
			system("cls");
			printf("输入错误！\t请按照提示重新输入\n");
			break;
		}
	}
}

void ChangeUserName()//修改用户
{
	int a, b = 0, c = 0;
	while (b < 3)
	{
		system("cls");
		printf("\n\t请输入新用户名称:");
		scanf("%s", curAccount->name);
		system("cls");
		printf("\n\t用户名称修改成功！\n");
		SaveUserData();
		b = 3;
		while (c < 3)
		{
			printf("\n1.返回上一页");
			printf("\t2.返回主菜单\n");
			printf("\n0.退出系统\n");
			
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				ChangeInformation();
				b = 3;
				break;
			case 2:
				system("cls");
				Menu();
				b = 3;
				break;
			case 0:
				b = 3;
				SaveUserData();
				exit(0);
			default:
				b++;
				break;
			}
		}
	}
}

void ChangePhone()//修改电话
{
	system("cls");
	int a, b = 0, c = 0;
	while (b < 3)
	{
		printf("\n\t请输入新联系电话号码");
		scanf("%s", curAccount->PhoneNum);
		system("cls");
		printf("\n\t联系电话修改成功！\n");
		SaveUserData();
		b = 3;
		while (c < 3)
		{
			printf("\n1.返回上一页");
			printf("\t2.返回主菜单\n");
			printf("\n0.退出系统\n");
			
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				ChangeInformation();
				c = 3;
				break;
			case 2:
				system("cls");
				Menu();
				c = 3;
				break;
			case 0:
				c = 3;
				SaveUserData();
				exit(0);
			default:
				c++;
				break;
			}
		}
	}
}

void ChangePassword()//修改密码
{
	system("cls");
	int a, b = 0, c = 0;
	char Password[100];
	while (b < 3)
	{
		printf("\n\n\t请输入原始密码：");
		char storePassword[10] = { '\0' };
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n请输入新密码:");
			getPassword(storePassword, 10);
			strcpy(curAccount->password, storePassword);
			system("cls");
			printf("\n修改成功！\n");
			SaveUserData();
			b = 3;
			while (c < 3)
			{
				printf("\n1.返回上一页");
				printf("\t2.返回主菜单\n");
				printf("\n0.退出系统\n");		
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					ChangeInformation();
					c = 3;
					break;
				case 2:
					system("cls");
					Menu();
					c = 3;
					break;
				case 0:
					c = 3;
					SaveUserData();
					exit(0);
				default:
					c++;
					break;
				}
			}
		}
		else
		{
			b++;
			system("cls");
			printf("\n\t密码错误!\n");
		}
	}
}

void getPassword(char* storePw, int maxPwLen)//密码输入
{
	char c = '\0';
	char* pc = storePw;
	int pwlen = 0;

	while (1)
	{
		c = getch();
		if (c == '\r')
			break;
		if (pwlen >= 0 && pwlen < maxPwLen - 1 && c)
		{
			*pc = c;
			pc++;
			pwlen++;
			putchar('*');
		}
	}
}

void SysTime()//系统时间
{
	time_t t = time(0);
	char tmp[20];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d/%X", localtime(&t));
	strcpy(TA.Time, tmp);
}

void SaveUserData()
{
	FILE* fp = fopen("D:/用户.txt", "w");//保存用户数据
	if (fp != NULL)
	{
		Account* curP = head;
		while (curP != NULL)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\t%f\n", curP->AccountNum, curP->name, curP->PhoneNum, curP->password, curP->balance);
			curP = curP->next;
		}
		fclose(fp);
	}
}

void SaveTransactionData()
{
	FILE* Tfp = fopen("D:/交易.txt", "at+");//保存交易数据
	if (Tfp != NULL)
	{
		Trade* TcurP = THead;
		while (TcurP != NULL)
		{
			if (TcurP->Tnext == NULL)
			{
				fprintf(Tfp, "%s\t%s\t%s\t%f\n", TcurP->TAccountNum, TcurP->Time, TcurP->Operation, TcurP->Money);
			}
			TcurP = TcurP->Tnext;
		}
		fclose(Tfp);
	}
}

void IniUser_Data()//初始化用户
{
	FILE* fp = fopen("D:/用户.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			Account* newNodeP = (Account*)malloc(sizeof(Account));
			fscanf(fp, "%s\t%s\t%s\t%s\t%f\n", newNodeP->AccountNum, newNodeP->name, newNodeP->PhoneNum, newNodeP->password, &newNodeP->balance);
			newNodeP->next = NULL;

			if (head == NULL)
			{
				head = newNodeP;
				tail = newNodeP;
			}
			else
			{
				tail->next = newNodeP;
				tail = newNodeP;
			}
		}
		fclose(fp);
	}
}

void InitTraData()//初始化交易信息
{
	FILE* Tfp = fopen("D:/交易.txt", "r");
	if (Tfp != NULL)
	{
		while (!feof(Tfp))
		{
			Trade* TnewNodeP = (Trade*)malloc(sizeof(Trade));
			fscanf(Tfp, "%s\t%s\t%s\t%f\n", TnewNodeP->TAccountNum, TnewNodeP->Time, TnewNodeP->Operation, &TnewNodeP->Money);
			TnewNodeP->Tnext = NULL;

			if (THead == NULL)
			{
				THead = TnewNodeP;
				TTail = TnewNodeP;
			}
			else
			{
				TTail->Tnext = TnewNodeP;
				TTail = TnewNodeP;
			}
		}
		fclose(Tfp);
	}
}

void SignUp()//注册函数
{
	int a, k = 0;
	system("cls");
	Pset->next = NULL;//Account* Pset = (Account*)malloc(sizeof(Account));//已定义
	if (head == NULL)
	{
		head = Pset;
		tail = Pset;//如果这是第一个创建的结点，则将头 尾指针指向这个结点
	}
	else
		tail->next = Pset; //如果不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
	printf("\n请输入姓名：\n");
	scanf("%s", ZX.name);
	strcpy(Pset->name, ZX.name);
	int ACCountNum = 10000;
	itoa(ACCountNum, ZX.AccountNum, 10);
	while (FindACC2(ZX))
	{
		ACCountNum++;
		itoa(ACCountNum, ZX.AccountNum, 10);
		break;
	}
	strcpy(Pset->AccountNum, ZX.AccountNum);
	SetPhoneNum();
	SetPassword();
	Pset->balance = 0;
	SaveUserData();
	while (k < 3)
	{
		system("cls");
		printf("\n注册成功!\n");
		printf("\n你的账号为%s\n", Pset->AccountNum);
		printf("\t0.退出系统\n");
		scanf("%d", &a);
		exit(0);
	}
}

void SetPassword()//设置密码
{
	int a = 0;
	while (a < 3)
	{
		a++;
		printf("\n请设置账户密码\n");
		char storePassword[10] = { '\0' };
		getPassword(storePassword, 10);
		strcpy(ZX.password, storePassword);
		if (strlen(ZX.password) == 6)
		{
			strcpy(Pset->password, ZX.password);
			break;
		}
		else
		{
			printf("\n密码为六位，密码设置有误！\n请重新设置\n");
		}
	}
}

void SetPhoneNum()//设置手机号
{
	int a = 0;
	while (a < 3)
	{
		a++;
		printf("请输入电话号码\n");
		scanf("%s", ZX.PhoneNum);
		if (strlen(ZX.PhoneNum) == 11)
		{
			strcpy(Pset->PhoneNum, ZX.PhoneNum);
			break;
		}
		else
		{
			system("cls");
			printf("\n号码有误！\n请重新输入\n");
		}
	}
}
