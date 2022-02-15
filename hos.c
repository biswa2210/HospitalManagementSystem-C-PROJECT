#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main_exit;
struct date{
    int month,day,year;

};
struct diagnostic{

    char name[60];
    int id_no,ward_no;
    char disease[60];
    char symtoms[15];
    double bed_no;
    char treatment[100];
    char tamt[100];
    char date[100];
    struct date doa;
    }d_a,chk;
struct patient_details{
        char name[60];
    int id_no,age;
    char address[60];
    char disease[15];
    double phone;
    char sex[10];
    float amt;
    struct date dob;
    struct date addrec;
    }add,check;

    void new_rec()
{
   system("color e");
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    id_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\nEnter the ID number(Only numbers):");
    scanf("%d",&check.id_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.id_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.disease,&add.phone,add.sex,&add.amt,&add.addrec.month,&add.addrec.day,&add.addrec.year)!=EOF)
    {
        if (check.id_no==add.id_no)
            {
                printf("\n\n\n\tId no. already in use!");
                Sleep(3000);
                goto id_no;

            }
    }
    add.id_no=check.id_no;
      printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.addrec.month,&add.addrec.day,&add.addrec.year);
    printf("\nEnter the name: ");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy): ");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
     printf("\nsex of patient : ");
    scanf("%s",add.sex);
    printf("\nEnter the age: ");
    scanf("%d",&add.age);
    printf("\nEnter the address : ");
    scanf("%s",add.address);
    printf("\nEnter the Disease : ");
    scanf("%s",add.disease);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the total amount for book a bed :--> rs:");
    scanf("%f",&add.amt);


        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.id_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.disease,add.phone,add.sex,add.amt,add.addrec.month,add.addrec.day,add.addrec.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            exit(0);
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }

   }

   void view_list()
{
    system("color f");
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\n  ID-NO.\t      NAME\t\t\t       \t  ADDRESS\t\t      \tPHONE\n\n----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

       while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.id_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.disease,&add.phone,add.sex,&add.amt,&add.addrec.month,&add.addrec.day,&add.addrec.year)!=EOF)
    {
           printf("\n\n\n%6d\t\t%10s\t\t\t\t%10s\t\t\t%.0lf",add.id_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}
int n1;
    view_list_invalid:
    printf("\n\n\n\n\n\n\n\t\t\t*****Enter 1 to go main menu and 0 to exit the program *****\n\t\t---------------------------------------------------------------------------\n\n\t\t\tenter your choice :: ");
   scanf("%d",&n1);
  if(n1==1)
   {

      menu();
   }
     else if(n1==0)
   {
       exit(0);
   }
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
   void d_a_diag_report()
    {
            system("cls");
    printf("#***************************************************************************#");
    system("color a");
      FILE *ptrda,*ptrff;

    ptrda=fopen("record2.dat","a+");
    account_no5:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ ADD DIAGNOSTIC REPORT  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter the ID number of patient : ");
    scanf("%d",&chk.id_no);
    ptrff=fopen("record.dat","r");
check.id_no=chk.id_no;
         while(fscanf(ptrff,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.id_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.disease,&add.phone,add.sex,&add.amt,&add.addrec.month,&add.addrec.day,&add.addrec.year)!=EOF)
    {
              if(add.id_no==check.id_no)
            {
                printf("\n\nDate of Admit :: %d/%d/%d\n\n",add.addrec.month,add.addrec.day,add.addrec.year);
            }
    }
    fclose(ptrff);
    while(fscanf(ptrda,"%d %s %d/%d/%d %d %s %s %lf %s %s %s\n",&d_a.id_no,d_a.name,&d_a.doa.month,&d_a.doa.day,&d_a.doa.year,&d_a.ward_no,d_a.disease,d_a.symtoms,&d_a.bed_no,d_a.treatment,d_a.tamt,d_a.date)!=EOF)
    {
        if (chk.id_no==d_a.id_no)
            {
                printf("\n\n\t\tID no. already in use!");
                Sleep(2000);
                goto account_no5;

            }
    }
    d_a.id_no=chk.id_no;
     printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%s",d_a.date);
    printf("\nEnter the name of patient : ");
    scanf("%s",d_a.name);
    printf("\nEnter the ward no: ");
    scanf("%d",&d_a.ward_no);
    printf("\nEnter the disease: ");
    scanf("%s",d_a.disease);
    printf("\nSymtoms : ");
    scanf("%s",d_a.symtoms);
    printf("\nEnter the bed number: ");
    scanf("%lf",&d_a.bed_no);
    printf("\n\nDETAILS OF TREATMENT(Don't use any space,you can use '-'or '_') :: ");
    scanf("%s",d_a.treatment);
 printf("\n\nTotal Treatment Amount :: ");
    scanf("%s",d_a.tamt);
        fprintf(ptrda,"%d %s %d/%d/%d %d %s %s %lf %s %s %s\n",d_a.id_no,d_a.name,d_a.doa.month,d_a.doa.day,d_a.doa.year,d_a.ward_no,d_a.disease,d_a.symtoms,d_a.bed_no,d_a.treatment,d_a.tamt,d_a.date);


    fclose(ptrda);
    printf("\nRecord added successfully!");
    d_a_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            exit(0);
    else
        {
            printf("\nInvalid!\a");
            goto d_a_invalid;
        }
    }
void display_rec()
{
    int choose;
    label:
    system("cls");
    printf("********************************************************************************");
    printf("\n\n\t\t\tPatient details\n\n\n");
    printf("********************************************************************************");
    printf("\n\nCATEGORY------>\n\n1.Patient Details\n2.Patient Diagnostic Report\n3.Patient Details With Diagnostic report\n4.Home\n5.Exit program");
    printf("\n\nEnter your choice :: ");
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:dis_pd();
        break;
    case 2: dis_diag_report();
        break;
            case 3: both();
        break;
    case 4: menu();
        break;
            case 5: exit(0);
        break;
        default: printf("INVALID INPUT !!! \a\a\a");
        goto label;
        break;

    }
}
void both()
{
    int comid;
         system("cls");
     int test=0;
     FILE *dispd;
     dispd=fopen("record.dat","r");
       printf("Enter the Id number of patient:");
        scanf("%d",&comid);
        check.id_no=comid;
        printf("\n\n#################################################################################\n\n");
            while(fscanf(dispd,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.id_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.disease,&add.phone,add.sex,&add.amt,&add.addrec.month,&add.addrec.day,&add.addrec.year)!=EOF)
    {
                    if(add.id_no==check.id_no)
            {
                test=1;

                printf("\n\n\nID NO.: %d\n\nName: %s \n\nDOB: %d/%d/%d \n\nAge  %d \n\nAddress: %s \n\nDisease : %s \n\nPhone number:%.0lf \n\nSex : %s \n\nAmount gain: Rs: %.2f \n\nDate Of  Admit : %d/%d/%d\n\n\n",add.id_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.disease,add.phone,
                add.sex,add.amt,add.addrec.month,add.addrec.day,add.addrec.year);
                        printf("\n\n#################################################################################\n\n");

            }

    }
    fclose(dispd);
    printf("\n\nDiagnostic Report ----->\n\n");
              FILE *ptrda;
    int test2=0;
    ptrda=fopen("record2.dat","r");
chk.id_no=comid;

        while (fscanf(ptrda,"%d %s %d/%d/%d %d %s %s %lf %s %s %s",&d_a.id_no,d_a.name,&d_a.doa.month,&d_a.doa.day,&d_a.doa.year,&d_a.ward_no,d_a.disease,d_a.symtoms,&d_a.bed_no,d_a.treatment,d_a.tamt,d_a.date)!=EOF)
        {
            if(d_a.id_no==chk.id_no)
            {
                test2=1;
            printf("\n\n#################################################################################\n\n");

                printf("\n\nWard no : %d \nDisease : %s \nSymtoms: %s \nBed number:%.0lf \n\n\nTreatment: %s \nTotal Treatment Cost : rs: %s \nDate Of Adding This Diagnostic Report : %s\n\n",d_a.ward_no,d_a.disease,d_a.symtoms,d_a.bed_no,
                d_a.treatment,d_a.tamt,d_a.date);
            printf("\n\n#################################################################################\n\n");
                                 add_invalid7:
    printf("\n\n\n\t\tEnter 1 to try again  and 0 to main menu:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
       dis_diag_report();
    else if(main_exit==0)
            menu();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid7;
        }


}
        }
        fclose(ptrda);
        if(test==0 && test2==0)
        {
            printf("\n\n\nThis Id number is not found.....................\n\n\n");
            d_a_invalid1:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            exit(0);
    else
        {
            printf("\nInvalid!\a");
            goto d_a_invalid1;
        }
        }
        else if(test==0)
        {
            printf("\n\n\nPatient Details Missing.............\n\n\n");
            d_a_invalid2:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            exit(0);
    else
        {
            printf("\nInvalid!\a");
            goto d_a_invalid2;
        }
        }
        else if(test2==0)
        {
            printf("\n\n\nDiagnostic Report Missing.................\n\n\n");
            d_a_invalid3:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            exit(0);
    else
        {
            printf("\nInvalid!\a");
            goto d_a_invalid3;
        }
        }
}
  void dis_pd()
 {
    int comid;
         system("cls");
     int test=0;
     FILE *dispd;
     dispd=fopen("record.dat","r");
       printf("Enter the Id number of patient:");
        scanf("%d",&comid);
        check.id_no=comid;
        printf("\n\n#################################################################################\n\n");
            while(fscanf(dispd,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.id_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.disease,&add.phone,add.sex,&add.amt,&add.addrec.month,&add.addrec.day,&add.addrec.year)!=EOF)
    {
                    if(add.id_no==check.id_no)
            {
                test=1;

                printf("\n\n\nID NO.: %d\n\nName: %s \n\nDOB: %d/%d/%d \n\nAge  %d \n\nAddress: %s \n\nDisease : %s \n\nPhone number:%.0lf \n\nSex : %s \n\nAmount gain: Rs: %.2f \n\nDate Of  Admit : %d/%d/%d\n\n\n",add.id_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.disease,add.phone,
                add.sex,add.amt,add.addrec.month,add.addrec.day,add.addrec.year);
                        printf("\n\n#################################################################################\n\n");

            }

    }
    fclose(dispd);
                        add_invalid5:
    printf("\n\n\n\t\tEnter 1 to try again  and 0 to main menu:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
       dis_pd();
    else if(main_exit==0)
            menu();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid5;
        }


 }
