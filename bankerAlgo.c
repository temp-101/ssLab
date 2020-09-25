#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char colours[5][10] = {"[0;31m", "[0;32m", "[0;33m", "[0;34m", "[0;36m"};
int numberOfProcesses, resourceTypes, notEnoughResources = 0, allocated[20][5], max[20][5], totalResources[5];
bool finished[20];
void execute(int i)
{
    for (int j = 0; j < resourceTypes; j++)
        totalResources[j] = totalResources[j] + allocated[i][j];
}
bool finishedExecute()
{
    notEnoughResources++;
    if (notEnoughResources > numberOfProcesses + 1)
    {
        printf("\n\n\033[1;31mFATAL ERROR OCCURED: Not Enough Resources\n");
        exit(0);
    }
    for (int i = 0; i < numberOfProcesses; i++)
        if (finished[i] == false)
            return false;
    return true;
}
void main()
{
    printf("\033[1;36mHow many processes are running? ");
    scanf("%d", &numberOfProcesses);
    printf("Enter the number of resource types ");
    scanf("%d", &resourceTypes);
    if (resourceTypes > 5)
    {
        printf("\033[1;31mToo many resource types\n");
        exit(0);
    }
    printf("Enter the  allocated resources fo each process");
    for (int i = 0; i < numberOfProcesses; i++)
    {
        printf("\033[0;35m\n\nPROCESS NUMBER:%d\n\n", i);
        for (int j = 0; j < resourceTypes; j++)
        {
            printf("\033%s RESOURCE NUMBER %d-> ", colours[j], j);
            scanf("%d", &allocated[i][j]);
        }
    }
    printf("\n\n\n\033[1;36mEnter the max resources for each process");
    for (int i = 0; i < numberOfProcesses; i++)
    {
        printf("\033[0;35m\n\nPROCESS NUMBER:%d\n\n", i);
        for (int j = 0; j < resourceTypes; j++)
        {
            printf("\033%s RESOURCE NUMBER %d-> ", colours[j], j);
            scanf("%d", &max[i][j]);
        }
    }
    printf("\n\n\033[1;36mEnter the total available resources\n");
    for (int i = 0; i < resourceTypes; i++)
    {
        printf("\033%sRESOURCE NUMBER %d->", colours[i], i);
        scanf("%d", &totalResources[i]);
    }

    while (!finishedExecute())
    {
        for (int i = 0; i < numberOfProcesses; i++)
        {
            bool possible = true;
            for (int j = 0; j < resourceTypes; j++)
            {

                if (max[i][j] - allocated[i][j] > totalResources[j] && finished[i] == false)
                    possible = false;
            }
            if (possible == true && finished[i] == false)
            {
                execute(i);
                if (finished[i] == false)
                {
                    printf("\033[1;36m PROCESS %d FINISHED EXECUTION. TOTAL RESOURCES=[", i);
                    for (int k = 0; k < resourceTypes; k++)
                        printf("\033%s   %d", colours[k], totalResources[k]);
                    printf("\033[1;36m   ]\n");
                }
                finished[i] = true;
            }
        }
    }
}
