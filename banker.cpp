#include <iostream>
using namespace std;
int main()
{
    int process;
    int instances;

    cout << "Enter The number of processes: ";
    cin >> process;
    cout << endl;

    cout << "Enter the number of instances: ";
    cin >> instances;
    cout << endl;

    int alloc[process][instances];

    cout << "Enter the alloction for each process" << endl;

    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < instances; j++)
        {
            cout << "Enter value of arr " << i << " " << j << " :";
            cin >> alloc[i][j];
        }
        cout << endl;
    }

    int max[process][instances];

    cout << "Enter the Maximun for each process" << endl;

    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < instances; j++)
        {
            cout << "Enter value of arr " << i << " " << j << " : ";
            cin >> max[i][j];
        }
        cout << endl;
    }

    int available[instances];
    cout << "Enter Avavilable resource: ";
    for (int i = 0; i < instances; i++)
    {
        cin >> available[i];
    }

    int need[process][instances];

    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < instances; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    cout << "Need Array" << endl;

    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < instances; j++)
        {

            cout << need[i][j] << " ";
        }
        cout << endl;
    }
    bool check;
    int id;
    cout << "Enter The Process id: " << endl;
    cin >> id;
    cout<<"Enter Requested"<<endl;
    int req[instances];
    for (int i = 0; i < instances; i++)
    {
        cin >> req[i];
    }

    for (int i = 0; i < instances; i++)
    {
        if (available[i] >= req[i] && need[id][i] >= req[i])
        {
            available[i] -= req[i];
            alloc[id][i] += req[i];
            need[id][i] -= req[i];
            check = true;
        }
        else
        {
            check = false;
            break;
        }
    }

    if (check == true)
    {

        int k;
        int f[process], ans[process], ind = 0;
        for (k = 0; k < process; k++)
        {
            f[k] = 0;
        }
        int y = 0;
        for (k = 0; k < 5; k++)
        {
            for (int i = 0; i < process; i++)
            {
                if (f[i] == 0)
                {

                    int flag = 0;
                    for (int j = 0; j < instances; j++)
                    {
                        if (need[i][j] > available[j])
                        {
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 0)
                    {
                        ans[ind++] = i;
                        for (y = 0; y < instances; y++)
                            available[y] += alloc[i][y];
                        f[i] = 1;
                    }
                }
            }
        }

        int flag = 1;

        for (int i = 0; i < process; i++)
        {
            if (f[i] == 0)
            {
                flag = 0;
                cout << "The given sequence is not safe";
                break;
            }
        }

        if (flag == 1)
        {
            cout << "Following is the SAFE Sequence" << endl;
            for (int i = 0; i < process - 1; i++)
                cout << " P" << ans[i] << " ->";
            cout << " P" << ans[process - 1] << endl;
        }
    }
    else
    {
        cout << endl;
        cout << "Not safe";
    }

    return 0;
}