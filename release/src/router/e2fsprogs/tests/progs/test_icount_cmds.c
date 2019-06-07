/* ./test_icount_cmds.c - automatically generated from ./test_icount_cmds.ct */
#include <ss/ss.h>

static char const * const ssu00001[] = {
"create_icount",
    "create",
    (char const *)0
};
extern void do_create_icount __SS_PROTO;
static char const * const ssu00002[] = {
"free_icount",
    "free",
    (char const *)0
};
extern void do_free_icount __SS_PROTO;
static char const * const ssu00003[] = {
"fetch",
    (char const *)0
};
extern void do_fetch __SS_PROTO;
static char const * const ssu00004[] = {
"increment",
    "inc",
    (char const *)0
};
extern void do_increment __SS_PROTO;
static char const * const ssu00005[] = {
"decrement",
    "dec",
    (char const *)0
};
extern void do_decrement __SS_PROTO;
static char const * const ssu00006[] = {
"store",
    (char const *)0
};
extern void do_store __SS_PROTO;
static char const * const ssu00007[] = {
"get_size",
    (char const *)0
};
extern void do_get_size __SS_PROTO;
static char const * const ssu00008[] = {
"dump",
    (char const *)0
};
extern void do_dump __SS_PROTO;
static char const * const ssu00009[] = {
"validate",
    "check",
    (char const *)0
};
extern void do_validate __SS_PROTO;
static ss_request_entry ssu00010[] = {
    { ssu00001,
      do_create_icount,
      "Create an icount structure",
      0 },
    { ssu00002,
      do_free_icount,
      "Free an icount structure",
      0 },
    { ssu00003,
      do_fetch,
      "Fetch an icount entry",
      0 },
    { ssu00004,
      do_increment,
      "Increment an icount entry",
      0 },
    { ssu00005,
      do_decrement,
      "Decrement an icount entry",
      0 },
    { ssu00006,
      do_store,
      "Store an icount entry",
      0 },
    { ssu00007,
      do_get_size,
      "Get the size of the icount structure",
      0 },
    { ssu00008,
      do_dump,
      "Dump the icount structure",
      0 },
    { ssu00009,
      do_validate,
      "Validate the icount structure",
      0 },
    { 0, 0, 0, 0 }
};

ss_request_table test_cmds = { 2, ssu00010 };
