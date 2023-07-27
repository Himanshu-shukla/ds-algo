#include <iostream>
#include <cstring>
using namespace std;

struct Activity{   //structure

 string id;
 int start;
 int finish;

};

void activity_Selection(Activity activities[],int n) //calling function
{
    int i,k=1;
    cout<<"solution_set:"<<endl;
    cout<<activities[1].id<<"\t"<<activities[1].start<<"\t"<< activities[1].finish<<endl;
    for(i=2;i<=n;i++)
    {
        if(activities[i].start>=activities[k].finish)
        {
          cout<<activities[i].id<<"\t"<<activities[i].start<<"\t"<< activities[i].finish<<endl;
          k=i;
        }
    }
}



int main()
{
    int n,i,j;
    cout<<"Enter the number of activities:";
    cin>>n;

    Activity activities[100],temp; //structure

    cout<<"Enter the activities:"<<endl;
    for(i=1;i<=n;i++)
    {
       cin>>activities[i].id>>activities[i].start>>activities[i].finish;
    }
    cout<<"Output:"<<endl;
     for(i=1;i<=n;i++)
    {
       cout<<activities[i].id<<"\t"<<activities[i].start<<"\t"<< activities[i].finish<<endl;
    }

    for(i=1;i<=n;i++){
		for(j=1;j<=n-1;j++){
			if(activities[j].finish > activities[j+1].finish){   //sorting technique
				temp = activities[j];
				activities[j] = activities[j+1];
				activities[j+1] = temp;
			}
		}
	}

    cout<<"activities are after rearrange according to the Finishing time:"<<endl;
	for(i=1;i<=n;i++)
    {
       cout<<activities[i].id<<"\t"<<activities[i].start<<"\t"<< activities[i].finish<<endl;
    }

    activity_Selection(activities, n); //function call
    return 0;
}