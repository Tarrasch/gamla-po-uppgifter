#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

struct Staket{
	int x1,y1,x2,y2;
};



int sortMyY (const void * a, const void * b){
  if ( (*(Staket*)a).x1 >  (*(Staket*)b).x1 ) return 1;
  if ( (*(Staket*)a).x1 == (*(Staket*)b).x1 ) return 0;
  if ( (*(Staket*)a).x1 <  (*(Staket*)b).x1 ) return -1;	
}

int sortMyX (const void * a, const void * b){
  if ( (*(Staket*)a).y1 >  (*(Staket*)b).y1 ) return 1;
  if ( (*(Staket*)a).y1 == (*(Staket*)b).y1 ) return 0;
  if ( (*(Staket*)a).y1 <  (*(Staket*)b).y1 ) return -1;	
}
	
	int nuys=0;
	int nuxs=0;	

	int ae[50][50];
	bool tagen[50][50];
	bool xblock[50][50];
	bool yblock[50][50];

long area(int x, int y){
	if(tagen[x][y]) return 0;
	
	//cout << x << " " << y << endl;
	
	tagen[x][y]=true;
	
	int tempa=ae[x][y];
	
	if( ((x+1)<(nuxs)) && !tagen[x+1][y] && !xblock[x+1][y])
		tempa+=area(x+1,y);
	
	if( ((x-1)>=0) && !tagen[x-1][y] && !xblock[x][y])
		tempa+=area(x-1,y);
	
	if( ((y+1)<(nuys)) && !tagen[x][y+1] && !yblock[x][y+1])
		tempa+=area(x,y+1);
		
	if( ((y-1)>=0) && !tagen[x][y-1] && !yblock[x][y])
		tempa+=area(x,y-1);
		
	return tempa;	
}


int main(int argc, char** argv)
{
	int b,h;
	int n;

	cin >> b >> h >> n;		

	Staket ys[50];
	int nys=0;
	Staket xs[50];
	int nxs=0;
	
	for(int i=0;i<n;i++){//inmatning
		Staket ts;
		cin >> ts.x1 >> ts.y1 >> ts.x2 >> ts.y2;		
		//cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2;
		if(ts.x1>ts.x2 || ts.y1>ts.y2){
			swap(ts.x1,ts.x2);swap(ts.y1,ts.y2);
			}
		if(ts.x1==ts.x2)
			ys[nys++]=ts;
		else
			xs[nxs++]=ts;
	}

	
	qsort(ys, nys, sizeof(Staket), sortMyY);
	qsort(xs, nxs, sizeof(Staket), sortMyX);

	int uys[50];
	int uyid[50];	
	int uxs[50];
	int uxid[50];
	
	int last=-1;
	
	for(int i=0;i<nys;i++){
		if(last!=ys[i].x1){
			uyid[nuys]=i;
			uys[nuys++]=ys[i].x1;
		}
		last=ys[i].x1;
	}
	last=-1;
	for(int i=0;i<nxs;i++){
		if(last!=xs[i].y1){
			uxid[nuxs]=i;
			uxs[nuxs++]=xs[i].y1;
		}
		last=xs[i].y1;
	}
	
	for(int y=0;y<(nuxs);y++){
		int y2=uxs[y+1],y1=uxs[y];
		if((y+1)==nuxs)
			y2=h;
		for(int x=0;x<(nuys);x++){
			int x2=uys[x+1],x1=uys[x]; //koord för rekt
			
			if((x+1)==nuys)
				x2=b;
			tagen[x][y]=false;		
			ae[x][y]=(x2-x1)*(y2-y1);//dx*dy
			//cout << ae[x][y] << endl;
			xblock[x][y]=false;
			yblock[x][y]=false;
		
			int id;
			id= uyid[x];
			 	
			while(ys[id].x1==x1){
				if(ys[id].y1<=y1 && ys[id].y2>=y2){
					xblock[x][y]=true;
					break;
				}
				id++;
			}
			id= uxid[y];
			//cout << id;
			while(xs[id].y1==y1){
				if(xs[id].x1<=x1 && xs[id].x2>=x2){
					yblock[x][y]=true;
					break;
				}
				id++;
			}
			//cout << xblock[x][y] << " "<< yblock[x][y] << endl;			
				
		}
	}
		
	long areamax=0;
	int at=0;
	
	while(at<((nuxs)*(nuys))){
		int x=at%(nuys),y=at/(nuys);
		
		if(!tagen[x][y]){
			areamax=max(areamax,area(x,y));
		}
		at++;
	}
		
	cout << areamax;
	
	return 0;
}
