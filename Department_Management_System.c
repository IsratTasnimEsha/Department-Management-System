/// bismillahir rahmanir rahim

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ll long long
#define dl double
#define ch char

#define cll(n) \
    ll n;      \
    scanf("%lld", &n);
#define cn(n) scanf("%lld", &n);
#define cnd(n) scanf("%lf", &n);
#define cns(n) scanf("%s", n);
#define cnc(n) scanf("%c", &n);

#define ct(n) printf("%lld", n);
#define ctd(n) printf("%lf", n);
#define cts(n) printf("%s", n);
#define ctc(n) printf("%c", n);

#define f(m, i, n) for (ll i = m; i < n; i++)
#define fr(m, i, n) for (ll i = n - 1; i >= m; i--)

#define yes printf("YES\n");
#define no printf("NO\n");

#define space printf(" ");
#define bye printf("\n");

/*
1.	Admin Panel.
2.	Teacher�s Panel.
3.	Student�s Portal.

Admin Panel:
1.	Login using Function + File
2.	Create Teacher and student Structure
3.	Create Teacher and student account using Function+ ___
4.	Updating Teachers & students Information using Function +  Pointer + File
5.	Assigning total_courses to teachers and updating it using Function + File

Teacher�s Panel:
1.	Login using Function + File
2.	Provide class test marks using Function+ File
3.	Find the student by the given first name using Function+ File + pointer
4.	Count of Students using Function+ File

Student�s Panel:
1.	Login using Function+ File
2.	Check the class test marks using Function+ File
*/

FILE *_info = NULL;
ll course_code, temp = 0;
ll total_courses[32];

/// Admin Login using Function + File

void _Login(ch _username[], ch _password[])
{
    puts("Admin Username is given in line 141.\nAdmin Password is given in line 142.\n");
    fflush(stdin);

    /// Username:

    ch *get_username = NULL;
    get_username = (ch *)malloc(32 * sizeof(ch));

    // saving  username in file.
    _info = fopen("Admin_Panel.text", "ab");

    fprintf(_info, "%s", "UserName: ");
    fprintf(_info, "%s\n", _username);

    fclose(_info);

    // getting username from user.
Username:
{
    puts("USERNAME: ");
    fflush(stdin);
    cns(get_username);
    bye;
}

    // checking whether password is right.
    while (strcmp(get_username, _username) != 0)
    {
        puts("\aCan't find your account.\n");
        fflush(stdin);

        goto Username;
    }

    free(get_username);

    /// Password:

    ch *get_password = NULL;

    get_password = (ch *)malloc(32 * sizeof(ch));

    // saving  password in file
    _info = fopen("Admin_Panel.text", "ab");

    fprintf(_info, "%s", "Password: ");
    fprintf(_info, "%s\n", _password);

    fclose(_info);

    // getting password from user.
Password:
{
    puts("PASSWORD: ");
    fflush(stdin);
    cns(get_password);
    bye;
}

    // checking whether password is right.
    while (strcmp(get_password, _password) != 0)
    {
        puts("\aWrong Password. Try again.\n");
        fflush(stdin);

        goto Password;
    }

    free(get_password);
}

void admin_login()
{
    system("cls");

    // Admin username and password are fixed.
    ch _username[] = "asdf";
    ch _password[] = "zxcv";

    _Login(_username, _password);

    system("cls");

    admin_panel();
}

void admin_panel()
{
    system("cls");

    printf("%50s----------WELCOME TO ADMIN PANEL----------\n\n\n", " ");

    while (1)
    {
        puts("Press 1 for add course codes.\nPress 2 for course informations.\nPress 3 for Teacher Informations.");
        puts("Press 4 for Student Informations.\nPress 5 for add teacher in Teacher_Panel.");
        puts("Press 6 for add student in Student_Panel.\nPress 7 for update Teacher_Panel.");
        puts("Press 8 for update Student_Panel.\nPress 9 for Student_Marks.\nPress 0 for Home Menu.\nPress any other for leave.\nPress: ");

        ll num2;
        cn(num2);

        system("cls");

        if (num2 == 0)
        {
            admin_panel();
        }

        else if (num2 == 1)
        {
            add_course_code();
        }

        else if (num2 == 2)
        {
            course_infomations();
            for_admin_account();
        }

        else if (num2 == 3)
        {
            teacher_input_display();
            for_admin_account();
        }

        else if (num2 == 4)
        {
            student_input_display();
            for_admin_account();
        }

        else if (num2 == 5)
        {
            teacher_input();
        }

        else if (num2 == 6)
        {
            student_input();
        }

        else if (num2 == 7)
        {
            Update_teacher_info();
        }

        else if (num2 == 8)
        {
            Update_student_info();
        }

        else if (num2 == 9)
        {
            student_marks_info();
        }

        else
        {
            main();
        }
    }
}

