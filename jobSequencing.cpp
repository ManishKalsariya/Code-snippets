// job sequencing problem on gfg is solved using greedy approach
// in this approach we sort the jobs in decreasing order of profit and then
//  we try to schedule the jobs in the available slots before their deadlines.
// We keep track of the number of jobs scheduled and the total profit earned.

// this problem makes you understand about how to deal with structures in c++ and how to sort them using custom comparator function.

/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution {
public:

    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {

        sort(arr, arr + n, cmp);

        int cnt = 0;
        int total = 0;

        int maxDeadline = 0;

        for(int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].deadline);
        }

        vector<int> slot(maxDeadline + 1, -1);

        for(int i = 0; i < n; i++) {

            for(int j = arr[i].deadline; j > 0; j--) {

                if(slot[j] == -1) {
                    slot[j] = arr[i].id;
                    cnt++;
                    total += arr[i].profit;
                    break;
                }
            }
        }

        return {cnt, total};
    }
};