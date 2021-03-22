
//线性代数基本运算程序

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<conio.h>

using namespace std;
const int maxn=50+10;//矩阵大小

//开始界面
void shan();
//延迟时间
void delay(int t);
//说明
void shuoming();
//使用
void make();
//开始计算
void start();
//输入错误重试或返回
void error1();
void error2();
//1.求行列式值
int hang(int n,int a[maxn][maxn]);
//2.计算矩阵的加法
void jujia(int n,int m,int a[maxn][maxn],int b[maxn][maxn]);
//3.计算矩阵的减法
void jujian(int n,int m,int a[maxn][maxn],int b[maxn][maxn]);
//4.计算矩阵的乘法
void jucheng(int n,int m1,int n2,int m2,int a[maxn][maxn],int b[maxn][maxn]);
//5.求伴随矩阵
void bansuijuzhen(int n,int a[maxn][maxn]);
//6.求逆矩阵
void juzhenni(int n,int a[maxn][maxn]);
//7.求过渡矩阵
void guodujuzhen(int n,int a[maxn][maxn],int b[maxn][maxn]);


int main(){

    //开始界面
    shan();
    //使用
    //make();
    return 0;
}


void shan(){

    int t=0;
    cout << "Please press any key to start";
    cout << endl;
    cout << endl;

    //标题闪烁,按任意键结束闪烁
    while(!kbhit()){
		t=(t+100)%200;
		cout << "    欢迎\r";
		delay(t);
		cout << "        使用\r";
		delay(t);
		cout << "            线性代数\r";
		delay(t);
		cout << "                    计算器\r";
		delay(t);
		cout << "                          ^-^\r";
	}

	cout << " ^-^欢迎使用线性代数计算器^-^";
	cout << endl;
	cout << endl;
    shuoming();

}

void delay(int t){
    clock_t T=clock();
	while(clock()-T<t);
}

void shuoming(){

    cout << "1.Instructions(请您认真阅读并遵守程序规则，以免给您带来不必要的麻烦)";
    cout << endl;
    cout << "2.Start to calculate";
    cout << endl;
    cout << "3.Exit";
    cout << endl;
    cout << endl;
    cout << "Please enter the corresponding number(1-3):";
    cout << endl;
    make();

}

void make(){

    int shu1;
    cin >> shu1;
    if(shu1==1){
        cout << endl;
        cout << "1.该程序适用于简单运算，输入的矩阵和行列式阶数不超过50，求伴随矩阵、逆矩阵和过渡矩阵时不超过10阶";
        cout << endl;
        cout << "2.计算时必须满足相应的运算规则，否则运算无效";
        cout << endl;
        cout << "3.一般运算在计算机范围内，暂时使用整数和小数表示，符合计算器要求";
        cout << endl;
        cout << "4.如在输入时有误，请关闭程序后重新运行";
        cout << endl;
        cout << "5.请勿输入非法字符，否则将导致程序错误，会给您的计算机带来不利影响";
        cout << endl;
        cout << "6.线性代数计算器能基本满足大家的学习需求";
        cout << endl;
        cout << "7.相信当您拥有它的时候，您会后悔现在才遇见它";
        cout << endl;
        cout << "8.该软件安全，请放心使用^-^";
        cout << endl;
        cout << endl;
        shuoming();

    }

    else if(shu1==2){
        start();
    }
    else if(shu1==3){
        exit(0);
    }
    else error1();
}

