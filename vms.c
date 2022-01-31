#include< stdio.h >
#include< stdlib.h >
#include< string.h >
char patName[20][30];
int takenVacc[20]={0};
int notakenVacc[20]={0};
int indexNumber=0;
void checkPatient()
{
    int i;
    printf("\n       1st/2nd Dose Done | Vaccination Not Taken\n");   
    for ( i = 0; i < indexNumber; i++)
    {        
        printf("%s",patName[i]);
        printf("              %d             %d\n",takenVacc[i],notakenVacc[i]);                           
    }    
}
void addPatient()
{
    int i,num,add;   
    if (indexNumber==0)
    {
        printf("Enter how many patients you want to add: ");
        fflush(stdin);
        scanf("%d",&num);
        for ( i = 0; i < num; i++)
        {        
            printf("\nEnter %d patient name to add in vaccination register: ",i+1);    
            fflush(stdin);
            gets(patName[i]);  
            indexNumber++;              
        }           
    }
    else
    {        
        printf("Enter how many patients you want to add: ");
        fflush(stdin);
        scanf("%d",&num);
        add=indexNumber+num;
        for ( i = indexNumber; i < add; i++)
        {        
            printf("\nEnter %d patient name to add in Vaccination Register: ",i+1);    
            fflush(stdin);
            gets(patName[i]);  
            indexNumber++;              
        }
    }            
}
void removePatient()
{
    char name[30];
    int i,j;
    printf("Enter patient name to remove: ");
    fflush(stdin);
    gets(name);
    for (i = 0; i < indexNumber; i++)
    {
        if (strcmp(name,patName[i])==0)
        {          
            for (j = i; j < indexNumber; j++)
            {
                strcpy(patName[j],patName[j+1]);  
                takenVacc[i]=takenVacc[i+1];
                notakenVacc[i]=notakenVacc[i+1];
            }     
            indexNumber--;
            printf("\n%s patient is removed\n",name);
            break;                    
        }
        else if(i==indexNumber-1)
        {
            printf("This name does not exits\n");
        }       
    }        
}
void takenVaccination()
{
    int i;
    char ch;
    printf("\nEnter Y for Vaccination Taken and N for Vaccination Not Taken\n");
    for ( i = 0; i < indexNumber; i++)
    {
        repeate:
        printf("%d. %s has taken the Vaccination: ",i+1,patName[i]);
        fflush(stdin);
        scanf("%c",&ch);
        if (ch=='Y'||ch=='y')
        {
            takenVacc[i]+=1;
        }
        else if (ch=='N'||ch=='n')
        {            
            notakenVacc[i]+=1;                                                    
        } 
        else
        {
            printf("Invalid character Try again\n");
            goto repeate;
        }              
    }    
}
void main()
{
    int choose;
    do
    {
        printf("\n**********Vaccination Menu***********\n");
        printf("Enter 1 to add patient\n");
        printf("Enter 2 to register First/Secod Dose\n");
        printf("Enter 3 to check the patient\n");
        printf("Enter 4 to remove patient\n");
        printf("Enter 5 to exit\n");
        printf("Please choose any menu: ");
        fflush(stdin);
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            addPatient();
            break;        
        case 2:
            takenVaccination();
            break;        
        case 3:
            checkPatient();
            break;        
        case 4:
            removePatient();
            break;        
        case 5:
            exit(0);
            break;        
        }
    } while (choose!=5);
    
}
