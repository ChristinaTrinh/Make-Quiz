//Description: This program makes a quiz.
//LAB: Math Tutor
//Course: CIT 120-T1
//Programmers: Christina Trinh, Francois, Charlie
//Professor: Makhene
//Date: 4/28/21
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include<string>
#include <fstream>

//prototypes
void banner();
int menu();
int quest();
void tutor(int, int);
void tutor2 (int , int );

using namespace std;
int main()
{
    bool conti; //flag to know if the user wants to continue or not
    char ch;
    do
    {
    int number, question;//variables
    string select; //variables
    number=menu(); //call menu function to get the user's choice
    question= quest(); //call quest function to get the user's desire questions

    //if the choice is 1, 2, 3, 4, 5, or 6
    if(number==1||number==2||number==3||number==4||number==5||number==6)
    tutor(number,question); //then we call the function tutor
    //if the choice is 7, 8, 9, or 10
    if(number==7||number==8||number==9||number==10)
    tutor2(number,question);//then we call the function tutor2
    if(number==11) //if the choice is exit
    exit(1); //then exit

    cout<<"Do you want to continue? (Yes/No) "; //ask user to continur or not
    cin>>select; //get input
    cin.ignore();
    if(select=="Yes"||select=="yes"||select=="YES") //if yes
    {
    conti=1; //set conti to true
    system("clear"); //clear screen
    }
    else //if any other
    {
    conti=0; //set conti to false
    cout <<"Thank you for using our Math Tutor. Have a great day!\n"
         <<"Press Enter to exit"; //exit message
    cin.get(ch);
    }
    }while(conti==1); //loop will only continue if user answered yes
    return 0;
}
void banner() // and banner
{
    //Heading
    cout << "\t\t\t\t\tDescription: This program does a quiz." << endl;
    cout << "\t\t\t\t\tLAB: Math Tutor" << endl;
    cout << "\t\t\t\t\tCourse: CIT 120-T1"<< endl;
    cout << "\t\t\t\t\tProgrammers: Christina Trinh, Francois, Charlie" << endl;
    cout << "\t\t\t\t\tProfessor: Makhene" << endl;
    cout << "\t\t\t\t\tDate: 4/28/21" << endl;
}
int menu() //menu function to display menu and get user's choice
{
    double choice;
    cout << "\t\tThis program tests your Math abilities\n"
    <<"for addition / subtraction / multiplication / division / modulo\n\n\n";
    cout <<"\tMenu\n"
         << "1) Addition only\n"
         << "2) Subtraction only\n"
         << "3) Multiplication only\n"
         << "4) Integer Division only\n"
         << "5) Real Division only\n"
         << "6) Modulo only\n"
         << "7) Addition and subtractions\n"
         << "8) Addition, subtraction, and multiplication\n"
         << "9) Addition, subtraction, multiplication and integer division\n"
         << "10) All operators\n"
         << "11) End program\n\n"
         << "Please Enter your choice: ";
    cin >> choice; //get choice
    cin.ignore();

    //validate choice
    while(choice<1 || choice >11|| cin.fail()||choice!=static_cast<int>(choice))
    {
        if (cin.fail())
        {
            cout <<"Input was not a number\n"
                 <<"Enter a VALID Number!: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin>>choice;
        }
        else if(choice<1||choice>11)
        {
        cout <<"Input is out of range\n"
             <<"Enter a VALID number from 1-11: ";
        cin >>choice;
        }
        else if(choice!=static_cast<int>(choice))
        {
            cout <<"Input is invalid\nPlease Enter a number from 1-11: ";
            cin>>choice;
        }
    }
    return choice; //return the choice
}

int quest()//quest function to get user's desire number of questions on quiz
{
    double num;
    cout <<"How many questions do you want to solve? ";
    cin >>num; //get input
    cin.ignore();

    //validat input
    while(cin.fail() || num<=0|| num!=static_cast<int>(num))
    {
        if(cin.fail())
        {
            cout <<"Please Enter a valid number of questions: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin>>num;
        }
        else if(num<=0)
        {
            cout << "Please Enter an invalid number of questions: ";
            cin>>num;
        }
        else if(num!=static_cast<int>(num))
        {
            cout <<"Input is invalid.\nPlease Enter a whole number for how many number of questions you want to solve: ";
            cin>>num;
        }
    }
    return num;//return the number
}

