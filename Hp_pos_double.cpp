#include <iostream>
using namespace std;

void add_float(char* a, char* b, char* res) {
	char ans[140]={0};
	int p1=0,p2=0,la=0,lb=0;
	while(a[la]!='\0'){
		if(a[la]=='.') p1=la;
		la++;
	}
	while(b[lb]!='\0'){
		if(b[lb]=='.') p2=lb;
		lb++;
	}
	if(p2>p1){
		for(int i=la;i>=0;i--){
			a[i+p2-p1]=a[i];
		}
		for(int i=p2-p1-1;i>=0;i--)
			a[i]='0';
		la=la+p2-p1;
	}
	if(p2<p1){
		for(int i=lb;i>=0;i--){
			b[i+p1-p2]=b[i];
		}
		for(int i=p1-p2-1;i>=0;i--)
			b[i]='0';
		lb=lb+p1-p2;
	}
	int p=p2>p1?p2:p1;
	if(la>lb){
		for(int i=la-1;i>=lb;i--){
			b[i]='0';
		}
		b[la]='\0';
	}
	if(lb>la){
		for(int i=lb-1;i>=la;i--){
			a[i]='0';
		}
		a[lb]='\0';
	}
	int l1=la>lb?la:lb;
//	cout<<a<<endl<<b<<endl;
	bool flag=0;
	int q=0;
	for(int i=l1-1;i>p;i--){
		ans[q]=b[i]+a[i]-'0'+flag;
		if(ans[q]>'9'){
			flag=1;
			ans[q]-=10;
		}
		else flag=0;
		q++;
	}
	ans[q++]='.';
	for(int i=p-1;i>=0;i--){
		ans[q]=b[i]+a[i]-'0'+flag;
		if(ans[q]>'9'){
			flag=1;
			ans[q]-=10;
		}
		else flag=0;
		q++;
	}
	if(flag) ans[q++]='1';
	ans[q]='\0';
	int l=q-1,r=0,t=0;
	while(ans[l]=='0') l--;
	while(ans[r]=='0') r++;
	for(int i=l;i>=r;i--){
		res[t++]=ans[i];
	}
	res[t]='\0';
}


int main()
{
    char num1[128], num2[128], res[128];
    cin >> num1;
    cin >> num2;
    add_float(num1, num2, res);
    cout << res << endl;
    return 0;
}