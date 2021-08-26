/*
# Copyright 2021, qnx-audi - https://github.com/h4570/qnx-audi
# Licenced under Apache License 2.0
# Sandro Sobczyński <sandro.sobczynski@gmail.com>
*/

#include "utils/debug.hh"

#ifdef NDEBUG
#ifdef ARCH_X86

// ----
// Release mode, x86
// ----

void Debug::_assert(const bool &t_condition, const char *t_message, const char *t_file, const int &t_line)((void)0);
void Debug::_log(const char *t_message, const char *t_file, const int &t_line)((void)0);

#else // ARCH_X86

// ----
// Release mode, SHLE
// ----

void Debug::_assert(const bool &t_condition, const char *t_message, const char *t_file, const int &t_line)((void)0);
void Debug::_log(const char *t_message, const char *t_file, const int &t_line)((void)0);

#endif // ARCH_X86
#else  // NDEBUG
#include <stdlib.h>
#ifdef ARCH_X86

// ----
// Debug mode, x86
// ----

#include <stdio.h>

void Debug::_assert(const bool &t_condition, const char *t_message, const char *t_file, const int &t_line)
{
    if (!t_condition)
    {
        fprintf(stderr, "Assertion failed: %s | %s:%d\n", t_message, t_file, t_line);
        exit(1);
    }
}

void Debug::_log(const char *t_message, const char *t_file, const int &t_line)
{
    fprintf(stdout, "Log: %s | %s:%d\n", t_message, t_file, t_line);
}

#else // ARCH_X86

// ----
// Debug mode, SHLE
// ----

#include <fstream>
#include "config.hh"

void Debug::_assert(const bool &t_condition, const char *t_message, const char *t_file, const int &t_line)
{
    if (!t_condition)
    {
        std::ofstream myfile;
        myfile.open(AUDI_LOGS_FILE, std::ios_base::app);
        myfile << "Assertion failed: " << t_message << " | " << t_file << ":" << t_line << "\n";
        myfile.close();
        exit(1);
    }
}

void Debug::_log(const char *t_message, const char *t_file, const int &t_line)
{
    std::ofstream myfile;
    myfile.open(AUDI_LOGS_FILE, std::ios_base::app);
    myfile << "Log: " << t_message << " | " << t_file << ":" << t_line << "\n";
    myfile.close();
}

#endif // ARCH_X86
#endif // NDEBUG