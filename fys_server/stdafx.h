#pragma once

#ifdef _WIN32

    // use std::min and std::max
    #define NOMINMAX

    #include <WinSock2.h>
    #include <Windows.h>

    #pragma comment(lib, "Ws2_32.lib")

#elif __linux__

    // TODO(zhord): linux includes

#endif

#include <string>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cassert>

#include "common_types.h"
