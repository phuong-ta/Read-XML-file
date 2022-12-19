#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<bits/stdc++.h>

#define NOT_FOUND "not found"

using namespace std;

string find_first_element(const string &xml, string tag_name, int *startPosition, int *endPosition);
vector<string> find_all_elements(const string &xml, string tag_name);

int main(){
	string page, line, location, temperature;
	string userInput;
	string stopCommand ("stop");
	ifstream inputFile("day-ahead-prices.xml");
	
	while (getline (inputFile, line)) {
 	    page.append(line);
 	    line.erase();
	}
	
	while(true){
		cout << "Enter a string "<<": ";
		getline (cin, userInput);
		if(userInput==stopCommand){
			break;
		}else{
			userInput.insert(userInput.length(), ">");
			userInput.insert(0, "<");
			vector<string> listAll;
			listAll = find_all_elements(page, userInput);
			int i;
			for(i = 0; i<listAll.size();i++){
				cout<<i+1<<": "<<listAll[i]<<endl;
			}
			cout<<"Length of vector: "<<i<<endl;
		}
	}
	return 0;
}
// 2B
vector<string> find_all_elements(const string &xml, string tag_name){
	vector<string> vecResults;
	int start =0, end =0;
	string strResult;
	while(true){
		strResult = find_first_element(xml, tag_name, &start, &end);
		if(strResult == NOT_FOUND){
			break;
		}else{
			vecResults.push_back(strResult);
			start+=1;
			end +=1;
		}
	}
	if(vecResults.size()==0){
		return vector<string>();
	}else{
		return vecResults;
	}
}
string find_first_element(const string &xml, string tag_name, int *startPosition, int *endPosition){
	string result;
	int start = xml.find(tag_name, *startPosition);
	if (start!=string::npos){
	  	tag_name.insert(1, "/");
	  	*startPosition = start;
	}else{
		return NOT_FOUND;
	}
	
    int end = xml.find(tag_name, *endPosition);
    if (end!=string::npos){
    	tag_name.erase(tag_name.begin() + 1);
    	start += tag_name.length();
    	*endPosition = end;
	  	for(start;start<end; start++){
	  		result.push_back(xml.at(start));
		}
		return result;
	}else{
		return NOT_FOUND;
	}
}


/*
// 2A
string find_first_element(const string &xml, string tag_name){
	string result;
	int start = xml.find(tag_name);
	if (start!=string::npos){
	  	tag_name.insert(1, "/");
	}else{
		return NOT_FOUND;
	}
	
    int end = xml.find(tag_name);
    if (end!=string::npos){
    	start += tag_name.length()-1;
	  	for(start;start<end; start++){
	  		result.push_back(xml.at(start));
		}
		return result;
	}else{
		return NOT_FOUND;
	}
}
*/