/* libstemmer/modules_utf8.h: List of stemming modules.
 *
 * This file is generated by mkmodules.pl from a list of module names.
 * Do not edit manually.
 *
 * Modules included by this file are: danish, dutch, english, finnish, french,
 * german, hungarian, italian, norwegian, porter, portuguese, romanian,
 * russian, spanish, swedish, turkish
 */


#include "../src_c/stem_UTF_8_english.h"
#include "../src_c/stem_UTF_8_russian.h"


typedef enum {
  ENC_UNKNOWN=0,
  ENC_UTF_8
} stemmer_encoding_t;

struct stemmer_encoding {
  const char * name;
  stemmer_encoding_t enc;
};
static struct stemmer_encoding encodings[] = {
  {"UTF_8", ENC_UTF_8},
  {0,ENC_UNKNOWN}
};

struct stemmer_modules {
  const char * name;
  stemmer_encoding_t enc; 
  struct SN_env * (*create)(void);
  void (*close)(struct SN_env *);
  int (*stem)(struct SN_env *);
};
static struct stemmer_modules modules[] = {
  {"en", ENC_UTF_8, english_UTF_8_create_env, english_UTF_8_close_env, english_UTF_8_stem},
  {"eng", ENC_UTF_8, english_UTF_8_create_env, english_UTF_8_close_env, english_UTF_8_stem},
  {"english", ENC_UTF_8, english_UTF_8_create_env, english_UTF_8_close_env, english_UTF_8_stem},
  {"ru", ENC_UTF_8, russian_UTF_8_create_env, russian_UTF_8_close_env, russian_UTF_8_stem},
  {"rus", ENC_UTF_8, russian_UTF_8_create_env, russian_UTF_8_close_env, russian_UTF_8_stem},
  {"russian", ENC_UTF_8, russian_UTF_8_create_env, russian_UTF_8_close_env, russian_UTF_8_stem},
  {0,ENC_UNKNOWN,0,0,0}
};
static const char * algorithm_names[] = {
  "danish", 
  "dutch", 
  "english", 
  "finnish", 
  "french", 
  "german", 
  "hungarian", 
  "italian", 
  "norwegian", 
  "porter", 
  "portuguese", 
  "romanian", 
  "russian", 
  "spanish", 
  "swedish", 
  "turkish", 
  0
};