//tutor function to make the quiz for choice 1,2,3,4,5,6
void tutor(int num, int quantity)
{
    int correct=0; //set correct as a count variable to record #correct
    int partial=0; //set partial as a count variable to record #partial
    int wrong=0; //set wrong as a count variable to record #wrong
    const int MIN_VALUE = 1;//the minimum value of operand
    const int MAX_VALUE = 99; //the maximum value of operand
    int num1, num2; //variables
    int answer, rightAns; //variables
    unsigned seed = time(0);
    srand(seed);

//if the user chose 1,2,3,4,5, or 6 from the menu would fall into this loop
    if(num==1||num==2||num==3||num==4||num==5||num==6||num==7)
    {
        //set this so we know how many time to create random sets
        for(int count=1; count<=quantity; count++)
        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE; //1st random number
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE; //2nd random number
        cout << "\nQuestion "<<count <<" of "<<quantity<<endl<<endl; //display the number of question
        if(num==1) //if the user chose 1 from menu
        {
        cout << setw(4) << num1 << endl << "+ " << num2 << endl << "--------" << endl;//display the problem
        cin >> answer; //get answer
        rightAns= num1+num2; //solve it
        if(answer==rightAns) //if user's answer matched with right answer
        {
            cout <<"Congratulations! You got it!\n ";//congrats message
            correct++; //store into the correct count variable
        }
        else if(answer!=rightAns ||cin.fail()) //if user entered a character or wrong answer
        {
            cout<<"That's not the right answer. Try again: "; //send error message
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer; //get answer again
            if(answer!=rightAns) //if second attempt is wrong
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n"; //move to next problem
            wrong++; //add to wrong count variable
            }
            else //but if the second attempt is correct
            {
            cout <<"Congratulation! You got it!"; //send congrats message
            partial++; //store to partial count variable
            }
        }
        }

        //this scope is repeated as above but is subtraction
        else if(num==2)
        {
            cout << setw(4) << num1 << endl << "- " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1-num2;
            if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
           else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
        }
        //this scope is also repeated as above but with multiplication
        else if(num==3)
        {
            cout << setw(4) << num1 << endl << "* " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1*num2;
            if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
        }
        //this scope is also repeated as above but with division
        else if(num==4)
        {
            cout << setw(4) << num1 << endl << "/ " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1/num2;
            if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
      }
        //this scope solve for real division which will accept up to 2 decimal points for the answer
        else  if(num==5)
        {
            float answer; //set answer variable for this local scope only
            float right; //also for this local scope only
            cout << setw(4) << num1 << endl << "/ " << num2 << endl << "--------" << endl;
            cin >> answer;//get answer
            cin.ignore();
            right= static_cast<float>(num1)/num2; //solve for the right answer and change it to float data type
        float nearestHundred= roundf(right*100)/100; //round up to 2 decimal points for the correct answer
            if(answer==nearestHundred) //compare user's answer with that and if it's correct
        {
            cout <<"Congratulations! You got it!\n"; //then display congrats message
            correct++; //add 1 to correct variable
        }
            else if(answer!=nearestHundred ||cin.fail()) //if not then give one more attempt
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=nearestHundred) //if still wrong then display message and move to other problem
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++; //add 1 to wrong variable
            }
            else //if 2nd attempt is correct
            {
            cout <<"Congratulations! You got it!\n"; //congrats message
            partial++; //add 1 to partial variable
            }
        }
        }
        //this scope repeated as the num==1 scope but with module
        else if(num==6)
        {
            cout << setw(4) << num1 << endl << "% " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1%num2;
            if(answer==rightAns)
        {
            cout <<"Congratulations! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulations! You got it!\n";
            partial++;
            }
        }
        }
        }
        }

        ofstream outputFile; //declare variable for file
        outputFile.open("mathTutor.txt"); //open a file

        //at the end, we calculated the percent of right, wrong, and partial and combine them as a total %
        //the user scored in the quiz
        double percentEach= 100/quantity; //get the average percent for each question
        double firstPercent=correct*percentEach; //get the percent total for correct answer
        double secondPercent= partial*percentEach*0.5; //get the percent total for partial answer
        //wrong answers don't count because they worth 0%
        double totalPercent= firstPercent+secondPercent; //add them together to a total % scored
        //summary table
        cout<< "---------------*** You Got ***---------------------\n|"
            << "\t  #Corrects  |   #Partials  |     #Wrong    |\n|\t"
            << "       "<<correct<<"     |       "<<partial<<"      |       "<<wrong <<"       |\n"
            <<"--------***Out of "<<quantity<<" questions asked!***-------------\n\n";
        cout<<"You scored "<<totalPercent<<"%\n\n";

        //save report to file mathTutor.txt
        outputFile << "\t\t\t***Your Quiz Report was recorded below ***\n\n"
                   << "---------------*** You Got ***---------------------\n|"
                   << "\t  #Corrects  |   #Partials  |     #Wrong    |\n|\t"
                   << "       "<<correct<<"     |       "<<partial<<"      |       "<<wrong <<"       |\n"
                   <<"--------***Out of "<<quantity<<" questions asked!***-------------\n\n";
        outputFile <<"You scored "<<totalPercent<<"%\n\n";
        outputFile.close(); //close the file
        cout <<"Your Report was also written to file mathTutor.txt so you don't lose it as a reference!\n\n";
    }

