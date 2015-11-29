#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getNextCipherChar(char c)
{
        if(c == 'z')
                return 'a';
        return c+1;
}

int inRange(char c)
{
        if(c == 0) return 1;

        return c > 31 && c < 127;
}

long long passageSum(const char *passage)
{
        return passage[0] == 0 ? 0 : passage[0] + passageSum(passage+1);
}

int isPrintable(const char *text,size_t len)
{
        int foundSpace = 0;

        for(size_t i = 0; i < len; i++)
        {
                if(!inRange(text[i]))
                        return 0;

                switch(text[i])
                {
                        case ' ':
                                foundSpace = 1;
                                break;
                        case '#':
                        case '$':
                                return 0;
                        default:
                                break;
                }
        }
        return 1;
}

void getNextCipher(char cipher[static 3])
{
        if((cipher[2] = getNextCipherChar(cipher[2])) == 'a')
                if((cipher[1] = getNextCipherChar(cipher[1])) == 'a')
                        cipher[0]++;
}

int main()
{
        const char *fname = "cipher.txt";
        FILE *infile = NULL;
        char text[1500];
        char result[1202];

        result[1201] = '\0';

        const char endCipher[3] = {'z','z','z'};
        char cipher[3] = {'a','a','a'};

        infile = fopen(fname, "r");

        int numLetters = 0;
        char letter;
        while(fscanf(infile, "%hhu,",&letter) != EOF)
        {
                text[numLetters] = letter;
        }

        while( memcmp(endCipher,cipher,sizeof(char) * 3))
        {
                for(int i = 0; i < numLetters; i++)
                {
                        const char key = cipher[i%3];

                        result[i] = key ^ text[i];
                }

                if(isPrintable(result,sizeof(result)))
                {
                        printf("%s\n",result);

                        printf("%lld\n",passageSum(result));
                }

                getNextCipher(cipher);
        }

        return 0;
}
