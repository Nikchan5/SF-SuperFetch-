#include <windows.h>
#include <stdio.h>

void getWindowsVersion() {
    OSVERSIONINFOA osvi;
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);
    if (GetVersionExA(&osvi)) {
        printf("Windows Version: %ld.%ld (Build %ld)\n", 
               osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber);
    } else {
        printf("Failed to get Windows version\n");
    }
}

void getComputerInfo() {
    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName);
    if (GetComputerNameA(computerName, &size)) {
        printf("Computer Name: %s\n", computerName);
    } else {
        printf("Failed to get computer name\n");
    }

    char userName[256];
    size = sizeof(userName);
    if (GetUserNameA(userName, &size)) {
        printf("User Name: %s\n", userName);
    } else {
        printf("Failed to get user name\n");
    }
}

void getCPUInfo() {
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    printf("CPU Architecture: %d\n", si.wProcessorArchitecture);
    printf("Number of Cores: %lu\n", si.dwNumberOfProcessors); // Используем %lu для DWORD
}

void getMemoryInfo() {
    MEMORYSTATUSEX mem;
    mem.dwLength = sizeof(mem);
    if (GlobalMemoryStatusEx(&mem)) {
        printf("Total RAM: %llu MB\n", mem.ullTotalPhys / (1024 * 1024));
        printf("Available RAM: %llu MB\n", mem.ullAvailPhys / (1024 * 1024));
    } else {
        printf("Failed to get memory info\n");
    }
}

void getGPUInfo() {
    DISPLAY_DEVICEA dd;
    dd.cb = sizeof(dd);
    if (EnumDisplayDevicesA(NULL, 0, &dd, 0)) {
        printf("GPU: %s\n", dd.DeviceString);
    } else {
        printf("Failed to get GPU info\n");
    }
}

void printLogo() {
     printf("\033[1;36m"); 
     printf(" ███████ ███████\n");
     printf(" ██      ██     \n");
     printf(" ███████ █████  \n");
     printf("      ██ ██     \n");
     printf(" ███████ ██     \n");
     printf("\033[0m");
 }
 

 #include <stdio.h>

 int main() {
     system("chcp 65001 > nul");
     getWindowsVersion();
     getComputerInfo();
     getCPUInfo();
     getMemoryInfo();
     getGPUInfo();
     printLogo();
 
     printf("\nPress Enter to exit...");
     getchar();
 
     return 0;
 }
