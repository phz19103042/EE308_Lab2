#include<iostream>
#include<string> 
#include<string.h>


using namespace std;

string keyword[32]={"auto","break;","case","char","const","continue","default:","double","do","else","enum","extern","float","for",
					"goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef",
					"union","unsigned","void","volatile","while"};
int num=0;  //记录关键词数量 

int stack[100]; 
int main ()
{
	string file_name,line;
	cout<<"输入文件的路径:";				
	cin>>file_name;						
	ifstream myfile(file_name.c_str());	//打开文件 
	while(getline(myfile,line))	//逐行读取 
	{
		istringstream is(line);	
		string sgl;
	}
    
	cout<<"total num: "<<num<<endl;
	
}
