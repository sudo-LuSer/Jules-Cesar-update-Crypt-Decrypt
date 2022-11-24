#include <iostream>
#include <math.h>
#include <map>
using namespace std;
char crypt(char s,int k){
	string alphabets = "abcdefghijklmnopqrstuvwxyz"; 
	for(int i = 0 ;i < 26;i++){
		if(alphabets[i]==s){
			return alphabets[(i+k)%26];
		}
	}
	return '-';
}
char decrypt(char s,int k){
	string alphabets = "abcdefghijklmnopqrstuvwxyz"; 
	for(int i = 0 ;i < 26;i++){
		if(alphabets[i]==s){
			if(i-k<0){
				return alphabets[(i-k+26)]; 
			}
			return alphabets[(i-k)%26];
		}
	}
	return '-';
}
string decryptMAP(string s,int k){
	string MAPED=s;
	for(int i = 0 ; i < s.size();i++){
		MAPED[i]=decrypt(s[i],k);
	}
	return MAPED;
}
int main(){
	int key;cin>>key;
	string word = "hitar";
	string cryptedMAP="";
	for(int i = 0;i<word.size();i++){
		cryptedMAP+=crypt(word[i],key);
	}
	cout<<cryptedMAP<<endl;
	cout<<"\n";
	for(int i = 0 ; i < 26 ;i++){
		cout<<decryptMAP(cryptedMAP,i)<<" key = "<<i<<endl;
	}
}