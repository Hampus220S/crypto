/*
 * keygen -b 4096 -d ~/Desktop/keys/
 *
 * -b, --bytes | The amount of bytes
 * -d, --dir   | Where to create the key files
 */

#include "file.h"
#include "rsa.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char SKEY_FILE[] = "key.private";
const char PKEY_FILE[] = "key.public";

char dir[128] = ".";
int bytes = 4096;

void args_parse(int argc, char* argv[])
{
  for(int index = 0; index < (argc - 1); index++)
  {
    char* arg = argv[index];
    char* next = argv[index + 1];

    if(!strcmp(arg, "-b") || !strcmp(arg, "--bytes"))
    {
      bytes = atoi(next);
    }
    else if(!strcmp(arg, "-d") || !strcmp(arg, "--dir"))
    {
      strcpy(dir, next);
    }
  }
}

int main(int argc, char* argv[])
{
  args_parse(argc, argv);

  char skey[4096];
  memset(skey, '\0', sizeof(skey));

  char pkey[4096];
  memset(pkey, '\0', sizeof(pkey));

  rsa_base64_create(skey, pkey);

  printf("Private key:\n%s\n", skey);
  printf("Public key:\n%s\n", pkey);

  return 0;
}