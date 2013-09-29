#include <stdio.h>

int N,d[20][20],nbrev[20],left[20],brev[20][100],mini;

void MLX(int now, int dist, int nleft) {
  int i,nbrevsav,leftsav;
  if(dist+d[now][0]>=mini) return;    //Kan aldrig bli en bästa lösning
  //Spara tillståndet:
  nbrevsav=nbrev[now];     
  leftsav=left[now];
  //Hämta paketen som ska skickas från now:
  for(i=0;i<nbrev[now];i++) left[brev[now][i]]--;
  nbrev[now]=0;
  //Lämna paketen som ska till now:
  if(left[now]==0) {
    left[now]=-1;
    nleft--;
  }
  if(nleft==0) {   //Om det var sista lämningen så är vi färdiga och har hittat den hittills bästa lösningen...
    mini=dist+d[now][0];     // ... men vi måste tillbaka till 0 också.
  }
  else {    //Annars fortsätter vi
    for(i=1;i<N;i++) if(nbrev[i]>0 || left[i]==0) {   //Välj en stad som vi antingen ska lämna eller hämta paket i
	MLX(i,dist+d[now][i],nleft);  //Rekursera!
      }
  }
  //Vi backtrackar. Återställ tillståndet:
  nbrev[now]=nbrevsav;
  for(i=0;i<nbrev[now];i++) left[brev[now][i]]++;
  left[now]=leftsav;
}

int main(){
  int i,j,nb,from,to,tot;
  
	FILE* f; // create a new file pointer
	((f=fopen("budbil.dat","r")));
  
  fscanf(f,"%d %d", &N, &nb);
  for(i=0;i<N;i++) {
    for(j=0;j<N;j++) fscanf(f,"%d", &d[i][j]);
    nbrev[i]=0;     //Antal paket som ska hämtas i staden
    left[i]=-1;     //Antal paket som ska till staden och ännu inte är upphämtade (eller -1 om redan levererat)
  }
  tot=0;    //Antal städer dit det ska levereras paket
  for(i=0;i<nb;i++) {
    fscanf(f,"%d %d", &from, &to); from--; to--;
    brev[from][nbrev[from]++]=to;
    if(left[to]==-1) {
      left[to]=1;
      if(to!=0) tot++;
    }
    else left[to]++;
  }
  mini=1000000000;
  MLX(0,0,tot);
  printf("Minsta körsträcka: %d\n",mini);
  return 0;
}
