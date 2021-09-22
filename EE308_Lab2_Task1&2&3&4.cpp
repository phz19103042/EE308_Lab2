#include<sstream>
#include<string.h>
using namespace std;
string keyword[32]={"auto","break;","case","char","const","continue","default:","double","do","else","enum","extern","float","for",
					"goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef",
					"union","unsigned","void","volatile","while"};
int num=0;//记录关键词数量 
int switchnum=0;//统计switch个数 
int casenum[100];//统计各组switch下case数 
int if_elseif_else_num=0,ifelse_num=0,top=0;
int stack[100]; 
int main ()
{
	string file_name,line;
	cout<<"输入文件的路径:";				
	cin>>file_name;						
	ifstream myfile(file_name.c_str());	//打开文件 
	void rank_1_2(string a);	
	void rank_3_4(string c);
	while(getline(myfile,line))	//逐行读取 
	{
		istringstream is(line);	
		string sgl;
	    Level_34(line);
		while(is>>sgl)//去除空格
		{
	        Level_12(sgl);
		}
	}
    cout<<"total num: "<<num<<endl;

	cout<<"switch num: "<<switchnum<<endl;
	cout<<"case num: ";
	for(int a=1;a<=switchnum;a++) cout<<" "<<casenum[a];
	cout<<endl;
	
	cout<<"if-else num: "<<ifelse_num<<endl;
	
	cout<<"if-elseif-else num: "<<if_elseif_else_num;
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