void dis_diag_report()
{
    system("cls");
    FILE *ptrda,*ptrf;
    int test2=0;
    ptrda=fopen("record2.dat","r");
    printf("Enter the ID number:");
        scanf("%d",&chk.id_no);
ptrf=fopen("record.dat","r");
check.id_no=chk.id_no;
         while(fscanf(ptrf,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.id_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.disease,&add.phone,add.sex,&add.amt,&add.addrec.month,&add.addrec.day,&add.addrec.year)!=EOF)
    {
              if(add.id_no==check.id_no)
            {
                printf("\n\nDate of Admit :: %d/%d/%d\n\n",add.addrec.month,add.addrec.day,add.addrec.year);
            }
    }
    fclose(ptrf);
        while (fscanf(ptrda,"%d %s %d/%d/%d %d %s %s %lf %s %s %s",&d_a.id_no,d_a.name,&d_a.doa.month,&d_a.doa.day,&d_a.doa.year,&d_a.ward_no,d_a.disease,d_a.symtoms,&d_a.bed_no,d_a.treatment,d_a.tamt,d_a.date)!=EOF)
        {
            if(d_a.id_no==chk.id_no)
            {
                test2=1;

                printf("\nID_NO.: %d\nName: %s \nWard no : %d \nDisease : %s \nSymtoms: %s \nBed number:%.0lf \n\n\nTreatment: %s \nTotal Treatment Cost : rs: %s \nDate Of Adding This Diagnostic Report : %s\n\n",d_a.id_no,d_a.name,d_a.ward_no,d_a.disease,d_a.symtoms,d_a.bed_no,d_a.treatment,d_a.tamt,d_a.date);
                      add_invalid5:
    printf("\n\n\n\t\tEnter 1 to try again  and 0 to main menu:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
       dis_diag_report();
    else if(main_exit==0)
            menu();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid5;
        }

}
        }
        fclose(ptrda);
        if(test2==0)
        {
printf("\n\n\nSorry,Patient diagnostic record is not found.....................\n\nTry again later..");
      add_invalid6:
    printf("\n\n\n\t\tEnter 1 to try again  and 0 to main menu:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
       dis_diag_report();
    else if(main_exit==0)
            menu();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid6;
        }

        }
}
void hist()
{
    system("cls");
     printf("\n\nHISTORY\n\n");
     printf("Healing people is a godly and noble work. Late Mr.Saroj Debroy trusted that. He wanted to make a Remedy Plus Carepital from his young \nage. Finally he succeeded to build it. On 2001,Oct,22. He and his family took the responsibility of the management of \nthe great Remedy Plus Carepital 'Remedy Plus Care'.They worked very hard and sacrificed for 'Remedy Plus Care'. After some years 'Remedy Plus Care' has become a very well \nknown Remedy Plus Carepital.It was given 'Suraksa' award by Govt.in 2010.The 'Jeevan','New life','Child care' all these awards \nwere given for its fabulous treatment methods and management.Also it own foreign awards for high tech methods of \ntreatment and management.It was specially appreciated by the Govt. for low cost treatment than others except being a \nprivate Remedy Plus Carepital.Its very popular for child treatment.");
     printf("\n\nABOUT 'Remedy Plus Care'\n\n");
     printf("Many well known doctors and specialists are here for diffent departments.Latest high tech facsilities are afforded.\nThe staffs are well trained and experienced.Different sections are here for diagnostic tests,operations and surgeries,\ndoctors' chambers,admition of patients. The cheif manager is Mr.B. Bhattachariya.The economical section is also in very \nfaithful and experienced hand.Special section of maintenance of the Remedy Plus Carepital which has three 5 blocked buildings, \nis here.People with poor economical conditions are considered with less costs.Patients are given food,medicines,\ntreatment with systemic manner.The child care section is very well managed.New born babies and new mothers are cared \nwith great responsibility.The officers greatly do their duty and very faithful.Throughout these 18 years our Remedy Plus Carepital \n'Remedy Plus Care' is trusted for its well management and good treatments.");
     printf("Remedy Plus Care has a high class department for cancer. Here, for \neach and every kind of cancer's treatment is available. Special fascility of kemo is available. Most of the dostors \nof eye department, giano department,gastro,diabetis department are from foreign. Diagnostic department is very well \nknown for x ray and other intensive tests. Test reports are provided within 12 hours. Our Remedy Plus Carepital 'Remedy Plus Care' is open for people for \n24 hours 7 days in week and 365 days.");
     printf("\nRemedy Plus Care is well known for its well known and faithful treatment.");
                         add_invalid9:
    printf("\n\n\n\t\tEnter 1 to main menu : ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
       menu();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid9;
        }

}
void head()
{
    printf("\n\n\n\n\n\t\t\tHOSPITAL MANAGEMENT SYSTEM");
    Sleep(5000);
    system("cls");
     printf("\n\n\n\n\n\t\t\tDON'T USE SPACE FOR GAPPING IN RUNTIME INPUT\n\n\t\t\tYOU CAN USE  '-' OR '_' FOR GAPPING");
    Sleep(5000);
    system("cls");
}
    int main()
        {
head();

              char pass[10],password[100]="UEMK";
    int i=0;
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------\n\t------------ :: Enter the password to login ::------------\n\n----------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\t\t\tPASSWORD ::   ");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\n----------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\t\t\t\tPassword Match!\n\n\t\t\t\t\tLOADING............\n\t\t\t\t\t");
Sleep(2000);
                system("cls");
            menu();
        }
    else
        {   printf("\n\n\nWrong password!!\a\a\a");
            login_try:
            printf("\n\n\n\n\n\n\n\t\t\t\t----:Enter 1 to try again and 0 to exit:----\n\n\t\t\t\tchoice:: ");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {
                        printf("\n\n\nInvalid!\a\a\a");
                       Sleep(2000);
                    system("cls");
                    goto login_try;}


  }
        }