void start(){

    //开始计算
    cout << endl;
    cout << "1.计算行列式的值";
    cout << endl;
    cout << "2.计算矩阵的加法";
    cout << endl;
    cout << "3.计算矩阵的减法";
    cout << endl;
    cout << "4.计算矩阵的乘法";
    cout << endl;
    cout << "5.求伴随矩阵";
    cout << endl;
    cout << "6.求逆矩阵";
    cout << endl;
    cout << "7.求过渡矩阵";
    cout << endl;
    cout << "8.Return";
    cout << endl;
    cout << "9.Exit";
    cout << endl;
    cout << endl;
    cout << "Please enter the corresponding number(1-9):";
    cout << endl;

    int shu2;
    cin >> shu2;

    //1.计算行列式的值
    if(shu2==1){

        int a[maxn][maxn];
        int n;
        cout << endl;
        cout << "Please input 行列式阶数,then press \"enter\":";
        cout << endl;
        cin >> n;
        cout << endl;
        cout << "Please input 行列式,每个数用空格隔开,每输入一行,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];

        cout << endl;
        cout << "The answer is: ";
        cout << hang(n,a);
        cout << endl;
        cout << endl;
        cout << "Continue or Return(1 or 0),please input\"1\"or\"0\":";
        cout << endl;

        int shu3;
        cin >> shu3;

        if(shu3==1){
            start();
        }
        else if(shu3==0){
            cout << endl;
            shuoming();
        }
        else error2();
    }
    //2.计算矩阵的加法
    else if(shu2==2){

        int a[maxn][maxn],b[maxn][maxn];
        int n,m;

        cout << endl;
        cout << "Please input 矩阵的行数和列数，之间用空格隔开,then press \"enter\":";
        cout << endl;
        cin >> n >> m;
        cout << endl;
        cout << "Please input 矩阵A,每个数用空格隔开,每输入一行,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> a[i][j];
        cout << endl;

        cout << endl;
        cout << "Please input 矩阵B,每个数用空格隔开,每输入一行,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> b[i][j];

        cout << endl;

        cout << "The answer is: ";
        jujia(n,m,a,b);
        cout << endl;
        cout << endl;
        cout << "Continue or Return(1 or 0),please input\"1\"or\"0\":";
        cout << endl;

        int shu3;
        cin >> shu3;

        if(shu3==1){
            start();
        }
        else if(shu3==0){
            cout << endl;
            shuoming();
        }
        else error2();

    }
    //3.计算矩阵的减法
    else if(shu2==3){

        int a[maxn][maxn],b[maxn][maxn];
        int n,m;

        cout << endl;
        cout << "Please input 矩阵的行数和列数，之间用空格隔开,then press \"enter\":";
        cout << endl;
        cin >> n >> m;
        cout << endl;
        cout << "Please input 矩阵A,每个数用空格隔开,每输入一行,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> a[i][j];
        cout << endl;

        cout << endl;
        cout << "Please input 矩阵B,每个数用空格隔开,每输入一行,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> b[i][j];

        cout << endl;

        cout << "The answer is: ";
        jujian(n,m,a,b);
        cout << endl;
        cout << endl;
        cout << "Continue or Return(1 or 0),please input\"1\"or\"0\":";
        cout << endl;

        int shu3;
        cin >> shu3;

        if(shu3==1){
            start();
        }
        else if(shu3==0){
            cout << endl;
            shuoming();
        }
        else error2();
    }
    //4.计算矩阵的乘法
    else if(shu2==4){

        int a[maxn][maxn],b[maxn][maxn];
        int n1,m1,n2,m2;

        cout << endl;
        cout << "Please input 矩阵A的行数和列数，之间用空格隔开,then press \"enter\":";
        cout << endl;
        cin >> n1 >> m1;
        cout << endl;
        cout << "Please input 矩阵A,每个数用空格隔开,每输入一行,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n1;i++)
            for(int j=0;j<m1;j++)
                cin >> a[i][j];
        cout << endl;

        cout << "Please input 矩阵B的行数和列数，之间用空格隔开,then press \"enter\":";
        cout << endl;
        cin >> n2 >> m2;
        cout << endl;
        cout << "Please input 矩阵B,每个数用空格隔开,每输入一行,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n2;i++)
            for(int j=0;j<m2;j++)
                cin >> b[i][j];

        cout << endl;

        cout << "The answer is: ";
        jucheng(n1,m2,n2,m2,a,b);
        cout << endl;
        cout << endl;
        cout << "Continue or Return(1 or 0),please input\"1\"or\"0\":";
        cout << endl;

        int shu3;
        cin >> shu3;
        if(shu3==1){
            start();
        }
        else if(shu3==0){
            cout << endl;
            shuoming();
        }
        else error2();
    }
    //5.计算伴随矩阵
    else if(shu2==5){

        int a[maxn][maxn];
        int n;

        cout << endl;
        cout << "Please input 矩阵阶数,then press \"enter\":";
        cout << endl;
        cin >> n;

        cout << endl;
        cout << "Please input 矩阵,每个数用空格隔开,每输入一行,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];

        cout << endl;
        cout << "The answer is: ";
        bansuijuzhen(n,a);
        cout << endl;
        cout << endl;
        cout << "Continue or Return(1 or 0),please input\"1\"or\"0\":";
        cout << endl;

        int shu3;
        cin >> shu3;

        if(shu3==1){
            start();
        }
        else if(shu3==0){
            cout << endl;
            shuoming();
        }
        else error2();
    }
    //6.计算矩阵的逆
    else if(shu2==6){

        int a[maxn][maxn];
        int n;

        cout << endl;
        cout << "Please input 矩阵阶数,then press \"enter\":";
        cout << endl;
        cin >> n;

        cout << endl;
        cout << "Please input 矩阵,每个数用空格隔开,每输入一行,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];

        cout << endl;
        cout << "The answer is: ";
        juzhenni(n,a);
        cout << endl;
        cout << endl;
        cout << "Continue or Return(1 or 0),please input\"1\"or\"0\":";
        cout << endl;

        int shu3;
        cin >> shu3;
        if(shu3==1){
            start();
        }
        else if(shu3==0){
            cout << endl;
            shuoming();
        }
        else error2();
    }
    //7.求过渡矩阵
    else if(shu2==7){

        int a[maxn][maxn],b[maxn][maxn];
        int n;

        cout << endl;
        cout << "求矩阵A到矩阵B的过渡矩阵：Please input 矩阵的阶数,then press \"enter\":";
        cout << endl;
        cin >> n;
        cout << endl;
        cout << "Please input 矩阵A,每个数用空格隔开,每输入一行,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];
        cout << endl;

        cout << "Please input 矩阵B,每个数用空格隔开,每输入一行,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> b[i][j];

        cout << endl;
        cout << "The answer is: ";
        guodujuzhen(n,a,b);
        cout << endl;
        cout << endl;
        cout << "Continue or Return(1 or 0),please input\"1\"or\"0\":";
        cout << endl;

        int shu3;
        cin >> shu3;
        if(shu3==1){
            start();
        }
        else if(shu3==0){
            cout << endl;
            shuoming();
        }
        else error2();
    }
    else if(shu2==8){
        shuoming();
    }
    else if(shu2==9){

        exit(0);

    }
    //输入错误重试或返回
    else error2();
}

