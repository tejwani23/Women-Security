#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<fstream>

# define V 451

using namespace std;


int minweight(int weight[],bool vis[])
{
    int min = INT_MAX, min_ver;
    for (int i = 0; i < V; i++)
        if (vis[i] == false && weight[i] <= min)
            min = weight[i], min_ver = i;
    return min_ver;
}

int *min_Path(int parent[], int p, int coor[2][V])
{
    static int a[V];
    static int i;
    if (parent[p] == - 1)
        return 0;
    min_Path(parent, parent[p],coor);
    setcolor(CYAN);
    int x1,x2,y1,y2,p2;
    p2=parent[p];
    x1=coor[0][p];
    y1=coor[1][p];
    x2=coor[0][p2];
    y2=coor[1][p2];
    line(x1,y1,x2,y2);
    if (x1==x2){
        line(x1+1,y1,x2+1,y2);
        line(x1-1,y1,x2-1,y2);
    }
    if (y1==y2){
        line(x1,y1+1,x2,y2+1);
        line(x1,y1-1,x2,y2-1);
    }

    a[i]=p;
    i++;
    return a;
}

void dijkstra(int road[V][V], int src,int des,int coor[2][V])
{
    int *b;
    int weight[V];

    bool vis[V];

    int parent[V];

    for (int i = 1; i < V; i++)
    {
        parent[i] = -1;
        weight[i] = INT_MAX;
        vis[i] = false;
    }

    weight[src] = 0;

    for (int count = 1; count < V - 1; count++)
    {
        int u = minweight(weight, vis);

        vis[u] = true;

        for (int v = 1; v < V; v++)
        {
            if (!vis[v] && road[u][v] && weight[u] + road[u][v] < weight[v])
            {
                parent[v] = u;
                weight[v] = weight[u] + road[u][v];
            }
        }
    }
    b = min_Path(parent,des,coor);
    ofstream fin;
    fin.open("spath.txt",ios::app);
    fin<<src<<" ";
    for(int i=0;i<V;i++)
    {
        if (b[i]!=0)
            fin<<b[i]<<" ";
        else{
            fin<<0<<" ";
            break;
        }
    }
    fin<<endl;
    fin.close();
}



int get_x(int x)
{
    int k,m,r;
    k=x-70;
    m=k/50;
    r=k%50;
    if(r<25)
    {
        k=(m*50)+70;
    }
    else
    {
        m=m+1;
        k=(m*50)+70;
    }
    return k;
}

int get_y(int y)
{
    int k,m,r;
    k=y-100;
    m=k/50;
    r=k%50;
    if(r<25)
        k=(m*50)+100;
    else
    {
        m=m+1;
        k=(m*50)+100;
    }
    return k;
}

