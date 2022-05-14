#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

 
void threePeg(int n, char from_rod,char to_rod, char temp,ofstream& output)
{
    if (n == 0)
    {
        return;
    }
    threePeg(n - 1, from_rod, temp, to_rod,output);
    output << n << " " << from_rod <<" " << to_rod << endl;
    threePeg(n - 1, temp, to_rod, from_rod,output);
}

void fourPeg(int n ,char  from_rod , char to_rod ,char temp,char temp2,ofstream& output)
{
    if(n==0)
        return;
    if(n==1)
    {
        output << n <<" "<< from_rod << " " << to_rod <<endl;
        return;
    }

    fourPeg(n - 2 , from_rod , temp , temp2 ,to_rod ,output);


    output <<  n-1 << " " << from_rod << " "<< temp2 <<endl;
    output <<  n << " " << from_rod << " "<< to_rod<<endl;
    output <<  n-1 << " " << temp2<< " "<< to_rod<<endl;

    fourPeg(n - 2, temp , to_rod , from_rod ,temp2,output);

}

void fivePeg(int n ,char  from_rod , char to_rod ,char temp,char temp2, char temp3,ofstream& output)
{
    if(n==0)
        return;
    if(n==1)
    {
        output << n <<" "<< from_rod << " " << to_rod <<endl;
        return;
    }
    if(n==2)
    {
        output <<  n-1 << " "<< from_rod << " " << temp <<endl;
        output <<  n << " "<< from_rod << " " << to_rod <<endl;
        output <<  n-1 << " "<< temp << " " << to_rod <<endl;
        return;
    }

    fivePeg(n - 3 , from_rod , temp , temp2 , temp3, to_rod ,output);

    output <<  n-2 << " " << from_rod << " "<< temp3 <<endl;
    output <<  n-1 << " " << from_rod << " "<< temp2 <<endl;
    output <<  n << " " << from_rod << " "<< to_rod<<endl;
    output <<  n-1 << " " << temp2<< " "<< to_rod<<endl;
    output <<  n-2 << " " << temp3<< " "<< to_rod<<endl;

    fivePeg(n - 3, temp , to_rod , from_rod ,temp2 , temp3,output);
}

int main(int argc, char** argv)
{
	string temp = argv[1];
    string temp2 = argv[2];
	istringstream ss(temp2);
    int num_of_peg;
    int num_of_disks;
    ss>>num_of_disks;
    istringstream kk(temp);
    kk>>num_of_peg;
    //string filename = "output.txt";
    ofstream output(argv[3]);
    
    if(num_of_peg == 3)
    {
        threePeg(num_of_disks, 'A','C','B',output);
    }
    else if(num_of_peg == 4)
    {
        fourPeg(num_of_disks, 'A','D','B','C',output);
    }
    else if(num_of_peg == 5)
    {
        fivePeg(num_of_disks, 'A','E','B','C','D',output);
    }
    output.close();
    return 0;
}