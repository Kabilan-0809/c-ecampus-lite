/*
USES OF VARIABLES:
qw=stores usernames of students,w[][]=stores passwords of students,bw,mw=used to get
username and password for comparison,c[]=used to get password for comparison
H[]=used in password to *,i,j=for iteration,opp,opp2=to get options in switch case.
FUNTIONS AND ITS USE:
login=to login into account,newacc=to create new account,academic=to view tt of
respective course,
home=to go back to login page,studentinfo=to check student profile or to change password
NUMBERS FOR CASE:
1 to choose first option ,2 for second and 3 for third , -1 for for coming a step back ,click any
other option to exit the program
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
struct sname {
    char name[20];
    char pass[20];
} qw, bw, mw;
void studentinfo(FILE *fp);
void newacc(FILE *fp);
void academic(FILE *fp);
void home(FILE *fp);
int login(FILE *fp);
char c[20], H[20], H1[20], str[1000];
int i, j, v, opp, opp2;
char r[20];
int login(FILE *fp) {
    rewind(fp);
    int k, z = 1;
    char p[] = "login successful";
    printf("\t\t\tPSG COLLEGE OF TECHNOLOGY LITE\n\n");
    printf("\t\t\t STUDENT LOGIN\n\n");
    printf("USERNAME : ");
    scanf("%s", bw.name);
    printf("PASSWORD : ");
    for (int i = 0; i < 14; i++) {
        scanf("%c", &H[i]);
        if (i % 2 != 0) {
            c[i / 2] = H[i];
        }
        printf("\n");
        system("clear");
        printf("\t\t\tPSG COLLEGE OF TECHNOLOGY LITE\n\n");
        printf("\t\t\t STUDENT LOGIN\n\n");
        printf("USERNAME : %s\n", bw.name);
        printf("PASSWORD : ");
        for (j = 0; j < i; j += 2) {
            printf("*");
        }
    }
    printf("\n");
    strcpy(bw.pass, c);
    while (fread(&mw, sizeof(struct sname), 1, fp)) {
        if (!strcmp(bw.name, mw.name)) {
            if (!strcmp(bw.pass, mw.pass)) {
                for (j = 0; j < strlen("login successful"); j++) {
                    for (k = 0; k <= j; k++) {
                        printf("\a");
                        printf("%c", p[k]);
                    }
                    printf("\n");
                    sleep(1);
                    system("clear");
                }
                printf("\n");
                z = 0;
                break;
            }
        }
        if (z == 0) {
            break;
        }
        i++;
    }
    v = i;
    if (z == 1) {
        printf("USERNAME OR PASSWORD INCORRECT, ENTER AGAIN !\n");
        sleep(3);
        system("clear");
        login(fp);
    }
    return z;
}
void newacc(FILE *fp) {
    rewind(fp);
    printf("\t\t\tPSG COLLEGE OF TECHNOLOGY LITE\n\n");
    printf("CREATE A ACCOUNT WITHIN A MINUTE\n\n");
    printf("USERNAME : ");
    scanf("%s", bw.name);
    while (fp != NULL) {
        fread(&qw, sizeof(struct sname), 1, fp);
        if (!strcmp(qw.name, bw.name)) {
            printf("USERNAME ALREADY EXISTS");
        } else {
            printf("PASSWORD : ");
            for (i = 0; i < 14; i++) {
                scanf("%c", &H[i]);
                if (i % 2 != 0) {
                    c[i / 2] = H[i];
                }
                printf("\n");
                system("clear");
                printf("\t\t\tPSG COLLEGE OF TECHNOLOGY LITE\n\n");
                printf("CREATE A ACCOUNT WITHIN A MINUTE\n\n");
                printf("USERNAME : %s\n", bw.name);
                printf("PASSWORD : ");
                for (int j = 0; j < i; j += 2) {
                    printf("*");
                }
            }
            break;
        }
    }
    printf("\n");
    strcpy(bw.pass, c);
    fseek(fp, 0, 2);
    fwrite(&bw, sizeof(struct sname), 1, fp);
    printf("\n");
    sleep(0.1);
    system("clear");
}
void home(FILE *fp) {
    time_t tm;
    time(&tm);
    sleep(2);
    system("clear");
    printf("\t\t\t\tSTUDENT ZONE\n");
    printf("%s", ctime(&tm));
    fseek(fp, v * sizeof(struct sname), 0);
    fread(&bw, sizeof(struct sname), 1, fp);
    printf("\t\t\t\t\t\t\t(%s)\n", bw.name);
    printf("1. HOME < > 2. STUDENT PROFILE < > 3. ACADEMIC\n");
    scanf("%d", &opp);
    switch (opp) {
        case (1): {
            printf("\n");
            sleep(0.1);
            system("clear");
            login(fp);
            break;
        }
        case (2): {
            printf("\n");
            sleep(0.1);
            system("clear");
            studentinfo(fp);
            break;
        }
        case (3): {
            printf("\n");
            sleep(0.1);
            system("clear");
            academic(fp);
            break;
        }
        default: {
            break;
        }
    }
}
void studentinfo(FILE *fp) {
    printf("\t\t\tSTUDENT PROFILE\n\n");
    printf("\t 1. PROFILE VIEW < > 2. CHANGE PASSWORD\n");
    scanf("%d", &opp2);
    switch (opp2) {
        case (1): {
            printf("\n");
            sleep(0.1);
            system("clear");
            printf("\t\t\tSTUDENT INFORMATION\n\n");
            fseek(fp, v * sizeof(struct sname), 0);
            fread(&bw, sizeof(struct sname), 1, fp);
            printf("ROLL NUMBER : %s\n", bw.name);
            strcpy(r, bw.name);
            if (r[3] == 'T') {
                printf("PROGRAMME : THEORETICAL COMPUTER SCIENCE\n");
            } else if (r[3] == 'D') {
                printf("PROGRAMME : DATA SCIENCE\n");
            } else if (r[3] == 'W') {
                printf("PROGRAMME : SOFTWARE SYSTEMS\n");
            } else if (r[3] == 'C') {
                printf("PROGRAMME : CYBER SECURITY\n");
            } else {
                printf("DOES NOT BELONG TO AMCS DEPARTMENT\n");
                exit(0);
            }
            printf("BATCH : 20%c%c\n", r[0], r[1]);
            scanf("%d", &opp);
            switch (opp) {
                case (-1): {
                    sleep(1);
                    system("clear");
                    studentinfo(fp);
                    break;
                }
                default: {
                    break;
                }
            }
            break;
        }
        case (2): {
            fclose(fp);
            fp = fopen("stud.txt", "w");
            printf("\n");
            sleep(0.1);
            system("clear");
            printf("\t\t\tCHANGE PASSWORD (DON'T FORGET AGAIN !)\n\n");
            printf("CURRENT PASSWORD : ");
            scanf("%s", mw.pass);
            fseek(fp, v * sizeof(struct sname), 0);
            fread(&bw, sizeof(struct sname), 1, fp);
            if (!strcmp(mw.pass, bw.pass)) {
                printf("ENTER NEW PASSWORD : ");
                scanf("%s", mw.pass);
                printf("RE-ENTER NEW PASSWORD : ");
                scanf("%s", mw.pass);
                strcpy(bw.pass, mw.pass);
                fseek(fp, -1 * sizeof(struct sname), 1);
                fwrite(&bw, sizeof(struct sname), 1, fp);
                fclose(fp);
                fp = fopen("stud.txt", "a+");
            } else {
                printf("THE PASSWORD ENTERED IS INCORRECT !\n");
            }
            scanf("%d", &opp);
            switch (opp) {
                case (-1): {
                    sleep(1);
                    system("clear");
                    studentinfo(fp);
                }
                default: {
                    break;
                }
            }
            break;
        }
        case (-1): {
            sleep(1);
            system("clear");
            home(fp);
            break;
        }
        default: {
            break;
        }
    }
}
void academic(FILE *fp) {
    printf("\t\t\tACADEMIC \n\n");
    printf("\t 1. TIME TABLE < > 2. LEAVE ENTRY\n");
    scanf("%d", &opp2);
    sleep(0.01);
    system("clear");
    switch (opp2) {
        case (1): {
            printf("PERIOD");
            for (int i = 1; i < 9; i++) {
                printf("\t %d \t", i);
            }
            printf("\n");
            printf("TIME ");
            float u = 8.30;
            for (int i = 1; i < 9; i++) {
                if (i == 2) {
                    printf(" %.2f-%.2f ", u, u + 0.9);
                    u += 1.1;
                } else if (i == 4) {
                    printf(" %.2f-%.2f ", u, u + 0.9);
                    u += 2.2 - 12;
                } else if (i == 6) {
                    printf(" %.2f-%.2f ", u, u + 0.9);
                    u++;
                } else {
                    if (u != 12.10) {
                        printf(" %.2f-%.2f ", u, u + 0.9);
                        u += 0.9;
                    }
                }
            }
            if (r[3] == 'T') {
                printf("TIME TABLE(THEORETICAL COMPUTER SCIENCE)\n");
                printf("\n");
                printf("MON 23XT11 23XT14 23XT16 23XT16 23XT15 23XT12 23XT13\n");
                printf("TUE 23XT13 23XT12 23XT11 SMR 23XT14 23XT15\n");
                printf("WED 23XT13 23XT17 23XT17 23XT18 23XT18 23XT16 23XT16\n");
                printf("THU 23XT15 23XT12 23XT11 23XT14 23XT13 23XT11 TWM\n");
                printf("FRI 23XT17 23XT17 23XT11 23XT14 23XT15 23XT18 23XT18\n");
                printf("\n23XT11-CALCULUS AND ITS APPLICATIONS\n23XT12-ENGLISH FOR PROFESSIONAL SKILLS\n23XT13-APPLIED PHYSICS\n23XT14-DIGITAL ELECTRONICS\n23XT15- PROBLEM SOLVING AND C PROGRAMMING\n23XT16-APPLIED PHYSICS AND DIGITAL ELECTRONICS LAB\n23XT17-C PROGRAMMING LAB\n23XT18-MATHEMATICS LABORATORY\n\n");
            } else if (r[3] == 'D') {
                printf("PROGRAMME : DATA SCIENCE\n");
                printf("\n");
                printf("MON 23XD17 23XD17 23XD15 23XD12 23XD14 23XD11\n");
                printf("TUE 23XD16 23XD16 23XD13 23XD14 23XD11 23XD15 23XD12\n");
                printf("WED 23XD13 SMR 23XD11 23XD11 23XD12 23XD12 23XD15\n");
                printf("THU 23XD11 23XD13 23XD16 23XD16 23XW12 23XD13 23XD14\n");
                printf("FRI 23XD18 23XD18 23XD17 23XD17 23XD14 TWM\n");
                printf("\n23XD11-CALCULUS AND ITS APPLICATIONS\n23XD12-COMPUTATIONAL BIOLOGY\n23XD13-DIGITAL ELECTRONICS\n23XD14-PROBLEM SOLVING AND C PROGRAMMING\n23XD15-ENGLISH FOR PROFESSIONAL SKILLS\n23XD16-MATHEMATICAL FOUNDATION LAB\n23XD17-C PROGRAMMING LAB\n23XD18-DIGITAL ELECTRONICS LAB\n\n");
            } else if (r[3] == 'W') {
                printf("PROGRAMME : SOFTWARE SYSTEMS\n");
                printf("\n");
                printf("MON 23XW18 23XW18 23XW13 23XW11 23XW15 TWM 23XW12\n");
                printf("TUE 23XW17 23XW17 23XW15 23XW14 23XW16 23XW16 23XW13\n");
                printf("WED 23XW14 23XW15 23XW16 23XW16 23XW18 23XW18 23XW11\n");
                printf("THU 23XW12 23XW11 23XW11 23XW13 SMR 23XW14\n");
                printf("FRI 23XW13 23XW14 23XW17 23XW17 23XW12 23XW15 23XW11\n");
                printf("\n23XW11-CALCULUS AND ITS APPLICATIONS\n23XW12-ENGLISH FOR PROFESSIONAL SKILLS\n23XW13-APPLIED PHYSICS\n23XW14-DIGITAL ELECTRONICS\n23XW15-C PROGRAMMING\n23XW16-APPLIED PHYSICS AND DIGITAL ELECTRONICS LAB\n23XW17-C PROGRAMMING LAB\n23XW18-MATHEMATICAL FOUNDATION LAB\n\n");
            } else if (r[3] == 'C') {
                printf("PROGRAMME : CYBER SECURITY\n");
                printf("\n");
                printf("MON 23XC17 23XC17 23XC15 23XC14 23XC11 TWM\n");
                printf("TUE 23XC12 23XC14 23XC16 23XC16 23XC13 SMR\n");
                printf("WED 23XC15 23XC13 23XC12 23XC14 23XC11 23XC13 23XC14\n");
                printf("THU 23XC17 23XC17 23XC11 23XC11 23XC15 23XC12 23XC13\n");
                printf("FRI 23XC16 23XC16 23XC18 23XC18 23XC15 23XC14 23XC11\n");
                printf("\n23XC11-CALCULUS AND ITS APPLICATIONS\n23XC12-ENGLISH FOR PROFESSIONAL SKILLS\n23XC13-APPLIED PHYSICS\n23XC14-DIGITAL ELECTRONICS\n23XC15-PROBLEM SOLVING AND C PROGRAMMING\n23XC16- MATHEMATICAL FOUNDATION LAB\n23XC17-C PROGRAMMING LAB\n23XC18-APPLIED PHYSICS AND DIGITAL ELECTRONICS LAB\n\n");
            }
            scanf("%d", &opp);
            switch (opp) {
                case (-1): {
                    sleep(1);
                    system("clear");
                    academic(fp);
                    break;
                }
                default: {
                    break;
                }
            }
            break;
        }
        case (2): {
            printf("\t\t\tSTUDENT LEAVE ENTRY\n");
            fseek(fp, v * sizeof(struct sname), 0);
            fread(&bw, sizeof(struct sname), 1, fp);
            printf("ROLL NUMBER : %s\n", bw.name);
            if (r[3] == 'T') {
                printf("PROGRAMME : THEORETICAL COMPUTER SCIENCE\n");
            } else if (r[3] == 'D') {
                printf("PROGRAMME : DATA SCIENCE\n");
            } else if (r[3] == 'W') {
                printf("PROGRAMME : SOFTWARE SYSTEMS\n");
            } else {
                printf("PROGRAMME : CYBER SECURITY\n");
            }
            printf("LEAVE START DATE : ");
            scanf("\n%s", H);
            printf("LEAVE END DATE : ");
            scanf("\n%s", H1);
            printf("LEAVE TYPE(1.LEAVE 2.MEDICAL 3.EXEMPTION) : ");
            scanf("\n%d", &j);
            sleep(0.01);
            system("clear");
            printf("\t\t\tSTUDENT LEAVE ENTRY\n");
            printf("ROLLNO : %s\n", bw.name);
            if (r[3] == 'T') {
                printf("PROGRAMME : THEORETICAL COMPUTER SCIENCE\n");
            } else if (r[3] == 'D') {
                printf("PROGRAMME : DATA SCIENCE\n");
            } else if (r[3] == 'W') {
                printf("PROGRAMME : SOFTWARE SYSTEMS\n");
            } else {
                printf("PROGRAMME : CYBER SECURITY\n");
            }
            printf("LEAVE START DATE : %s\n", H);
            printf("LEAVE END DATE : %s\n", H1);
            printf("LEAVE TYPE : ");
            switch (j) {
                case (1): {
                    printf("LEAVE");
                    break;
                }
                case (2): {
                    printf("MEDICAL");
                    break;
                }
                case (3): {
                    printf("EXEMPTION");
                    break;
                }
                default: {
                    printf("ENTERED WRONG OPTION");
                    academic(fp);
                    break;
                }
            }
            sleep(2);
            system("clear");
            printf("\t\t\t\tLEAVE APPLIED\n");
            scanf("\n%[^\n]s", str);
            scanf("\n%d", &opp);
            switch (opp) {
                case (-1): {
                    sleep(1);
                    system("clear");
                    academic(fp);
                    break;
                }
                default: {
                    break;
                }
            }
            break;
        }
        case (-1): {
            sleep(2);
            system("clear");
            home(fp);
            break;
        }
        default: {
            break;
        }
    }
}
int main() {
    FILE *fp;
    fp = fopen("stud.txt", "a+");
    int a, x;
    printf("\t\t\tPSG COLLEGE OF TECHNOLOGY LITE\n\n");
    printf("\t\t 1.LOGIN < > 2.NEW ACCOUNT\n");
    sleep(4);
    system("clear");
    scanf("%d", &a);
    sleep(0.1);
    system("clear");
    if (a == 1) {
        x = login(fp);
    } else if (a == 2) {
        newacc(fp);
        x = login(fp);
    }
    switch (x) {
        case (0):
            home(fp);
    }
    printf("\n");
    sleep(3);
    system("clear");
    printf("PLEASE VISIT PSG COLLEGE OF TECHNOLOGY LITE WEB AGAIN !");
    return 0;
}