void for_admin_account()
{
    puts("\nPress 0 for Home Menu.\nPress any other number for Home Page.");
    fflush(stdin);

    ll num6;
    cn(num6);

    if (num6 == 0)
    {
        admin_panel();
    }

    else
    {
        main();
    }
}

/// Creating Teacher and student Structure

typedef struct TeacherInfo
{
    ch first_name[32];
    ch last_name[32];
    ch academic_rank[32];
    ll course[32];  // for Part-1 of a course
    ll course2[32]; // for Part-2 of a course
    ll course_part[32];
    ch username[32];
    ch password[32];
    ch mobile_no[32];
} teacher;

teacher teacher_array;

typedef struct StudentInfo
{
    ch first_name[32];
    ch last_name[32];
    ch student_id[32];
    ch username[32];
    ch password[32];
    ll course[32];
    ll class_test_marks[32];  // for Part-1 of a course
    ll class_test_marks2[32]; // for Part-2 of a course
} student;

student student_array;

/// Creating Teacher and student account using Function+ __

void teacher_account()
{
    system("cls");

    printf("%50s----------WELCOME TO TEACHER PANEL----------\n\n", " ");

    info_of_teacher();

    teacher_course();

    while (1)
    {
        printf("\nPress 1 for student information.\nPress 2 for provide mark.\nPress 3 for search student.\n");
        fflush(stdin);
        puts("Press 4 for count student.\nPress 0 for Home Menu.\nPress any other for Home Page.\nPress: ");
        fflush(stdin);
        cll(num3);

        if (num3 == 0)
        {
            teacher_account();
        }

        else if (num3 == 1)
        {
            student_info();
            for_teacher_account();
        }

        else if (num3 == 2)
        {
            provide_mark();
        }

        else if (num3 == 3)
        {
            search_student();
            for_teacher_account();
        }

        else if (num3 == 4)
        {
            count_student();
        }

        else
        {
            main();
        }
    }
}

void teacher_course()
{
    total_course();

    f(1, i, temp)
    {
        if (teacher_array.course_part[i] == 1)
        {
            printf("Course-%lld: %lld-1\n", i, total_courses[teacher_array.course[i]]); // printing serial no. and course codes(part-1) for a teacher
        }

        else if (teacher_array.course_part[i] == 2)
        {
            printf("Course-%lld: %lld-2\n", i, total_courses[teacher_array.course2[i]]); // printing serial no. and course codes(part-2) for a teacher
        }
    }
}

void for_teacher_account()
{
    puts("\nPress 0 for Home Menu.\nPress any other number for Home Page.");
    fflush(stdin);
    cll(num6);

    if (num6 == 0)
    {
        teacher_account();
    }

    else
    {
        main();
    }
}

void student_account()
{
    system("cls");

    printf("%50s----------WELCOME TO STUDENT PANEL----------\n\n", " ");

    info_of_student();

    puts("Courses:");
    fflush(stdin);

    total_course();

    ll i = 1;

    while (student_array.course[i] != 0)
    {
        printf("%lld\n", total_courses[student_array.course[i]]);
        i++;
    }
    bye;

    while (1)
    {
        puts("Press 1 for student information.\nPress any other for Home Page.\nPress: ");
        fflush(stdin);
        cll(num3);

        if (num3 == 1)
        {
            Student_Info();
            for_student_account();
        }

        else
        {
            main();
        }
    }
}

void for_student_account()
{
    puts("\nPress 0 for Home Menu.\nPress any other number for Home Page.");
    fflush(stdin);
    cll(num6);

    if (num6 == 0)
    {
        student_account();
    }

    else
    {
        main();
    }
}

/// Updating Teachers & students Information using Function +  Pointer + File

