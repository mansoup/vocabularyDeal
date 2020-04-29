#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<map>
using namespace std;
//修正字符串
 void correctString(map<string, int> &stringNum,ifstream &in2){
	vector<string> s;
//	map<string, int> stringNum;
	vector<string>::iterator it;
	string c;
	string k;
	cout<<"please input your correct character end with #(例如单词\"TGsoup.\"删除顿号就输入.)"<<endl;	
	while(cin>>c){
		if(c!="#"){
		s.push_back(c);
    	}
    	else if(c=="#"){
    		break;
		}
	}
	while(in2 >> k){
		k[0]=tolower(k[0]);
		for(it=s.begin();it!=s.end();it++){
			int i = k.find(*it);			
			if(i!=string::npos){
				k.erase(i,(*it).size());
			}
		}
		stringNum[k]++;
	} 
}
int main(int argc, char *argv[])
{
	ifstream in("源词.txt");
	ofstream out("粗词.txt");
	ifstream in2("源词.txt");
    ofstream out2("修正.txt");
    ofstream out3("修正带频率.txt");
    ofstream out4("修正不带频率.txt");
	cout<<"welcome to build my stange vocabulary small program copyright belong to TGsoup"<<endl;
	cout<<"			please choose the corresponding function						 "<<endl;
	cout<<"			0.produce raw list(产生原始单词)								 "<<endl; 
	cout<<"			1.correct vocabulary(修正单词)									 "<<endl;
	cout<<"			2.choose your desire ratio(选择频率区间)						 "<<endl;
	cout<<"			3.generate your personal vocabulary list(生成个人单词表无频率)	 "<<endl;
	int i;
	cout<<"please input you choice ensure between 0 to 3"<<endl;
	cout<<"your choice:";
	cin>>i;
	cout<<endl;
	int flag=0;//默认下没有产生list 
	while(i>=0&&i<=3){
		switch(i){
			case 0 :
					{
					string c;
					map<string, int> stringNum;
					while (in >> c) { 
						stringNum[c]++; 
					}
					for (map<string, int>::iterator it = stringNum.begin(); it != stringNum.end(); it++)
					{
						out << it->first << " : " << it->second << endl;
					}
					in.close();
					flag=1;
				    }
					break;
			case 1 :
					if(flag==1){
					map<string, int>::iterator it;										
					map<string,int> map;				
					correctString(map,in2);					
					for(it=map.begin();it!=map.end();it++){
						out2<<it->first<<" : "<<it->second<<endl;
					}
					in2.close();
					}
					break;
			case 2 :
					if(flag==1){
					map<string, int>::iterator it;										
					map<string,int> map2;				
					correctString(map2,in2);	
					int left,right;
					cout<<"please input your interval"<<endl;
					cout<<"please input your left value and right value(先左后右input):";
					cin>>left>>right;	
					for(it=map2.begin();it!=map2.end();it++){
						if(it->second<=right&&it->second>=left)	{
						out3<<it->first<<" : "<<it->second<<endl;
						}
					}
					in2.close();
					}
					break;
			case 3 :
					if(flag==1){
					map<string, int>::iterator it;										
					map<string,int> map3;				
					correctString(map3,in2);	
					int left,right;
					cout<<"please input your interval"<<endl;
					cout<<"please input your left value and right value(先左后右input):";
					cin>>left>>right;	
					for(it=map3.begin();it!=map3.end();it++){
						if(it->second<=right&&it->second>=left)	{
						out4<<it->first<<endl;
						}
					}
					in2.close();
					}
					break; 
		}
		cout<<"please input your wanted function"<<endl;
		cin>>i;
	}
	
	return 0;
}

