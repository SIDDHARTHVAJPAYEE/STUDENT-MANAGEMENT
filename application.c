#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
int rollNumber;
char name[35];
char gender;
};
void printLine(char c,int size)
{
int i;
for(i=1;i<size;i++) printf("%c",c);
printf("\n");
}
void addStudent();
void editStudent();
void deleteStudent();
void displayListOfStudents();
void searchStudent();
int main()
{
int ch;
while(1)
{
printf("1.Add Student\n");
printf("2.Edit Student\n");
printf("3.Delete Student\n");
printf("4.Display List Of Students\n");
printf("5.Search Student\n");
printf("6.Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
fflush(stdin);
if(ch==1) addStudent();
else if(ch==2) editStudent();
else if(ch==3) deleteStudent();
else if(ch==4) displayListOfStudents();
else if(ch==5) searchStudent();
else if(ch==6) break;
else printf("Invalid Choice\n");
}
return 0;
}
void addStudent()
{
FILE *f;
struct Student t,g;
int y;
char m;
char name[37];
int rollNumber;
char gender;
printf("ADD(Module)\n");
printf("Enter Roll Number:");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("Invalid RollNumber\n");
return;
}
f=fopen("Student.dat","rb");
if(f!=NULL)
{
while(1)
{
fread(&t,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollNumber==t.rollNumber)
{
printf("That roll Number has been alloted to %s",t.name);
fclose(f);
return;
}
}
fclose(f);
}
printf("Enter name of Student:");
fgets(name,37,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Gender:(M/F):");
gender=getchar();
fflush(stdin);
if(gender!='m' && gender!='M' && gender!='f' && gender!='F')
{
printf("Please select gender:");
return;
}
printf("SAVE(Y/N): ");
m=getchar();
if(m!='y' && m!='Y')
{
printf("Data not saved:\n");
return;
}
strcpy(g.name,name);
g.rollNumber=rollNumber;
g.gender=gender;
f=fopen("Student.dat","ab");
fwrite(&g,sizeof(struct Student),1,f);
fclose(f);
printf("Student Added:\n");
printf("Please Enter to continue...");
getchar();
fflush(stdin);
}


void editStudent()
{
FILE *f1,*f2;
struct Student t,g;
int rollNumber;
int found;
char name[37];
char gender;
char m;
printf("Edit(Module)\n");
printf("Enter Student's Roll-Number to Edit:");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<0)
{
printf("Invalid RollNumber\n");
return;
}
f1=fopen("Student.dat","rb");
if(f1==NULL)
{
printf("Invalid Roll-Number\n");
return;
}
found=0;
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(t.rollNumber==rollNumber)
{
found=1;
break;
}
}
fclose(f1);
if(found==0)
{
printf("Invalid Roll-Number");
return;
}
printf("Name: %s\n",t.name);
if(t.gender=='m' || t.gender=='M')
{
printf("Gender %s\n","MALE");
}
else
{
printf("Gender %s\n","FEMALE");
}
printf("Edit(Y/N):");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not Updated\n");
return;
}
printf("Enter name: ");
fgets(name,37,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Enter gender(M/F): ");
gender=getchar();
fflush(stdin);
if(gender!='m' && gender!='M' && gender!='f' && gender!='F')
{
printf("Invalid gender Entry\n");
return;
}
printf("Update(Y/N): ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Data not updated\n");
return;
}
g.rollNumber=rollNumber;
strcpy(g.name,name);
g.gender=gender;
f1=fopen("Student.dat","rb");
f2=fopen("tmp.tmp","wb");
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(t.rollNumber!=rollNumber)
{
fwrite(&t,sizeof(struct Student),1,f2);
}
else
{
fwrite(&g,sizeof(struct Student),1,f2);
}
}
fclose(f1);
fclose(f2);
f1=fopen("Student.dat","wb");
f2=fopen("tmp.tmp","rb");
while(1)
{
fread(&t,sizeof(struct Student),1,f2);
if(feof(f2)) break;
fwrite(&t,sizeof(struct Student),1,f1);
}
fclose(f1);
fclose(f2);
f2=fopen("tmp.tmp","w");
fclose(f2);
printf("Student Updated, press Enter to continue....");
getchar();
fflush(stdin);
}


