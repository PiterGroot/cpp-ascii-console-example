#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

#define FULL_BLOCK static_cast<char>(219) << static_cast<char>(219)

static void SetupConsole()
{
#ifdef _WIN32 // Enable ANSI escape sequences on windows.
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
}

// RGB color functions.
static std::string rgb(int r, int g, int b)
{
    return "\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
}

static std::string bgRgb(int r, int g, int b)
{
    return "\033[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
}

// ANSI color codes.
const char* RESET = "\033[0m";
const char* RED = "\033[31m";
const char* GREEN = "\033[32m";
const char* YELLOW = "\033[33m";
const char* BLUE = "\033[34m";
const char* MAGENTA = "\033[35m";
const char* CYAN = "\033[36m";
const char* WHITE = "\033[37m";

// Background colors.
const char* BG_RED = "\033[41m";
const char* BG_GREEN = "\033[42m";
const char* BG_BLUE = "\033[44m";

// Bright/bold colors.
const char* BRIGHT_RED = "\033[91m";
const char* BRIGHT_GREEN = "\033[92m";
const char* BRIGHT_YELLOW = "\033[93m";

int main()
{
    SetupConsole();

    // Colored blocks.
    std::cout << RED << FULL_BLOCK << RESET << std::endl;
    std::cout << GREEN << FULL_BLOCK << RESET << std::endl;
    std::cout << BLUE << FULL_BLOCK << RESET << std::endl;

    // Rainbow.
    std::cout << RED << FULL_BLOCK
        << YELLOW << FULL_BLOCK
        << GREEN << FULL_BLOCK
        << CYAN << FULL_BLOCK
        << BLUE << FULL_BLOCK
        << MAGENTA << FULL_BLOCK
        << RESET << std::endl;

    // Custom RGB colors.
    std::cout << std::endl << rgb(255, 0, 0) << FULL_BLOCK << RESET << " Red\n";
    std::cout << rgb(255, 165, 0) << FULL_BLOCK << RESET << " Orange\n";
    std::cout << rgb(128, 0, 128) << FULL_BLOCK << RESET << " Purple\n";
    std::cout << rgb(0, 255, 127) << FULL_BLOCK << RESET << " Spring Green\n";

    // Gradient example.
    std::cout << "\nGradient: ";
    for (int i = 0; i <= 255; i += 15) 
    {
        std::cout << rgb(255, i, 0) << FULL_BLOCK;
    }
    std::cout << RESET << std::endl;

    // Background color with RGB.
    std::cout << std::endl << bgRgb(50, 50, 200) << "  Blue background  " << RESET << std::endl;

    // Combine foreground and background.
    std::cout << rgb(255, 255, 0) << bgRgb(128, 0, 128)
        << FULL_BLOCK << " Yellow on Purple"
        << RESET << std::endl;

    return 0;
}