void Update_teacher_info()
{
    ch *search = NULL;
    search = (ch *)malloc(32 * sizeof(ch));

    ll flag = 0;

    total_course();

    printf("Teacher's First Name(If identical) or Mobile Number: ");
    fflush(stdin);
    gets(search);

    course_infomations();

    _info = fopen("Teacher_Part.text", "rb+");

    while (fread(&teacher_array, sizeof(teacher_array), 1, _info) == 1)
    {
        // comparing teacher's first name and search string
        if (strcmpi(teacher_array.first_name, search) == 0 || strcmpi(teacher_array.mobile_no, search) == 0)
        {
            flag = 1;

            puts("\nOld Informations: ");
            fflush(stdin);

            info_of_teacher();

            f(1, i, temp)
            {
                if (teacher_array.course_part[i] == 1)
                {
                    if (total_courses[teacher_array.course[i]] != 0)
                    {
                        printf("Course: %lld-1\n", total_courses[teacher_array.course[i]]); // printing course code(part-1)
                    }
                }

                else if (teacher_array.course_part[i] == 2)
                {
                    if (total_courses[teacher_array.course2[i]] != 0)
                    {
                        printf("Course: %lld-2\n", total_courses[teacher_array.course2[i]]); // printing course code(part-2)
                    }
                }
            }

            puts("\nPress 1 to update first_name.\nPress any other number to skip.");
            fflush(stdin);
            cll(num1);
            bye;

            if (num1 == 1)
            {
                t_first_name(); // t_ = teacher
            }

            puts("Press 1 to update last_name.\nPress any other number to skip.");
            fflush(stdin);
            cll(num2);
            bye;

            if (num2 == 1)
            {
                t_last_name();
            }

            puts("Press 1 to update academic_rank.\nPress any other number to skip.");
            fflush(stdin);
            cll(num3);
            bye;

            if (num3 == 1)
            {
                t_academic_rank();
            }

            puts("Press 1 to update username.\nPress any other number to skip.");
            fflush(stdin);
            cll(num4);
            bye;

            if (num4 == 1)
            {
                t_username();
            }

            puts("Press 1 to update password.\nPress any other number to skip.");
            fflush(stdin);
            cll(num5);
            bye;

            if (num5 == 1)
            {
                t_password();
            }

            puts("Press 1 to update mobile number.\nPress any other number to skip.");
            fflush(stdin);
            cll(num6);
            bye;

            if (num6 == 1)
            {
                t_mobile_number();
            }

            puts("Press 1 to update course_code.\nPress any other number to skip.");
            fflush(stdin);
            cll(num7);
            bye;

            if (num7 == 1)
            {
                t_course_code();
            }

            fseek(_info, -(sizeof(teacher_array)), 1);               // 1 step back
            fwrite(&teacher_array, sizeof(teacher_array), 1, _info); // teacher informations are updated successfully

            fclose(_info);
        }
    }

    if (flag == 0)
    {
        puts("\nNo teacher matched.\n");
        fflush(stdin);
    }

    free(search);
}

void t_first_name()
{
    puts("New First Name: ");
    fflush(stdin);

    ch first_name[32];
    gets(first_name);
    get_new_first_name(&first_name);

    bye;
}

void t_last_name()
{
    puts("New Last Name: ");
    fflush(stdin);

    ch last_name[32];
    gets(last_name);
    get_new_last_name(&last_name);

    bye;
}

void t_academic_rank()
{
    puts("New Academic Rank: ");
    fflush(stdin);

    ch academic_rank[32];
    gets(academic_rank);
    get_new_academic_rank(&academic_rank);

    bye;
}

void t_username()
{
    puts("New Username: ");
    fflush(stdin);

    ch username[32];
    gets(username);
    get_new_username(&username);

    bye;
}

void t_password()
{
    puts("New Password: ");
    fflush(stdin);

    ch password[32];
    gets(password);
    get_new_password(&password);

    bye;
}

void t_mobile_number()
{
    puts("New Mobile Number: ");
    fflush(stdin);

    ch mobile_no[32];
    gets(mobile_no);
    get_new_mobile_no(&mobile_no);

    bye;
}

/// Updating teachers assigned total courses using Function + File

void t_course_code()
{
    puts("Press 0 for stop updating course code. Else enter course code.");
    fflush(stdin);
    bye;

    f(1, i, temp)
    {
        puts("New Part:");
        fflush(stdin);

        puts("Press 1 for Part-1.\nPress 2 for Part-2.\nPress any other for Home Menu.");
        fflush(stdin);
        cn(teacher_array.course_part[i]);
        bye;

        puts("New Course:");
        fflush(stdin);

        if (teacher_array.course_part[i] == 1)
        {
            cn(teacher_array.course[i]); // getting course serial no. for part-1
        }

        else if (teacher_array.course_part[i] == 2)
        {
            cn(teacher_array.course2[i]); // getting course serial no. for part-2
        }

        else
        {
            break;
        }
        bye;
    }
}

void info_of_teacher()
{
    printf("Name: %s %s\n", teacher_array.first_name, teacher_array.last_name);
    printf("Academic Rank: %s\n", teacher_array.academic_rank);
    printf("Username: %s\n", teacher_array.username);
    printf("Password: %s\n", teacher_array.password);
    printf("Mobile Number: %s\n\n", teacher_array.mobile_no);
}

void get_new_first_name(ch (*first_name)[])
{
    strcpy(teacher_array.first_name, *first_name);
}

void get_new_last_name(ch (*last_name)[])
{
    strcpy(teacher_array.last_name, *last_name);
}

void get_new_academic_rank(ch (*academic_rank)[])
{
    strcpy(teacher_array.academic_rank, *academic_rank);
}

