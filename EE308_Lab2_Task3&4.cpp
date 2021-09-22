
#include<string>

#include<string.h>
using namespace std;
string keyword[32]={"auto","break;","case","char","const","continue","default:","double","do","else","enum","extern","float","for",
					"goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef",
					"union","unsigned","void","volatile","while"};
 
int if_elseif_else_num=0,ifelse_num=0,top=0;
int stack[100]; 
int main ()
{
	
	string file_name,line;
	cout<<"输入文件的路径:";				
	cin>>file_name;						
	
	ifstream myfile(file_name.c_str());	//打开文件 	
	void rank_3_4(string c);
	while(getline(myfile,line))	//逐行读取 
	{
		istringstream is(line);	
		string sgl;
	    rank_3_4(line);
		
	}
		cout<<"if-else num: "<<ifelse_num<<endl;

		cout<<"if-elseif-else num: "<<if_elseif_else_num;
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
