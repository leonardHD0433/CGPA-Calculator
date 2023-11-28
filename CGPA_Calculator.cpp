#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;

string courseID_pool[] = {"KBEN1033N", "MPU3323N", "MPU2183N","MPU3432N", "MPU2193N", "XBCS1043N", "XBCS1023N", "XBCS1183N","XBCS1103N","XBCS1053N","XBCS2143N", "XBCS1093N", "XBCS1063N", "XBCS3013N", "XBCS1073N", "XBCS2013N"};

string courseName_pool[] = {"Oral Communication", "Malaysia and Global Issues", "Penghayatan Etika dan Peradaban (PEP)", "Global Social Responsibility", "Falsafah dan Isu Semasa (FIS)", "Computing Mathematics", 
 "Fundamentaals of Programming", "Database Management & Security", "Discrete Mathematics", "Object Oriented System Analysis & Design", "Intelligent Systems", "Java Programming", "Computer Architecture", "Data Structures & Algorithms", "Data Communication & Networking", "Principles of Software Engineering"};

int courseNo[] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

int creditHour_pool[] = {3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3};

string grade[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D", "F"};

double grade_system[] = {4.00, 4.00, 3.67, 3.33, 3.00, 2.67, 2.33, 2.00, 1.00, 0.00};

int credit_hours[16] = {0}, sem_noSubject[16] = {0};
string course_name[16] = {" "}, course_id[16] = {" "}, grade_store[16] = {" "};
double grade_points[16] = {0.00}, semesterGpa[16] = {0.00};
int num = 0, course_storing = 0, num_semester = 0, totalCredit = 0, maxName_length = 0, transcript_no = 0, previous_subject = 0;
double totalGrade = 0.00, cgpa = 0.00;
bool valid = true;
string upperCase = " ", subject_confirm = " ", take_all = " ", final_transcript = " ", clear_history = " ", capture = " ", stud_name, stud_id;


void reset()
{
  num = 0, course_storing = 0, num_semester = 0, totalCredit = 0, maxName_length = 0, transcript_no = 0, previous_subject = 0, totalGrade = 0.00, cgpa = 0.00;
  valid = true, upperCase = " ", subject_confirm = " ", take_all = " ", final_transcript = " ", clear_history = " ", capture = " ";
  for(int i = 0; i < 16; i++)
  {
      credit_hours[i] = 0, sem_noSubject[i] = 0;
      course_name[i] = " ", course_id[i] = " ", grade_store[i] = " ";
      grade_points[i] = 0.00, semesterGpa[i] = 0.00;
      courseNo[i] = i + 1;
  }
}

void error()
{
  cout << "\nInvalid Input. Try Again.\n";
}

string confirm()
{
  upperCase = " ";
  getline(cin, upperCase);
  for(char& c : upperCase)   /*   Sravani S (2020) What is the use of the '&' symbol in C++? [source code] 
                                  https://www.tutorialspoint.com/What-is-the-use-of-the-and-symbol-in-Cplusplus (Date Accessed: 20/7/2023)
                                  
                                  Asked by:edjoker(2018) Answered by: Arnav Borborah(2018) the difference between for(char& c:s) and for(char c:s)? [source code] 
                                  https://stackoverflow.com/questions/48999260/the-difference-between-forchar-c-s-and-forchar-c-s (Date Accessed: 20/7/2023)
                             */
  {
    c = toupper(c);
    break;
  }
  return upperCase;
}

int string_int()
{
  capture = " ";
  num = 0;
  getline(cin, capture);
  valid = false;
  for(char c : capture)
    {
      if(!isdigit(c) || capture.empty())   /*  Programiz (n.d.) C <ctype.h> [article] 
                                               https://www.programiz.com/c-programming/library-function/ctype.h (Date Accessed: 29/7/2023)

                                               Code_r (2023) dot (.) operator in C++ [source code] 
                                               https://www.geeksforgeeks.org/list-empty-function-in-c-stl/  (Date Accessed: 1/8/2023)

                                               barykrg (2023) list empty() function in C++ STL
                                               https://www.geeksforgeeks.org/list-empty-function-in-c-stl/ (Date Accessed: 1/8/2023) 
                                           */
      {
        valid = true;
        break;
      }
    }
   stringstream ss;           /*  Dionysia Lemonaki (2021) String to Int in C++ – How to Convert a String to an Integer Example [source code] 
                                  https://www.freecodecamp.org/news/string-to-int-in-c-how-to-convert-a-string-to-an-integer-example/ (Date Accessed: 31/7/2023)
                              */
   ss << capture;
   ss >> num;
   return num;
}

inline void dash()
{
  for(int n = 0; n < 98; n++)
   {
     cout << "-";
   }
}

void displayCourseTable()
{
  cout << "\nCourse Table" << endl;
  dash();

  cout << "\nNo: \t" << "Course ID\t\t" <<  "Course Name" << endl;
  
  for(int p = 0; p < 16; p++)
   {
     if(courseNo[p] == 0)
     {
       continue;
     }
     else
     {
       if(p < 9)
       {
         cout << courseNo[p] << ". \t\t" << courseID_pool[p] << "\t\t" << courseName_pool[p] << endl;
       }
       else
       {
         cout << courseNo[p] << ". \t" << courseID_pool[p] << "\t\t" << courseName_pool[p] << endl;
       }
     }
   }
  dash();
  cout << endl;
}

inline void displayGradeTable()
{
  cout << "\nGrade Table\n";
  dash();
  cout << "\nGrade\tGrade Point\n";
  for(int q = 0; q < 10 ; q++)
    {
      cout << grade[q] << "\t\t" << grade_system[q] << endl;
    }
  dash();
  cout <<endl;
}

void thanks()
{
  cout << endl;
  dash();
  cout << "\nThanks for using our calculator. XD\n";
  dash();
  cout << endl;
}

void calculateCGPA() 
{
 if(course_storing != 0)
 {
   do
   {
      cout << "Look likes there is a previous history. Would you like to start a new input anyway? (Y/N)\n";
      clear_history = confirm();
      if(clear_history != "Y" && clear_history != "N")
      {
        error();
      }
   }while(clear_history != "Y" && clear_history != "N");
 }

 if(clear_history == "Y")
 {
   reset();
 }
 else if (clear_history == "N")
 {
   return;
 }
  
 cout << fixed << setprecision(2);
 string gradeInput;
 int num_subject = 0, courseID_input, semCredit = 0;
 double semGrade = 0.00;

 valid = true;
 do
 {
   cout << "\nHello student, please enter your name." << endl;
   getline(cin, stud_name);
   if (!stud_name.empty())
   {
     if(stud_name[0] != ' ')
     {
       if(stud_name.find("  ") == string::npos) /*  Mohit Sahay (2023) find() Function in C++ [source code] 
                                                    https://www.scaler.com/topics/cpp-find/ (Date Accessed: 1/8/2023)

                                                    aktmishra143 (2022) string::npos in C++ with Examples [source code]
                                                    https://www.geeksforgeeks.org/stringnpos-in-c-with-examples/ (Date Accessed: 1/8/2023)
                                                */
       {
         if(all_of(stud_name.begin(), stud_name.end(), [](char c){return isalpha(c) || isspace(c);}))  /*  GeeksforGeeks (2023) std::all_of() in C++ [source code]
                                                                                                           https://www.geeksforgeeks.org/stdall_of-in-cpp/ 
                                                                                                           (Date Accessed: 29/7/2023)
                                                                                                           
                                                                                                           GeeksforGeeks(2022) Lambda expression in C++ [source code]
                                                                                                           https://www.geeksforgeeks.org/lambda-expression-in-c/
                                                                                                           (Date Accessed: 29/7/2023)
                                                                                                       */
         {
           valid = false;
         }
         else
         {
           cout << "\nInvalid Input. Your name should only consist of letters." << endl;
         }
       }
       else
       {
         error();
       }
     }
     else
     {
       error();
     }
   }
   else
   {
     error();
   }

 }while(valid);

 valid = true;
 do
 {
  valid = false;
  cout << "\nPlease enter your student ID. (Your ID should only be 7 digits in total.)" << endl;
  getline(cin, stud_id);
  for(char c : stud_id)
    {
      if(!isdigit(c))
      {
        valid = true;
        break;
      }
    }
   if(valid)
   {
     cout << "\nInvalid Input. Student ID should only consist of digits.\n";
   }
   else
   {  
     if(stud_id.length() != 7)
     {
       if(stud_id.empty())
       {
         error();
         valid = true;
       }
       else
       {
          cout << "\nInvalid Input. Student ID should only be 7 digits.\n";
          valid = true;
       }
     }
   }
 }while(valid);

 valid = true;
 do
 {
   cout << "\nEnter the number of semesters you have taken: ";
   num_semester = string_int();
   
   if(valid)
   {
     error();
   }
   else
   {
     if (num_semester == 0)
           {
             error();
             valid = true;
           }
     
     if(num_semester > 16)
     {
       cout << "\nIt is unlikely you will exceed 16 se mesters for your entire programme.\n";
       valid = true;
     }
   }
 }while(valid);
     
 for(int i = 0; i < num_semester; i++)
 {
     valid = true;
     if(course_storing == 16)
     {
       num_semester = i;
       break;
     }
   
     do{
         cout << "Enter number of subjects you are taking for semester " << i+1 << ": ";
         num_subject = string_int();
     
         if(valid)
         {
           error();
         }
         else
         { 
           if (num_subject == 0)
           {
             error();
             valid = true;
           }
           else if(num_subject > 5)
           {
             cout << "You can only have 5 subjects at max for one semester.\n";
             valid = true;
           }
           else if (num_subject == (16 - course_storing))
           {
             take_all = "Y";
             sem_noSubject[i] = num_subject;
             num_semester = i + 1;
             cout << endl;
           }
           else if(num_subject > (16 - course_storing))
           {
             if(num_subject > 5)
             {
               cout << "You can only have 5 subjects at max for one semester.\n";
               valid = true;
             }
             else
             {
               cout << "You only have " << 16 - course_storing << " subjects left.\n";
               do
               {
                 cout << "Will you take all of them? (Y/N) ";
                 take_all = confirm();

                 if(take_all != "Y" && take_all != "N")
                 {
                   error();
                 }

                }while(take_all != "Y" && take_all != "N");

               if (take_all == "Y")
               {
                 num_subject = 16 - course_storing;
                 sem_noSubject[i] = num_subject;
                 num_semester = i + 1;
                 cout << endl;
               }
               else if(take_all == "N")
               {
                 valid = true;
               }
             }
           }
           else
           {
             sem_noSubject[i] = num_subject;
           }
         }
      }while(valid);


     if(take_all != "Y")
     {
       cout << "Semester " << i+1 << ":" << endl;
       cout << "\nBased on the course table, choose the subject that you will be taking by inputing the numbers given.\n(For example, press 1 to choose the subject Oral Communication.)\n";
       semGrade = 0;
       semCredit = 0;
       for(int j = course_storing; j < (course_storing + num_subject); j++)
       {
         do
         {
            displayCourseTable(); 
            valid = true;
            
            do
            {
              cout << "\nSubject " << j+1 << ": ";
              courseID_input = string_int();
   
              if(valid)
              {
                error();
                valid = true;
              }
              else
              {
                if(courseNo[courseID_input - 1] == 0)
                {
                  cout << "Choose the remaining subjects from the table above.\n";
                  valid = true;
                }
                else
                {
                  if(courseID_input > 16 || courseID_input == 0)
                  {
                    cout << "Choose the remaining subjects from the table above.\n";
                    valid = true;
                  }
                }
              }
             }while(valid);
         
            courseID_input --;
       
            dash();
            cout << "\nSubject " << j+1;
            cout << "\nCourse ID: " << courseID_pool[courseID_input] << "\nCourse Name: " << courseName_pool[courseID_input] << "\nCredit Hours: " << creditHour_pool[courseID_input] << endl;
            dash();

            subject_confirm = " ";
            do
            {
              cout << "\nConfirm subject selection? (Y/N): ";
              subject_confirm = confirm();

              if(subject_confirm != "Y" && subject_confirm != "N")
              {
                 error();
              }

            }while(subject_confirm != "Y" && subject_confirm != "N");

            if(subject_confirm == "Y")
            {
              course_id[j] = courseID_pool[courseID_input];
              course_name[j] = courseName_pool[courseID_input];
              credit_hours[j] = creditHour_pool[courseID_input];
              courseNo[courseID_input] = 0;
            }
       
          }while(subject_confirm != "Y");
     
         valid = false;
         do{
            displayGradeTable();
            cout << "\nEnter the grade received for subject " << courseName_pool[courseID_input] << ": ";
            gradeInput = confirm();
            for(int k = 0; k < 10; k++)
            {
             if(gradeInput == grade[k])
             { 
               grade_store[j] = gradeInput;
               grade_points[j] = grade_system[k]; 
               valid = true;
               break;
             }
            } 
        
            if (!valid || gradeInput.empty())
            {
             error();
            }
        
           }while(!valid);
         semGrade += grade_points[j]*credit_hours[j];
         semCredit += credit_hours[j];
         semesterGpa[i] = semGrade/semCredit;
         cout << endl;
       }
    } 
     else
     {
       semGrade = 0;
       semCredit = 0;
       for(int j = course_storing; j < (course_storing + num_subject); j++)
       {
         dash();
         cout << "\nSubject " << j+1;
         cout << "\nCourse ID: " << courseID_pool[j] << "\nCourse Name: " << courseName_pool[j] << "\nCredit Hours: " << creditHour_pool[j] << endl;
         dash();

         course_id[j] = courseID_pool[j];
         course_name[j] = courseName_pool[j];
         credit_hours[j] = creditHour_pool[j];
         courseNo[j] = 0;

         do
         {
           displayGradeTable();
           cout << "\nEnter the grade received for subject " << courseName_pool[j] << ": ";
           gradeInput = confirm();
           for(int k = 0; k < 10; k++)
           {
            if(gradeInput == grade[k])
            { 
              grade_store[j] = gradeInput;
              grade_points[j] = grade_system[k]; 
              valid = true;
              break;
            }
           } 
        
           if (!valid || gradeInput.empty())
           {
            error();
           }
        
         }while(!valid);

         semGrade += grade_points[j]*credit_hours[j];
         semCredit += credit_hours[j];
         semesterGpa[i] = semGrade/semCredit;
         cout << endl;
       }
     }
   
     totalGrade += semGrade;
     totalCredit += semCredit;
     cgpa = totalGrade/totalCredit; 
     cout << "\n\n";
     dash();
     cout << "\nStudent Name: " << stud_name << "\n\n";
     cout << "Student ID: " << stud_id << "\n\n";
     cout << "Transcript for Semester " << i+1 << "\n";
     maxName_length = 0;
     for(int l = course_storing; l < (course_storing + num_subject); l++)
       {
         if(course_name[l].length() > maxName_length)
         {
           maxName_length = course_name[l].length();
         }
       }
     dash();
     cout << endl << left << setw(10) << "Course ID\t" << setw(maxName_length) << "Course Name" << "\t  Grade\t\tGrade Point\t\tCredit Hours\n";
     dash();
     cout << endl;
     for(int m = course_storing; m < (course_storing + num_subject); m++)
       {
         cout << left << setw(10) << course_id[m] << "\t" << setw(maxName_length) << course_name[m] << "\t\t" << grade_store[m] << "\t\t\t" << grade_points[m] << "\t" << right << setw(10) << credit_hours[m] << endl;
       }
     dash();
     cout << "\nSemester " << i + 1 << " GPA: " << semesterGpa[i] << endl;
     cout << "CGPA: " << cgpa << "\n\n";
     course_storing += num_subject;
 }

  final_transcript = " ";
  cout << "\nWould you like to see your overall transcript? (Y/N) ";
  do
  {
    final_transcript = confirm();
    if(final_transcript != "Y" && final_transcript != "N")
    {
      error();
    }
  }while(final_transcript != "Y" && final_transcript != "N");
  
  if(final_transcript == "Y")
  {
    maxName_length = 0;
    for(int s = 0; s < 16; s++)
    {
      if(course_name[s].length() > maxName_length)
      {
        maxName_length = course_name[s].length();
      }
    }
    dash();
    cout << endl << left << setw(10) << "Course ID\t" << setw(maxName_length) << "Course Name" << "\t  Grade\t\tGrade Point\t\tCredit Hours\n";
    dash();
    cout << endl;  
    for(int r = 0; r < course_storing; r++)
    {   
      cout << left << setw(10) << course_id[r] << "\t" << setw(maxName_length) << course_name[r] << "\t\t" << grade_store[r] << "\t\t\t" << grade_points[r] << "\t" << right << setw(10) << credit_hours[r] << endl;
    }
    dash();
    cout << "\nTotal (grade points x credit hours): " << totalGrade << endl; 
    cout << "Total credit hours: " << totalCredit << endl;
    cout << "CGPA: " << cgpa << endl;
  }
}

void case1()
{
  previous_subject = 0;
  valid = true;
  do
  {
    transcript_no = 0;
    cout << "Which semester transcript would you like to check? ";
    transcript_no = string_int();
    if(valid || transcript_no == 0)
    {
      error();
    }
    else if (transcript_no > num_semester)
    {
      cout << "Based on your previous history, there are only " << num_semester << " semesters. Try again.\n";
      valid = true;
    }
  }while(valid);
  
  dash();
  cout << "\nStudent Name: " << stud_name << "\n\n";
  cout << "Student ID: " << stud_id << "\n\n";
  cout << "Transcript for Semester " << transcript_no << "\n";
  for(int i = 1; i < transcript_no; i++)
  {
    previous_subject += sem_noSubject[i - 1];
  }
  
  maxName_length = 0;

  for(int l = previous_subject; l < (previous_subject + sem_noSubject[transcript_no - 1]); l++)
  {
    if(course_name[l].length() > maxName_length)
    {
      maxName_length = course_name[l].length();
    }
  }

  dash();
  cout << endl << left << setw(10) << "Course ID\t" << setw(maxName_length) << "Course Name" << "\t  Grade\t\tGrade Point\t\tCredit Hours\n";
  dash();
  cout << endl;
  
  for(int m = previous_subject; m < (previous_subject + sem_noSubject[transcript_no - 1]); m++)
  {
    cout << left << setw(10) << course_id[m] << "\t" << setw(maxName_length) << course_name[m] << "\t\t" << grade_store[m] << "\t\t\t" << grade_points[m] << "\t" << right << setw(10) << credit_hours[m] << endl;
  }
  dash();
  cout << "\nSemester " << transcript_no << " GPA: " << semesterGpa[transcript_no - 1] << endl;
}

void case2()
{
    maxName_length = 0;
    for(int s = 0; s < 16; s++)
    {
      if(course_name[s].length() > maxName_length)
      {
        maxName_length = course_name[s].length();
      }
    }
    dash();
    cout << endl << left << setw(10) << "Course ID\t" << setw(maxName_length) << "Course Name" << "\t  Grade\t\tGrade Point\t\tCredit Hours\n";
    dash();
    cout << endl;  
    for(int r = 0; r < course_storing; r++)
    {   
      cout << left << setw(10) << course_id[r] << "\t" << setw(maxName_length) << course_name[r] << "\t\t" << grade_store[r] << "\t\t\t" << grade_points[r] << "\t" << right << setw(10) << credit_hours[r] << endl;
    }
    dash();
    cout << "\nTotal (grade points x credit hours): " << totalGrade << endl; 
    cout << "Total credit hours: " << totalCredit << endl;
    cout << "CGPA: " << cgpa << endl;
}

void history()
{
  if(course_storing != 0)
  {
    int historyCheck;
    do
    {
      cout << "1. Semester Transcript\n";
      cout << "2. Overall Transcript\n";
      cout << "3. Exit\n";
      cout << "What would you like to check for? (Press 1 or 2)\n";
      historyCheck = string_int();
      switch(historyCheck)
      {
        case 1: case1(); break;
        case 2: case2(); break;
        case 3: return; break;
        default: error();
      }
    }while(historyCheck != 3);
  }
  else
  {
    cout << "\nYou have no history recorded yet." << endl;
  }
}

int main()
{
  int menu;
  dash();
  cout << "\nWelcome to the CGPA calculator! :D\n";
  dash();
  cout << "\n\n";
  do
  {
  cout << endl;
  dash();
  cout << "\nMENU" << endl;
  dash();
  cout << "\n1. New Input\n";
  cout << "2. History\n";
  cout << "3. Exit\n";
  
  cout << "What would you like to do? (eg: Press 1 to for New Input.)\n";
  menu = string_int();
  switch(menu)
  {
    case 1: calculateCGPA(); break;
    case 2: history(); break;
    case 3: thanks(); break;
    default: error();
  }
  }while(menu != 3);
}



 