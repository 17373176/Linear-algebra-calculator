
//���Դ��������������

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<conio.h>

using namespace std;
const int maxn=50+10;//�����С

//��ʼ����
void shan();
//�ӳ�ʱ��
void delay(int t);
//˵��
void shuoming();
//ʹ��
void make();
//��ʼ����
void start();
//����������Ի򷵻�
void error1();
void error2();
//1.������ʽֵ
int hang(int n,int a[maxn][maxn]);
//2.�������ļӷ�
void jujia(int n,int m,int a[maxn][maxn],int b[maxn][maxn]);
//3.�������ļ���
void jujian(int n,int m,int a[maxn][maxn],int b[maxn][maxn]);
//4.�������ĳ˷�
void jucheng(int n,int m1,int n2,int m2,int a[maxn][maxn],int b[maxn][maxn]);
//5.��������
void bansuijuzhen(int n,int a[maxn][maxn]);
//6.�������
void juzhenni(int n,int a[maxn][maxn]);
//7.����ɾ���
void guodujuzhen(int n,int a[maxn][maxn],int b[maxn][maxn]);


int main(){

    //��ʼ����
    shan();
    //ʹ��
    //make();
    return 0;
}


void shan(){

    int t=0;
    cout << "Please press any key to start";
    cout << endl;
    cout << endl;

    //������˸,�������������˸
    while(!kbhit()){
		t=(t+100)%200;
		cout << "    ��ӭ\r";
		delay(t);
		cout << "        ʹ��\r";
		delay(t);
		cout << "            ���Դ���\r";
		delay(t);
		cout << "                    ������\r";
		delay(t);
		cout << "                          ^-^\r";
	}

	cout << " ^-^��ӭʹ�����Դ���������^-^";
	cout << endl;
	cout << endl;
    shuoming();

}

void delay(int t){
    clock_t T=clock();
	while(clock()-T<t);
}

void shuoming(){

    cout << "1.Instructions(���������Ķ������س���������������������Ҫ���鷳)";
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
        cout << "1.�ó��������ڼ����㣬����ľ��������ʽ����������50���������������͹��ɾ���ʱ������10��";
        cout << endl;
        cout << "2.����ʱ����������Ӧ��������򣬷���������Ч";
        cout << endl;
        cout << "3.һ�������ڼ������Χ�ڣ���ʱʹ��������С����ʾ�����ϼ�����Ҫ��";
        cout << endl;
        cout << "4.��������ʱ������رճ������������";
        cout << endl;
        cout << "5.��������Ƿ��ַ������򽫵��³�����󣬻�����ļ������������Ӱ��";
        cout << endl;
        cout << "6.���Դ����������ܻ��������ҵ�ѧϰ����";
        cout << endl;
        cout << "7.���ŵ���ӵ������ʱ�����������ڲ�������";
        cout << endl;
        cout << "8.�������ȫ�������ʹ��^-^";
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

    //��ʼ����
    cout << endl;
    cout << "1.��������ʽ��ֵ";
    cout << endl;
    cout << "2.�������ļӷ�";
    cout << endl;
    cout << "3.�������ļ���";
    cout << endl;
    cout << "4.�������ĳ˷�";
    cout << endl;
    cout << "5.��������";
    cout << endl;
    cout << "6.�������";
    cout << endl;
    cout << "7.����ɾ���";
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

    //1.��������ʽ��ֵ
    if(shu2==1){

        int a[maxn][maxn];
        int n;
        cout << endl;
        cout << "Please input ����ʽ����,then press \"enter\":";
        cout << endl;
        cin >> n;
        cout << endl;
        cout << "Please input ����ʽ,ÿ�����ÿո����,ÿ����һ��,then press \"enter\":";
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
    //2.�������ļӷ�
    else if(shu2==2){

        int a[maxn][maxn],b[maxn][maxn];
        int n,m;

        cout << endl;
        cout << "Please input �����������������֮���ÿո����,then press \"enter\":";
        cout << endl;
        cin >> n >> m;
        cout << endl;
        cout << "Please input ����A,ÿ�����ÿո����,ÿ����һ��,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> a[i][j];
        cout << endl;

        cout << endl;
        cout << "Please input ����B,ÿ�����ÿո����,ÿ����һ��,then press \"enter\":";
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
    //3.�������ļ���
    else if(shu2==3){

        int a[maxn][maxn],b[maxn][maxn];
        int n,m;

        cout << endl;
        cout << "Please input �����������������֮���ÿո����,then press \"enter\":";
        cout << endl;
        cin >> n >> m;
        cout << endl;
        cout << "Please input ����A,ÿ�����ÿո����,ÿ����һ��,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> a[i][j];
        cout << endl;

        cout << endl;
        cout << "Please input ����B,ÿ�����ÿո����,ÿ����һ��,then press \"enter\":";
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
    //4.�������ĳ˷�
    else if(shu2==4){

        int a[maxn][maxn],b[maxn][maxn];
        int n1,m1,n2,m2;

        cout << endl;
        cout << "Please input ����A��������������֮���ÿո����,then press \"enter\":";
        cout << endl;
        cin >> n1 >> m1;
        cout << endl;
        cout << "Please input ����A,ÿ�����ÿո����,ÿ����һ��,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n1;i++)
            for(int j=0;j<m1;j++)
                cin >> a[i][j];
        cout << endl;

        cout << "Please input ����B��������������֮���ÿո����,then press \"enter\":";
        cout << endl;
        cin >> n2 >> m2;
        cout << endl;
        cout << "Please input ����B,ÿ�����ÿո����,ÿ����һ��,then press \"enter\":";
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
    //5.����������
    else if(shu2==5){

        int a[maxn][maxn];
        int n;

        cout << endl;
        cout << "Please input �������,then press \"enter\":";
        cout << endl;
        cin >> n;

        cout << endl;
        cout << "Please input ����,ÿ�����ÿո����,ÿ����һ��,then press \"enter\":";
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
    //6.����������
    else if(shu2==6){

        int a[maxn][maxn];
        int n;

        cout << endl;
        cout << "Please input �������,then press \"enter\":";
        cout << endl;
        cin >> n;

        cout << endl;
        cout << "Please input ����,ÿ�����ÿո����,ÿ����һ��,then press \"enter\":";
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
    //7.����ɾ���
    else if(shu2==7){

        int a[maxn][maxn],b[maxn][maxn];
        int n;

        cout << endl;
        cout << "�����A������B�Ĺ��ɾ���Please input ����Ľ���,then press \"enter\":";
        cout << endl;
        cin >> n;
        cout << endl;
        cout << "Please input ����A,ÿ�����ÿո����,ÿ����һ��,then press \"enter\":";
        cout << endl;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];
        cout << endl;

        cout << "Please input ����B,ÿ�����ÿո����,ÿ����һ��,then press \"enter\":";
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
    //����������Ի򷵻�
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
    //���ؿ�ʼ����
    if(chong==0)
        start();
    //����
    else error2();
}
//�ݹ��������ʽ
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