void get_new_username(ch (*username)[])
{
    strcpy(teacher_array.username, *username);
}

void get_new_password(ch (*password)[])
{
    strcpy(teacher_array.password, *password);
}

void get_new_mobile_no(ch (*mobile_no)[])
{
    strcpy(teacher_array.mobile_no, *mobile_no);
}

void Update_student_info()
{
    ch *search = NULL;
    search = (ch *)malloc(32 * sizeof(ch));

    ll flag = 0;

    puts("Student's ID: ");
    fflush(stdin);
    gets(search);

    course_infomations();

    _info = fopen("Student_Part.text", "rb+");

    while (fread(&student_array, sizeof(student_array), 1, _info) == 1)
    {
        if (strcmpi(student_array.student_id, search) == 0)
        {
            flag = 1;

            puts("\nOld Informations: ");
            fflush(stdin);

            info_of_student();

            puts("Press 1 to update first_name.\nPress any other number to skip.");
            fflush(stdin);
            cll(num1);
            bye;

            if (num1 == 1)
            {
                s_first_name(); // s_ = student
            }

            puts("Press 1 to update last_name.\nPress any other number to skip.");
            fflush(stdin);
            cll(num2);
            bye;

            if (num2 == 1)
            {
                s_last_name();
            }

            puts("Press 1 to update ID.\nPress any other number to skip.");
            fflush(stdin);
            cll(num3);
            bye;

            if (num3 == 1)
            {
                s_ID();
            }

            puts("Press 1 to update username.\nPress any other number to skip.");
            fflush(stdin);
            cll(num4);
            bye;

            if (num4 == 1)
            {
                s_username();
            }

            puts("Press 1 to update password.\nPress any other number to skip.");
            fflush(stdin);
            cll(num5);
            bye;

            if (num5 == 1)
            {
                s_password();
            }

            puts("Press 1 to update course_code.\nPress any other number to skip.");
            fflush(stdin);
            cll(num6);
            bye;

            if (num6 == 1)
            {
                s_course_code();
            }

            fseek(_info, -(sizeof(student_array)), 1);
            fwrite(&student_array, sizeof(student_array), 1, _info); // student informations are updated successfully.

            fclose(_info);
        }
    }

    if (flag == 0)
    {
        puts("\nNo student matched.\n");
        fflush(stdin);
    }

    free(search);
}

void s_first_name()
{
    puts("\nNew First Name: ");
    fflush(stdin);

    ch _first_name[32];

    gets(_first_name);
    _new_first_name(&_first_name);

    bye;
}

void s_last_name()
{
    puts("\nNew Last Name: ");
    fflush(stdin);

    ch _last_name[32];

    gets(_last_name);
    _new_last_name(&_last_name);

    bye;
}

void s_ID()
{
    puts("\nNew ID: ");
    fflush(stdin);

    ch _ID[32];

    gets(_ID);
    _new_ID(&_ID);

    bye;
}

void s_username()
{
    puts("\nNew Username: ");
    fflush(stdin);

    ch _username[32];

    gets(_username);
    _new_username(&_username);

    bye;
}

void s_password()
{
    puts("\nNew Password: ");
    fflush(stdin);

    ch _password[32];

    gets(_password);
    _new_password(&_password);

    bye;
}

void s_course_code()
{
    puts("Press 0 for stop updating course code. Else enter course code.");
    fflush(stdin);
    bye;

    f(1, i, 21)
    {
        puts("New Course:");
        fflush(stdin);

        cn(student_array.course[i]);

        if (student_array.course[i] == 0)
        {
            f(i, j, 21)
            {
                student_array.course[j] = 0;
            }
            break;
        }
        bye;
    }
}

void info_of_student()
{
    printf("Name: %s %s\n", student_array.first_name, student_array.last_name);
    printf("ID: %s\n", student_array.student_id);
    puts("Department: CSE");
    fflush(stdin);
    printf("Username: %s\n", student_array.username);
    printf("Password: %s\n\n", student_array.password);
}

void _new_first_name(ch (*_first_name)[])
{
    strcpy(student_array.first_name, *_first_name);
}

void _new_last_name(ch (*_last_name)[])
{
    strcpy(student_array.last_name, *_last_name);
}

void _new_ID(ch (*_ID)[])
{
    strcpy(student_array.student_id, *_ID);
}

void _new_username(ch (*username)[])
{
    strcpy(student_array.username, *username);
}

void _new_password(ch (*password)[])
{
    strcpy(student_array.password, *password);
}

/// Teacher's Login using Function + File

