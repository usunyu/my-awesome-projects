#include <vector>
#include <stdio.h>

using namespace std;

typedef unsigned char sal_uInt8;
typedef unsigned short sal_uInt16;

/* 
Reference: Office Open XML Part4 - Markup Language Reference, Section 
3.3.1.81 sheetProtection (Sheet Protection Options) 
 
Specifies the hash of the password required for editing this worksheet. This 
protection is optional and may be ignored by applications that choose not to 
support this functionality. The hash is generated from an 8-bit wide 
character. 16-bit Unicode characters must be converted down to 8 bits before 
the hash is computed, using the logic defined in the revisionsPassword 
attribute of §3.2.29. The resulting value is hashed using the algorithm 
defined below. 
 
[Note: An example algorithm to hash the user input into the value stored is 
as follows:
 
// Function Input:
//       szPassword: NULL terminated C-Style string
//       cchPassword: The number of characters in szPassword (not
including the NULL terminator)
WORD GetPasswordHash(const CHAR *szPassword, int cchPassword) {
        WORD wPasswordHash;
        const CHAR *pch;
        wPasswordHash = 0;
        if (cchPassword > 0)
                {
                pch = &szPassword[cchPassword];
                while (pch-- != szPassword)
                         {
                         wPasswordHash = ((wPasswordHash >> 14) &
0x01) | ((wPasswordHash << 1) & 0x7fff);
                         wPasswordHash ^= *pch;
                         }
                wPasswordHash ^= (0x8000 | ('N' << 8) | 'K');
                }
        return(wPasswordHash);
}
 
end note] 
 
*/

sal_uInt16 getPasswordHash(const char* szPassword)
{
    sal_uInt16 cchPassword = strlen(szPassword);
    sal_uInt16 wPasswordHash = 0;
    if (!cchPassword)
        return wPasswordHash;

    const char* pch = &szPassword[cchPassword];
    while (pch-- != szPassword)
    {
        wPasswordHash = ((wPasswordHash >> 14) & 0x01) | 
                        ((wPasswordHash << 1) & 0x7fff);
        wPasswordHash ^= *pch;
    }

    wPasswordHash = ((wPasswordHash >> 14) & 0x01) | 
                    ((wPasswordHash << 1) & 0x7fff);

    wPasswordHash ^= (0x8000 | ('N' << 8) | 'K');
    wPasswordHash ^= cchPassword;

    return wPasswordHash;
}

int main (int argc, char** argv)
{
    if (argc < 2)
        exit(1);

    printf("input password = %s\n", argv[1]);
    sal_uInt16 hash = getPasswordHash(argv[1]);
    printf("hash = %4.4X\n", hash);

    return 0;
}

