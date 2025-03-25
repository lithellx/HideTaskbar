#include <windows.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

//void PrintHexData(const BYTE* data, size_t size)
//{
//    for (size_t i = 0; i < size; i += 8)
//    {
//        cout << setw(8) << setfill('0') << hex << i << "  ";
//        for (size_t j = 0; j < 8 && (i + j) < size; ++j)
//        {
//            cout << setw(2) << setfill('0') << hex << (int)data[i + j] << " ";
//        }
//        cout << endl;
//    }
//}

void restartExplorer()
{
    system("taskkill /f /im explorer.exe");
    system("start explorer.exe");
}

void setTaskbarAutoHide(bool enable)
{
    HKEY hKey;
    const char* regPath = "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StuckRects3";

    if (RegOpenKeyExA(HKEY_CURRENT_USER, regPath, 0, KEY_QUERY_VALUE | KEY_SET_VALUE, &hKey) == ERROR_SUCCESS)
    {
        DWORD dataSize = 0;
        if (RegQueryValueExA(hKey, "Settings", NULL, NULL, NULL, &dataSize) == ERROR_SUCCESS)
        {
            BYTE* data = new BYTE[dataSize];
            if (RegQueryValueExA(hKey, "Settings", NULL, NULL, data, &dataSize) == ERROR_SUCCESS)
            {
                data[8] = enable ? 0x03 : 0x02;

                RegSetValueExA(hKey, "Settings", 0, REG_BINARY, data, dataSize);

                //PrintHexData(data, dataSize);
            }
            delete[] data;
        }
        RegCloseKey(hKey);

        restartExplorer();
    }
    else
    {
        cerr << "Failed to open registry key." << endl;
    }
}

int main()
{
    string userInput;
    bool enableAutoHide = false;

    cout << "Manage Taskbar Auto-Hide (true/false or 1/0): ";
    getline(cin, userInput);

    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

    if (userInput == "true" || userInput == "1")
        enableAutoHide = true;
    else if (userInput == "false" || userInput == "0")
        enableAutoHide = false;
    else
    {
        cerr << "Invalid input." << endl;
        return 1;
    }

    setTaskbarAutoHide(enableAutoHide);

    cout << "Changes applied successfully." << endl;

    return 0;
}