void teacher_login()
{
    system("cls");

    ch *get_username = NULL, *get_password = NULL;
    ;
    get_username = (ch *)malloc(32 * sizeof(ch));
    get_password = (ch *)malloc(32 * sizeof(ch));

TeacherLogin:
{
    ll flag = 0;

    puts("USERNAME: ");
    fflush(stdin);
    gets(get_username);
    bye;

    puts("PASSWORD: ");
    fflush(stdin);
    gets(get_password);
    bye;

    _info = fopen("Teacher_Part.text", "rb");

    while (fread(&teacher_array, sizeof(teacher_array), 1, _info))
    {
        // checking if teacher username and given name are same or not and teacher password and given password are same or not
        if (strcmpi(teacher_array.username, get_username) == 0 && strcmpi(teacher_array.password, get_password) == 0)
        {
            flag = 1;
            teacher_account();
            break;
        }
    }

    fclose(_info);

    if (flag == 0)
    {
        puts("\a\nInvalid.\n");
        fflush(stdin);
        goto TeacherLogin;
    }

    free(get_username);
    free(get_password);
}
}

/// Provide class test marks using Function+ File

void provide_mark()
{
    system("cls");

    teacher_course();

    puts("\nPress Course Serial No. to provide number.");
    fflush(stdin);

    cll(num4);

ProvideMark:
{
    bye;

    _info = fopen("Student_Part.text", "rb+");

    while (fread(&student_array, sizeof(student_array), 1, _info) == 1)
    {
        f(1, i, 21)
        {
            if (teacher_array.course_part[num4] == 1)
            {
                // checking if teacher's course code and student's course code are same or not
                if (total_courses[teacher_array.course[num4]] == total_courses[student_array.course[i]])
                {
                    if (student_array.class_test_marks[teacher_array.course[num4]] == -1) // class test marks are initially -1
                    {
                        info_of_student();

                        puts("\nMark: ");
                        fflush(stdin);

                        cn(student_array.class_test_marks[teacher_array.course[num4]]);

                        fseek(_info, -(sizeof(student_array)), 1);
                        fwrite(&student_array, sizeof(student_array), 1, _info); // marks are saved successfully

                        fclose(_info);
                    }
                }
            }

            if (teacher_array.course_part[num4] == 2)
            {
                // checking if teacher's course code and student's course code are same or not
                if (total_courses[teacher_array.course2[num4]] == total_courses[student_array.course[i]])
                {
                    if (student_array.class_test_marks2[teacher_array.course2[num4]] == -1) // class test marks are initially -1
                    {
                        info_of_student();

                        puts("\nMark: ");
                        fflush(stdin);

                        cn(student_array.class_test_marks2[teacher_array.course2[num4]]);

                        fseek(_info, -(sizeof(student_array)), 1);
                        fwrite(&student_array, sizeof(student_array), 1, _info); // marks are saved successfully

                        fclose(_info);
                    }
                }
            }
        }
    }

    puts("\nPress 1 for providing another marks for same course.\nPress any other number for Home Menu.");
    fflush(stdin);
    cll(num5);

    if (num5 == 1)
    {
        goto ProvideMark;
    }

    else
    {
        teacher_account();
    }
}
}

/// Find the student by the first name using Function+ File

void search_student()
{
    system("cls");

    ll flag = 0;

    ch *search = NULL;
    search = (ch *)malloc(32 * sizeof(ch));

    printf("Search by user name: ");
    fflush(stdin);
    gets(search);

    printf("%50s----------STUDENT INFORMATIONS----------\n\n\n", " ");
    printf("%s %20s %20s", "NAME", "STUDENT ID", "DEPARTMENT");

    total_course();

    f(1, i, temp)
    {
        if (teacher_array.course_part[i] == 1)
        {
            printf("%10sCourse:%lld-%lld", "", total_courses[teacher_array.course[i]], teacher_array.course_part[i]); // printing course code and course part
        }

        else if (teacher_array.course_part[i] == 2)
        {
            printf("%10sCourse:%lld-%lld", "", total_courses[teacher_array.course2[i]], teacher_array.course_part[i]); // printing course code and course part
        }
    }
    bye;

    _info = fopen("Student_Part.text", "rb");

    while (fread(&student_array, sizeof(student_array), 1, _info))
    {
        ch name[32];
        _name(&name);

        if (strcmpi(name, search) == 0)
        {
            flag = 1;

            printf("%s %s %20s %20s", name, student_array.last_name, student_array.student_id, "CSE");

            f(1, i, temp)
            {
                if (teacher_array.course_part[i] == 1)
                {
                    if (student_array.class_test_marks[teacher_array.course[i]] != -1)
                    {
                        printf("%20lld", student_array.class_test_marks[teacher_array.course[i]]); // printing class test marks for part-1
                    }
                    else
                    {
                        printf("%20s", " ");
                    }
                }

                else if (teacher_array.course_part[i] == 2)
                {
                    if (student_array.class_test_marks2[teacher_array.course2[i]] != -1)
                    {
                        printf("%20lld", student_array.class_test_marks2[teacher_array.course2[i]]); // printing class test marks for part-2
                    }
                    else
                    {
                        printf("%20s", " ");
                    }
                }
            }
            bye;
        }
    }

    fclose(_info);

    if (flag == 0)
    {
        printf("Search Not Found.\n");
    }

    free(search);
}

