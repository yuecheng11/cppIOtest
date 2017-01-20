**********************************************************************/

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

// 数据类型

typedef unsigned char       UINT8;

typedef unsigned int        UINT32;

 

 

/**********************************************************************

*功能描述：主函数

*输入参数：无

*输出参数：无

*返回值：0-执行成功  1-执行失败

*其它说明：无

*修改日期         版本号    修改人           修改内容

* ----------------------------------------------------------------------------------------------

*20140503        V1.0     Zhou Zhaoxiong       创建

***********************************************************************/

UINT32 main(void)

{

    FILE  *fp                                    = NULL;

    UINT8 cSingleChar                 = '\0';

    UINT8 szString[100]               = {0};

    UINT32 iFileDescription      = 0;

    UINT8  szAlphabeticSet[30]  = {0};

    UINT32 iLoopFlg                   = 0;

    UINT32 iCharCount               = 0;

    UINT8 *pIdentify                   = NULL;

 

    // fopen

    fp = fopen("Example.txt", "r");    // 在当前工程目录下有一个有具体内容的文件Example.txt

    if (fp == NULL)

    {

        printf("Open the file failed!\n");

        return 1;

    }

 

    // fgetc

    if ((cSingleChar = fgetc(fp)) != EOF)

    {

        printf("%c\n", cSingleChar);

        fclose(fp);                   // 只读取第一个字符

    }

    else

    {

        printf("The file is empty!\n");

        fclose(fp);

    }

 

    // fgets

    fgets(szString, 100, fp);

    if (strlen(szString) != 0)

    {

        printf("%s\n", szString);

    }

    else

    {

        printf("The file is empty!\n");

    }

    fclose(fp);

   

    // fputc

    for (iLoopFlg = 0; iLoopFlg < 27; iLoopFlg ++)

    {

        cSingleChar = fputc(szAlphabeticSet[iLoopFlg], fp);

        if (cSingleChar == EOF)

        {

            printf("Input %c to file failed!\n", szAlphabeticSet[iLoopFlg]);

            fclose(fp);

            return 1;

        }

    }

    printf("Input to file successfully!\n");

    fclose(fp);

 

    // fputs

    iCharCount = fputs(szAlphabeticSet, fp);

    if (iCharCount == EOF)

    {

        printf("Input %s to file failed!\n", szAlphabeticSet);

        fclose(fp);

        return 1;

    }

    printf("Input to file successfully! Content = %s.\n", szAlphabeticSet);

    fclose(fp);

 

    // fread

    iCharCount = fread(szAlphabeticSet, 1, 26, fp);

    if (iCharCount == EOF)

    {

        printf("Read from file failed!\n");

        fclose(fp);

        return 1;

    }

    printf("Read from file successfully! Content = %s.\n", szAlphabeticSet);

    fclose(fp);

 

    // fseek

    iFileDescription = fseek(fp, 5, SEEK_SET);

    if (iFileDescription == 0)

    {

        printf("offset = %d\n", ftell(fp));

    }

    fclose(fp);

 

    // fwrite

    iCharCount = fwrite(szAlphabeticSet, 1, 26, fp);

    if (iCharCount == EOF)

    {

        printf("Write into file failed!\n");

        fclose(fp);

        return 1;

    }

    printf("Write into file successfully! Content = %s.\n", szAlphabeticSet);

    fclose(fp);

 

    // getc

    cSingleChar = getc(fp);

    if (cSingleChar != EOF)

    {

        printf("The got char is %c.\n", cSingleChar);

        fclose(fp);                   // 只读取第一个字符

    }

    else

    {

        printf("The file is empty!\n");

        fclose(fp);

        return 1;

    }

 

    // getchar与putchar

    cSingleChar = getchar();

    putchar(cSingleChar);

    printf("\n");

   

    // gets

    pIdentify = gets(szAlphabeticSet);

    if (pIdentify != NULL)

    {

        printf("The got string is %s.\n", szAlphabeticSet);

    }

    else

    {

        printf("Get string from scream failed!\n");

        return 1;

    }

   

    // putc

    cSingleChar = putc('a', fp);

    if (cSingleChar == EOF)

    {

        printf("Input to file failed!\n");

        fclose(fp);

        return 1;

    }

    printf("Input to file successfully!\n");

    fclose(fp);

 

    // putc与putchar

    cSingleChar = putc('a', fp);

    if (putchar(cSingleChar) == EOF)

    {

        printf("Input to scream failed!\n");

        return 1;

    }

    printf("\n");

    printf("Input to scream successfully!\n");

 

    // getc

    cSingleChar = getc(fp);

    if (cSingleChar != EOF)

    {

        printf("The got char is %c.\n", cSingleChar);

        fclose(fp);                   // 只读取第一个字符

    }

    else

    {

        printf("The file is empty!\n");

        fclose(fp);

        return 1;

    }

   

    return 0;

}
