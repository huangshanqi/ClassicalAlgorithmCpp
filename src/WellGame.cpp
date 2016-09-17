#include <iostream>
#define SBOUNDARY 2000
#define BOARDSIZE 3
#define SUCCESSSTATUS 8
using namespace std;

class WellGame
{
public:
    static void run()
    {
        // ��¼3��3�м������Խ��ߵĺ͵����
        int status[SUCCESSSTATUS];

        // ÿһ�����붼�������д����Һ���û�ж����̽��б��������ֻ��Ҫʹ��һ��[3][
        int input[SBOUNDARY][BOARDSIZE][BOARDSIZE];
        int result[SBOUNDARY];

        int s;
        char ch;
        int xCount=0;
        int oCount=0;

        cin >> s;
        // ���������ͳ�ƣ����ж�����״̬
        for (int index=0; index<s; index++)
        {
            xCount = 0;
            oCount = 0;
            for(int i=0; i<SUCCESSSTATUS; i++)
            {
                status[i] = 0;
            }

            for(int i=0; i<BOARDSIZE; i++)
            {
                for(int j=0; j<BOARDSIZE; j++)
                {
                    cin >> ch;
                    if(ch == 'X')
                    {
                        input[index][i][j] = 1;
                        xCount++;
                    }
                    else if (ch == 'O')
                    {
                        input[index][i][j] = 4;
                        oCount++;
                    }
                    else if(ch == '_')
                    {
                        input[index][i][j] = 0;
                    }

                    if (i==0)
                    {
                        status[0] += input[index][i][j];
                    }
                    else if(i == 1)
                    {
                        status[1] += input[index][i][j];
                    }
                    else if(i ==2)
                    {
                        status[2] += input[index][i][j];
                    }

                    if(j == 0)
                    {
                        status[3] += input[index][i][j];
                    }
                    else if(j == 1)
                    {
                        status[4] += input[index][i][j];
                    }
                    else if(j == 2)
                    {
                        status[5] += input[index][i][j];
                    }

                    if(i == j)
                    {
                        status[6] += input[index][i][j];
                    }
                    else if(i+j == 2)
                    {
                        status[7] += input[index][i][j];
                    }
                }
            }

             // �Ե�ǰ�������ֽ����ж�
            if (xCount < oCount)
            {
                // �Ƿ�״̬
                result[index] = -1;
            }
            else
            {
                int i = 0;
                for (; i<SUCCESSSTATUS; i++)
                {
                    if(status[i] == 3)
                    {
                        // xʤ��ʹ��3���Ϊx��ʤ--�������3��������1
                        result[index] = 3;
                        break;
                    }
                    else if(status[i] == 12)
                    {
                        // oʤ��ʹ��12���o��ʤ--�������3��������4
                        result[index] = 12;
                        break;
                    }
                    else if(status[i] == 2 && xCount == oCount)
                    {
                        // ��������������x����һ����x��
                        // next xʤ
                        result[index] = 4;
                        break;
                    }
                    else if(status[index] == 8 && xCount==oCount+1)
                    {
                        // ��������������o����һ����o��
                        // next oʤ
                        result[index] = 13;
                        break;
                    }
                }

                if(i == 8 && xCount+oCount == 9)
                {
                    // ���δ��������ʤ���������ô�ж��Ƿ�ƽ��
                    // ����������ƽ��;ƽ�ֲ��ܽ�ֵ��Ϊresult[]�ĳ�ʼĬ��ֵ0
                    result[index] == 1;
                }
            }

        }

        for(int i=0; i<s; i++)
        {
            if(result[i] == -1)
            {
                cout<<"Invalid"<<endl;
            }
            else if(result[i] == 3)
            {
                cout<<"X win"<<endl;
            }
            else if(result[i] == 12)
            {
                cout<<"O win"<<endl;
            }
            else if(result[i] == 4 || result[i] == 13)
            {
                cout<<"Next win"<<endl;
            }
            else if(result[i] == 1)
            {
                cout<<"Draw"<<endl;
            }
            else
            {
                cout<<"Next cannot win"<<endl;
            }
        }

    }
};
