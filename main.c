
//#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <stdio.h>
#include <windows.h>
#include "itmojun.h"//����ͷ�ļ������ͷ�ļ��ڵ�ǰ����Ŀ¼�£�������˫���Ű���

#pragma comment(lib,"itmojun.lib")//���Ӿ�̬��
#pragma comment(lib,"winmm.lib")

int iShowText=0;//����������ʾ��ĻΪ���Ӯ����Ļ���������ʾ��Ļ��
int iMessageBox=0;//����������Ϣ��0Ϊ����ʾ��0Ϊ��ʾ

DWORD WINAPI ShowTextThr(LPVOID IpPara);  //��Ļ����
DWORD WINAPI MessageBoxThr(LPVOID IpPara);//��Ϣ�򷽷�

int main()
{
	HANDLE hTextThr=NULL;
	HANDLE hMessageThr = NULL;

	char msg[301];//���ڴ��΢�Ŷ˷��͵�����
	system("color f4");
//	AutoRun();//�Զ�����

	//�����߳� ������ʾ��Ļ
	hTextThr=CreateThread(NULL,0,ShowTextThr,NULL,0,NULL);
	//�رվ��
	CloseHandle(hTextThr);

	//�����߳� ���ڿ�����Ϣ��
	hMessageThr=CreateThread(NULL,0,MessageBoxThr,NULL,0,NULL);
	//�رվ��
	CloseHandle(hMessageThr);


	while(1)
	{
		 
		GetPCCmd("cui",msg);//����΢�Ŷ˷��͸�IDΪxxy�����ݣ��������msg��  ��ͨ��΢�Ź����ţ�ITħ��  ���룺���������� �����ӣ�֥����� �Ͽ����ӡ���
		printf("%s\n",msg);
		if(strstr(msg,"����"))
		{
			mciSendString("play bg.mp3",NULL,0,NULL);
		}
		else if(strstr(msg,"ֹͣ"))
		{
			mciSendString("stop bg.mp3",NULL,0,NULL);
		}
		else if(strstr(msg,"��ͣ"))
		{
			mciSendString("pause bg.mp3",NULL,0,NULL);
		}

		else if(strstr(msg,"�ػ�"))
		{
			//WinExec("shutdown -s -t 0",0);//�õ��Թػ�
		}
		else if(strstr(msg,"����"))
		{
			//WinExec("shutdown -r -t 0",0);//�õ�������
		}

		else if(strstr(msg,"ɱQQ"))
		{
			WinExec("cmd /C taskkill /f /im qq.exe",0);//�ر�QQ
		}
		else if(strstr(msg,"Ӣ������"))
		{
			WinExec("cmd /C taskkill /f /im client.exe",0);//�ر�Ӣ������
		}

		else if(strstr(msg,"��������"))
		{
			//WinExec("cmd /C taskkill /f /im explorer.exe",0);
			//1.�ҵ�����
			//2.��������

			HWND desktop,taskker;
			desktop = FindWindow("ProgMan",NULL);//�ҵ�������
			taskker = FindWindow("Shell_TrayWnd",NULL);//�ҵ����������
		
			ShowWindow(desktop,SW_HIDE);//�������洰��
			ShowWindow(desktop,SW_HIDE);//����������
		}
		else if(strstr(msg,"��ʾ����"))
		{
			//WinExec("C:\\windows\\explorer.exe",1);//��������win10ϵͳ
			HWND desktop,taskker;
			desktop = FindWindow("ProgMan",NULL);//�ҵ�������
			taskker = FindWindow("Shell_TrayWnd",NULL);//�ҵ����������
		
			ShowWindow(desktop,SW_SHOW);//��ʾ���洰��
			ShowWindow(desktop,SW_SHOW);//��ʾ������
		}

		else if(strstr(msg,"�ٶ�"))
		{
			WinExec("explorer http://www.baidu.com",1);
		}
		else if(strstr(msg,"�Ա�"))
		{
			WinExec("explorer http://www.taobao.com",1);
		}

		else if(strstr(msg,"��ʾ��Ļ"))
		{
			//����������ʾһ�仰 ͨ���߳̽��
			iShowText=1;
		}
		else if(strstr(msg,"�ر���Ļ"))
		{
			iShowText=0;
		}

		else if(strstr(msg,"������Ϣ��"))
		{
			//����������ʾһ�仰 ͨ���߳̽��
			iMessageBox=1;
		}
		else if(strstr(msg,"������Ϣ��"))
		{
			iMessageBox=0;
		}
		Sleep(3000);

	}

	return 0;
}

DWORD WINAPI ShowTextThr(LPVOID IpPara)
{
	HFONT hFont=CreateFont(100,50,0,0,FW_THIN,0,0,0,ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,"����");
	
	HFONT hOldFont;
	HDC hdc;
	
	const char*ShowText = "����һ��";

	while(1)
	{
		if(iShowText!=0)//��������ʾ��Ļ
		{
			//��ʾ��Ļ
			//printf("��ʾ��Ļdadada\n");
			hdc = GetDC(NULL);
			SetBkMode(hdc,TRANSPARENT);
			SetTextColor(hdc,RGB(0,255,0));//���ñ���ɫ
			hOldFont=(HFONT)SelectObject(hdc,hFont);//��ʾ������
			TextOut(hdc,50,50,ShowText,strlen(ShowText));//�������
			SelectObject(hdc,hOldFont);
			ReleaseDC(NULL,hdc);
		}
		Sleep(1000);
	}
}

DWORD WINAPI MessageBoxThr(LPVOID IpPara)
{
	while(1)
	{
		if(iMessageBox==1)
		{
			//��ʾ��Ϣ��
			MessageBox(NULL,"��ã����磡","��ܰ��ʾ",MB_OKCANCEL | MB_ICONWARNING);

		}else
		{
			Sleep(1000);
		}
	}
}
