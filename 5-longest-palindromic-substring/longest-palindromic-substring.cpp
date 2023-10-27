#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> buildSuffixArray(string str) {
	str += "!";
	int n = str.size(), k = 0;
	vector<int> pos(n);
	vector<int> cls(n);
	cls[0] = 0;
	vector<pair<char, int>>  arr(n);
	for(int i = 0 ; i < n ; i++){
		arr[i] = {str[i], i};
	}

	sort(arr.begin(), arr.end());

	for(int i = 0 ; i < n ; i++){
		pos[i] = arr[i].second;
	}

	for(int i = 1 ; i < n ; i++){
		if(arr[i].first == arr[i-1].first)
			cls[pos[i]] = cls[pos[i-1]];
		else
			cls[pos[i]] = cls[pos[i-1]] + 1;
	}
	
	while((1 << k) < n){
		vector<pair<pair<int, int>, int>> arr(n);
		for(int i = 0 ; i < n ; i++){
			arr[i] = {{cls[i], cls[(i + (1 << k)) % n]}, i};
		}

		sort(arr.begin(), arr.end());

		for(int i = 0 ; i < n ; i++){
			pos[i] = arr[i].second;
		}

		for(int i = 1 ; i < n ; i++){
			if(arr[i].first == arr[i-1].first)
				cls[pos[i]] = cls[pos[i-1]];
			else
				cls[pos[i]] = cls[pos[i-1]] + 1;
		}
		k++;
	}
	vector<int> res;
	for(int i = 1 ; i < n ; i++){
		res.push_back(pos[i]);
	}
	return res;
}

int minSt(vector<int> &st, int ns, int ne, int qs, int qe, int nodeNo){
    if(ns >= qs && ne <= qe)
        return st[nodeNo];
    
    if(ne < qs || ns > qe)
        return INT_MAX;
    
    int mid = ns + (ne - ns)/2;
    return min(minSt(st, ns, mid, qs, qe, 2*nodeNo + 1), minSt(st, mid + 1, ne, qs, qe, 2*nodeNo + 2));
}

int fillST(vector<int> &st, vector<int> &arr, int as, int ae, int nodeNo){
    if(as == ae)
        return st[nodeNo] = arr[as];
    
    int mid = as + (ae - as)/2;
    return st[nodeNo] = min(fillST(st, arr, as, mid, 2*nodeNo + 1), fillST(st, arr, mid + 1, ae, 2*nodeNo + 2));
}

vector<int> buildST(vector<int> &arr, int n){
    vector<int> st(4*n);
    
    st[0] = fillST(st, arr, 0, n - 1, 0);
    
    return st;
}


string Helper(string str)
{
	
    int m = str.size();
    string temp = str;
    reverse(temp.begin(), temp.end());
    str += '$' + temp + "#";
    int n = str.size();
    vector<int> suffixArr = buildSuffixArray(str);
    vector<int> lcp(n, 0);
    vector<int> invertedSuffix(n, 0);

    for (int i=0; i < n; i++)
        invertedSuffix[suffixArr[i]] = i;

    int l = 0;

    for (int i = 0 ; i< n ; i++)
    {
        if (invertedSuffix[i] == n-1){
            l = 0;
            continue;
        }
 
        int j = suffixArr[invertedSuffix[i]+1];
 
        while (i + l < n && j + l < n && str[i+l] == str[j+l])
            l++;
 
        lcp[invertedSuffix[i]] = l; 
 
        if (l>0)
            l--;
    }

	vector<int> st = buildST(lcp, n);

	// for(int i : suffixArr){
	// 	cout << i << " ";
	// }
	// cout << endl;
	// for(int i : lcp){
	// 	cout << i << " ";
	// }
	// cout << endl;

	// for(int i : invertedSuffix){
	// 	cout << i << " ";
	// }

	// cout << endl;

	int maxLen = 0;
	int strtInd = -1;

	for(int i = 0 ; i < m ; i++){
		//odd
		int currInd = i;
		int nextInd = n - i - 2;
		int currRnk = invertedSuffix[currInd];
		int nxtRnk = invertedSuffix[nextInd];
		int newCurrRnk = min(currRnk, nxtRnk);
		int newNxtRnk = max(currRnk, nxtRnk);
		int mini = minSt(st, 0, n - 1, newCurrRnk, newNxtRnk - 1, 0);
		int length = 2*mini - 1;
		if(length == maxLen){
			if(invertedSuffix[i - mini + 1] < invertedSuffix[strtInd]){
				strtInd = i - mini + 1;
			}
		}
		else if(length > maxLen){
			maxLen = length;
			strtInd = i - mini + 1;
		}
	}

	for(int i = 0 ; i < m - 1; i++){
		// even
		int currInd = i + 1;
		int nextInd = n - i - 2;
		int currRnk = invertedSuffix[currInd];
		int nxtRnk = invertedSuffix[nextInd];
		int newCurrRnk = min(currRnk, nxtRnk);
		int newNxtRnk = max(currRnk, nxtRnk);
		int mini = minSt(st, 0, n - 1, newCurrRnk, newNxtRnk - 1, 0);
		int length = 2*mini;
		if(length == maxLen){
			if(invertedSuffix[i - mini + 1] < invertedSuffix[strtInd]){
				strtInd = i - mini + 1;
			}
		}
		else if(length > maxLen){
			maxLen = length;
			strtInd = i - mini + 1;
		}
	}
	return str.substr(strtInd , maxLen);
}


class Solution {
public:
    string longestPalindrome(string s) {
        return Helper(s);
    }
};