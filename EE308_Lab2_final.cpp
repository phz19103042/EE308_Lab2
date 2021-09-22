#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<string.h>

using namespace std;

string keyword[32]={"auto","break;","case","char","const","continue","default:","double","do","else",
                    "enum","extern","float","for","goto","if","int","long","register","return","short",
					"signed","sizeof","static","struct","switch","typedef","union","unsigned","void",
					"volatile","while"};   /*Build a keyword thesaurus*/


int num=0;           /*Record the number of keywords*/ 
int switchnum=0;     /* Collecting the Number of Switches*/
int casenum[100];/*Count the cases of each switch*/  
int if_elseif_else_num=0,ifelse_num=0,top=0;
int stack[100]; 
int main ()
{
	int rank;
	string file_name,line;
	cout<<"input the file path:";				
	cin>>file_name;						
	cout<<"Enter the rank to search for:";
	/*Search rank:
	Rank 1 --- Basic requirement: output "keyword" statistics
    Rank 2 --- Advanced requirement: output the number of "switch case" structures, 
	           and output the number of "case" corresponding to each group
    Rank 3 --- Uplifting requirement: output the number of "if else" structures
    Rank 4 --- Ultimate requirement: output the number of "if, else if, else" structures*/ 
	cin>>rank; 
	ifstream myfile(file_name.c_str());	 /*opening the file*/ 
	void rank_1_2(string a);	
	void rank_3_4(string c);
	while(getline(myfile,line))	 /*read line by line*/
	{
		istringstream is(line);	
		string sgl;
		if(rank>=3) rank_3_4(line);
		while(is>>sgl)          /*Delete the blank space*/
		{
		if(rank>=1) rank_1_2(sgl);
		}
	}
	if(rank>=1) cout<<"total num: "<<num<<endl;
	if(rank>=2)
	{
		cout<<"switch num: "<<switchnum<<endl;
		cout<<"case num: ";
		for(int a=1;a<=switchnum;a++) cout<<" "<<casenum[a];
		cout<<endl;
	}
	if(rank>=3)
	{
		cout<<"if-else num: "<<ifelse_num<<endl;
	}
	if(rank>=4)
	{
		cout<<"if-elseif-else num: "<<if_elseif_else_num;
	}
}
void rank_1_2(string sige)		
{
	char s1[100],s2[100];
	for(int i=0;i<32;i++)			
	{
	int length1=sige.length(),length2=keyword[i].length();
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	for(int j=0;j<length1;j++) s1[j]=sige[j];
	for(int j=0;j<length2;j++) s2[j]=keyword[i][j];
		if(strcmp(s1,s2)==0)
		{
			if(strcmp(s2,"switch")==0) switchnum++;
			if(strcmp(s2,"case")==0) casenum[switchnum]++;
			num++;
			break;
		}
	}
}	
void rank_3_4(string sige)		
{
	if(sige.find("else if")!=string::npos)
	{
		top++;
		stack[top]=2;
	}
	else
	{
		if(sige.find("if")!=string::npos)
		{
			top++;
			stack[top]=1;
		}
		else
		{
			if(sige.find("else")!=string::npos)
			{
				if(stack[top]==1)
				{
					ifelse_num++;
					top--;
				}
				else	
				{
					if(stack[top]==2)
					{
						if_elseif_else_num++;
						top--;
					}
				}
			}
		}
	}
}
