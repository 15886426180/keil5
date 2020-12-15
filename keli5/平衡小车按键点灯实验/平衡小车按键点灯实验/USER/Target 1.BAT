SET PATH=D:\keil5\K5\ARM\ARMCC\Bin;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;C:\Program Files\dotnet\;C:\Program Files\Microsoft SQL Server\130\Tools\Binn\;D:\VS2017\VisualStudio2017(2)\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\Microsoft SQL Server\Client SDK\ODBC\110\Tools\Binn\;C:\Program Files (x86)\Microsoft SQL Server\120\Tools\Binn\;C:\Program Files\Microsoft SQL Server\120\Tools\Binn\;C:\Program Files\Microsoft SQL Server\120\DTS\Binn\;C:\Program Files (x86)\Windows Kits\8.1\Windows Performance Toolkit\;D:\MATLAB R2019b\runtime\win64;D:\MATLAB R2019b\bin;D:\MATLAB R2019b\polyspace\bin;D:\anaconda;D:\anaconda\Library\mingw-w64\bin;D:\anaconda\Library\usr\bin;D:\anaconda\Library\bin;D:\anaconda\Scripts;C:\Users\GJX\AppData\Local\Programs\Python\Python37\Scripts\;C:\Users\GJX\AppData\Local\Programs\Python\Python37\;C:\Users\GJX\AppData\Local\Microsoft\WindowsApps;D:\VScode\Microsoft VS Code\bin
SET CPU_TYPE=STM32F103RC
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x00B71B00
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\main.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\stm32f10x_it.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\system_stm32f10x.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\key.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\led.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\stm32f10x_gpio.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\stm32f10x_rcc.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\misc.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\stm32f10x_usart.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmAsm" --Via "..\obj\startup_stm32f10x_hd._ia"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\delay.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\sys.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\usart.__i"
"D:\keil5\K5\ARM\ARMCC\Bin\ArmLink" --Via "..\OBJ\PROJECT1.lnp"
"D:\keil5\K5\ARM\ARMCC\Bin\fromelf.exe" "..\OBJ\PROJECT1.axf" --i32combined --output "..\OBJ\PROJECT1.hex"
