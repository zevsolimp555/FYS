#pragma once

#ifdef _WIN32
    
    #include <WinSock2.h>
    #include <Windows.h>

    #pragma comment(lib, "Ws2_32.lib")

#elif __linux__

    // TODO(zhord): linux includes

#endif

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "common_types.h"