void deleteStudent()
{
FILE *f1,*f2;
struct Student t;
int rollNumber;
int found;
char m;
printf("DELETE(Module)\n");
printf("Enter Student's Roll-Number to Delete:");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<0)
{
printf("Invalid RollNumber\n");
return;
}
f1=fopen("Student.dat","rb");
if(f1==NULL)
{
printf("Invalid Roll-Number\n");
return;
}
found=0;
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(t.rollNumber==rollNumber)
{
found=1;
break;
}
}
fclose(f1);
if(found==0)
{
printf("Invalid Roll-Number");
return;
}
printf("Name: %s\n",t.name);
if(t.gender=='m' || t.gender=='M')
{
printf("Gender %s\n","MALE");
}
else
{
printf("Gender %s\n","FEMALE");
}
printf("Delete(Y/N): ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Data not Deleted\n");
return;
}
f1=fopen("Student.dat","rb");
f2=fopen("tmp.tmp","wb");
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(t.rollNumber!=rollNumber)
{
fwrite(&t,sizeof(struct Student),1,f2);
}
}
fclose(f1);
fclose(f2);
f1=fopen("Student.dat","wb");
f2=fopen("tmp.tmp","rb");
while(1)
{
fread(&t,sizeof(struct Student),1,f2);
if(feof(f2)) break;
fwrite(&t,sizeof(struct Student),1,f1);
}
fclose(f1);
fclose(f2);
f2=fopen("tmp.tmp","w");
fclose(f2);
printf("Student Deleted, press Enter to continue....");
getchar();
fflush(stdin);
}



void displayListOfStudents()
{
int sno,newPage,pageSize;
FILE *f;
struct Student t;
f=fopen("Student.dat","rb");
if(f==NULL)
{
printf("LIST(Module)\n");
printLine('-',63);
printf("%2s %-35s %-12s %-8s\n","S.NO","NAME","Roll-Number","Gender");
printLine('-',63);
printf("NO student ADDED\n");
printLine('-',63);
printf("Press Enter to Continue...");
getchar();
fflush(stdin);
return;
}
pageSize=5;
newPage=1;
sno=0;
while(1)
{
if(newPage==1)
{
printf("LIST(Module)\n");
printLine('-',63);
printf("%2s %-35s %-12s %-8s\n","S.NO","NAME","Roll-Number","Gender");
printLine('-',63);
newPage=0;
}
fread(&t,sizeof(struct Student),1,f);
if(feof(f)) break;
sno++;
if(t.gender=='m' || t.gender=='M')
{
printf("%4d %-35s %-12d %-8s\n",sno,t.name,t.rollNumber,"MALE");
}
else
{
printf("%4d %-35s %-12d %-8s\n",sno,t.name,t.rollNumber,"FEMALE");
}
if(sno%pageSize==0)
{
printLine('-',63);
printf("Press enter to continue....");
getchar();
fflush(stdin);
newPage=1;
}
}
if(sno==0)
{
printf("No records added:\n");
printLine('-',63);
printf("Press enter to continue....");
getchar();
fflush(stdin);
}
if(sno%pageSize!=0)
{
printLine('-',63);
printf("Press enter to continue....");
getchar();
fflush(stdin);
}
fclose(f);
return;
}



void searchStudent()
{
FILE *f;
struct Student t;
int rollNumber;
int found;
printf("Search(Module)\n");
printf("Enter roll number:");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<0)
{
printf("Invalid Roll-Number");
return;
}
f=fopen("Student.dat","rb");
if(f==NULL)
{
printf("Invalid roll number");
return;
}
while(1)
{
fread(&t,sizeof(struct Student),1,f);
if(feof(f)) break;
if(t.rollNumber==rollNumber)
{
found=1;
break;
}
}
if(found==0)
{
printf("No student Found\n");
return; 
}
else
{
printf("Name: %s\n",t.name);
if(t.gender=='M' || t.gender=='m')
{
printf("Gender:%s\n","MALE");
}
else
{
printf("Gender:%s\n","FEMALE");
}
printf("Press enter to continue....");
getchar();
fflush(stdin);
}
}