// https://www.naukri.com/code360/problems/minimum-cost-to-connect-sticks_1402396

#include<bits/stdc++.h>
long long int minimumCostToConnectSticks(vector<int> &arr) {
     // Write your Code here.
     long long int cost = 0;
     priority_queue<int, vector<int>, greater<int>> pq;
     for (int &x: arr) pq.push(x);
     if (pq.size() < 2) return 0;
     while (pq.size() > 1) {
          int currCost = pq.top(); pq.pop();
          currCost += pq.top(); pq.pop();
          cost += currCost;
          pq.push(currCost);
     }
     return cost;
}