void menu()
{
    int choice;
    pichon:
      system("mode 1000");
    system("cls");
    printf("\t\t\t\t# Remedy Plus Care #");
     system("color f");

          printf("\n\n\n\n**********************************************\n\n1.ADD NEW PATIENT RECORD\n\n2.Add diagnostic report of patient\n\n3.Full History of Patient\n\n4.All Patients list\n\n5.Total history of Remedy plus care\n\n6.Exit\n\n7.Credits\n\n**********************************************");
printf("\n\nEnter Your Choice :: ");
scanf("%d",&choice);
switch(choice)
{
case 1: new_rec();
    break;
case 2: d_a_diag_report();
        break;
case 3: display_rec();
            break;
case 4:view_list();
                break;
case 5:hist();
            break;
case 6:exit(0);
            break;
case 7: system("cls");
             system("color b");
             printf("\n\n\n\n\t\t\t\tLoading\n\n");
Sleep(1000);
    printf("\t\t\t|||||");
    Sleep(1000);
    printf("||||||||||");
    Sleep(1000);
    printf("||||||||||");
    Sleep(2000);
    system("cls");
    system("color e");
   printf("\t|        DEVELOPERS        |");
    printf("\n*--------------------------------------------*\n");
    printf("|\n|\n|\n|\t\tMade By Biswa\n|\n|\n|");
    printf("\n*--------------------------------------------*\n");

                         add_invalid8:
    printf("\n\n\n\t\tEnter 1 to main menu : ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
       menu();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid8;
        }

break;
default: printf("\n\n\t\t\tINVALID INPUT....TRY AGAIN!!!\a\a\a\a");
Sleep(2000);
              goto pichon;
                break;
}
}