//tutor2 function for choice 7,8,9,or 10
void tutor2 (int num, int quantity)
{
    //count variables
    int correct=0;
    int partial=0;
    int wrong=0;
    int count=0;

    //constant variables for the range of operands
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 99;

    //other variables
    int num1, num2;
    int answer, rightAns;
    unsigned seed = time(0);
    srand(seed);


    if(num==7) //if choice 7 is chose
    {
    for(int index=1; index<=quantity; index+=2) //outer loop for subtraction problems
    {
    for( ;count<=index; count+=2) //inner input for addition problems
        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        cout << "\nQuestion "<<count+1 <<" of "<<quantity<<endl<<endl;
        cout << setw(4) << num1 << endl << "+ " << num2 << endl << "--------" << endl;
        cin >> answer; //get answer for the problem
            rightAns= num1+num2; //solve for the problem
            if(answer==rightAns)//if the answer is right
        {
            cout <<"Congratulation! You got it!\n"; //display congrats message
            correct++; //add 1 to correct variable
        }
            else if(answer!=rightAns ||cin.fail()) //if the answer is wrong or character is entered
        {
            cout<<"That's not the right answer. Try again: "; //display error message
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer; //get answer again
            if(answer!=rightAns) //if it's wrong again
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n"; //error messgage
            wrong++; //add 1 to wrong
            }
            else //if second attempt is right
            {
            cout <<"Congratulation! You got it!\n";
            partial++; //add 1 to partial variable
            }
        }
        }
       if(index<quantity) //this scope will only display if the index is less than number of question
        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            cout << "\nQuestion "<<index+1 <<" of "<<quantity<<endl<<endl;
             cout << setw(4) << num1 << endl << "- " << num2 << endl << "--------" << endl;
             cin >> answer;
            rightAns= num1-num2;
            if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
        }
    }
    }


    //repeated the same as num==7 scope but there is multiply combination
    else if(num==8)
    {
    for(int j=2; j<=quantity; j+=2) //loop for multiply problems
    {
    for(int index=1; index<=j; index+=2) //loop for subtraction problems
    {
    for( ;count<index; count+=2) //loop for addition problems
        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        cout << "\nQuestion "<<count+1 <<" of "<<quantity<<endl<<endl;
        cout << setw(4) << num1 << endl << "+ " << num2 << endl << "--------" << endl;
        cin >> answer;
            rightAns= num1+num2;
            if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n ";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
        }

        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            cout << "\nQuestion "<<index+1 <<" of "<<quantity<<endl<<endl;
            cout << setw(4) << num1 << endl << "- " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1-num2;
        if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
        }
        if(j<quantity)
        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            cout << "\nQuestion "<<j+1 <<" of "<<quantity<<endl<<endl;
            cout << setw(4) << num1 << endl << "* " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1*num2;
        if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
          {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
          }
        }
      }
     }
    }

    //repeated as num==7 scope but with division problems
    else if(num==9)
{
    for(int i=3; i<=quantity;i+=2)//loop for division problems
    {
    for(int j=2; j<=i; j+=2) //loop for multiplication problems
    {
    for(int index=1; index<=j; index+=2) //loop for subtraction problems
    {
    for( ;count<index; count+=2) //loop for addition problems
        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        cout << "\nQuestion "<<count+1 <<" of "<<quantity<<endl<<endl;
        cout << setw(4) << num1 << endl << "+ " << num2 << endl << "--------" << endl;
        cin >> answer;
            rightAns= num1+num2;
            if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n ";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
        }

        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            cout << "\nQuestion "<<index+1 <<" of "<<quantity<<endl<<endl;
            cout << setw(4) << num1 << endl << "- " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1-num2;
        if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
        }
        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            cout << "\nQuestion "<<j+1 <<" of "<<quantity<<endl<<endl;
            cout << setw(4) << num1 << endl << "* " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1*num2;
        if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
          {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
          }
        }
         if(j<quantity)
             {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            cout << "\nQuestion "<<i+1 <<" of "<<quantity<<endl<<endl;
            cout << setw(4) << num1 << endl << "/ " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1/num2;
        if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
          {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
          }
            }
      }
     }
    }
}
//repeated as the num==7 scope but for all types of problems
        else if(num==10)
    {
    for( int f=5; f<=quantity; f+=2 ) //loop for modulo problems
            {
    for(int k=4; k<=f; k+=2) //loops for real division problems
    {
    for(int i=3; i<=k;i+=2) //loop for division problems
    {
    for(int j=2; j<=i; j+=2) //loop for multiplication problems
    {
    for(int index=1; index<=j; index+=2) //loop for subtraction problems
    {
    for( ;count<index; count+=2) //loop for addition problems
        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        cout << "\nQuestion "<<count+1 <<" of "<<quantity<<endl<<endl;
        cout << setw(4) << num1 << endl << "+ " << num2 << endl << "--------" << endl;
        cin >> answer;
            rightAns= num1+num2;
            if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n ";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
        }
        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            cout << "\nQuestion "<<index+1 <<" of "<<quantity<<endl<<endl;
            cout << setw(4) << num1 << endl << "- " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1-num2;
        if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
        }
        {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            cout << "\nQuestion "<<j+1 <<" of "<<quantity<<endl<<endl;
            cout << setw(4) << num1 << endl << "* " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1*num2;
        if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
          {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
          }
        }
             {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            cout << "\nQuestion "<<i+1 <<" of "<<quantity<<endl<<endl;
            cout << setw(4) << num1 << endl << "/ " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1/num2;
        if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
          {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
            {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
          }
             }
            {
                //repeated as num==5 scope to require 2 decimal points for correct answer
                float right;
                float answer1;
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            cout << "\nQuestion "<<k+1 <<" of "<<quantity<< " (real division)" <<endl<<endl;
            cout << setw(4) << num1 << endl << "/ " << num2 << endl << "--------" << endl;
            cin >> answer1;
            cin.ignore();
            right= static_cast<float>(num1)/num2;
        float nearestHundred= roundf(right*100)/100;
            if(answer1==nearestHundred)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer1!=nearestHundred ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer1;
            if(answer1!=nearestHundred)
            {
            cout<< "\nWrong again. The right answer is: "<< nearestHundred<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
            }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
            }
            if(f<quantity)
            {
            num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            cout << "\nQuestion "<<f+1 <<" of "<<quantity<<endl<<endl;
            cout << setw(4) << num1 << endl << "% " << num2 << endl << "--------" << endl;
            cin >> answer;
            rightAns= num1%num2;
            if(answer==rightAns)
        {
            cout <<"Congratulation! You got it!\n";
            correct++;
        }
            else if(answer!=rightAns ||cin.fail())
        {
            cout<<"That's not the right answer. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >>answer;
            if(answer!=rightAns)
          {
            cout<< "\nWrong again. The right answer is: "<< rightAns<<endl;
            cout<<"But it's okay, let's move on!\n";
            wrong++;
          }
            else
            {
            cout <<"Congratulation! You got it!\n";
            partial++;
            }
        }
       }
      }
     }
    }
   }
  }
 }

 ofstream outputFile; //declare variable for file
