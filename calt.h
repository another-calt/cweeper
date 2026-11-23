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
/* SELECTOR */
//

#define KEYWORDS
   #define ASSIGNMENTS
   #define TYPES
#define FUNCTIONS
#define CLASSES
   #define VECTORS

//
/* IMPORTS */
//

#include <stdio.h>
#include <stdlib.h>

#pragma once

//
/* KEYWORDS */
//

#ifdef KEYWORDS

   #define app int main(void)
   #define application() int main(int argc, char **argv)

   #define elif else if

   #ifdef ASSIGNMENTS
      #define var __auto_type
      #define lock const __auto_type
   #endif

   #ifdef TYPES
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

      typedef char *str; // this has flipped between *str and str[] so many times
   #endif
#endif
//
/* FUNCTIONS */
//
#ifdef FUNCTIONS

   #define println(out)                                                           \
      _Generic(((out)),                                                            \
         int: printf("%d\n", (out)),                                              \
         int *: printf("%x\n", (out)),                                            \
         unsigned int: printf("%d\n", (out)),                                     \
         unsigned int *: printf("%x\n", (out)),                                   \
         float: printf("%f\n", (out)),                                            \
         double: printf("%f\n", (out)),                                           \
         size_t: printf("%d\n", (out)),                                           \
         char: printf("%c\n", (out)),                                             \
         char *: printf("%s\n", (out)),                                           \
         const char *: printf("%s\n", (out)),                                     \
         FILE *: printf("%x\n", (out)),                                           \
         default: printf("[unknown print type]\n"))
#endif

//
/* CLASSES */
//
#ifdef CLASSES
   // ok they arent classes, but... you get what i mean.
   #ifdef VECTORS
      #define $Vector(T)                                                                                                   \
         typedef struct {                                                                                                         \
            size_t size;                                                                                                         \
            size_t max;                                                                                                          \
            T *list;                                                                                                                      \
         } vector_##T;                                                          \
         static inline void vappend_##T(vector_##T *vec, T value) {                              \
            if (vec->size >= vec->max) {                                                                \
               if (vec->max == 0) vec->max = 4;                                                                                             \
               else vec->max *= 2;                                                                                  \
               vec->list = realloc(vec->list, vec->max * sizeof(T));                                      \
            }                                                                                                                                 \
            vec->list[vec->size] = value;                                                                               \
            vec->size++;                                                                                                   \
         }            
   #endif
#endif