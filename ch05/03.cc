
typedef unsigned char         uchar;
typedef const unsigned char   const_uchar;
typedef int                   *pint;
typedef char                  **ppchar;

// pointer to array of char
typedef char                 (*pchar)[];

// array of 7 pointers to int
typedef int                  *spint[7];

// pointer to an array of 7 pointers to int
typedef int                  *(*pspint)[7];

// array of 8 arrays of 7 pointers to int
typedef int                  *a8a7pint[8][7];