int main()
{

    int road[V][V];
    for (int i=1;i<V;i++)
    {
        road[i][0]=0;
        road[0][i]=0;

        for (int j=1;j<V;j++)
        {
            if(i==j)
                road[i][j]=0;
            else if(i==450)
            {
                road[i][j]=0;
                road[450][449]=4;
                road[450][420]=4;
            }

            else if(i%30==0)
            {
                road[i][i+30]=4;
                road[i+30][i]=4;
            }
            else if(i>420)
            {
                road[i][i+1]=4;
                road[i+1][i]=4;
            }
            else
            {
                road[i][i+1]=4;
                road[i][i+30]=4;
                road[i+30][i]=4;
                road[i+1][i]=4;
            }
    }
    road[64][65]=1;
    road[65][64]=1;
    road[72][73]=1;
    road[73][72]=1;
    road[80][81]=1;
    road[81][80]=1;
    road[63][93]=5;
    road[93][63]=5;
    road[71][101]=5;
    road[101][71]=5;
    road[79][109]=5;
    road[109][79]=5;
    road[87][117]=5;
    road[117][87]=5;
    road[127][157]=3;
    road[157][127]=3;
    road[135][165]=3;
    road[165][135]=3;
    road[143][173]=3;
    road[173][143]=3;
    road[184][185]=1;
    road[185][184]=1;
    road[192][193]=1;
    road[193][192]=1;
    road[200][201]=1;
    road[201][200]=1;
    road[183][213]=5;
    road[213][183]=5;
    road[221][191]=5;
    road[191][221]=5;
    road[199][229]=5;
    road[229][199]=5;
    road[207][237]=5;
    road[237][207]=5;
    road[217][218]=2;
    road[218][217]=2;
    road[234][235]=2;
    road[235][234]=2;
    road[304][305]=1;
    road[305][304]=1;
    road[312][313]=1;
    road[313][312]=1;
    road[320][321]=1;
    road[321][320]=1;
    road[307][337]=3;
    road[337][307]=3;
    road[315][345]=3;
    road[345][315]=3;
    road[323][353]=3;
    road[353][323]=3;
    road[333][363]=5;
    road[363][333]=5;
    road[341][371]=5;
    road[371][341]=5;
    road[349][379]=5;
    road[379][349]=5;
    road[357][387]=5;
    road[387][357]=5;
}

    int cordinates[2][V];
    cordinates[0][0]=0;
    cordinates[1][0]=0;
    int count1=0,j=0,k=0;
    for(int i=0;i<15;i++)
    {
        cordinates[1][k+1]=100+(i*50);
        for(j=0;j<30;j++)
        {
            count1++;
            cordinates[0][count1]=70+(j*50);
            cordinates[1][count1]=cordinates[1][k+1];
        }
        k=count1;
    }



    DWORD ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD ScreenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(ScreenWidth,ScreenHeight,"",-3,-3);

    settextstyle(10,HORIZ_DIR,10);
    outtextxy(600,80,"JIIT");
    settextstyle(10,HORIZ_DIR,6);
    outtextxy(655,180,"SEC 62");
    settextstyle(10,HORIZ_DIR,8);
    outtextxy(420,300,"WOMEN SECURITY");
    settextstyle(10,HORIZ_DIR,5);
    outtextxy(1100,490,"SUBMITTED TO:");
    outtextxy(1100,550,"K VIMAL KUMAR");
    outtextxy(60,490,"SUBMITTED BY:");
    outtextxy(60,550,"ASHISH KUMAR KHETAN   (17103178)");
    outtextxy(60,590,"DISHA SAWLANI         (17103195)");
    outtextxy(60,630,"DHANSHREE TEJWANI     (17103194)");
    outtextxy(60,670,"TANVI THAKUR          (17103181)");

    getch();
    closegraph();


    initwindow(ScreenWidth,ScreenHeight,"",-3,-3);


    setcolor(BLUE);
    settextstyle(8,0,4);
    outtextxy(0,0,"POLICE STATION");
    setcolor(YELLOW);
    outtextxy(390,0,"AIRPORT");
    setcolor(WHITE);
    outtextxy(634,0,"COMMON SHOPS");
    setcolor(RED);
    outtextxy(980,0,"BEER SHOP");
    setcolor(GREEN);
    outtextxy(1260,0,"HOSPITAL");

    setcolor(WHITE);
    settextstyle(8,0,1);

    rectangle(70,100,1520,800);

    line(70,100,70,800);
    line(120,100,120,800);
    line(170,100,170,800);
    line(220,100,220,800);
    line(270,100,270,800);
    line(320,100,320,800);
    line(370,100,370,800);
    line(420,100,420,800);
    line(470,100,470,800);
    line(520,100,520,800);
    line(570,100,570,800);
    line(620,100,620,800);
    line(670,100,670,800);
    line(720,100,720,800);
    line(770,100,770,800);
    line(820,100,820,800);
    line(870,100,870,800);
    line(920,100,920,800);
    line(970,100,970,800);
    line(1020,100,1020,800);
    line(1070,100,1070,800);
    line(1120,100,1120,800);
    line(1170,100,1170,800);
    line(1220,100,1220,800);
    line(1270,100,1270,800);
    line(1320,100,1320,800);
    line(1370,100,1370,800);
    line(1420,100,1420,800);
    line(1470,100,1470,800);

    line(70,150,1520,150);
    line(70,200,1520,200);
    line(70,250,1520,250);
    line(70,300,1520,300);
    line(70,350,1520,350);
    line(70,400,1520,400);
    line(70,450,1520,450);
    line(70,500,1520,500);
    line(70,550,1520,550);
    line(70,600,1520,600);
    line(70,650,1520,650);
    line(70,700,1520,700);
    line(70,750,1520,750);





    setcolor(WHITE);
    outtextxy(55,80,"001");
    outtextxy(105,80,"002");
    outtextxy(155,80,"003");
    outtextxy(205,80,"004");
    outtextxy(255,80,"005");
    outtextxy(305,80,"006");
    outtextxy(355,80,"007");
    outtextxy(405,80,"008");
    outtextxy(455,80,"009");
    outtextxy(505,80,"010");
    outtextxy(555,80,"011");
    outtextxy(605,80,"012");
    outtextxy(655,80,"013");
    outtextxy(705,80,"014");
    outtextxy(755,80,"015");
    outtextxy(805,80,"016");
    outtextxy(855,80,"017");
    outtextxy(905,80,"018");
    outtextxy(955,80,"019");
    outtextxy(1005,80,"020");
    outtextxy(1055,80,"021");
    outtextxy(1105,80,"022");
    outtextxy(1155,80,"023");
    outtextxy(1205,80,"024");
    outtextxy(1255,80,"025");
    outtextxy(1305,80,"026");
    outtextxy(1355,80,"027");
    outtextxy(1405,80,"028");
    outtextxy(1455,80,"029");
    outtextxy(1505,80,"030");


    outtextxy(55,130,"031");
    outtextxy(105,130,"032");
    outtextxy(155,130,"033");
    outtextxy(205,130,"034");
    outtextxy(255,130,"035");
    outtextxy(305,130,"036");
    outtextxy(355,130,"037");
    outtextxy(405,130,"038");
    outtextxy(455,130,"039");
    outtextxy(505,130,"040");
    outtextxy(555,130,"041");
    outtextxy(605,130,"042");
    outtextxy(655,130,"043");
    outtextxy(705,130,"044");
    outtextxy(755,130,"045");
    outtextxy(805,130,"046");
    outtextxy(855,130,"047");
    outtextxy(905,130,"048");
    outtextxy(955,130,"049");
    outtextxy(1005,130,"050");
    outtextxy(1055,130,"051");
    outtextxy(1105,130,"052");
    outtextxy(1155,130,"053");
    outtextxy(1205,130,"054");
    outtextxy(1255,130,"055");
    outtextxy(1305,130,"056");
    outtextxy(1355,130,"057");
    outtextxy(1405,130,"058");
    outtextxy(1455,130,"059");
    outtextxy(1505,130,"060");

    outtextxy(55,180,"061");
    outtextxy(105,180,"062");
    outtextxy(155,180,"063");
    outtextxy(205,180,"064");
    outtextxy(255,180,"065");
    outtextxy(305,180,"066");
    outtextxy(355,180,"067");
    outtextxy(405,180,"068");
    outtextxy(455,180,"069");
    outtextxy(505,180,"070");
    outtextxy(555,180,"071");
    outtextxy(605,180,"072");
    outtextxy(655,180,"073");
    outtextxy(705,180,"074");
    outtextxy(755,180,"075");
    outtextxy(805,180,"076");
    outtextxy(855,180,"077");
    outtextxy(905,180,"078");
    outtextxy(955,180,"079");
    outtextxy(1005,180,"080");
    outtextxy(1055,180,"081");
    outtextxy(1105,180,"082");
    outtextxy(1155,180,"083");
    outtextxy(1205,180,"084");
    outtextxy(1255,180,"085");
    outtextxy(1305,180,"086");
    outtextxy(1355,180,"087");
    outtextxy(1405,180,"088");
    outtextxy(1455,180,"089");
    outtextxy(1505,180,"090");

    outtextxy(55,230,"091");
    outtextxy(105,230,"092");
    outtextxy(155,230,"093");
    outtextxy(205,230,"094");
    outtextxy(255,230,"095");
    outtextxy(305,230,"096");
    outtextxy(355,230,"097");
    outtextxy(405,230,"098");
    outtextxy(455,230,"099");
    outtextxy(505,230,"100");
    outtextxy(555,230,"101");
    outtextxy(605,230,"102");
    outtextxy(655,230,"103");
    outtextxy(705,230,"104");
    outtextxy(755,230,"105");
    outtextxy(805,230,"106");
    outtextxy(855,230,"107");
    outtextxy(905,230,"108");
    outtextxy(955,230,"109");
    outtextxy(1005,230,"110");
    outtextxy(1055,230,"111");
    outtextxy(1105,230,"112");
    outtextxy(1155,230,"113");
    outtextxy(1205,230,"114");
    outtextxy(1255,230,"115");
    outtextxy(1305,230,"116");
    outtextxy(1355,230,"117");
    outtextxy(1405,230,"118");
    outtextxy(1455,230,"119");
    outtextxy(1505,230,"120");

    outtextxy(55,280,"121");
    outtextxy(105,280,"122");
    outtextxy(155,280,"123");
    outtextxy(205,280,"124");
    outtextxy(255,280,"125");
    outtextxy(305,280,"126");
    outtextxy(355,280,"127");
    outtextxy(405,280,"128");
    outtextxy(455,280,"129");
    outtextxy(505,280,"130");
    outtextxy(555,280,"131");
    outtextxy(605,280,"132");
    outtextxy(655,280,"133");
    outtextxy(705,280,"134");
    outtextxy(755,280,"135");
    outtextxy(805,280,"136");
    outtextxy(855,280,"137");
    outtextxy(905,280,"138");
    outtextxy(955,280,"139");
    outtextxy(1005,280,"140");
    outtextxy(1055,280,"141");
    outtextxy(1105,280,"142");
    outtextxy(1155,280,"143");
    outtextxy(1205,280,"144");
    outtextxy(1255,280,"145");
    outtextxy(1305,280,"146");
    outtextxy(1355,280,"147");
    outtextxy(1405,280,"148");
    outtextxy(1455,280,"149");
    outtextxy(1505,280,"150");

    outtextxy(55,330,"151");
    outtextxy(105,330,"152");
    outtextxy(155,330,"153");
    outtextxy(205,330,"154");
    outtextxy(255,330,"155");
    outtextxy(305,330,"156");
    outtextxy(355,330,"157");
    outtextxy(405,330,"158");
    outtextxy(455,330,"159");
    outtextxy(505,330,"160");
    outtextxy(555,330,"161");
    outtextxy(605,330,"162");
    outtextxy(655,330,"163");
    outtextxy(705,330,"164");
    outtextxy(755,330,"165");
    outtextxy(805,330,"166");
    outtextxy(855,330,"167");
    outtextxy(905,330,"168");
    outtextxy(955,330,"169");
    outtextxy(1005,330,"170");
    outtextxy(1055,330,"171");
    outtextxy(1105,330,"172");
    outtextxy(1155,330,"173");
    outtextxy(1205,330,"174");
    outtextxy(1255,330,"175");
    outtextxy(1305,330,"176");
    outtextxy(1355,330,"177");
    outtextxy(1405,330,"178");
    outtextxy(1455,330,"179");
    outtextxy(1505,330,"180");

    outtextxy(55,380,"181");
    outtextxy(105,380,"182");
    outtextxy(155,380,"183");
    outtextxy(205,380,"184");
    outtextxy(255,380,"185");
    outtextxy(305,380,"186");
    outtextxy(355,380,"187");
    outtextxy(405,380,"188");
    outtextxy(455,380,"189");
    outtextxy(505,380,"190");
    outtextxy(555,380,"191");
    outtextxy(605,380,"192");
    outtextxy(655,380,"193");
    outtextxy(705,380,"194");
    outtextxy(755,380,"195");
    outtextxy(805,380,"196");
    outtextxy(855,380,"197");
    outtextxy(905,380,"198");
    outtextxy(955,380,"199");
    outtextxy(1005,380,"200");
    outtextxy(1055,380,"201");
    outtextxy(1105,380,"202");
    outtextxy(1155,380,"203");
    outtextxy(1205,380,"204");
    outtextxy(1255,380,"205");
    outtextxy(1305,380,"206");
    outtextxy(1355,380,"207");
    outtextxy(1405,380,"208");
    outtextxy(1455,380,"209");
    outtextxy(1505,380,"210");

    outtextxy(55,430,"211");
    outtextxy(105,430,"212");
    outtextxy(155,430,"213");
    outtextxy(205,430,"214");
    outtextxy(255,430,"215");
    outtextxy(305,430,"216");
    outtextxy(355,430,"217");
    outtextxy(405,430,"218");
    outtextxy(455,430,"219");
    outtextxy(505,430,"220");
    outtextxy(555,430,"221");
    outtextxy(605,430,"222");
    outtextxy(655,430,"223");
    outtextxy(705,430,"224");
    outtextxy(755,430,"225");
    outtextxy(805,430,"226");
    outtextxy(855,430,"227");
    outtextxy(905,430,"228");
    outtextxy(955,430,"229");
    outtextxy(1005,430,"230");
    outtextxy(1055,430,"231");
    outtextxy(1105,430,"232");
    outtextxy(1155,430,"233");
    outtextxy(1205,430,"234");
    outtextxy(1255,430,"235");
    outtextxy(1305,430,"236");
    outtextxy(1355,430,"237");
    outtextxy(1405,430,"238");
    outtextxy(1455,430,"239");
    outtextxy(1505,430,"240");

    outtextxy(55,480,"241");
    outtextxy(105,480,"242");
    outtextxy(155,480,"243");
    outtextxy(205,480,"244");
    outtextxy(255,480,"245");
    outtextxy(305,480,"246");
    outtextxy(355,480,"247");
    outtextxy(405,480,"248");
    outtextxy(455,480,"249");
    outtextxy(505,480,"250");
    outtextxy(555,480,"251");
    outtextxy(605,480,"252");
    outtextxy(655,480,"253");
    outtextxy(705,480,"254");
    outtextxy(755,480,"255");
    outtextxy(805,480,"256");
    outtextxy(855,480,"257");
    outtextxy(905,480,"258");
    outtextxy(955,480,"259");
    outtextxy(1005,480,"260");
    outtextxy(1055,480,"261");
    outtextxy(1105,480,"262");
    outtextxy(1155,480,"263");
    outtextxy(1205,480,"264");
    outtextxy(1255,480,"265");
    outtextxy(1305,480,"266");
    outtextxy(1355,480,"267");
    outtextxy(1405,480,"268");
    outtextxy(1455,480,"269");
    outtextxy(1505,480,"270");

    outtextxy(55,530,"271");
    outtextxy(105,530,"272");
    outtextxy(155,530,"273");
    outtextxy(205,530,"274");
    outtextxy(255,530,"275");
    outtextxy(305,530,"276");
    outtextxy(355,530,"277");
    outtextxy(405,530,"278");
    outtextxy(455,530,"279");
    outtextxy(505,530,"280");
    outtextxy(555,530,"281");
    outtextxy(605,530,"282");
    outtextxy(655,530,"283");
    outtextxy(705,530,"284");
    outtextxy(755,530,"285");
    outtextxy(805,530,"286");
    outtextxy(855,530,"287");
    outtextxy(905,530,"288");
    outtextxy(955,530,"289");
    outtextxy(1005,530,"290");
    outtextxy(1055,530,"291");
    outtextxy(1105,530,"292");
    outtextxy(1155,530,"293");
    outtextxy(1205,530,"294");
    outtextxy(1255,530,"295");
    outtextxy(1305,530,"296");
    outtextxy(1355,530,"297");
    outtextxy(1405,530,"298");
    outtextxy(1455,530,"299");
    outtextxy(1505,530,"300");

    outtextxy(55,580,"301");
    outtextxy(105,580,"302");
    outtextxy(155,580,"303");
    outtextxy(205,580,"304");
    outtextxy(255,580,"305");
    outtextxy(305,580,"306");
    outtextxy(355,580,"307");
    outtextxy(405,580,"308");
    outtextxy(455,580,"309");
    outtextxy(505,580,"310");
    outtextxy(555,580,"311");
    outtextxy(605,580,"312");
    outtextxy(655,580,"313");
    outtextxy(705,580,"314");
    outtextxy(755,580,"315");
    outtextxy(805,580,"316");
    outtextxy(855,580,"317");
    outtextxy(905,580,"318");
    outtextxy(955,580,"319");
    outtextxy(1005,580,"320");
    outtextxy(1055,580,"321");
    outtextxy(1105,580,"322");
    outtextxy(1155,580,"323");
    outtextxy(1205,580,"324");
    outtextxy(1255,580,"325");
    outtextxy(1305,580,"326");
    outtextxy(1355,580,"327");
    outtextxy(1405,580,"328");
    outtextxy(1455,580,"329");
    outtextxy(1505,580,"330");

    outtextxy(55,630,"331");
    outtextxy(105,630,"332");
    outtextxy(155,630,"333");
    outtextxy(205,630,"334");
    outtextxy(255,630,"335");
    outtextxy(305,630,"336");
    outtextxy(355,630,"337");
    outtextxy(405,630,"338");
    outtextxy(455,630,"339");
    outtextxy(505,630,"340");
    outtextxy(555,630,"341");
    outtextxy(605,630,"342");
    outtextxy(655,630,"343");
    outtextxy(705,630,"344");
    outtextxy(755,630,"345");
    outtextxy(805,630,"346");
    outtextxy(855,630,"347");
    outtextxy(905,630,"348");
    outtextxy(955,630,"349");
    outtextxy(1005,630,"350");
    outtextxy(1055,630,"351");
    outtextxy(1105,630,"352");
    outtextxy(1155,630,"353");
    outtextxy(1205,630,"354");
    outtextxy(1255,630,"355");
    outtextxy(1305,630,"356");
    outtextxy(1355,630,"357");
    outtextxy(1405,630,"358");
    outtextxy(1455,630,"359");
    outtextxy(1505,630,"360");

    outtextxy(55,680,"361");
    outtextxy(105,680,"362");
    outtextxy(155,680,"363");
    outtextxy(205,680,"364");
    outtextxy(255,680,"365");
    outtextxy(305,680,"366");
    outtextxy(355,680,"367");
    outtextxy(405,680,"368");
    outtextxy(455,680,"369");
    outtextxy(505,680,"370");
    outtextxy(555,680,"371");
    outtextxy(605,680,"372");
    outtextxy(655,680,"373");
    outtextxy(705,680,"374");
    outtextxy(755,680,"375");
    outtextxy(805,680,"376");
    outtextxy(855,680,"377");
    outtextxy(905,680,"378");
    outtextxy(955,680,"379");
    outtextxy(1005,680,"380");
    outtextxy(1055,680,"381");
    outtextxy(1105,680,"382");
    outtextxy(1155,680,"383");
    outtextxy(1205,680,"384");
    outtextxy(1255,680,"385");
    outtextxy(1305,680,"386");
    outtextxy(1355,680,"387");
    outtextxy(1405,680,"388");
    outtextxy(1455,680,"389");
    outtextxy(1505,680,"390");

    outtextxy(55,730,"391");
    outtextxy(105,730,"392");
    outtextxy(155,730,"393");
    outtextxy(205,730,"394");
    outtextxy(255,730,"395");
    outtextxy(305,730,"396");
    outtextxy(355,730,"397");
    outtextxy(405,730,"398");
    outtextxy(455,730,"399");
    outtextxy(505,730,"400");
    outtextxy(555,730,"401");
    outtextxy(605,730,"402");
    outtextxy(655,730,"403");
    outtextxy(705,730,"404");
    outtextxy(755,730,"405");
    outtextxy(805,730,"406");
    outtextxy(855,730,"407");
    outtextxy(905,730,"408");
    outtextxy(955,730,"409");
    outtextxy(1005,730,"410");
    outtextxy(1055,730,"411");
    outtextxy(1105,730,"412");
    outtextxy(1155,730,"413");
    outtextxy(1205,730,"414");
    outtextxy(1255,730,"415");
    outtextxy(1305,730,"416");
    outtextxy(1355,730,"417");
    outtextxy(1405,730,"418");
    outtextxy(1455,730,"419");
    outtextxy(1505,730,"420");

    outtextxy(55,780,"421");
    outtextxy(105,780,"422");
    outtextxy(155,780,"423");
    outtextxy(205,780,"424");
    outtextxy(255,780,"425");
    outtextxy(305,780,"426");
    outtextxy(355,780,"427");
    outtextxy(405,780,"428");
    outtextxy(455,780,"429");
    outtextxy(505,780,"430");
    outtextxy(555,780,"431");
    outtextxy(605,780,"432");
    outtextxy(655,780,"433");
    outtextxy(705,780,"434");
    outtextxy(755,780,"435");
    outtextxy(805,780,"436");
    outtextxy(855,780,"437");
    outtextxy(905,780,"438");
    outtextxy(955,780,"439");
    outtextxy(1005,780,"440");
    outtextxy(1055,780,"441");
    outtextxy(1105,780,"442");
    outtextxy(1155,780,"443");
    outtextxy(1205,780,"444");
    outtextxy(1255,780,"445");
    outtextxy(1305,780,"446");
    outtextxy(1355,780,"447");
    outtextxy(1405,780,"448");
    outtextxy(1455,780,"449");
    outtextxy(1505,780,"450");

    setcolor(RED);
    circle(170,225,5);
    circle(570,225,5);
    circle(970,225,5);
    circle(170,425,5);
    circle(570,425,5);
    circle(970,425,5);
    circle(170,675,5);
    circle(570,675,5);
    circle(970,675,5);
    circle(1370,225,5);
    circle(1370,425,5);
    circle(1370,675,5);
    setfillstyle(SOLID_FILL,RED);
    floodfill(170,225,RED);
    floodfill(570,225,RED);
    floodfill(970,225,RED);
    floodfill(170,425,RED);
    floodfill(570,425,RED);
    floodfill(970,425,RED);
    floodfill(170,675,RED);
    floodfill(570,675,RED);
    floodfill(970,675,RED);
    floodfill(1370,225,RED);
    floodfill(1370,675,RED);
    floodfill(1370,425,RED);


    setcolor(GREEN);
    circle(370,325,5);
    circle(770,325,5);
    circle(1170,325,5);
    circle(370,625,5);
    circle(770,625,5);
    circle(1170,625,5);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(370,325,GREEN);
    floodfill(770,325,GREEN);
    floodfill(1170,325,GREEN);
    floodfill(370,625,GREEN);
    floodfill(770,625,GREEN);
    floodfill(1170,625,GREEN);


    setcolor(YELLOW);
    circle(395,450,5);
    circle(1245,450,5);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(395,450,YELLOW);
    floodfill(1245,450,YELLOW);


    setcolor(BLUE);
    circle(250,200,5);
    circle(650,200,5);
    circle(1050,200,5);
    circle(250,400,5);
    circle(650,400,5);
    circle(1050,400,5);
    circle(250,600,5);
    circle(650,600,5);
    circle(1050,600,5);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(250,200,BLUE);
    floodfill(250,400,BLUE);
    floodfill(250,600,BLUE);
    floodfill(650,200,BLUE);
    floodfill(650,400,BLUE);
    floodfill(650,600,BLUE);
    floodfill(1050,200,BLUE);
    floodfill(1050,400,BLUE);
    floodfill(1050,600,BLUE);




    POINT CursorPosition;
    int x,y;
    int cot=0;

    setcolor(WHITE);
    outtextxy(8,40,"Click starting position");

    while(1)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&CursorPosition);
            x = CursorPosition.x;
            y = CursorPosition.y;
            setcolor(BLACK);
            outtextxy(8,40,"Click starting position");
            setcolor(WHITE);
            outtextxy(8,40,"Click destination");

            break;

        }
    }
    delay(200);

    int xs,ys;
    xs=get_x(x);
    ys=get_y(y);

    setcolor(CYAN);
    setfillstyle(SOLID_FILL,CYAN);
    circle(xs,ys,5);
    outtextxy(xs-5,ys-25,"S");
    floodfill(xs,ys,CYAN);


    delay(200);
     while(1)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&CursorPosition);
            x = CursorPosition.x;
            y = CursorPosition.y;
            setcolor(BLACK);
            outtextxy(8,40,"Click destination");
            setcolor(WHITE);
            outtextxy(8,40,"Click to show recommended path");

            break;

        }
    }

    int xd,yd;
    xd=get_x(x);
    yd=get_y(y);

    setcolor(CYAN);
    setfillstyle(SOLID_FILL,CYAN);
    circle(xd,yd,5);
    outtextxy(xd-5,yd-25,"D");
    floodfill(xd,yd,CYAN);

    int sp,ep;
    for(int i=1;i<451;i++)
    {
        if((cordinates[0][i]==xs) && (cordinates[1][i]==ys))
            sp=i;
        if((cordinates[0][i]==xd) && (cordinates[1][i]==yd))
            ep=i;
    }

    delay(200);
    if (sp!=ep){
     while(1)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            dijkstra(road, sp, ep, cordinates);
            setcolor(BLACK);
            outtextxy(8,40,"Click to show recommebded path");
            setcolor(WHITE);
            outtextxy(8,40,"Press any key to close");

            break;

        }
    }
    }
    else{
        setcolor(BLACK);
            outtextxy(8,40,"Click to show recommebded path");
            setcolor(WHITE);
            outtextxy(8,40,"Press any key to close");
    }
    getch();
    closegraph();
}
