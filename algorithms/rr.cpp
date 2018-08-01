#include <iostream>
#include <vector>
#include <ostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class Process 
{
private:
	string pid;
	int arrival_time;
	int burst_time;
	int completion_time;
	int turnaround_time;
	int waiting_time;

public:
	string getPID()         { return pid;             }
	int getArrivalTime()    { return arrival_time;    } 
	int getBurstTime()      { return burst_time;      }
	int getCompletionTime() { return completion_time; }
	int getTurnaroundTime() { return turnaround_time; }
	int getWaitingTime()    { return waiting_time;    }

	void setPID(string n)          { pid             =  n; }
	void setArrivalTime(int at)    { arrival_time    = at; }
	void setBurstTime(int bt)      { burst_time      = bt; }
	void setCompletionTime(int ct) { completion_time = ct; }
	void setTurnaroundTime(int tt) { turnaround_time = tt; }
	void setWaitingTime(int wt)    { waiting_time    = wt; }

	Process()
	{
		pid             = "";
		arrival_time    =  0;
		burst_time      =  0;
		completion_time =  0;
		turnaround_time =  0;
		waiting_time    =  0;
	}

	Process(string n, int at, int bt) 
	{
		pid             =  n;
		arrival_time    = at;
		burst_time      = bt;
		completion_time =  0;
		turnaround_time =  0;
		waiting_time    =  0;
	}

	friend ostream& operator<<(ostream &ostr, const Process &p)
	{
		int w = 4;
		return ostr << left << setw(w) << p.pid             <<  \
									 left << setw(w) << p.arrival_time    <<  \
									 left << setw(w) << p.burst_time      <<  \
									 left << setw(w) << p.completion_time <<  \
									 left << setw(w) << p.turnaround_time <<  \
									 left << setw(w) << p.waiting_time    <<  endl;
	}

	friend bool operator<(const Process &p, const Process &q)
	{
	  return p.arrival_time < q.arrival_time;
	}
};

void printProcesses(vector<Process> list)
{
	int w = 4;
	cout << left << setw(w) << "ID";
	cout << left << setw(w) << "AT";
	cout << left << setw(w) << "BT";
	cout << left << setw(w) << "CT";
	cout << left << setw(w) << "TT";
	cout << left << setw(w) << "WT";
	cout << endl;

	for(int i = 0; i < list.size(); i++)
	{
		cout << list.at(i);
	}

	cout << endl;
}

// N^2
void sortByPID(vector<Process> &list)
{
	vector<Process> sortedList;

	//iterate whole list
	for(int i = 0; i < list.size(); i++)
	{
		//until found target
		for(int j = 0; j < list.size(); j++)
		{
			//if target == i
			string targetPID = "P" + to_string(j + 1);
			if(list.at(i).getPID() == targetPID)
			{
				sortedList.push_back(list.at(j));
			}
		}
	}
	list = sortedList;
}

void sortByArrivalTime(vector<Process> &list)
{
	sort(list.begin(), list.end());
}

int sumBurstTime(vector<Process> &list)
{
	int sumBurst = 0;
	for(int i = 0; i < list.size(); i++)
	{
		sumBurst += list.at(i).getBurstTime();
	}
	return sumBurst;
}

int sumTurnaroundTime(vector<Process> &list)
{
	int sumTurnaround = 0;
	for(int i = 0; i < list.size(); i++)
	{
		sumTurnaround += list.at(i).getTurnaroundTime();
	}
	return sumTurnaround;
}

int sumWaitingTime(vector<Process> &list)
{
	int sumWaiting = 0;
	for(int i = 0; i < list.size(); i++)
	{
		sumWaiting += list.at(i).getWaitingTime();
	}
	return sumWaiting;
}

int avgTime(int timeToSum, vector<Process> &list)
{
	return timeToSum / list.size();
}

/* ID AT BT CT TT WT RT
	 P4 1  9  30 29 20  9
	 P5 2  2   6  4  2  2
	 P3 3  7  33 30 23  3
	 P2 4  6  27 23 17  5
	 P1 5  5  32 27 22 10
   P6 6  3  21 15 12 12 */
void process(int const TIMEQUANTUM, int i, int cycles, vector<Process> &list)
{
	int time_passed = cycles * (i + 1) * TIMEQUANTUM;
	int turnaround_time = list.at(i).getTurnaroundTime();
	int 	 arrival_time = list.at(i).getArrivalTime();
	int completion_time = list.at(i).getCompletionTime();
	int	     burst_time = list.at(i).getBurstTime();

	cout << i + 1 << ": " << time_passed << endl;
	
	if(time_passed == list.at(i).getBurstTime())
	{
		list.at(i).setCompletionTime(turnaround_time + arrival_time);
	}
	else if(time_passed > list.at(i).getBurstTime())
	{
		int overflow_time = time_passed - list.at(i).getBurstTime();
		list.at(i).setCompletionTime(turnaround_time + arrival_time - overflow_time);
	}

	if(list.at(i).getCompletionTime() > 0)
	{
		list.at(i).setTurnaroundTime(completion_time - arrival_time);
		list.at(i).setWaitingTime(turnaround_time - burst_time);
	}
}

void roundRobin(int TIMEQUANTUM, vector<Process> &list)
{
	sortByArrivalTime(list);
	int time = 1;
	int cycles = 1;
	int burstTimeSum = sumBurstTime(list);
	bool processesComplete = false;
	int time_passed = 0;

	while(!processesComplete)
	{
		for(int i = 0; i < list.size(); i++)
		{
			process(TIMEQUANTUM, i, cycles, list);
	  	time_passed = TIMEQUANTUM * (i + 1) * cycles;
		}
		cycles++;

		if(time_passed >= burstTimeSum)
		{
			processesComplete = true;
		}
	}
}

int main()
{
	vector<Process> processes;
	const int TIMEQUANTUM = 3;

	Process p1 = Process("P1", 5, 5);
	Process p2 = Process("P2", 4, 6);
	Process p3 = Process("P3", 3, 7);
	Process p4 = Process("P4", 1, 9);
	Process p5 = Process("P5", 2, 2);
	Process p6 = Process("P6", 6, 3);

	processes.push_back(p1);
	processes.push_back(p2);
	processes.push_back(p3);
	processes.push_back(p4);
	processes.push_back(p5);
	processes.push_back(p6);

	printProcesses(processes);
	//schedule by roundrobin
	roundRobin(TIMEQUANTUM, processes);

	printProcesses(processes);
	return 0;
}
