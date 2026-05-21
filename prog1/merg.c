#include<stdio.h>
#define max 100
#define filename "std.dat"  //std  is the data file of the students


typedef struct 
{
    int id;
    char name[100];
    float marks;
} stds;

void input(stds std[], int n);
void wbf(stds std[],int n,const char *file);
int  rbf(stds std[],int n,const char *file);
void print(stds std[],int n);

int main()
{
    int n;
    int count;
    FILE *fp;

    Printf("Enter the size :\n ");
    scanf("%d",&n);

    if(n<=0)
    {
        printf("The Enter is the invaild");
        return 0;
    }

    stds std[max];

    input(std,n);

    wbf(std,n,filename);

    int c=rbf(std,n,filename);

    wbf(std,n,filename);

    return 0;
}

void input(stds std[], int n)
{
     for(int i=0;i<n;i++)
     {
        printf("Enter the details of the Students %d\n",i+1);

      printtf("Enter the ID");
      scanf("%d",&std[i].id);

      printf("Enter the Name");
      scanf("%d",&std[i].name);

      printf("Enter the Marks");
      scanf("%d",&std[i].marks);

     }
}

void wbf(stds std[],int n,const char *file)
{
    FILE *fp=(filename ,"rb");
    if(fp==NULL)
    {
        printf("Error opening binary file for reading \n");
        return;
    }

    fwrite(std ,sizeof(stds),n,fp);
    fclose(fp);
}

int  rbf(stds std[],int n,const char *file)
{
    
}


