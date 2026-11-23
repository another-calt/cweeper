#include "calt.h"
#import <string.h>

typedef struct {                                                                                                         
   size_t size;                                                                                                         
   size_t max;                                                                                                          
   str *list;                                                                                                                      
} vector_str; 

/// ill test this later
static inline void vappend_str
      (vector_str *vec, str value) {                        
   if (vec->size >= vec->max) {                                                                
      if (vec->max == 0) vec->max = 4;                                                                                             
      else vec->max *= 2;                                                                                  
      vec->list = realloc(vec->list, vec->max * sizeof(str));                                      
   }                                                                                                                                 
   strcpy(vec->list[vec->size], value);
   vec->size++;
}

typedef struct {
    char* scope;
    vector_str hitlist;
    vector_str allowlist;
} RuleSet;

typedef struct {
  size_t size;
  size_t max;
  RuleSet *list;
} vector_RuleSet;

static inline void vappend_RuleSet(vector_RuleSet *vec, RuleSet value) {
  if (vec->size >= vec->max) {
    if (vec->max == 0)
      vec->max = 4;
    else
      vec->max *= 2;
    vec->list = realloc(vec->list, vec->max * sizeof(RuleSet));
  }
  vec->list[vec->size] = value;
  vec->size++;
}

static RuleSet rules_list = {0};