void error1(){

    cout << endl;
    cout << "Input error";
    cout << endl;
    cout << "Please enter the corresponding number(1-3)again:";
    cout << endl;
    cout << endl;

    make();
}

void error2(){

    cout << endl;
    cout << "Input error";
    cout << endl;
    cout << "Please input\"0\"return,then enter the corresponding number again(1-8)";
    cout << endl;
    cout << endl;

    int chong;
    cin >> chong;
    //返回开始界面
    if(chong==0)
        start();
    //错误
    else error2();
}
//递归求解行列式
int hang(int n,int a[maxn][maxn]){

    int b[maxn][maxn]={{0}};
    int p,q,sum=0;

    if(n==1)return a[0][0];

    for(int i=0;i<n;i++){
        for(int c=0;c<n-1;c++){
            if(c<i)p=0; else p=1;
            for(int j=0;j<n-1;j++)
                b[c][j]=a[c+p][j+1];
        }
        if(i%2==0)q=1;
        else  q=-1;
        sum+=a[i][0]*q*hang(n-1,b);
    }
    return sum;

}

void jujia(int n,int m,int a[maxn][maxn],int b[maxn][maxn]){

    int c[maxn][maxn]={{0}};
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            c[i][j]=a[i][j]+b[i][j];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

void jujian(int n,int m,int a[maxn][maxn],int b[maxn][maxn]){

    int c[maxn][maxn]={{0}};
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            c[i][j]=a[i][j]-b[i][j];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

void jucheng(int n1,int m1,int n2,int m2,int a[maxn][maxn],int b[maxn][maxn]){

    int c[maxn][maxn]={{0}};
    for(int i=0;i<n1;i++)
        for(int j=0;j<m2;j++)
            for(int k=0;k<m1;k++)
                c[i][j]+=a[i][k]*b[k][j];

    for(int i=0;i<n1;i++){
        cout << endl;
        for(int j=0;j<m2;j++)
            cout << c[i][j] << " ";

    }
}

void bansuijuzhen(int n,int a[maxn][maxn]){

    int d[maxn][maxn]={{0}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int b[maxn][maxn]={{0}},p,q,k;
            for(int c=0;c<n-1;c++){
                if(c<i)p=0; else p=1;
                for(int h=0;h<n-1;h++){
                    if(h<j)q=0; else q=1;
                    b[c][h]=a[c+p][h+q];
                }
            }
            if((i+j)%2==0)k=1;
            else  k=-1;
            d[i][j]=k*hang(n-1,b);
        }
    }

    for(int i=0;i<n;i++){
        cout << endl;
        for(int j=0;j<n;j++)
            cout << d[j][i] << " ";
    }
}

void juzhenni(int n,int a[maxn][maxn]){

    int d[maxn][maxn]={{0}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int b[maxn][maxn]={{0}},p,q,k;
            for(int c=0;c<n-1;c++){
                if(c<i)p=0; else p=1;
                for(int h=0;h<n-1;h++){
                    if(h<j)q=0; else q=1;
                    b[c][h]=a[c+p][h+q];
                }
            }
            if((i+j)%2==0)k=1;
            else  k=-1;
            d[i][j]=k*hang(n-1,b);
        }
    }

    double sum=hang(n,a);
    for(int i=0;i<n;i++){
        cout << endl;
        for(int j=0;j<n;j++)
            printf("%.2f ",d[j][i]/sum);
    }
}

void guodujuzhen(int n,int a[maxn][maxn],int b[maxn][maxn]){

    int d[maxn][maxn]={{0}},c[maxn][maxn];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int b[maxn][maxn]={{0}},p,q,k;
            for(int c=0;c<n-1;c++){
                if(c<i)p=0; else p=1;
                for(int h=0;h<n-1;h++){
                    if(h<j)q=0; else q=1;
                    b[c][h]=a[c+p][h+q];
                }
            }
            if((i+j)%2==0)k=1;
            else  k=-1;
            d[i][j]=k*hang(n-1,b);
        }
    }

    double sum=hang(n,a);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            c[i][j]=d[j][i]/sum;

    jucheng(n,n,n,n,c,b);
}
