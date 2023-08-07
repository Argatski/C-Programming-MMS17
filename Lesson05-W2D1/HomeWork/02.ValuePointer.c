#include <stdint.h>
#include <stdio.h>
#define  TINT 1
#define  TDOUBLE 2
#define  TCHAR 3
#define  TFLOAT 4
#define  TUINT8_T 5
#define  TUINT16_T 6
#define  TUINT32_T 7
#define  TUINT64_T 8
void printValue(const void *valuePtr,uint8_t flag)
{
    switch (flag)
    {
        case 1://TINT
            printf("%d\n",*(int*)valuePtr);
        break;
        case 2://TDOUBLE
            printf("%f\n",*(double*)valuePtr);
        break;
        case 3://TCHAR
            printf("%c\n",*(char*)valuePtr);
        break;
        case 4://TFLOAT
            printf("%f\n",*(float*)valuePtr);
        break;
        case 5://TUINT8_T
            printf("%u\n",*(uint8_t*)valuePtr);
        break;
        case 6://TUINT16_T
            printf("%u\n",*(uint16_t*)valuePtr);
        break;
        case 7://TUINT32_T
            printf("%d\n",*(uint32_t*)valuePtr);
        break;
        case 8://TUINT64_T
        printf("%lu\n",*(uint64_t*)valuePtr);
        break;

    }
}

int main(int argc, char *argv[]) 
{
    //Read "int" from console (-2,147,483,648 to 2,147,483,647)
    int intValue = 0;
    printf("Int number: ");
    scanf("%d",&intValue);    
    printValue(&intValue, 1/*TUINT*/);

    //Read double from console
    double doubleValue=0.0;
    printf("Double number: ");
    scanf("%lf",&doubleValue);
    printValue(&doubleValue, 2/*TDOUBLE*/);

    //Read char from console (a-z,A-Z)
    char ch='A';
    printValue(&ch, 3 /*TCHAR*/);


    //Read float from console
    float floatValue = 0.0f;
    printf("Float number: ");
    scanf("%f",&floatValue);
    printValue(&floatValue, 4/*TFLOAT*/);

    //Read uint8_t from console (0 to 255)
    uint8_t uint8Value = 0;
    printf("Uint8 number: ");
    scanf("%hhu",&uint8Value);
    printValue(&uint8Value, 5/*TUINT8_T*/);

    //Read uint16_t from console (0 to 65535)
    uint16_t uint16Value=0;
    printf("Uint16 number: ");
    scanf("%hu",&uint16Value);
    printValue(&uint16Value, 6/*TUINT16_T*/);

    //Read uint32_t from console (0 to 4294967295)
    uint32_t uint32Value = 0;
    printf("Uint32 number: ");
    scanf("%u",&uint32Value);
    printValue(&uint32Value, 7/*TUINT32_T*/);

    //Read uint64_t from console (0 to 18446744073709551615)
    uint64_t uint64Value = 0u;
    printf("Uint64 number: ");
    scanf("%lu",&uint64Value);
    printValue(&uint64Value, 8/*TUINT64_T*/);

    return 0;
}