outputFile.open("mathTutor.txt"); //open a file
 //calculate percent scored and displays summaries exact same as the function tutor
        double percentEach= 100/quantity;
        double firstPercent=correct*percentEach;
        double secondPercent= partial*percentEach*0.5;
        double totalPercent= firstPercent+secondPercent;
 cout<< "---------------*** You Got ***---------------------\n|"
     << "\t  #Corrects  |   #Partials  |     #Wrong    |\n|\t"
     << "       "<<correct<<"     |       "<<partial<<"      |       "<<wrong <<"       |\n"
     <<"--------***Out of "<<quantity<<" questions asked!***-------------\n\n";
     cout<<"You scored "<<totalPercent<<"%\n\n";

     //write the report into file mathtutor
     outputFile << "\t\t\t***Your Quiz Report was recorded below ***\n\n"
                   << "---------------*** You Got ***---------------------\n|"
                   << "\t  #Corrects  |   #Partials  |     #Wrong    |\n|\t"
                   << "       "<<correct<<"     |       "<<partial<<"      |       "<<wrong <<"       |\n"
                   <<"--------***Out of "<<quantity<<" questions asked!***-------------\n\n";
        outputFile <<"You scored "<<totalPercent<<"%\n\n";
        outputFile.close(); //close the file
        cout <<"Your Report was also written to file mathTutor.txt so you don't lose it as a reference!\n\n";
}