void _name(ch (*name)[])
{
    strcpy(*name, student_array.first_name);
}

/// Count of Students using Function+ File

void count_student()
{
    system("cls");

    ll count = 0;

    puts("Course Code:");
    cll(num3);

    _info = fopen("Student_Part.text", "rb");

    while (fread(&student_array, sizeof(student_array), 1, _info))
    {
        f(1, i, temp)
        {
            if (num3 == total_courses[student_array.course[i]] && total_courses[student_array.course[i]] != 0)
            {
                count++;
            }
        }
    }

    printf("\nNumber of students: %lld\n", count);

    puts("\nPress 1 for Student Count.\nPress any other number for Home Menu.");
    fflush(stdin);
    cll(num6);

    if (num6 == 1)
    {
        count_student();
    }

    else
    {
        teacher_account();
    }
}

/// Student Login using Function+ File

void student_login()
{
    system("cls");

    ch *get_username = NULL, *get_password = NULL;
    ;
    get_username = (ch *)malloc(32 * sizeof(ch));
    get_password = (ch *)malloc(32 * sizeof(ch));

StudentLogin:
{
    ll flag = 0;

    puts("USERNAME: ");
    fflush(stdin);
    gets(get_username);
    bye;

    puts("PASSWORD: ");
    fflush(stdin);
    gets(get_password);
    bye;

    _info = fopen("Student_Part.text", "rb");

    while (fread(&student_array, sizeof(student_array), 1, _info))
    {
        if (strcmpi(student_array.username, get_username) == 0 && strcmpi(student_array.password, get_password) == 0)
        {
            flag = 1;
            printf("\nName: %s %s\nID: %s\nDepartment: CSE\n", student_array.first_name, student_array.last_name,
                   student_array.student_id);

            student_account();
            break;
        }
    }

    fclose(_info);

    if (flag == 0)
    {
        puts("\aInvalid.\n");
        fflush(stdin);

        goto StudentLogin;
    }
}
}

/// Check the class test marks using Function+ File

void Student_Info()
{
    system("cls");

    total_course();

    printf("%50s----------COURSE WISE ACQUIRED MARKS----------\n\n\n", " ");
    printf("%77s %54s\n", "COURSE CODE", "ACQUIRED MARKS\n");

    f(1, i, temp)
    {
        if (student_array.class_test_marks[i] != -1 || student_array.class_test_marks2[i] != -1)
        {
            printf("%74lld-1 %51lld\n", total_courses[i], student_array.class_test_marks[i]);
            printf("%74lld-2 %51lld\n", total_courses[i], student_array.class_test_marks2[i]);
        }
    }
    bye;
}

/// Information of Teachers for Admin Panel

void teacher_input()
{
    f(1, i, temp)
    {
        teacher_array.course_part[i] = 0;
        teacher_array.course[i] = 0;
        teacher_array.course2[i] = 0;
    }

    course_infomations();

    _info = fopen("Teacher_Part.text", "ab");

    puts("\nTeacher's First Name: ");
    fflush(stdin);
    gets(teacher_array.first_name);

    puts("\nTeacher's Last Name: ");
    fflush(stdin);
    gets(teacher_array.last_name);

    puts("\nAcademic Rank: ");
    fflush(stdin);
    gets(teacher_array.academic_rank);

    puts("\nUsername: ");
    fflush(stdin);
    gets(teacher_array.username);

    puts("\nPassword: ");
    fflush(stdin);
    gets(teacher_array.password);

    puts("\nMobile Number: ");
    fflush(stdin);
    gets(teacher_array.mobile_no);

    bye;

    puts("Courses:");
    fflush(stdin);

    /// Assigning total_courses to teachers using Function + File

    f(1, i, 21)
    {
        puts("\nPress 1 for part 1.\nPress 2 for part 2.\nPrint any other number to stop taking courses.\n");
        fflush(stdin);
        cn(teacher_array.course_part[i]);

        if (teacher_array.course_part[i] == 1)
        {
            puts("\nCourse Code Serial Number:");
            cn(teacher_array.course[i]);
        }

        else if (teacher_array.course_part[i] == 2)
        {
            puts("\nCourse Code Serial Number:");
            cn(teacher_array.course2[i]);
        }

        else
        {
            f(i, j, 21)
            {
                teacher_array.course[j] = 0;
                teacher_array.course2[j] = 0;
            }
            break;
        }
    }

    bye;

    fwrite(&teacher_array, sizeof(teacher_array), 1, _info); // teacher informations are saved successfully
    fclose(_info);

    puts("Press 1 for add another teacher.\nPress any other number for Home Menu.\n");
    fflush(stdin);
    cll(num8);

    if (num8 == 1)
    {
        system("cls");

        teacher_input();
    }

    else
    {
        admin_panel();
    }
}

