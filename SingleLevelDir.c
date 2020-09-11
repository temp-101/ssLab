#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char files[50][50];
char dir_name[50];
int search()
{
  printf("Enter name of the file: ");
  char filename[50];
  scanf("%s",filename);
  for(int i=0;i<50;i++)
    if(strcmp(filename,files[i])==0)
      return i;
  return -1;
}
void menu()
{
  printf("\n\n\n1.Insert file\n2.Search file\n3.Delete file\n4.Display contents\n0.EXIT\nCHOOSE OPTION: ");
  int option=-1,s;
  scanf("%d",&option);
  switch(option)
  {
    case 1: for(int i=0;i<50;i++)
            {
              if(strcmp(files[i],"\0")==0)
              {
                printf("Enter name of the file: ");
                scanf("%s",files[i]);
                printf("FILE CREATED");
                menu();
              }
            }
            printf("NO MORE SPACE");
            break;
    case 2: if(search()!=-1)
              {
                printf("FILE FOUND");
                menu();
              }
            printf("FILE NOT FOUND");
            break;
    case 3: s=search();
            if(s!=-1)
            {
              files[s][0]='\0';
              printf("FILE DELETED");
              menu();
            }
            printf("FILE DOES NOT EXIST");
            break;
    case 4: printf("Contents of Directory %s\n",dir_name);
            for(int i=0;i<50;i++)
            {
              if(strcmp(files[i],"\0")!=0)
                printf("%s\n",files[i]);
            }
            menu();
            break;
    case 0:exit(0);
    default: menu();
    break;
  }
  menu();
}
int main()
{
  printf("Enter the name of directory ");
  scanf("%s",dir_name);
  menu();
  return 0;
}
