/*
   Copyright 2026 github.com/another-calt

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

//
// CHECKS
//
#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 201112L ||                \
    !defined(__GNUC__) || defined(__STRICT_ANSI__)
#error "GNU C11 or later is required, compile with '-std=gnu11'"
#endif

#pragma once

//
// IMPORTS
//

#include <stdint.h>
#include <stdio.h>

//
// KEYWORDS
//

#define program int main()

// assignment
#define var __auto_type
#define lock const __auto_type

// types

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef char str[];

//
// FUNCTIONS
//

#define println(out)                                                           \
    _Generic(((out)),                                                            \
        int: printf("%d\n", (out)),                                              \
        int *: printf("%x\n", (out)),                                            \
        unsigned int: printf("%d\n", (out)),                                     \
        unsigned int *: printf("%x\n", (out)),                                   \
        float: printf("%f\n", (out)),                                            \
        double: printf("%f\n", (out)),                                           \
        char: printf("%c\n", (out)),                                             \
        char *: printf("%s\n", (out)),                                           \
        const char *: printf("%s\n", (out)),                                     \
        FILE *: printf("%x\n", (out)),                                           \
        default: printf("[unknown print type]\n"))