void teacher_input_display()
{
    system("cls");

    printf("%50s----------TEACHER INFORMATIONS----------\n\n\n", " ");
    printf("%s %17s %15s %15s %15s %5s", "NAME", "ACADEMIC RANK", "USERNAME", "PASSWORD", "MOBILE", " ");

    total_course();

    f(1, i, temp)
    {
        printf("%12s-%lld", "COURSE", i);
    }
    bye;
    bye;

    _info = fopen("Teacher_Part.text", "rb");

    while (fread(&teacher_array, sizeof(teacher_array), 1, _info))
    {
        printf("%s %s %15s %15s %15s %15s %5s", teacher_array.first_name, teacher_array.last_name,
               teacher_array.academic_rank, teacher_array.username, teacher_array.password, teacher_array.mobile_no, " ");

        f(1, i, temp)
        {
            if (teacher_array.course_part[i] == 1)
            {
                printf("%13lld-%lld", total_courses[teacher_array.course[i]], teacher_array.course_part[i]); // printing course code(part-1)
            }

            else if (teacher_array.course_part[i] == 2)
            {
                printf("%13lld-%lld", total_courses[teacher_array.course2[i]], teacher_array.course_part[i]); // printing course code(part-1)
            }
        }
        bye;
    }
    bye;

    fclose(_info);
}

/// Information of Students for Admin Panel

void student_input()
{
    course_infomations();

    _info = fopen("Student_Part.text", "ab");

    puts("\nStudent's First Name: ");
    fflush(stdin);
    gets(student_array.first_name);

    puts("\nStudent's Last Name: ");
    fflush(stdin);
    gets(student_array.last_name);

    puts("\nStudent ID: ");
    fflush(stdin);
    gets(student_array.student_id);

    puts("\nUsername: ");
    fflush(stdin);
    gets(student_array.username);

    puts("\nPassword: ");
    fflush(stdin);
    gets(student_array.password);

    bye;

    puts("\nCourses: ");
    fflush(stdin);

    puts("\nPress 0 for stop taking courses. Else enter Serial No. of Course Code.\n");

    f(1, i, 21)
    {
        puts("\nSerial No. of Course Code: ");

        cn(student_array.course[i]);
        if (student_array.course[i] == 0)
        {
            f(i, j, 21)
            {
                student_array.course[j] = 0;
            }
            break;
        }
    }

    f(1, i, 21)
    {
        student_array.class_test_marks[i] = -1; // class test marks initialization for part-1
    }

    f(1, i, 21)
    {
        student_array.class_test_marks2[i] = -1; // class test marks initialization for part-1
    }

    bye;

    fwrite(&student_array, sizeof(student_array), 1, _info); // student informations are saved successfully
    fclose(_info);

    puts("Press 1 for add another student.\nPress any other number for Home Menu.\n");
    fflush(stdin);
    cll(num8);

    if (num8 == 1)
    {
        system("cls");

        student_input();
    }

    else
    {
        admin_panel();
    }
}

void student_input_display()
{
    system("cls");

    printf("%50s----------STUDENT INFORMATIONS----------\n\n\n", " ");
    printf("%s %15s %15s %15s %15s", "NAME", "STUDENT ID", "DEPARTMENT", "USERNAME", "PASSWORD");

    total_course();

    f(1, i, temp)
    {
        printf("%11s:%lld", "COURSE", i);
    }
    bye;
    bye;

    _info = fopen("Student_Part.text", "rb");

    while (fread(&student_array, sizeof(student_array), 1, _info))
    {
        printf("%s %s %15s %15s %15s %15s", student_array.first_name, student_array.last_name, student_array.student_id,
               "CSE", student_array.username, student_array.password, " ");

        f(1, i, temp)
        {
            if (total_courses[student_array.course[i]] != 0)
            {
                printf("%13lld", total_courses[student_array.course[i]]);
            }
        }
        bye;
    }
    bye;

    fclose(_info);
}

void student_marks_info()
{
    system("cls");

    printf("%50s----------STUDENT MARKS INFORMATIONS----------\n\n\n", " ");
    printf("%s %15s %15s", "NAME", "STUDENT ID", "DEPARTMENT");

    total_course();

    f(1, i, temp)
    {
        printf("%13lld-1", total_courses[i]); // printing all Course Code(part-1)
        printf("%13lld-2", total_courses[i]); // printing all Course Code(part-2)
    }
    bye;
    bye;

    _info = fopen("Student_Part.text", "rb");

    while (fread(&student_array, sizeof(student_array), 1, _info))
    {
        printf("%s %s %15s %15s", student_array.first_name, student_array.last_name, student_array.student_id, "CSE");

        f(1, i, temp)
        {
            if (student_array.class_test_marks[i] != -1)
            {
                printf("%15lld", student_array.class_test_marks[i]); // printing student marks(part-1)
            }

            else
            {
                printf("%15s", " ");
            }

            if (student_array.class_test_marks2[i] != -1)
            {
                printf("%15lld", student_array.class_test_marks2[i]); // printing student marks(part-2)
            }

            else
            {
                printf("%15s", " ");
            }
        }
        bye;
    }
    bye;
    bye;
}

/// Course Codes for Admin Panel

void add_course_code()
{
    _info = fopen("Course_Code.text", "ab");

    puts("\nCourse Code.: ");
    fflush(stdin);
    cn(course_code);

    fwrite(&course_code, sizeof(course_code), 1, _info);
    fclose(_info);

    puts("\nPress 1 for add course.\nPress 0 for Home Menu.\nPress any other number for Home Page.\n\nPress: ");
    fflush(stdin);
    cll(num7);

    if (num7 == 0)
    {
        admin_panel();
    }

    else if (num7 == 1)
    {
        add_course_code();
    }

    else
    {
        main();
    }
}

void total_course()
{
    ll count = 1;

    _info = fopen("Course_Code.text", "rb");

    while (fread(&course_code, sizeof(course_code), 1, _info))
    {
        total_courses[count] = course_code;
        count++; // counting number of courses
    }

    temp = count;
}

void course_infomations()
{
    total_course();

    bye;

    printf("%50s----------COURSE INFOMATIONS----------\n\n\n", " ");
    printf("%76s %48s\n", "SERIAL NO.", "COURSE CODE\n");

    f(1, i, temp)
    {
        printf("%72lld %48lld\n\n", i, total_courses[i]); // printing serial no. and course codes
    }
}

/// Information of Students for Teacher Panel

void student_info()
{
    system("cls");

    printf("%50s----------STUDENT INFORMATIONS----------\n\n\n", " ");
    printf("%s %20s %20s", "NAME", "STUDENT ID", "DEPARTMENT");

    total_course();

    f(1, i, temp)
    {
        if (teacher_array.course_part[i] == 1)
        {
            printf("%11sCourse:%lld-%lld", "", total_courses[teacher_array.course[i]], teacher_array.course_part[i]); // printing course codes(Part-1)
        }

        else if (teacher_array.course_part[i] == 2)
        {
            printf("%11sCourse:%lld-%lld", "", total_courses[teacher_array.course2[i]], teacher_array.course_part[i]); // printing course codes(Part-2)
        }
    }
    bye;
    bye;

    _info = fopen("Student_Part.text", "rb");

    while (fread(&student_array, sizeof(student_array), 1, _info))
    {
        printf("%s %s %20s %20s", student_array.first_name, student_array.last_name, student_array.student_id,
               "CSE");

        f(1, i, temp)
        {
            if (teacher_array.course_part[i] == 1)
            {
                if (student_array.class_test_marks[teacher_array.course[i]] != -1)
                {
                    printf("%21lld", student_array.class_test_marks[teacher_array.course[i]]); // class test marks for part-1
                }
                else
                {
                    printf("%21s", " ");
                }
            }

            else if (teacher_array.course_part[i] == 2)
            {
                if (student_array.class_test_marks2[teacher_array.course2[i]] != -1)
                {
                    printf("%21lld", student_array.class_test_marks2[teacher_array.course2[i]]); // class test marks for part-2
                }
                else
                {
                    printf("%21s", " ");
                }
            }
        }
        bye;
    }
}

/// Main Function

int main()
{
    system("cls");

    printf("%50s----------WELCOME TO DEPARTMENT MANAGEMENT SYSTEM----------\n\n\n", " ");
    puts("Please use the large screen.\n");
    fflush(stdin);

    puts("Press 1 if you are Admin.\nPress 2 if you are Teacher.\nPress 3 if you are Student.\nPress any other to exit.\n\nPress:");
    fflush(stdin);

    cll(num1);
    bye;

    if (num1 == 1)
    {
        admin_login();
    }

    else if (num1 == 2)
    {
        teacher_login();
    }

    else if (num1 == 3)
    {
        student_login();
    }

    else
    {
        exit(0);
    }

    return 0;
}